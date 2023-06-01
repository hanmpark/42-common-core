# libft

> A library is a collection of prewritten code that provides ready-to-use functions and features. It helps programmers by offering commonly used functionalities, such as input/output operations, string manipulation, chained list manipulation, etc. By using libraries, programmers can save time and effort by reusing existing code instead of writing everything from scratch.

![Library](https://github.com/hanmpark/libft/blob/master/Library.jpeg)

## Project
The purpose of the project is to create a library of essential functions that can be used in subsequent projects throughout the course. The name "Libft" stands for "Library Functions," and the project requires students to implement their own versions of various standard C library functions.

The "Libft" library, once done, can then be utilized by students in their future projects, reducing the reliance on built-in library functions and enabling them to further develop their programming skills. It encourages students to think critically about the functionality of the standard library functions and helps them gain a deeper understanding of how these functions are implemented.

***
## Functions
### Char manipulation
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_strlen | calculates the length of a null-terminated string. |
| ft_strlcpy | copies a null-terminated string from the source to the destination, while ensuring that the destination buffer does not overflow. |
| ft_strlcat | appends a null-terminated string from the source to the destination, while ensuring that the destination buffer does not overflow. |
| ft_toupper | converts a given lowercase character to its corresponding uppercase representation. |
| ft_tolower | converts a given uppercase character to its corresponding lowercase representation. |
| ft_strchr | searches for the first occurrence of a specified character in a string. |
| ft_strrchr | searches for the last occurrence of a specified character in a string. |
| ft_strncmp | compares two strings up to a specified number of characters. |
| ft_strnstr | searches for a substring within a given string, but with a specified maximum length to search. |
| ft_strdup | duplicates a null-terminated string. |
| ft_substr | creates a new string that contains a portion of the original string starting at a specified index and with a specified length. |
| ft_strjoin | takes two parameters: pointers to the two strings to be concatenated. |
| ft_strtrim | removes specified characters from the beginning and end of a string. |
| ft_split | splits a string into an array of substrings based on a specified delimiter. |
| ft_atoi | converts a string representation of an integer into its corresponding integer value. |
| ft_itoa | converts an integer into a string. |
| ft_strmapi | applies a function to each character of a string, creating a new string with the modified characters. |
| ft_striteri | applies a function to each character of a string, with the index of the character passed as an argument to the function. |

### Memory manipulation
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_bzero | sets a specified block of memory to zero by writing null bytes. |
| ft_memset | sets a specified number of bytes in a memory block to a given value. |
| ft_memcpy | copies a specified number of bytes from the source memory block to the destination memory block. |
| ft_memmove | copies a specified number of bytes from a source memory block to a destination memory block, handling overlapping memory regions correctly. |
| ft_memchr | searches for the first occurrence of a specified byte value in a memory block. |
| ft_memcmp | compares two memory blocks up to a specified number of bytes. |
| ft_calloc | allocates a block of memory for an array and initializes all the bytes to zero. |

### Output to a filedescriptor
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_putchar_fd | writes a character to a specified file descriptor. |
| ft_putstr_fd | writes a string to a specified file descriptor. |
| ft_putendl_fd | writes a string followed by a newline character to a specified file descriptor. |
| ft_putnbr_fd | writes an integer value to a specified file descriptor. |

### Is something
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_isalpha | checks whether a given character is an alphabetic character. It determines if the character is either an uppercase letter (A-Z) or a lowercase letter (a-z). |
| ft_isdigit | checks if a given character is a digit (0-9). |
| ft_isalnum | checks whether a given character is alphanumeric, meaning it is either an alphabetic character (a-z, A-Z) or a digit (0-9). |
| ft_isascii | checks whether a given character is a valid ASCII character. |
| ft_isprint | checks if a given character is a printable character. |

### Chained list manipulation
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_lstnew | creates a new linked list node. |
| ft_lstadd_front | adds a new node at the beginning of a linked list. |
| ft_lstadd_back | adds a new node at the end of a linked list. |
| ft_lstsize | counts the number of elements in a linked list. |
| ft_lstlast | returns the last element of a linked list. |
| ft_lstdelone | deletes a single node from a linked list. |
| ft_lstclear | deletes and frees all the nodes in a linked list. |
| ft_lstiter | applies a function to each element of a linked list. |
| ft_lstmap | applies a function to each element of a linked list and creates a new list with the modified elements. |
