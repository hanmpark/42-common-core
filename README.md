<div align="center">
    <img src="https://github.com/hanmpark/42-project-badges/blob/main/badges/common_coren.png"/>
</div>

<h1 align="center">42 Common Core Projects</h1>

<p align="center">
    <b><i>All my 42 Common Core projects gathered in a single monorepo with preserved commit history.</i></b>
</p></br>

<div align="center">
    <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/hanmpark/42-common-core"/>
    <img alt="GitHub language count" src="https://img.shields.io/github/languages/count/hanmpark/42-common-core"/>
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/hanmpark/42-common-core"/>
</div>

## 📖 Description
> This repository centralizes all my 42 Common Core projects, each preserved as a subtree with its original Git history.
>
> The projects cover:
> - "**C fundamentals (`libft`, `get_next_line`, `ft_printf`)**"
> - "**Algorithms & optimization (`push_swap`, `philosophers`)**"
> - "**UNIX & processes (`pipex`, `minishell`, `ft_irc`)**"
> - "**Graphics (`so_long`, `miniRT`)**"
> - "**C++ OOP (`cpp_modules`)**"
> - "**Full-stack web (`ft_transcendence`)**"

---

## 📂 Projects

- [`libft/`](./libft) — C utility library (strings, lists, memory) *(solo)*
- [`get_next_line/`](./get_next_line) — Read a file descriptor line-by-line *(solo)*
- [`ft_printf/`](./ft_printf) — Reimplementation of `printf` *(solo)*
- [`push_swap/`](./push_swap) — Stack-based sorting with constrained ops *(solo)*
- [`pipex/`](./pipex) — UNIX pipelines & process management *(solo)*
- [`so_long/`](./so_long) — 2D game using MiniLibX *(solo)*
- [`philosophers/`](./philosophers) — Dining philosophers (threads/mutexes) *(solo)*
- [`minishell/`](./minishell) — A small shell (parsing, env, pipes, redirects) *(group project, with [@Kariyu42](https://github.com/Kariyu42))*
- [`miniRT/`](./miniRT) — Minimal raytracer (vectors, cameras, lights) *(group project, with [@YounesBouhlel](https://github.com/YounesBouhlel))*
- [`cpp_modules/`](./cpp_modules) — C++00–09: OOP basics, canon form, exceptions, templates *(solo)*
- [`ft_irc/`](./ft_irc) — RFC-style IRC server (C++98, sockets, epoll/poll) *(group project, with [@Kariyu42](https://github.com/Kariyu42))*
- [`ft_transcendence/`](./ft_transcendence) — Final web project (Javascript, React, Django, etc.) *(group project, with [@Kariyu42](https://github.com/Kariyu42), [@okbrandon](https://github.com/okbrandon), [@evnsh](https://github.com/evnsh))*

---

# 🧮 Project Scores

This file tracks my results for each 42 Common Core project.
Badges are from [ayogun/42-project-badges](https://github.com/ayogun/42-project-badges).

---

| Project          | Badge                                                                                         | Score |
|------------------|-----------------------------------------------------------------------------------------------|-------|
| **libft**        | ![libft](https://github.com/hanmpark/42-project-badges/blob/main/badges/libftm.png)            | 125/100 |
| **get_next_line**| ![get_next_line](https://github.com/hanmpark/42-project-badges/blob/main/badges/get_next_linem.png) | 125/100 |
| **ft_printf**    | ![ft_printf](https://github.com/hanmpark/42-project-badges/blob/main/badges/ft_printfm.png)    | 125/100 |
| **push_swap**    | ![push_swap](https://github.com/hanmpark/42-project-badges/blob/main/badges/push_swapm.png)    | 125/100 |
| **pipex**        | ![pipex](https://github.com/hanmpark/42-project-badges/blob/main/badges/pipexm.png)            | 125/100 |
| **so_long**      | ![so_long](https://github.com/hanmpark/42-project-badges/blob/main/badges/so_longm.png)        | 125/100 |
| **philosophers** | ![philosophers](https://github.com/hanmpark/42-project-badges/blob/main/badges/philosophersm.png) | 125/100 |
| **minishell**    | ![minishell](https://github.com/hanmpark/42-project-badges/blob/main/badges/minishellm.png)    | 125/100 |
| **miniRT**       | ![miniRT](https://github.com/hanmpark/42-project-badges/blob/main/badges/minirtn.png)          | 120/100 |
| **cpp_modules**  | ![cpp_modules](https://github.com/hanmpark/42-project-badges/blob/main/badges/cppn.png)| 100/100 |
| **ft_irc**       | ![ft_irc](https://github.com/hanmpark/42-project-badges/blob/main/badges/ft_ircm.png)          | 125/100 |
| **ft_transcendence** | ![ft_transcendence](https://github.com/hanmpark/42-project-badges/blob/main/badges/ft_transcendencem.png) | 125/100 |

---

## 🛠️ Repository Management

- Projects imported as **subtrees**, preserving commit history.
- Update all projects:
```bash
make update
```
- Update a single project:
```bash
make one NAME=<project>
```
- List remotes:
```bash
make remotes
```
- Ensure remotes are set (on fresh clone):
```bash
make ensure-remotes
```

---

## 🧭 Structure
```
.
├── cpp_modules/
├── ft_irc/
├── ft_printf/
├── ft_transcendence/
├── get_next_line/
├── libft/
├── miniRT/
├── minishell/
├── philosophers/
├── pipex/
├── push_swap/
└── so_long/
```

---

## 📖 About 42
[42](https://42nice.fr/en/homepage/) is a project-based, peer-learning CS school.
The Common Core spans C/C++, UNIX, algorithms, graphics (MiniLibX), and web.

---

## ⚠️ Disclaimer
This repository is shared for educational and portfolio purposes only.
Unless otherwise stated, the code is not licensed for reuse.

---

## 👤 Authors
- [hanmpark](https://github.com/hanmpark)
- [Kariyu42](https://github.com/Kariyu42) - minishell, ft_irc, ft_transcendence
- [YounesBouhlel](https://github.com/YounesBouhlel) - miniRT
- [okbrandon](https://github.com/okbrandon) - ft_transcendence
- [evnsh](https://github.com/evnsh) - ft_transcendence
