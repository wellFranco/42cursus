/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:10:16 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/04 19:04:00 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

// ./assistant/ft_strlen.c
size_t	ft_strlen(const char *str); // NAO USANDO POR ENQUANTO

// ./assistant/ft_strtrim
char	*ft_strtrim(char const *s1, char const *set); // NAO USANDO POR ENQUANTO

// ./assistant/ft_split.c
char	**ft_split(char const *s, char c); // NAO USANDO POR ENQUANTO

// ./assistant/skip_str.c
char	*skip_char(char *str);
char	*skip_space(char *str);

// ./assistant/concatenate.c
char    *build_path(char *str1, char *str2);

// ./commands/echo.c
// int	search_operator(char *str, char *operator) // TEMPORARIO // NAO USANDO POR ENQUANTO
int	search_operator(char **argv, char *operator); // TEMPORARIO
void	echo(char **argv);

// ./commands/cd.c
void	cd(char *command);

// ./commands/pwd.c
void	pwd(void);

// ./commands/export.c

// ./commands/unset.c

// ./commands/env.c

// ./commands/exit.c
void	free_split(char **argv);    // TEMPORARIO
void	exit_shell(char **argv, char *str);

// ./commands/exec_program.c
void    exec_program(char **argv, char **env, char *str);




// ./minishell.c
char    *tester_path(char **path, char *file);
int	compare(char *s1, char *s2);    // TEMPORARIO



#endif