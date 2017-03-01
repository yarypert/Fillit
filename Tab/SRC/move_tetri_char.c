/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:29:42 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/01 14:01:53 by jorobin          ###   ########.fr       */
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
	int		xmin;
	int		ymin;
	int		i;
	int		j;

	xmin = find_x_min_char(tab_tetri);
	ymin = find_y_min_char(tab_tetri);
	i = 0;
	j = 0;
	tab_tetri = xmin_diff_zero(tab_tetri, i, xmin);
	tab_tetri = ymin_diff_zero(tab_tetri, i, ymin);

	return (tab_tetri);
}

int		find_x_min_char(char	*tab_tetri)
{
	int		i;
	int		j;
	int		xmin;
	int		count;

	xmin = 0;
	i = 0;
	count = 0;
	j = 0;
	while (tab_tetri[i] != '\0')
	{
		while (tab_tetri[i] != '\n')
		{
			if (tab_tetri[i] == '#')
			{
				if (count == 0 || j <= xmin)
					xmin = j;
				count++;
			}
			j++;
			i++;
		}
		j = 0;
		i++;
	}
	return (xmin);
}

int		find_y_min_char(char	*tab_tetri)
{
	int		i;
	int		j;
	int		ymin;
	int		count;

	ymin = 0;
	i = 0;
	count = 0;
	j = 0;
	while (tab_tetri[i] != '\0')
	{
		while (tab_tetri[i] != '\n')
		{
			if (tab_tetri[i] == '#')
			{
				if (count == 0 || j <= ymin)
					ymin = j;
				count++;
			}
			i++;
		}
		j++;
		i++;
	}
	return (ymin);
}

