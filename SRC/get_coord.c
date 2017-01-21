/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:02:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/18 20:55:58 by yarypert         ###   ########.fr       */
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
		ft_adjust(var.xmin, &list);
		return (list);
	}
}

void	ft_adjust(int xmin, t_tetri *list)
{
	if (xmin < list->coord[0])
	{
		list->coord[0] = list->coord[0] - xmin;
		list->coord[2] = list->coord[2] - xmin;
		list->coord[4] = list->coord[4] - xmin;
		list->coord[6] = list->coord[6] - xmin;
	}
}
