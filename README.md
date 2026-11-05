*This project has been created as part of the 42 curriculum by abenabda.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf`. The goal of the project is to learn how variadic functions work (`<stdarg.h>`), how to parse a format string, and how to convert numbers to text by hand using only the `write` system call.

The result is a static library, `libftprintf.a`, exposing one function:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, or `-1` on error (NULL format, invalid conversion, or a failed `write`), like the original.

### Supported conversions

| Conversion | Output |
|------------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is NULL) |
| `%p` | a pointer in hexadecimal, prefixed by `0x` (`(nil)` if NULL) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a literal percent sign |

Flags, width and precision are not handled, as they are not part of the mandatory part.

### Project structure

| File | Content |
|------|---------|
| `ft_printf.h` | prototypes and required includes |
| `ft_printf.c` | `ft_printf`, the format-string loop and the conversion dispatcher |
| `ft_printf_utils.c` | `ft_putchar_len`, `ft_putstr_len`, `ft_putnbr_len`, `ft_putunsigned_len` and the generic base printer |
| `ft_printf_utils_2.c` | `ft_puthex_len` and `ft_putptr_len` |
| `Makefile` | builds `libftprintf.a` |

## Instructions

### Compilation

```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

The code is compiled with `cc -Wall -Wextra -Werror`.

### Usage

Include the header in your program and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	int	len;

	len = ft_printf("Hello %s, you are %d (0x%x)\n", "42", 42, 42);
	ft_printf("printed %d characters\n", len);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structure

### Overall design

`ft_printf` reads the format string **once, from left to right**, with a single index:

1. If the current character is not `%`, it is written as is.
2. If it is `%`, the next character selects a conversion. A dispatcher (`ft_format`) calls the matching helper, and the argument is fetched with `va_arg` using the right type (`int` for `%c`, `%d`, `%i`; `unsigned int` for `%u`, `%x`, `%X`; `char *` for `%s`; `void *` for `%p`).
3. Every helper **returns the number of characters it wrote** (or `-1` if `write` failed). The main loop sums these values into `count`, which is the return value of `ft_printf`.

**Why return lengths instead of counting the format string?** The return value of `printf` is the number of characters *output*, not the number of characters *read*. `%d` with `-42` consumes 2 characters of the format but outputs 3. Having each helper report what it actually wrote is the simplest way to be exact, and it also propagates `write` errors up to the caller with no global state.

### Number conversion: recursive base printing

All numeric conversions share one function, `ft_putnbr_base(n, base, len)`, which prints an unsigned number in any base:

- If `n >= len`, there is more than one digit: call itself on `n / len` to print the leading digits first.
- Then print the last digit, `base[n % len]`.

For example, `123` in base 10 recurses to print `12` (which recurses to print `1`, then `2`) and finally prints `3`. The same logic with `"0123456789abcdef"` and base 16 gives hexadecimal. The base is a string of digit characters, so decimal, lowercase hex and uppercase hex differ only by the string passed in.

**Why recursion?** Digits are naturally produced from the least significant to the most significant, but must be printed in the opposite order. Recursion stores the pending digits on the call stack, which reverses the order for free. The alternative is to fill a temporary buffer backwards and print it, which needs either a fixed-size array or dynamic allocation. Recursion avoids both: the depth is at most 20 for a 64-bit value in base 10 and 16 in base 16, so stack usage is negligible.

**Edge cases handled:**
- `INT_MIN`: `ft_putnbr_len` copies the `int` into a `long` before negating it, because `-INT_MIN` does not fit in an `int`.
- `0`: `n >= len` is false, so the single digit `0` is printed.
- `%x` / `%X` / `%u` use `unsigned int`, so negative arguments such as `-1` print as `ffffffff` / `4294967295`.
- `%p` uses `unsigned long` so a full 64-bit address fits.

### Data structures

No data structure is needed beyond the call stack and a few integers. `ft_printf` is a streaming algorithm: it never needs to store the output, so there is **no buffer and no dynamic allocation**. This means no memory can leak, there is no buffer size limit, and the function is simple to verify. The trade-off is one `write` call per character for numbers (strings are written in a single call), which is slower than a buffered implementation but is acceptable for this project and keeps the code short and norm-compliant.

## Resources

### References

- `man 3 printf` — behaviour of the original function and its conversions
- `man 3 stdarg` — `va_start`, `va_arg`, `va_end`, `va_list`
- `man 2 write` — the system call used for all output
- [cppreference: variadic arguments](https://en.cppreference.com/w/c/variadic)
- [cppreference: printf format specification](https://en.cppreference.com/w/c/io/fprintf)
