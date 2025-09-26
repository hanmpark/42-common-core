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
