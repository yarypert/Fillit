/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:02:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/23 16:01:55 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
t_tetri		get_coord(t_tetri	list, t_var var)
{
	var.j = 0;
	var.i = 0;
	var.y = 0;
	var.x = 0;
	var.xmin = 0;
	var.ymin = 0;

while (list.tetri[var.i] != '\0')
{
	while (list.tetri[var.i] != '\n')
	{
		if (list.tetri[var.i] == '#')
		{
			ft_putnbr(var.x);
			list.coord[var.j] = var.x;
			list.coord[var.j + 1] = var.y;
			var.j = var.j + 2;
		}
		var.i++;
		var.x++;
	}
	var.i++;
	var.y++;
	var.x = 0;
}

var.i = 0;
var.xmin = list.coord[var.i];
var.ymin = list.coord[var.i + 1];

while (list.coord[var.i] != '\0')
{
	if (list.coord[var.i + 2] < list.coord[var.i])
		var.xmin = list.coord[var.i + 2];
	if (list.coord[var.i + 3] < list.coord[var.i + 1])
		var.ymin = list.coord[var.i + 3];
	var.i++;
}

printf("%s%d\n", "xmin = ", var.xmin);
printf("%s%d\n", "ymin = ", var.ymin);
if (var.xmin != 0 || var.ymin != 0)
{
	ft_adjust(var.xmin, var.ymin, &list);
	return (list);
}
else
	return (list);
}

void	ft_adjust(int xmin, int ymin, t_tetri *list)
{
	list->coord[0] = list->coord[0] - xmin;
	list->coord[1] = list->coord[1] - ymin;
	list->coord[2] = list->coord[2] - xmin;
	list->coord[3] = list->coord[3] - ymin;
	list->coord[4] = list->coord[4] - xmin;
	list->coord[5] = list->coord[5] - ymin;
	list->coord[6] = list->coord[6] - xmin;
	list->coord[7] = list->coord[7] - ymin;
}

int main(void)
{
	t_tetri list;
	t_var var;

	list.tetri = ".###\n..#.\n....\n....\n";
	list = get_coord(list, var);
	printf("%s%d%s%d\n","X1 = ", list.coord[0], " et Y1 = ", list.coord[1]);
	printf("%s%d%s%d\n","X2 = ", list.coord[2], " et Y2 = ", list.coord[3]);
	printf("%s%d%s%d\n","X3 = ", list.coord[4], " et Y3 = ", list.coord[5]);
	printf("%s%d%s%d\n","X4 = ", list.coord[6], " et Y4 = ", list.coord[7]);
	return 0;
}
