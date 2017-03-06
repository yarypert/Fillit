/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:21:44 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/01 22:32:10 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_char(char *str)
{
	int i;

	i = 0;

	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (1);
	while (i < 20)
	{
		if (str[i] != 46 && str[i] != 35 && str[i] != 10)
			return (1);
		i++;
	}
	return (0);
}

int		check_links(char *str)
{
	int i;
	int count_links;

	count_links = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 5] == '#' && i < 15)
				count_links++;
			if (str[i - 5] == '#' && i > 4)
				count_links++;
			if (str[i + 1] == '#' && i < 19)
				count_links++;
			if (str[i - 1] == '#' && i > 0)
				count_links++;
		}
		i++;
	}
	return ((count_links == 6 || count_links == 8) ? 0 : 1);
}

int		check_lines(char *str)
{
	int		count_bn;
	int		count_char;
	int		count_hashtags;
	int		i;

	i = 0;
	count_hashtags = 0;
	count_char = 0;
	count_bn = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			count_hashtags++;
		if (str[i] != '\n')
			count_char++;
		if (str[i] == '\n')
			count_bn++;
		i++;
	}
	return ((count_hashtags == 4 && count_char == 16 && count_bn == 4) ? 0 : 1);
}

int		check_final(char **str,int piece_nb)
{
	int i;
	int a;
	int b;
	int c;

	i = 0;
	while (i < piece_nb)
	{
		a = check_char(str[i]);
		b = check_links(str[i]);
		c = check_lines(str[i]);

		if (a != 0 || b != 0 || c != 0)
			return (1);
		i++;
	}
	return (0);
}
