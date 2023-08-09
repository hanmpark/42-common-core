/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:52:31 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/09 15:18:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"
#include "parsing.h"
#include "exit.h"

/*
* Parser part:
* - verifies the format of the line and creates a binary tree of commands.
* - this step ensures a well-structured execution flow
* during the execution phase.
*/
static t_tree	*parser(t_tok *l_token, t_mnsh *mnsh)
{
	t_tree	*cmdtable;

	cmdtable = NULL;
	if (!check_order(l_token) || !check_parentheses(l_token))
		return (NULL);
	cmdtable = get_table(l_token, mnsh);
	return (cmdtable);
}

/*
* Lexer part:
* - divides the given line into a sequence of tokens.
* - identifies the building blocks of the command(s) using these tokens.
* - if no errors are encountered, returns the command table.
*/
static t_tok	*lexer(t_mnsh *mnsh)
{
	t_lex	lex;

	lex.cur = 0;
	lex.last = 0;
	lex.l_token = NULL;
	while (mnsh->line[lex.last])
	{
		if (!tokenize(&lex, mnsh))
		{
			free_tokens(&lex.l_token);
			return (NULL);
		}
	}
	return (lex.l_token);
}

/*
* Parsing part:
* - parses the line: creates tokens from the input line and checks
* the order of tokens to handle special cases like
* parentheses and redirections.
* - generates the minishell's AST to represent the parsend line's structure.
*/
static t_tree	*parsing(t_mnsh *mnsh)
{
	t_tree	*cmdtable;
	t_tok	*l_token;

	cmdtable = NULL;
	l_token = lexer(mnsh);
	if (!l_token)
		return (NULL);
	cmdtable = parser(l_token, mnsh);
	if (mnsh->is_debug)
	{
		print_tokens(l_token);
		print_tree(cmdtable);
	}
	free_tokens(&l_token);
	return (cmdtable);
}

/*
* Handles the given line in 3 parts:
* 1. parses the line: tokenizes and processes the input line
* through lexing, parsing, and expanding stages.
* 2. creates an AST: stores the relevant data in an Abstract Syntax Tree (AST)
* to represent the parsed line's structure.
* 3. executes the line: if parsing is successful,
* executes the actions specified by the AST.
*/
void	handle_line(t_mnsh *mnsh)
{
	t_tree	*tree;

	if (!*mnsh->line)
	{
		free(mnsh->line);
		return ;
	}
	add_history(mnsh->line);
	tree = parsing(mnsh);
	free(mnsh->line);
	if (!tree)
		return ;
	execute(mnsh, tree);
	free_tree(tree);
}
