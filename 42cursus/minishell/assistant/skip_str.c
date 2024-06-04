#include "../minishell.h"

/// @brief CAMINHA COM O ENDERECO DE MEMORIA ATE ENCONTRAR ESPACO OU TABULACAO
/// @param str STRING QUE SERA USADA
/// @return RETORNA O ENDERECO DO PRIMEIRO ESPACO OU TABULACAO ENCONTRADO
char	*skip_char(char *str)
{
	while (*str && *str != ' ' && *str != '	')
		str++;
	return (str);
}

/// @brief CAMINHA COM O ENDERECO DE MEMORIA ATE ENCONTRAR ALGO DIFERENTE DE ESPACO OU TABULACAO
/// @param str STRING QUE SERA USADA
/// @return RETORNA O ENDERECO DO PRIMEIRO ELEMENTO DIFERENTE DE ESPACO OU TABULACAO ENCONTRADO
char	*skip_space(char *str)
{
	while (*str && (*str == ' ' || *str == '	'))
		str++;
	return (str);
}

/// @brief CAMINHA COM O ENDERECO DE MEMORIA ATE ENCONTRAR O CONTEUDO DE c
/// @param str STRING QUE SERA PERCORRIDA
/// @param c CHAR Q SERA USADO COMO REFERENCIA PARA PARAR O WHILE
/// @return RETORNA O ENDERECO DO PRIMEIRO ELEMENTO DIFERENTE DO CHAR c
/// @return RETORNA NULL CASO str SEJA NULL
char	*skip_c(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	// while (str[i] != c) // ERA ASSIM SE DER ERRO VOLTAR AKI
	while (str[i] && str[i] != c)
		i++;
	return (&str[i]);
}

// void	check_operator(char **arg)
// {
// 	int i;

// 	i = 0;

// 	while(arg[i] && arg[i + 1] != NULL)
// 	{
// 		if(arg[i][0] == '|' && (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<'))
// 		{
// 			printf("syntax error\n");
// 			return ;
// 		}
// 		else if(arg[i][0] == '>' && (arg[i + 1][0] == '|' || arg[i + 1][0] == '<'))
// 		{
// 			return ;
// 		}
// 		else if(arg[i][0] == '<' && (arg[i + 1][0] == '|' || arg[i + 1][0] == '>'))
// 		{
// 			return ;
// 		}
// 		i++;
// 	}
// }

void check_operator(char **arg)
{
    int i;

i = 0;
while (arg[i] && arg[i + 1] != NULL)
{
	if (arg[i][0] == '|')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '>')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '<')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	i++;
}
	if (arg[i][0] == '|' && (arg[i][1] == '>' || arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '>' && (arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '<' && (arg[i][1] == '|' || arg[i][1] == '>'))
		printf("syntax error near '%c'\n", arg[i][0]);
}
