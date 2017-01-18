/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zizi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:02:02 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/18 16:00:33 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		find_x_y(t_tetri	list)
{
	char	tabxy[4];
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
					x++;
			}
			i++;
		}
		i++;
		y++;
		x = 0;
	}
	return (list);
}
