/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/17 10:46:30 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

void	ft_placement(int nbpiece, char ***tab_tetri)
{
	t_var	*var;
	char	*grid = NULL;
	int		i;
	t_var	*list;

	create_grid(nbpiece);
	i = 0;
	while (**tab_tetri[i] != NULL)
	{
		move_tetri(tab_tetri[i]);
		place_tetri(list, **tab_tetri[i], grid);
		if (list->flag == -1)
		{
			if (i == 0)
				//fonction pour agrandir la map de 1
			if (i != 0)
				//reculer d'une piece
		}
		if (list->flag == 1)
		{
			i++;
		}
	}
}
