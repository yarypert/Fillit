/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:29:42 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/13 19:20:03 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char	**move_tetri(char **tab_tetri)
{
	int		xmin;
	int		ymin;
	int		i;
	int		j;

	xmin = find_x_min(tab_tetri);
	ymin = find_y_min(tab_tetri);
	i = 0;
	j = 0;
	while (tab_tetri[i][j])
	{
		while (tab_tetri[i][j] != '\n')
		{
			if (tab_tetri[i][j] == '#')
			{
				tab_tetri[i][j] = '.';
				tab_tetri[i - ymin][j - xmin] = '#';
			}
			j++;
		}
		i++;
	}
	return (tab_tetri);
}

int		find_x_min(char		**tab_tetri)
{
	int		i;
	int		j;
	int		xmin;
	int		count;

	xmin = 0;
	i = 0;
	count = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 4)
		{
			if (tab_tetri[i][j] == '#')
			{
				if (count == 0 || j <= xmin)
					xmin = j;
				count++;
			}
			j++;
		}
		i++;
	}
	printf("%s%d\n", "le xmin est: ", xmin);
	return (xmin);
}

int		find_y_min(char		**tab_tetri)
{
	int		i;
	int		j;
	int		ymin;
	int		count;

	ymin = 0;
	i = 0;
	count = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 4)
		{
			if (tab_tetri[i][j] == '#')
			{
				if (count == 0 || i <= ymin)
					ymin = i;
				count++;
			}
			j++;
		}
		i++;
	}
	printf("%s%d\n", "le ymin est: ", ymin);
	return (ymin);
}






int main()
{
	char	**test;
	test[0] = "....\n";
	test[1] = "...#\n";
	test[2] = "...#\n";
	test[3] = "..##\n";

	move_tetri(test);
	return 0;
}
