/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	if (!src)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_make_num_key(char *str)
{
	if (!str)
		return (NULL);
	return (ft_substr(str, 0, 1));
}

void	ft_free_lists(t_dict *dict, t_num *num)
{
	t_dict	*dict_tmp;
	t_num	*num_tmp;

	while (dict)
	{
		free(dict->key);
		free(dict->val);
		dict_tmp = dict->next;
		free(dict);
		dict = dict_tmp;
	}
	while (num)
	{
		free(num->d1);
		free(num->d2);
		free(num->d3);
		free(num->d4);
		num_tmp = num->next;
		free(num);
		num = num_tmp;
	}
}

char	*ft_strreplace(char *str, char *replace)
{
	if (str)
		free(str);
	return (ft_strdup(replace));
}
