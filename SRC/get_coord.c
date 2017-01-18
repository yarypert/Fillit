/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zizi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:02:02 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/18 15:22:16 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		find_x_y(t_tetri	list)
{
	char	tabxy[4];
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = 0;
	while (list.tetri[i] != '\0')
	{
		while (pieces != 4)
			while (list.tetri[i] != '\n')
			{
				if (list.tetri[i] == '#')
				{
					list.x1 = x;
					list.y1 = y;
					x++;
				}
				i++;
			}
			i++;
			y++;
			x = 0;
	}
}
