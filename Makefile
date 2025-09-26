REPOS := \
  cpp_modules \
  ft_irc \
  ft_printf \
  ft_transcendence \
  get_next_line \
  libft \
  miniRT \
  minishell \
  philosophers \
  pipex \
  push_swap \
  so_long

# Behavior
STASH   ?= auto      # auto | skip
DRY_RUN ?= 0

# Colors
C0=\033[0m
C1=\033[1;36m
C2=\033[1;32m
C3=\033[1;33m
CE=\033[1;31m

SUBTREES := \
	cpp_modules:main:cpp_modules \
	ft_irc:main:ft_irc \
	ft_printf:master:ft_printf \
	ft_transcendence:main:ft_transcendence \
	get_next_line:master:get_next_line \
	libft:master:libft \
	miniRT:master:miniRT \
	minishell:main:minishell \
	philosophers:master:philosophers \
	pipex:master:pipex \
	push_swap:master:push_swap \
	so_long:master:so_long

URL_cpp_modules = https://github.com/hanmpark/cpp_modules.git
URL_ft_irc = https://github.com/hanmpark/ft_irc.git
URL_ft_printf = https://github.com/hanmpark/ft_printf.git
URL_ft_transcendence = https://github.com/hanmpark/ft_transcendence.git
URL_get_next_line = https://github.com/hanmpark/get_next_line.git
URL_libft = https://github.com/hanmpark/libft.git
URL_miniRT = https://github.com/hanmpark/miniraytracer.git
URL_minishell = https://github.com/hanmpark/minishell.git
URL_philosophers = https://github.com/hanmpark/philosophers.git
URL_pipex = https://github.com/hanmpark/pipex.git
URL_push_swap = https://github.com/hanmpark/push_swap.git
URL_so_long = https://github.com/hanmpark/so_long.git

.DEFAULT_GOAL := help

help:
	@echo "$(C1)Targets$(C0)"
	@echo "  make ensure-remotes           - add remotes for all projects"
	@echo "  make update                   - fetch + subtree pull for all projects"
	@echo "  make one NAME=<remote>        - update only one project by remote name"
	@echo "  make remotes                  - list configured remotes"
	@echo "  make log PREFIX=dir           - git log limited to a subtree dir"

guard-clean:
	@git rev-parse --verify HEAD >/dev/null 2>&1 || { echo "$(CE)No initial commit.$(C0)"; exit 1; }
	@git diff --quiet || { echo "$(CE)Dirty tree. Commit/stash manually, then retry.$(C0)"; exit 1; }
	@git diff --cached --quiet || { echo "$(CE)Staged changes present. Commit/unstage first.$(C0)"; exit 1; }

ensure-remotes:
	@set -e; \
	for s in $(SUBTREES); do \
	  r=$${s%%:*}; url_var=URL_$${r}; eval url=\$$$${url_var}; \
	  if git remote get-url $$r >/dev/null 2>&1; then \
	    printf "$(C2)✔$(C0) remote '%s' exists\n" $$r; \
	  else \
	    [ -n "$$url" ] || { echo "$(CE)Missing $$url_var$(C0)"; exit 1; } ; \
	    echo "Adding remote $$r -> $$url"; \
	    git remote add $$r $$url; \
	  fi; \
	done

update: guard-clean
	@set -e; \
	for s in $(SUBTREES); do \
	  r=$${s%%:*}; rest=$${s#*:}; b=$${rest%%:*}; p=$${rest#*:}; \
	  if [ ! -d "$$p" ]; then \
	    echo "$(CE)Missing dir $$p/ (was it added?)$(C0)"; exit 1; \
	  fi; \
	  echo "==> PULL $$r / $$b -> $$p/"; \
	  git fetch $$r --tags; \
	  git subtree pull --prefix="$$p" "$$r" "$$b"; \
	done

one: guard-clean
ifndef NAME
	@echo "$(CE)Need NAME=<remote> (e.g., NAME=minishell)$(C0)"; exit 1
endif
	@set -e; \
	found=0; \
	for s in $(SUBTREES); do \
	  r=$${s%%:*}; rest=$${s#*:}; b=$${rest%%:*}; p=$${rest#*:}; \
	  if [ "$$r" = "$(NAME)" ]; then \
	    found=1; \
	    [ -d "$$p" ] || { echo "$(CE)Missing dir $$p/ (was it added?)$(C0)"; exit 1; }; \
	    echo "==> PULL $$r / $$b -> $$p/"; \
	    git fetch $$r --tags; \
	    git subtree pull --prefix="$$p" "$$r" "$$b"; \
	  fi; \
	done; \
	[ "$$found" -eq 1 ] || { echo "$(CE)NAME '$(NAME)' not found in SUBTREES$(C0)"; exit 1; }

remotes:
	@git remote -v

log:
ifndef PREFIX
	@echo "$(CE)Need PREFIX=<dir> (e.g., libft)$(C0)"; exit 1
endif
	@git log --oneline --graph --decorate -- $(PREFIX)
