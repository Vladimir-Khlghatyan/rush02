/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_util(t_dict *dict, t_num *num);

void	ft_print(t_dict *dict, t_num *num)
{
	if (!num->next && num->d1[0] == '0' && \
		num->d2[0] == '0' && num->d3[0] == '0')
	{
		ft_putstr(ft_dictval(dict, num->d3));
		ft_putstr("\n");
	}
	else
		ft_print_util(dict, num);
}
