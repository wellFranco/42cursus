/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:27:08 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/23 16:32:39 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] != '\0' && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	j;

	if (NULL == list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			if (list->buf[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->buf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
