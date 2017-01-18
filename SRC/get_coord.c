/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:02:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/18 18:27:33 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
t_tetri		get_coord(t_tetri	list, t_var var)
{
	var.j = 0;
	var.i = 0;
	var.y = 0;
	var.x = 0;

	while (list.tetri[var.i] != '\0')
	{
		while (list.tetri[var.i] != '\n')
		{
			if (list.tetri[var.i] == '#')
			{
				list.coord[var.j] = var.x;
				list.coord[var.j + 1] = var.y;
				if (var.xmin == 0 || var.xmin > var.x)
					var.xmin = var.x;
				var.j++;
			}
			var.i++;
			var.x++;
		}
		var.i++;
		var.y++;
		var.x = 0;
	}
	var.j = 0;
	if (var.xmin == list.coord[var.j])
		return (list);
	else 
	{
		list.coord = (ft_adjust(var.xmin, list.coord));
		return (list);
	}
}

t_tetri		ft_adjust(int xmin, int *list, t_tetri wesh)
{
	if (xmin < list[0])
		list[0] = list[0] - xmin;
		list[2] = list[2] - xmin;
		list[4] = list[4] - xmin;
		list[6] = list[6] - xmin;
	wesh.coord = list;
	return (wesh);
}