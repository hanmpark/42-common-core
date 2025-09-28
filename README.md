<div align="center">
    <img src="https://github.com/hanmpark/42-project-badges/blob/main/covers/cover-libft-bonus.png"/>
</div>

<p align="center">
    <b><i>This project involves coding a C library that will include numerous general purpose functions for your programs.</i></b>
</p></br>

<div align="center">
    <img alt="Repository created at" src="https://img.shields.io/github/created-at/hanmpark/libft
    "/>
    <img alt="Repository code size" src="https://img.shields.io/github/languages/code-size/hanmpark/libft
    "/>
    <img alt="Mostly used language" src="https://img.shields.io/github/languages/top/hanmpark/libft
    "/>
</div>

## 📖 Description

> Libft is the first project of the 42 Common Core.
> The goal is to create a personal C library that reimplements essential functions of the standard C library, as well as additional utility functions (string manipulation, memory handling, linked lists, etc.).
>
> This library will serve as a foundation for future projects, helping to reduce reliance on built-in functions and strengthening understanding of how they work internally.

## 🛠️ Features

### 🔤 Character and String Manipulation
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

### 💾 Memory Manipulation
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_bzero | sets a specified block of memory to zero by writing null bytes. |
| ft_memset | sets a specified number of bytes in a memory block to a given value. |
| ft_memcpy | copies a specified number of bytes from the source memory block to the destination memory block. |
| ft_memmove | copies a specified number of bytes from a source memory block to a destination memory block, handling overlapping memory regions correctly. |
| ft_memchr | searches for the first occurrence of a specified byte value in a memory block. |
| ft_memcmp | compares two memory blocks up to a specified number of bytes. |
| ft_calloc | allocates a block of memory for an array and initializes all the bytes to zero. |

### 🖊️ File Descriptor Output
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_putchar_fd | writes a character to a specified file descriptor. |
| ft_putstr_fd | writes a string to a specified file descriptor. |
| ft_putendl_fd | writes a string followed by a newline character to a specified file descriptor. |
| ft_putnbr_fd | writes an integer value to a specified file descriptor. |

### 🔎 Character Checks
| FUNCTIONS | DESCRIPTION |
| :-: | --- |
| ft_isalpha | checks whether a given character is an alphabetic character. It determines if the character is either an uppercase letter (A-Z) or a lowercase letter (a-z). |
| ft_isdigit | checks if a given character is a digit (0-9). |
| ft_isalnum | checks whether a given character is alphanumeric, meaning it is either an alphabetic character (a-z, A-Z) or a digit (0-9). |
| ft_isascii | checks whether a given character is a valid ASCII character. |
| ft_isprint | checks if a given character is a printable character. |

### 🔗 Linked List Functions
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

---

## 📦 Installation
Clone the repository and compile the library.
```bash
git clone https://github.com/hanmpark/libft.git
cd libft
make
```
This will create `libft.a`, which you can link to your projects.

---

## 🚀 Usage
To use `libft` in your project:
```bash
gcc main.c -L. -lft -I. -o my_program
```

---

## 👤 Authors
- [hanmpark](https://github.com/hanmpark)
