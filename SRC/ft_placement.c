/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/25 15:11:04 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
char	*place_tetri(t_tetri *list, char *grid)
{
	char *null;
	return(null);
}

int		check_place(t_tetri *list, char *grid)
{
	int null;
	return(null);
}
*/
void	ft_placement(int nbpiece, t_tetri list)
{
	t_var	structure;
	char	*grid;
	int		count;

	count = 0;
	
	grid = create_grid(nbpiece);
	//on essaye de placer le premier tetri
	//si ca ne marche pas on revient en arriere
	//si on peut pas aller en arriere on agrandit la grid
	//et on reessaye
	while (count != nbpiece)
	{
		get_coord(list, structure);
		if (check_place(list, grid) == 1)
			count++;
			place_tetri(list, grid);
	}

}
