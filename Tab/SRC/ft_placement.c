/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/17 11:01:13 by jorobin          ###   ########.fr       */
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
		while (list->flag != 0)//tant qu'on a pas bien place une piece
		{
			if (list->flag == 1)//plus de possibilite d'aller une piece en arriere
				//>>>>> agrandir la map de 1
				grid_1_up(i);
			if (list->flag == -1)
				//revenir a la piece precedente si pas d'autre placement
				i--;
			if (list->flag == 2)
				//tester un autre placement
		}
		i++;
	}
}
