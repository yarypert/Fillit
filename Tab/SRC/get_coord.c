/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 08:18:08 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/04 14:33:39 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

void	ft_print_int_tab(int	**coord, int	piece_nb)
{
	int i;
	int j;

	i = 0;


	while (i < piece_nb - 1)
	{
		j = 0;
		while (j < 8)
		{
			ft_putstr("X = \n");
			ft_putnbr(coord[i][j]);
			ft_putstr("\n");
			j++;
			ft_putstr("Y = \n");
			ft_putnbr(coord[i][j]);
			ft_putstr("\n");
			j++;
		}
		i++;
	}
}

void get_coord(char ***tetri, int piece_nb)
{
	int i;
	int j;
	int k;
	int l;
	int		**coord;

	coord = (int **)malloc(sizeof(int *) * piece_nb);
	i = 0;
	while (i < 8)
	{
		coord[i] = (int *)malloc(sizeof(int) * 8);
		i++;
	}

	
	i = 0;
	while (i < piece_nb)
	{
		l = 0;
		ft_putnbr(i + 1);
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 5)
			{
				ft_putchar(tetri[i][j][k]);
				if(tetri[i][j][k] == '#')
				{
					coord[i][l] = k;
					coord[i][l + 1] = j;
					l = l + 2;
				}
				k++;
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_print_int_tab(coord,piece_nb);
	ft_putchar('f');
}
