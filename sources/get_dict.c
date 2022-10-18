/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static t_dict	*ft_new_dict_node(char *key, char *val)
{
	t_dict	*node;

	node = (t_dict *)malloc(sizeof(t_dict));
	if (!node)
		return (NULL);
	node->key = key;
	node->val = val;
	node->next = NULL;
	return (node);
}

static void	ft_add_dict_node(t_dict **head, t_dict *new)
{
	t_dict	*last_node;

	last_node = *head;
	if (!*head)
		*head = new;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
}

static char	*ft_singl_space(char *str)
{
	char	**arr;
	int		i;

	arr = ft_split(str, ' ');
	free(str);
	if (!arr)
		return (NULL);
	str = ft_strjoin_free(arr[0], "", NULL, NULL);
	i = 0;
	while (arr[++i])
	{
		str = ft_strjoin_free(str, " ", str, NULL);
		str = ft_strjoin_free(str, arr[i], str, NULL);
	}
	ft_arrfree(arr);
	return (str);
}

static char	*ft_remove_carriage_return(char *buffer)
{
	char	*new_buffer;
	int		i;

	if (!buffer)
		return (NULL);
	if (buffer[ft_strlen(buffer) - 1] != '\r')
		return (buffer);
	new_buffer = (char *)malloc(sizeof(char *) * ft_strlen(buffer));
	if (!new_buffer)
		return (ft_free(buffer, NULL));
	i = -1;
	while (buffer[++i])
		new_buffer[i] = buffer[i];
	new_buffer[i - 1] = '\0';
	free(buffer);
	return (new_buffer);
}

t_dict	*ft_create_dict(char *path, char *buffer)
{
	int		fd;
	char	**kv;
	t_dict	*head;
	t_dict	*node;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	head = NULL;
	while (1)
	{
		buffer = ft_free(buffer, NULL);
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		if (buffer[0] == '\0')
			continue ;
		buffer = ft_remove_carriage_return(buffer);
		kv = ft_split(buffer, ':');
		node = ft_new_dict_node(ft_singl_space(kv[0]), ft_singl_space(kv[1]));
		ft_add_dict_node(&head, node);
		free(kv);
	}
	return (head);
}
