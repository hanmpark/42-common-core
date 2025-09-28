<div align="center">
    <img src="https://github.com/hanmpark/42-project-badges/blob/main/badges/pipexm.png"/>
</div>

<h1 align="center">pipex</h1>

<p align="center">
    <b><i>Reimplementation of UNIX pipes behavior in C.</i></b>
</p></br>

<div align="center">
    <img alt="Repository created at" src="https://img.shields.io/github/created-at/hanmpark/pipex"/>
    <img alt="Repository code size" src="https://img.shields.io/github/languages/code-size/hanmpark/pipex"/>
    <img alt="Mostly used language" src="https://img.shields.io/github/languages/top/hanmpark/pipex"/>
</div>

## 📖 Description
> The **pipex** project consists of recreating the behavior of UNIX pipes (`|`) in C.
>
> It executes a series of commands, redirecting the output of one command as the input of the next.
>
> To achieve this, `pipex` makes use of:
>
> - "**File descriptors for redirection**"
> - "**Pipes for inter-process communication**"
> - "**`fork()` and `execve()` for process creation and command execution**"

## 🛠️ Features
- Handle **two-command piping** (mandatory part)
- Extend to **multiple commands** (bonus)
- Support **here_doc** functionality with a limiter (bonus)
- Correctly manage file redirections (`<`, `>`, `>>`)
- Robust handling of processes and errors

## 📦 Installation
Clone the repository and compile:
```bash
git clone https://github.com/hanmpark/pipex.git
cd pipex
make
```

## 🚀 Usage
### ✅ Mandatory
```bash
./pipex file1 cmd1 cmd2 file2
```
Equivalent to:
```bash
< file1 cmd1 | cmd2 > file2
```

### 🔥 Bonus – Multiple Commands
```bash
🔥 Bonus – Multiple Commands
```
Equivalent to:
```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

### 🔥 Bonus – here_doc
```bash
./pipex here_doc LIMITER cmd cmd1 file
```
Equivalent to:
```bash
cmd << LIMITER | cmd1 >> file
```

## Authors
- [hanmpark](https://github.com/hanmpark)
