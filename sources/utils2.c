/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:43:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/09/25 14:43:23 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		s_len;
	char	*substr;

	s_len = ft_strlen(s);
	if (s_len < start)
	{
		substr = malloc(sizeof(*s) * 1);
		substr[0] = '\0';
		return (substr);
	}
	if (s_len - start >= len)
		substr = malloc(sizeof(*s) * (len + 1));
	else
		substr = malloc(sizeof(*s) * (s_len - start + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin_free(char *s1, char *s2, char *free1, char *free2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	ft_free(free1, free2);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	if (c == '\0')
		return (str + i);
	i = 0;
	while (str[i])
	{
		if (str[i] != (char) c)
			i++;
		else
			return (str + i);
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		++i;
	}
	return (0);
}

int	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
