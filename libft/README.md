𝘛𝘩𝘪𝘴 𝘱𝘳𝘰𝘫𝘦𝘤𝘵 𝘩𝘢𝘴 𝘣𝘦𝘦𝘯 𝘤𝘳𝘦𝘢𝘵𝘦𝘥 𝘢𝘴 𝘱𝘢𝘳𝘵 𝘰𝘧 𝘵𝘩𝘦 42 𝘤𝘶𝘳𝘳𝘪𝘤𝘶𝘭𝘶𝘮 𝘣𝘺 <𝘮𝘢𝘱𝘦𝘢𝘳𝘴𝘰>.

## Description

Libft is a custom C library developed as part of the 42 curriculum. The goal of this project is to
recreate a selection of standard C library functions while developing a deeper understanding of memory management,
pointers, string manipulation, data structures, and low-level programming concepts.

The library contains implementations of functions from `<ctype.h>`, `<string.h>`, `<stdlib.h>`, and additional utility functions 
commonly used in C programming. It also includes a linked list API for creating, modifying, and managing dynamic data structures.

The project focuses on:
- Understanding how standard C functions work internally.
- Managing memory safely using dynamic allocation.
- Working with pointers and pointer arithmetic.
- Handling edge cases such as null pointers, overlapping memory regions, and integer limits.
- Creating reusable functions following strict coding standards.

## Instructions

### Compilation

The library can be compiled using the provided Makefile.

To compile the library:

```bash
make
```

This will generate the static library:

```
libft.a
```

To remove object files:

```bash
make clean
```

To remove object files and the compiled library:

```bash
make fclean
```

To rebuild the project:

```bash
make re
```

### Usage

Include the library header in your C files:

```c
#include "libft.h"
```

Compile your program together with the library:

```bash
cc main.c libft.a
```

The library can then be used like any other static C library.

---

## Resources

### Documentation

The following resources were used as references:

- GNU C Library Documentation
- Linux manual pages (`man pages`)

The following resources were used to aid implementation:

 - GeeksforGeeks
 - W3Schools
 - StackOverflow
 - 42 peers

Example manual pages:

```bash
man strlen
man memcpy
man memmove
man malloc
man atoi
```

### AI Usage

AI tools were used as a learning assistant during development.

AI was used for:
- Helping to identify potential edge cases.
- Explaining difficult concepts at times when students were unavailable.
- Assisting with documentation structure.

All functions were implemented, tested, and understood by the project author.

---

# Library Description

All descriptions were written by the author as the functions were created, simpler functions may simply have a rewriting of the manual,
more complex functions include some more of the thought process and reasoning behind the implementation.

ft_isalpha:
Checks single unsigned char c, whether it is alphabetic or not.
Returns 1 for positive result - is alphabetic. Returns 0 otherwise.

ft_isdigit:
Checks single unsigned char c, whether it is numeric or not.
Returns 1 for positive result - is numeric. Returns 0 otherwise.

ft_isalnum:
Checks single unsigned char c, whether it is alphanumeric or not.
Returns 1 for positive result - is alphanumeric. Returns 0 otherwise.

ft_isascii:
Checks single unsigned char c, whether it is an ascii character or not.
Returns 1 for positive result - is ascii. Returns 0 otherwise. 

ft_isprint:
Checks single unsigned char c, whether it is a printable character or not.
Returns 1 for positive result - is printable. Returns 0 otherwise.

ft_strlen:
Calculates length of string pointed to by s, not including null terminator.

ft_memset:
Fill the first n bytes pointed to by s, with the value from c.
Return the pointer to s. Testing the return shows a string of length n with character c.

ft_bzero:
Erase data of n bytes starting from pointer s, by replacing any data with 0 values. No return expected.
Testing can be done by using memset to set n bytes to a character, confirm, and then use bzero to erase them.

ft_memcpy:
Copy n bytes of memory from src to dest. Return pointer to dest.
memcpy should take in any data type, hence being declared with void dest and src.
Use temp pointers, pointing to locations of dest and src, in order to keep originals unchanged to return.
Assign type unsigned char to iterate by single bytes, unsigned here is convention and considered best practice, it signals usage of bytes not characters.
temps point to the relevant locations, assign data to those locations, then when using the function the original pointer will read the data from the same location
and therefore be reading what was copied there.

ft_memmove:
Same as ft_memcpy but the bytes to be copied can overlap. Meaning the pointers run into each other when dest > src and the number of bytes to be copied make dest
loop on itself as it starts to copy from the front.
Create temp array of size defined in function, copy the src to the array first. Then copy array to dest to avoid overlap issues. Return dest.
Norm not allowing variable length array so method above unusable.
New method, as suggested by peers:
when dest<src, copy as normal like memcpy.
When dest>src copy backwards instead, meaning once the pointed to data is overlapped it has already been copied forward in dest and therefore can be overwritten.

ft_strlcpy:
Copy size - 1 characters from nul-terminated string src to dst. Resulting string is nul terminated.
Return strlen of src - the size of the string trying to be created.
Remember that

ft_strlcat:
Copy size-dest-1 bytes from src to end of dst, not including nul byte in src. Essentially the total size we accept minus the existing string in dest -1 for nul terminator.
Written as (size > (dest_size + j + 1)) in the code meaning we work from original string size of dest, up to size as a maximum, accounting for 0 index and nul terminator.
Initial src byte will overwrite nul at end of dst. End dst with nul unless exceding dest+size
Return dst+src, but dst limited by size. If we traverse size without finding nul, length is equal to size and dest is not nul-terminated.

ft_toupper:
Convert lowercase letter to uppercase. If uppercase letter is given, then it returns the same letter unchanged.

ft_tolower:
Convert uppercase letter to lowercase. If lowercase letter is given, then it returns the same letter unchanged.

ft_strchr:
Check for first instance of a character in a string. Takes in the character as int so first convert to char. Loop through string until character match.
Return upon hitting a match, return the pointer to the character location. If no match, check again for nul terminator as this is allowed as c. 
If end character not nul matching, return null.

ft_strrchr:
Checks for last instance of a character in a string. Same as strchr except we store the found pointer in a result variable, which updates each time the char is found.
Again if none found, nul is checked. Result set to null by default so ending return of result always correct.

ft_strncmp:
Comparing two strings, loop through characters if they are the same and until iterator reaches given size minus 0 adjustment and nul terminator, and both are true.
Return s1 minus s2. 0 if they are the same end character. + or - if different depending on the different characters which is higher ascii value

ft_memchr:
Same as strchr except we only go up to n bytes and are required to convert both string and char to unsigned char. So typcasting is changed and loop condition changed for 
i < n. Removed final check for null as only looking through n bytes. Otherwise outputs same.

ft_memcmp:
Same as strncmp except for pointer locations not data. As such the change is to convert s1 and s2 to unsigned char first then iterate through and return the difference
the same as strncmp.

ft_strnstr:
Similar to strchr except we are searching for a smaller string within a bigger string. Therefore within the loop of the bigger string we loop again 
checking the current character in big matches that of little and as long as big still exists and the given size isn't reached.
Return big if little is empty. Return pointer to first char of little in big if little is found. Return null if not found.

ft_atoi:
Convert char to integer. Refers to strtol for detail. Take in string, remove white space with isspace, check for + or -(note only one sign is allowed as per strtol).
If characters in string are numbers, begin iterating through converting to ascii values for each by taking away '0' (ascii 48). To build final number we multiple by 10
each iteration to move the existing digit forward, and adding the next behind it. Multiple by the sign in case of negative before returning final integer.

ft_calloc:
Memory allocation of a defined block determined by count of data points input(nmemb) and the size of each data point, usually assigned by using sizeof when calling calloc.
Return Null if memory allocation fails. Ensure no overflow by checking memory to be allocated doesn't exceed SIZE_MAX. 
Allocated memory is assigned 0 to each block. Pointer to this block is returned when assigned, or if nmemb or size are 0.

ft_strdup:
Take in a string, duplicate it to another memory slot allocated by malloc. Return pointer to new string. Null returned if insufficient memory, which will be caught by malloc failing.
Works simply by mallocing a set of memory size defined by incoming string length. Then iterate through assigning each char of the string to the newly allocated memory slots.

ft_substr:
Duplicate a substring from a longer string, defined by a start index within that string. Duplicate is assigned to allocated memory.
Check s actually has data, otherwise return null. if the start index is beyond the length of s, nothing to duplicate so return empty string.
If the length input to duplicate goes beyond the string provided, we limit the length to only the available string(length from start index to end of string).
Malloc the defined length +1 for null terminator. Return null if malloc failed. Copy from original to new pointer for length and return pointer to the new string.

ft_strjoin:
Join two strings, with a different string as the return with the concatenation. Malloc the length of both strings + 1 for nul. Return null if failed.
Add first string to result char by char until end, then reset iterator and add second string to result. finally add nul terminator and return result.

ft_strtrim:
Take a string to be trimmed and a set of letters to trim from it. Allocate memory for the new string with characters removed.
Check if there is a string or a set, return null if one doesn't exist. If string length is 0 return an empty string. Set i and j to be the beginning and ending of the string.
Iterate through the string increasing i, checking additional function if the current character exists in the set for trimming. If it does keep iterating through the string.
i value ends on the start of the non-trimmed string. Iterate backwards with j from length-1 doing the same thing to find the ending. Use values to put into substr.
s1 is string, i is start, j-i+1 is length(+1 to account for indexes switching to length, 4-2 = 2 but has 3 characters). Substr output gives the malloc'd string required for return.

ft_split:
Split a string seperated by a given character. Require word count first to allocated memory for the array of strings.
Function made for this, iterate through string, add to count when not hitting c. Boolean variable made to ensure not counting the same word, resets when c is hit. count adds every time new word starts.
Using this we allocate for the word array, the return the result which calls another function which builds the array. In this function we again iterate through s, moving forward when matching c.
Record start point of word as i when c is not matched and continue i++ until next c is hit. Use substr to separate out the string based on start and length now i-start. Assign this into current iterated point of array.
continues until string ends, or any failed allocation resulting in null and freeing memory with additional function that takes in the current array and position within, and iterates through freeing all the allocated memory.

ft_itoa:
integer to string. count the digits in the int to malloc array of proper size. Do this by dividing by 10 and adding to count until !n. Malloc char *.
Adding numbers from the back so set i to length and add null terminator first. Then loop, i--. Adding each digit to the char * using modulo 10 to get last digit, and converting with + '0'.
iterate by dividing by 10 until n doesn't exist. return string.
Filling the string was separated into a different function due to exceeding line count.

ft_strmapi:
take a string and a function, apply function to each char of string. strlen to malloc new string. From i to len apply given function to s[i]. Add each to mallocd string.
Return result.

ft_striteri:
Take a string and a function, apply function to each character. No return, original modified based on address of each char passed to function for altering.

ft_putchar_fd:
write char c to specified fd. Interest here is in the testing, with a simple call any fd 0,1,2 will just print the char to the terminal. But each has a different use.
0 - standard input, for reading user input from terminal. 1 - standard output, writing to the terminal. 2 - standard error, to write errors to the terminal, same as 1 but can be used for error logging to file.

ft_putstr_fd:
write a string to specified fd. Same as putchar, but use ft_strlen to designate number of characters to be written.

ft_putendl_fd:
putstr and a new line.

ft_putnbr_fd:
Output int n to given fd. 
First we add the - to write if < 0 and then make the value positive. Check if the value is a single integer, write if yes.
If not, call the function back dividing by 10(heading toward a single digit). The recursions stack, meaning once a single digit is hit the call to ft_putnbr is successfull and the next ft_putnbr
is called, with what was the last given value(before dividing).
Meaning each time we return the single digit, followed by what was the remainder before dividing it by 10, eventually printing the whole number.

ft_lstnew:
Creates a new list node with content and next set to NULL.
Parameters: content - pointer to the node content.
Return value: new list node, or NULL on allocation failure.

ft_lstadd_front:
Adds the node new at the beginning of the list.
Parameters: lst - pointer to list head, new - node to add.
Return value: none.

ft_lstsize:
Counts the number of nodes in the list.
Parameters: lst - beginning of the list.
Return value: number of nodes.

ft_lstlast:
Returns the last node of the list.
Parameters: lst - beginning of the list.
Return value: last node, or NULL if list is empty.

ft_lstadd_back:
Adds the node new at the end of the list.
Parameters: lst - pointer to list head, new - node to add.
Return value: none.

ft_lstdelone:
Deletes a single node, freeing its content with del and freeing the node.
Parameters: lst - node to delete, del - function to free content.
Return value: none.

ft_lstclear:
Deletes and frees every node of the list using del on each content.
Parameters: lst - pointer to list head, del - function to free content.
Return value: none.

ft_lstiter:
Iterates over the list and applies f to the content of each node.
Parameters: lst - beginning of the list, f - function to apply.
Return value: none.

ft_lstmap:
Creates a new list by applying f to the content of each node in lst.
Parameters: lst - source list, f - mapping function, del - cleanup on fail.
Return value: new list, or NULL on failure.
