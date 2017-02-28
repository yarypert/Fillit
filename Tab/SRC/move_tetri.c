/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:29:42 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/25 14:56:26 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"
/*
void	ft_putdoubletab(char **tab_tetri)
{
	int t1 = 0;
	int t2 = 0;
	while (tab_tetri[t1] != NULL)
	{
		while (tab_tetri[t1][t2] != '\n')
		{
			ft_putchar(tab_tetri[t1][t2]);
			t2++;
		}
			ft_putchar(tab_tetri[t1][t2]);
		t2 = 0;
		t1++;
	}
}
*/
char	**ymin_diff_zero(char **tab_tetri, int i, int j, int ymin)
{
	if (ymin != 0)
	{
		while (tab_tetri[i] != NULL)
		{
			while (tab_tetri[i][j] != '\n')
			{
				if (tab_tetri[i][j] == '#')
				{
					tab_tetri[i][j] = '.';
					tab_tetri[i - ymin][j] = '#';
				}
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
	}
	return (tab_tetri);
}


char	**xmin_diff_zero(char **tab_tetri, int i, int j, int xmin)
{

if (xmin != 0)
	{
		while (tab_tetri[i] != NULL)
		{
			while (tab_tetri[i][j] != '\n')
			{
				if (tab_tetri[i][j] == '#')
				{
					tab_tetri[i][j] = '.';
					tab_tetri[i][j - xmin] = '#';
				}
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
	}
	return (tab_tetri);
}



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
	tab_tetri = xmin_diff_zero(tab_tetri, i, j, xmin);
	tab_tetri = ymin_diff_zero(tab_tetri, i, j, ymin);

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
	while (tab_tetri[i] != NULL)
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
	while (tab_tetri[i] != NULL)
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
	return (ymin);
}
/*
int main()
{
	char	*test;
	char **tmp;

	tmp = NULL;
	test = (char *)malloc(sizeof(char) * 24 + 1);
	test = "....\ni....\ni.##.\ni....\ni\0";
	tmp = ft_strsplit(test, 'i');
	if (tmp)
	{
		ft_putendl("split reussi");
	}
	move_tetri(tmp);
	return 0;
}
*/
