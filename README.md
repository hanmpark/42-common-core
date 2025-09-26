# 42 Common Core Projects
This repository gathers all of my [42](https://42nice.fr/en/homepage/) Common Core projects in a single place.
Each project lives in its own folder, with its full Git history preserved via `git subtree`.

---

## 📂 Projects

- [`libft/`](./libft) — C utility library (strings, lists, memory)
- [`get_next_line/`](./get_next_line) — Read a file descriptor line-by-line
- [`ft_printf/`](./ft_printf) — Reimplementation of `printf`
- [`push_swap/`](./push_swap) — Stack-based sorting with constrained ops
- [`pipex/`](./pipex) — UNIX pipelines & process management
- [`so_long/`](./so_long) — 2D game using MiniLibX
- [`philosophers/`](./philosophers) — Dining philosophers (threads/mutexes)
- [`minishell/`](./minishell) — A small shell (parsing, env, pipes, redirects)
- [`miniRT/`](./miniRT) — Minimal raytracer (vectors, cameras, lights)
- [`cpp_modules/`](./cpp_modules) — C++00–09: OOP basics, canon form, exceptions, templates
- [`ft_irc/`](./ft_irc) — RFC-style IRC server (C++98, sockets, epoll/poll)
- [`ft_transcendence/`](./ft_transcendence) — Final web project (Javascript, React, Django, etc.)

---

# 🧮 42 Project Scores

This file tracks my results for each 42 Common Core project.
Badges are from [ayogun/42-project-badges](https://github.com/ayogun/42-project-badges).

---

| Project          | Badge                                                                                         | Score |
|------------------|-----------------------------------------------------------------------------------------------|-------|
| **libft**        | ![libft](https://github.com/ayogun/42-project-badges/raw/master/badges/libftm.png)            | 125/100 |
| **get_next_line**| ![get_next_line](https://github.com/ayogun/42-project-badges/raw/master/badges/get_next_linem.png) | 125/100 |
| **ft_printf**    | ![ft_printf](https://github.com/ayogun/42-project-badges/raw/master/badges/ft_printfm.png)    | 125/100 |
| **push_swap**    | ![push_swap](https://github.com/ayogun/42-project-badges/raw/master/badges/push_swapm.png)    | 125/100 |
| **pipex**        | ![pipex](https://github.com/ayogun/42-project-badges/raw/master/badges/pipexm.png)            | 125/100 |
| **so_long**      | ![so_long](https://github.com/ayogun/42-project-badges/raw/master/badges/so_longn.png)        | 125/100 |
| **philosophers** | ![philosophers](https://github.com/ayogun/42-project-badges/raw/master/badges/philosophersn.png) | 125/100 |
| **minishell**    | ![minishell](https://github.com/ayogun/42-project-badges/raw/master/badges/minishelln.png)    | 125/100 |
| **miniRT**       | ![miniRT](https://github.com/ayogun/42-project-badges/raw/master/badges/miniRTn.png)          | 120/100 |
| **cpp_modules**  | ![cpp_modules](https://github.com/ayogun/42-project-badges/raw/master/badges/cpp_modulesn.png)| 100/100 |
| **ft_irc**       | ![ft_irc](https://github.com/ayogun/42-project-badges/raw/master/badges/ft_ircn.png)          | 125/100 |
| **ft_transcendence** | ![ft_transcendence](https://github.com/ayogun/42-project-badges/raw/master/badges/ft_transcendencen.png) | 125/100 |

---

## 🛠️ How this repo works

- Each project was imported as a **subtree**, preserving its commit history.
- To update all projects from their original repositories:
  ```bash
  make update
  ```
- to update a single project:
  ```bash
  make one NAME=<remote>
  # e.g.
  make one NAME=minishell
  ```
> Tip: run `make remotes` to see configured remotes, and `make ensure-remotes` once on a fresh clone.

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
