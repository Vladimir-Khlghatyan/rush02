/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:32:04 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/10/16 14:32:08 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct s_dict
{
	char			*key;
	char			*val;
	struct s_dict	*next;
}				t_dict;

typedef struct s_num
{
	char			*d1;
	char			*d2;
	char			*d3;
	char			*d4;
	struct s_num	*prev;
	struct s_num	*next;
}				t_num;

char	*get_next_line(char *message, int fd);
char	*ft_free(char *str1, char *str2);
char	**ft_arrfree(char **arr);
char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin_free(char *s1, char *s2, char *free1, char *free2);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_make_num_key(char *str);
void	ft_free_lists(t_dict *dict, t_num *num);
char	*ft_strreplace(char *str, char *replace);
t_dict	*ft_create_dict(char *path, char *buffer);
t_num	*ft_create_num(t_dict *dict, char *str, int i);
char	*ft_dictval(t_dict *dict, char *str);
void	ft_print(t_dict *dict, t_num *num);

#endif
