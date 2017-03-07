/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:43:04 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/07 14:49:01 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ymin_diff_zero(char *tetri, int i, int ymin)
{
	if (ymin != 0)
	{
		while (tetri[i] != '\0')
		{
			if (tetri[i] == '#')
			{
				tetri[i] = '.';
				tetri[i - (5 * ymin)] = '#';
			}
			i++;
		}
	}
	return (tetri);
}

char	*xmin_diff_zero(char *tetri, int i, int xmin)
{
	if (xmin != 0)
	{
		while (tetri[i] != '\0')
		{
			if (tetri[i] == '#')
			{
				tetri[i] = '.';
				tetri[i - xmin] = '#';
			}
			i++;
		}
	}
	return (tetri);
}

char	*move_tetri_char(char *tab_tetri)
{
	t_xymin	var;

	var.xmin = find_x_min_char(tab_tetri);
	var.ymin = find_y_min_char(tab_tetri);
	var.i = 0;
	var.j = 0;
	tab_tetri = xmin_diff_zero(tab_tetri, var.i, var.xmin);
	tab_tetri = ymin_diff_zero(tab_tetri, var.i, var.ymin);
	return (tab_tetri);
}

int		find_x_min_char(char *tab_tetri)
{
	t_xymin	var;

	var.xmin = 0;
	var.i = 0;
	var.count = 0;
	var.j = 0;
	while (tab_tetri[var.i] != '\0')
	{
		while (tab_tetri[var.i] != '\n')
		{
			if (tab_tetri[var.i] == '#')
			{
				if (var.count == 0 || var.j <= var.xmin)
					var.xmin = var.j;
				var.count++;
			}
			var.j++;
			var.i++;
		}
		var.j = 0;
		var.i++;
	}
	return (var.xmin);
}

int		find_y_min_char(char *tab_tetri)
{
	t_xymin	var;

	var.ymin = 0;
	var.i = 0;
	var.count = 0;
	var.j = 0;
	while (tab_tetri[var.i] != '\0')
	{
		while (tab_tetri[var.i] != '\n')
		{
			if (tab_tetri[var.i] == '#')
			{
				if (var.count == 0 || var.j <= var.ymin)
					var.ymin = var.j;
				var.count++;
			}
			var.i++;
		}
		var.j++;
		var.i++;
	}
	return (var.ymin);
}
