<div align="center">
    <img src="https://github.com/hanmpark/42-project-badges/blob/main/badges/get_next_linem.png"/>
</div>

<h1 align="center">get_next_line</h1>

<p align="center">
    <b><i>A function that reads from a file descriptor line by line.</i></b>
</p></br>

<div align="center">
    <img alt="Repository created at" src="https://img.shields.io/github/created-at/hanmpark/get_next_line"/>
    <img alt="Repository code size" src="https://img.shields.io/github/languages/code-size/hanmpark/get_next_line"/>
    <img alt="Mostly used language" src="https://img.shields.io/github/languages/top/hanmpark/get_next_line"/>
</div>

## Description

> The get_next_line project introduces dynamic memory allocation, buffer management, and file descriptor handling.
>
> The goal is to implement a function that reads one line at a time from a file descriptor without loading the entire file into memory.
> This makes it possible to process large files efficiently and handle multiple file descriptors simultaneously.

## 🛠️ Features
- Reads from a file descriptor line by line.
- Handles dynamic memory allocation for variable-length lines.
- Manages multiple file descriptors at the same time.
- Stops reading at newline (`\n`) or EOF.
- Safe and efficient buffer handling.

### Function Prototype
```c
char *get_next_line(int fd);
```

## 📦 Installation
Clone the repository and compile the project:
```bash
git clone https://github.com/hanmpark/get_next_line.git
cd get_next_line
make
```
This will build the project with the default BUFFER_SIZE.

## 🚀 Usage
Compile with a custom buffer size if needed:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
Call the function inside your program:
```c
char *line;
int fd = open("file.txt", O_RDONLY);

line = get_next_line(fd);
while (line)
{
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
}
close(fd);
```

## 👤 Authors
- [hanmpark](https://github.com/hanmpark)
