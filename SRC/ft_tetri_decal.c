/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_decal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:09:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/03/08 13:16:52 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_tetri_decal(char *tetri_bef)
{
	t_decal		td;

	td.tetri_next = NULL;
	tetri_bef = move_tetri_char(tetri_bef);
	td.tetri_next = (char*)malloc(sizeof(char) * find_len(tetri_bef, &td) + 1);
	td.i = 0;
	td.j = 0;
	td.taille = 0;
	td.flag = 0;
	td.count = 0;
	ft_tetri_decal_2(tetri_bef, &td);
	return (td.tetri_next);
}

void	is_diese(t_decal *td, char *tetri_before)
{
	td->tetri_next[td->j] = tetri_before[td->i];
	td->j++;
	td->flag = 1;
	td->count++;
}

void	flag_zero(t_decal *td)
{
	td->tetri_next[td->j] = ' ';
	td->j++;
}

void	ft_tetri_decal_2(char *tetri_before, t_decal *td)
{
	while (td->count <= 3)
	{
		while (tetri_before[td->i] != '\n')
		{
			if (tetri_before[td->i] == '#')
				is_diese(td, tetri_before);
			if (tetri_before[td->i] == '.')
				if (td->flag == 0)
					flag_zero(td);
			td->i++;
		}
		if (td->flag == 1)
		{
			td->flag = 0;
			td->tetri_next[td->j] = tetri_before[td->i];
			td->j++;
		}
		td->i++;
	}
	td->tetri_next[td->j] = '\0';
}
