/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:29:42 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/16 16:12:10 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

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

char	**move_tetri(char **tab_tetri)
{
	int		xmin;
	int		ymin;
	int		i;
	int		j;

	ft_putendl("fonction move_tetri avant les find");
	xmin = find_x_min(tab_tetri);
	ymin = find_y_min(tab_tetri);
	i = 0;
	j = 0;

	ft_putdoubletab(tab_tetri);
	ft_putendl("fonction move_tetri");

	if (xmin != 0)
	{
		ft_putendl("premier if");
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
	ft_putdoubletab(tab_tetri);
	}
	i = 0;
	if (ymin != 0)
	{
		ft_putendl("second if");
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
	}
	ft_putdoubletab(tab_tetri);
	return (tab_tetri);
}

int		find_x_min(char		**tab_tetri)
{
	int		i;
	int		j;
	int		xmin;
	int		count;

	ft_putendl("fonction x_min");
	xmin = 0;
	i = 0;
	count = 0;
	while (tab_tetri[i] != NULL)
	{
		ft_putendl("while y");
		j = 0;
		while (j < 4)
		{
			ft_putchar('\n');
			ft_putchar(tab_tetri[i][j]);
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
	ft_putendl("fin de fonction x_min");
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
	printf("%s%d\n", "le ymin est: ", ymin);
	return (ymin);
}

int main()
{
	char	*test;
	char **tmp;

	tmp = NULL;
	test = (char *)malloc(sizeof(char) * 24 + 1);
	ft_putstr("test dans le main\n");
	test = "....\ni...#\ni...#\ni..##\ni\0";
	ft_putendl("split dans le main");
	tmp = ft_strsplit(test, 'i');
	if (tmp)
	{
		ft_putendl("split reussi");
	}
	move_tetri(tmp);
	return 0;
}
