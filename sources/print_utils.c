/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_dictval(t_dict *dict, char *str)
{
	t_dict	*tmp;

	tmp = dict;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, str))
			return (tmp->val);
		tmp = tmp ->next;
	}
	return (NULL);
}

static	void	ft_pr(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		write(1, s1, ft_strlen(s1));
	if (s1 && (s2 || s3))
		write(1, " and ", 5);
	else if (s1 && !s2 && !s3 && s4)
		write(1, " ", 1);
	if (s2)
		write(1, s2, ft_strlen(s2));
	if (s2 && s3)
		write(1, "-", 1);
	else if (s2 && !s3)
		write(1, " ", 1);
	if (s3)
		write(1, s3, ft_strlen(s3));
	if (s3 && s4)
		write(1, " ", 1);
	if (s4)
		write(1, s4, ft_strlen(s4));
}

static void	ft_set_null_str(char **s1, char **s2, char **s3, char **s4)
{
	*s1 = NULL;
	*s2 = NULL;
	*s3 = NULL;
	*s4 = NULL;
}

void	ft_print_last_char(t_num *num)
{
	t_num	*tmp;

	if (!num->next)
	{
		write(1, "\n", 1);
		return ;
	}
	if (num->d1[0] == '0' && num->d2[0] == '0' && num->d3[0] == '0')
		return ;
	tmp = num->next;
	while (tmp)
	{
		if (tmp->d1[0] != '0' || tmp->d2[0] != '0' || tmp->d3[0] != '0')
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	write(1, ", ", 2);
}

void	ft_print_util(t_dict *dict, t_num *num)
{
	char	*d1;
	char	*d2;
	char	*d3;
	char	*d4;

	while (num)
	{
		ft_set_null_str(&d1, &d2, &d3, &d4);
		if (num->d1[0] != '0')
		{
			d1 = ft_dictval(dict, num->d1);
			d1 = ft_strjoin_free(d1, " ", NULL, NULL);
			d1 = ft_strjoin_free(d1, ft_dictval(dict, "100"), d1, NULL);
		}
		if (num->d2[0] != '0')
			d2 = ft_dictval(dict, num->d2);
		if (num->d3[0] != '0')
			d3 = ft_dictval(dict, num->d3);
		if ((d1 || d2 || d3) && num->d4[0] != '0' && num->next)
			d4 = ft_dictval(dict, num->d4);
		ft_pr(d1, d2, d3, d4);
		ft_free(d1, NULL);
		ft_print_last_char(num);
		num = num->next;
	}
}
