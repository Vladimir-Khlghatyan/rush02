/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:32:04 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/10/16 14:32:08 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*get_next_line1(int fd)
{
	int		i;
	int		rd;
	char	c;
	char	*buffer;

	i = -1;
	rd = 1;
	buffer = (char *)malloc(sizeof(char) * 1000);
	if (!buffer)
		return (NULL);
	while (1)
	{
		rd = read(fd, &c, 1);
		buffer[++i] = c;
		if (rd <= 0)
			break ;
		if (c == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
		return (ft_free(buffer, NULL));
	if (c == '\n')
		buffer[i - 1] = '\0';
	return (buffer);
}

static char	*ft_remove_new_line_char(char *str)
{
	int		len;
	char	*new_str;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
	{
		new_str = ft_substr(str, 0, len - 1);
		free(str);
		return (new_str);
	}
	return (str);
}

char	*get_next_line2(int fd)
{
	int		i;
	int		rd;
	char	c;
	char	*buffer;

	i = -1;
	rd = 1;
	buffer = (char *)malloc(sizeof(char) * 1000);
	if (!buffer)
		return (NULL);
	while (rd)
	{
		rd = read(fd, &c, 1);
		if (rd <= 0)
			break ;
		buffer[++i] = c;
		if (c == '\n')
			break ;
	}
	if ((!buffer[i] && !rd) || rd == -1)
		return (ft_free(buffer, NULL));
	buffer[i + 1] = '\0';
	buffer = ft_remove_new_line_char(buffer);
	return (buffer);
}
