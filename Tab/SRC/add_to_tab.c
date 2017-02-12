/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/04 18:11:06 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char	**str_to_tab(char *str)
{
	char	**tetri;
	int i;

	i = 0;
	tetri = ft_strsplit(str, '\n');

	while(i < 4)
	{
		tetri[i] = ft_strjoin(tetri[i],"\n");
		i++;
	}
	return (tetri);
}

void	print_tab(char ***tab, int piece_nb)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < piece_nb)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 5)
			{
				ft_putchar(tab[i][j][k]);
				k++;
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
