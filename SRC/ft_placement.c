/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/25 14:48:30 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*place_tetri(t_tetri *list, char *grid)
{
}

int		check_place(t_tetri *list, char *grid)
{
}

void	ft_placement(int nbpiece, t_tetri *list)
{
	t_var	*var;
	char	*grid;
	int		count;
	
	grid = create_grid(nbpiece);
	//on essaye de placer le premier tetri
	//si ca ne marche pas on revient en arriere
	//si on peut pas aller en arriere on agrandit la grid
	//et on reessaye
	while (count != nbpiece)
	{
		get_coord(*list, *var);
		if (check_place(list, grid) = 1)
			count++;
			place_tetri(list, grid);
	}

}
