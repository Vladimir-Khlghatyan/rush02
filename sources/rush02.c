/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:32:04 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/10/16 14:32:08 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static char	*ft_num_check(char *str)
{
	int		i;
	int		start;

	if (!str)
		return (NULL);
	i = 0;
	if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (NULL);
	while (str[i] && str[i] == '0')
		i++;
	if (!str[i] || str[i] < '0' || str[i] > '9')
		return (ft_strdup("0"));
	start = i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (ft_substr(str, start, i - start));
}

int	main(int ac, char **av)
{
	t_dict	*dict;
	t_num	*num;
	char	*buffer;

	if (ac > 3)
		return (ft_putstr("Too many arguments\n"));
	else if (ac == 3)
		dict = ft_create_dict(av[ac - 2], NULL);
	else if (ac < 3)
		dict = ft_create_dict("./dictionary/numbers.dict", NULL);
	if (!dict)
		return (ft_putstr("Dict Error\n"));
	if (ac == 2 || ac == 3)
		num = ft_create_num(dict, ft_num_check(av[ac - 1]), -1);
	else if (ac == 1)
	{
		buffer = get_next_line(0);
		num = ft_create_num(dict, ft_num_check(buffer), -1);
		ft_free(buffer, NULL);
	}
	if (!num)
		return (ft_putstr("Error\n"));
	ft_print(dict, num);
	ft_free_lists(dict, num);
	return (0);
}
