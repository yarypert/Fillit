/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_decal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:09:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/03/07 15:26:03 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_tetri_decal(char *tetri_before)
{
	t_decal		td;

	td.i = 0;
	td.j = 0;
	td.taille = 0;
	td.flag = 0;
	td.count = 0;
	td.tetri_next = NULL;
	tetri_before = move_tetri_char(tetri_before);
	td.tetri_next = (char*)malloc(sizeof(char) * find_len(tetri_before) + 1);

	while (td.count <= 3)
	{
		while (tetri_before[td.i] != '\n')
		{
			if (tetri_before[td.i] == '#')
			{
				td.tetri_next[td.j] = tetri_before[td.i];
				td.j++;
				td.flag = 1;
				td.count++;
			}
			if (tetri_before[td.i] == '.')
			{
				if (td.flag == 0)
				{
					td.tetri_next[td.j] = ' ';
					td.j++;
				}
			}
			td.i++;
		}
		if (td.flag == 1)
		{
			td.flag = 0;
			td.tetri_next[td.j] = tetri_before[td.i];
			td.j++;
		}
		td.i++;
	}
	td.tetri_next[td.j] = '\0';
	return(td.tetri_next);
}

int		find_len(char *str)
{
	int		i;
	int		flag;
	int		count;
	int		taille;

	i = 0;
	flag = 0;
	count = 0;
	taille = 0;
	while (count < 4)
	{
		while (str[i] != '\n')
		{
			if (str[i] == '#')
			{
				taille++;
				flag = 1;
				count++;
			}
			if (str[i] == '.')
			{
				if (flag == 0)
					taille++;
			}
			i++;
		}
		if (flag == 1)
		{
			taille++;
			flag = 0;
		}
		i++;
	}
	return(taille);
}
