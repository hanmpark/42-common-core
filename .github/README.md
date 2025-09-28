<div align="center">
    <img src="https://github.com/hanmpark/42-project-badges/blob/main/badges/ft_printfm.png"/>
</div>

<h1 align="center">ft_printf</h1>

<p align="center">
    <b><i>A versatile and customizable formatted output function.</i></b>
</p></br>

<div align="center">
    <img alt="Repository created at" src="https://img.shields.io/github/created-at/hanmpark/ft_printf"/>
    <img alt="Repository code size" src="https://img.shields.io/github/languages/code-size/hanmpark/ft_printf"/>
    <img alt="Mostly used language" src="https://img.shields.io/github/languages/top/hanmpark/ft_printf"/>
</div>

## 📖 Description

> The ft_printf project reimplements the standard C printf function.
>
> The goal is to create a function capable of formatting and printing different types of data, supporting multiple conversion specifiers, flags, and modifiers.
> This project deepens the understanding of variadic functions, parsing, and formatted output.

## 🛠️ Features
### Function Prototype
```c
int ft_printf(const char *, ...);
```

### ✅ Supported Conversion Specifiers
- `%c` – Character
- `%s` – String
- `%p` – Pointer address
- `%d` / `%i` – Signed integers
- `%u` – Unsigned integer
- `%x` / `%X` – Hexadecimal (lowercase/uppercase)
- `%%` – Percent sign

### ⚙️ Supported Flags
- `-` (left align)
- `0` (zero padding)
- `.` (precision)
- `#` (alternate form for hex)
- `+` (force sign)
- space (prepend a space for positive numbers)

---

## 📦 Installation
Clone the repository and compile the library:
```bash
git clone https://github.com/hanmpark/ft_printf.git
cd ft_printf
make
```
This will create `libftprintf.a` which you can link into your projects.

---

## 🚀 Usage
Example usage:
```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d, Hex: %x\n", "world", 42, 42);
    ft_printf("Printed %d characters.\n", count);
    return (0);
}
```
Compile with:
```bash
gcc main.c -L. -lftprintf -I. -o my_program
```

---

## 👤 Authors
- [hanmpark](https://github.com/hanmpark)
