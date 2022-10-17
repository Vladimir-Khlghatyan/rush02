/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (NULL);
}

char	**ft_arrfree(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
		if (arr[i])
			arr[i] = ft_free(arr[i], NULL);
	free(arr);
	arr = NULL;
	return (NULL);
}

static int	wordcount(char *s, char c)
{
	int	q;
	int	i;

	q = 1;
	if (s[0] == c)
		q = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			q++;
		i++;
	}
	return (q);
}

static int	wordlen(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] && s[i++] != c)
		len++;
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		wc;
	int		i[2];

	if (!s)
		return (NULL);
	i[0] = -1;
	wc = wordcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	while (++i[0] < wc)
	{
		tab[i[0]] = (char *)malloc(sizeof(char) * (wordlen(s, c) + 1));
		if (!tab[i[0]])
			return (ft_arrfree(tab));
		while (*s == c)
			s++;
		i[1] = 0;
		while (*s != c && *s)
			tab[i[0]][i[1]++] = *s++;
		tab[i[0]][i[1]] = '\0';
	}
	tab[i[0]] = NULL;
	return (tab);
}
