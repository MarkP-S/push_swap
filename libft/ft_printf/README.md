𝘛𝘩𝘪𝘴 𝘱𝘳𝘰𝘫𝘦𝘤𝘵 𝘩𝘢𝘴 𝘣𝘦𝘦𝘯 𝘤𝘳𝘦𝘢𝘵𝘦𝘥 𝘢𝘴 𝘱𝘢𝘳𝘵 𝘰𝘧 𝘵𝘩𝘦 42 𝘤𝘶𝘳𝘳𝘪𝘤𝘶𝘭𝘶𝘮 𝘣𝘺 <𝘮𝘢𝘱𝘦𝘢𝘳𝘴𝘰>.

## Description

**ft_printf** is a custom implementation of the standard C `printf` function, developed as part of the 42 curriculum. The goal of the project is to gain a deeper understanding of variadic functions, formatted output, and low-level input/output by recreating the core behavior of `printf` from scratch.

The implementation supports the mandatory conversion specifiers:

* `%c` - character
* `%s` - string
* `%p` - pointer address
* `%d` / `%i` - signed decimal integer
* `%u` - unsigned decimal integer
* `%x` - hexadecimal (lowercase)
* `%X` - hexadecimal (uppercase)
* `%%` - percent sign

Each conversion function returns the number of characters written, allowing `ft_printf` to match the behavior of the standard `printf` by returning the total number of printed characters.

## Instructions

### Compilation

Compile the library by running:

```bash
make
```

This generates the static library:

```text
libftprintf.a
```

To remove object files:

```bash
make clean
```

To remove object files and the library:

```bash
make fclean
```

To rebuild the project from scratch:

```bash
make re
```

### Using the Library

Include the header in your source file:

```c
#include "ft_printf.h"
```

Compile your program and link it against the library:

```bash
cc main.c libftprintf.a -o program
```

Run the executable:

```bash
./program
```


## Resources

### Documentation

The following resources were used as references:

- GNU C Library Documentation
- Linux manual page for printf

The following resources were used to aid implementation:

 - GeeksforGeeks
 - StackOverflow
 - 42 peers


### AI Usage

AI tools were used as a learning assistant during development.

AI was used for:
- Helping to identify potential edge cases.
- Explaining difficult concepts at times when students were unavailable.
- Assisting with documentation structure.

All functions were implemented, tested, and understood by the project author.

---

# Function Descriptions
ft_printf:
Contains ft_formats - a series of if conditions checking which converter is required to reference and print the proper output.
Contains ft_is_conversion - a checker for an expected conversion character after %.
ft_printf takes in a string and a variadic function. Initialise an index, a count, and the argument list.
If no string is present -1 is returned. 
va_start initialises running through the arguments starting from the first arg after the string.
Iterate through the string, if % is found and the next character is an expected conversion, ft_formats is called to check which conversion is needed and complete it. Otherwise the current character of the string is written to output. Once string ends, va_end stops the arg processing. Throughout the function count is added to based on returns from the functions, so the final output of ft_printf is the entire count.

Each additional function returns a count, which is gained by incrimenting for every character that will be written to output. This is so the ft_printf function itself can track this count from the returns to output the final count when the function is run.

ft_strlen:
Calculates length of string pointed to by s, not including null terminator.

ft_putchar:
write char c to standard output.

ft_putstr:
write a string to output. Same as putchar, but use ft_strlen to designate number of characters to be written.

ft_putnbr:
Output int n to standard output. 
First we add the - to write if < 0 and then make the value positive.
If the number is more than a single digit call the function back dividing by 10(heading toward a single digit). The recursions stack, meaning once a single digit is hit the call to ft_putnbr is successfull and the next line is processed with what was the last given value(before dividing).
Meaning each time we return the single digit, followed by what was the remainder before dividing it by 10, eventually printing the whole number.

ft_puthex:
Converts an unsigned integer into its hexadecimal representation and writes it to the standard output. Similar to ft_putnbr, it uses recursion to process the number. The base is given in the function variables, allowing use by %x and %X.
Each recursion divides by 16 stacking until a single digit is reached. Once reached the corresponding character from base for each digit is written to standard output.

ft_putunsigned:
Same logic as ft_putnbr except without negative handling as unsigned int cannot be negative.

ft_putptr:
Prints the memory address of a pointer in hexadecimal format.
If the pointer is "NULL", the function prints "(nil)". Otherwise, it first prints the "0x" prefix used for hexadecimal memory addresses, then casts the pointer to an unsigned long long and passes it to ft_puthex along with the lowercase hexadecimal character set ("0123456789abcdef"). Unsigned long long used to ensure no loss of data.


