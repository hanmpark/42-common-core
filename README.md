# 42 Common Core Projects
This repository gathers all of my [42](https://42nice.fr/en/homepage/) Common Core projects in a single place.
Each project lives in its own folder, with its full Git history preserved via `git subtree`.

---

## 📂 Projects

- [`libft/`](./libft) — C utility library (strings, lists, memory) *(solo)*
- [`get_next_line/`](./get_next_line) — Read a file descriptor line-by-line *(solo)*
- [`ft_printf/`](./ft_printf) — Reimplementation of `printf` *(solo)*
- [`push_swap/`](./push_swap) — Stack-based sorting with constrained ops *(solo)*
- [`pipex/`](./pipex) — UNIX pipelines & process management *(solo)*
- [`so_long/`](./so_long) — 2D game using MiniLibX *(solo)*
- [`philosophers/`](./philosophers) — Dining philosophers (threads/mutexes) *(solo)*
- [`minishell/`](./minishell) — A small shell (parsing, env, pipes, redirects) *(group project, with @Kariyu42)*
- [`miniRT/`](./miniRT) — Minimal raytracer (vectors, cameras, lights) *(group project, with @YounesBouhlel)*
- [`cpp_modules/`](./cpp_modules) — C++00–09: OOP basics, canon form, exceptions, templates *(solo)*
- [`ft_irc/`](./ft_irc) — RFC-style IRC server (C++98, sockets, epoll/poll) *(group project, with @Kariyu42)*
- [`ft_transcendence/`](./ft_transcendence) — Final web project (Javascript, React, Django, etc.) *(group project, with @Kariyu42, @okbrandon, @evnsh)*

---

# 🧮 42 Project Scores

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

---

## 📑 Repository Meta

This monorepo also contains some project-management files:

- [`.github/CODEOWNERS`](./.github/CODEOWNERS) — defines ownership of each project folder (including group projects).
- [`CONTRIBUTING.md`](./CONTRIBUTING.md) — explains contribution guidelines (this repo is portfolio-only, no external PRs).
- [`.github/SECURITY.md`](./.github/SECURITY.md) — clarifies that these projects are for educational purposes and not maintained for production.

These files are mainly here to keep the repository structured and professional.
