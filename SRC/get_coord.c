/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:02:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/18 16:26:13 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		get_coord(t_tetri	list)
{
	int		i;
	int		j;
	int		x;
	int		y;

	j = 0;
	i = 0;
	y = 0;
	x = 0;
	while (list.tetri[i] != '\0')
	{
		while (list.tetri[i] != '\n')
		{
			if (list.tetri[i] == '#')
			{
				list.coord[j] = x;
				list.coord[j + 1] = y;
			}
			i++;
			x++;
		}
		i++;
		y++;
		x = 0;
	}
	return (list);
}
