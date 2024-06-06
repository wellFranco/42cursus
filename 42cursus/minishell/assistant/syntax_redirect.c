#include "../minishell.h"

	int check_syntax_error(char operator, char next_char)
	{
	(void)next_char;
	printf("syntax error near '%c'\n", operator);
	return (1);
	}

	int check_pipe(char **arg, int i)
	{
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<')
		check_syntax_error(arg[i][0], arg[i + 1][0]);
	if (arg[i][1] == '|' || arg[i][1] == '>' || arg[i][1] == '<')
		check_syntax_error(arg[i][0], arg[i][1]);
	return (0);
	}

	int check_greater(char **arg, int i)
	{
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '<')
		check_syntax_error(arg[i + 1][0], arg[i + 1][0]);
	if (arg[i][1] == '|' || arg[i][1] == '<')
		check_syntax_error(arg[i][0], arg[i][1]);
	return (0);
	}

	int check_less(char **arg, int i)
	{
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>')
		check_syntax_error(arg[i + 1][0], arg[i + 1][0]);
	if (arg[i][1] == '|' || arg[i][1] == '>')
		check_syntax_error(arg[i][0], arg[i][1]);
	return (0);
	}

	int check_operator(char **arg)
	{
	int i;
	int	error;

	i = 0;
	error = 0;
	while (arg[i] && arg[i + 1] != NULL)
	{
		if (arg[i][0] == '|')
			error += check_pipe(arg, i);
		else if (arg[i][0] == '>')
			error += check_greater(arg, i);
		else if (arg[i][0] == '<')
			error += check_less(arg, i);
		i++;
	}
	if (arg[i][0] == '|' && (arg[i][1] == '>' || arg[i][1] == '|' || arg[i][1] == '<'))
		error += check_syntax_error(arg[i][0], arg[i][1]);
	else if (arg[i][0] == '>' && (arg[i][1] == '|' || arg[i][1] == '<'))
		error += check_syntax_error(arg[i][0], arg[i][1]);
	else if (arg[i][0] == '<' && (arg[i][1] == '|' || arg[i][1] == '>'))
		error += check_syntax_error(arg[i][0], arg[i][1]);
	return (0);
	}