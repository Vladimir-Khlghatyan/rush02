/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_num	*ft_last_node(t_num *head)
{
	t_num	*last_node;

	last_node = head;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

void	ft_num_del_node(t_num **head, t_num **node)
{
	t_num	*remember;

	if (*node == NULL)
		return ;
	if (*node == *head)
		*head = (*head)->next;
	remember = *node;
	if ((*node)->next != NULL)
		(*node)->next->prev = (*node)->prev;
	if ((*node)->prev != NULL)
		(*node)->prev->next = (*node)->next;
	*node = (*node)->prev;
	free(remember->d1);
	free(remember->d2);
	free(remember->d3);
	free(remember->d4);
	free(remember);
}

t_num	*ft_check_if_value_is_in_dick(t_dict *dict, t_num *num)
{
	t_num	*tmp;

	tmp = num;
	while (tmp)
	{
		if (!ft_dictval(dict, tmp->d4))
		{
			ft_free_lists(NULL, num);
			ft_putstr("Dict ");
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (num);
}
