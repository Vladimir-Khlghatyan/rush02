/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_num	*ft_last_node(t_num *head);
void	ft_num_del_node(t_num **head, t_num **node);
t_num	*ft_check_if_value_is_in_dick(t_dict *dict, t_num *num);

static t_num	*ft_new_num_node(char *d3, char *d4)
{
	t_num	*node;

	node = (t_num *)malloc(sizeof(t_num));
	if (!node)
		return (NULL);
	node->d1 = ft_strdup("0");
	node->d2 = ft_strdup("0");
	node->d3 = d3;
	node->d4 = d4;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	ft_add_num_node(t_num **head, t_num *new)
{
	t_num	*last_node;

	last_node = *head;
	if (!*head)
		*head = new;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
		new->prev = last_node;
	}
}

static char	*ft_replace_str(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	str[0] = '1';
	i = 0;
	while (str[++i])
		str[i] = '0';
	return (str);
}

static void	ft_set_list(t_num **head)
{
	t_num	*lt;

	lt = ft_last_node(*head);
	while (lt)
	{
		if ((ft_strlen(lt->d4) - 1) % 3 != 0)
			ft_num_del_node(head, &lt);
		else if (lt)
		{
			if (lt->prev && lt->prev->prev)
				lt->d1 = ft_strreplace(lt->d1, lt->prev->prev->d3);
			if (lt->prev && lt->prev->d3[0] == '1')
			{
				lt->d2 = ft_strjoin_free(lt->prev->d3, lt->d3, lt->d2, NULL);
				lt->d3 = ft_strreplace(lt->d3, "0");
			}
			else if (lt->prev && lt->prev->d3[0] != '1')
				lt->d2 = ft_strjoin_free(lt->prev->d3, "0", lt->d2, NULL);
			lt = lt->prev;
		}
	}
}

t_num	*ft_create_num(t_dict *dict, char *str, int i)
{
	t_num	*head;
	t_num	*node;
	char	*key;
	char	*val;

	if (!str)
	{
		ft_free_lists(dict, NULL);
		return (NULL);
	}
	head = NULL;
	while (str[++i])
	{
		val = ft_substr(str + i, 0, ft_strlen(str + i));
		key = ft_make_num_key(val);
		node = ft_new_num_node(key, ft_replace_str(val));
		ft_add_num_node(&head, node);
	}
	ft_set_list(&head);
	head = ft_check_if_value_is_in_dick(dict, head);
	if (!head)
		ft_free_lists(dict, head);
	free(str);
	return (head);
}
