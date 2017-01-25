/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/25 20:14:29 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"
/*
char	*place_tetri(t_tetri *list, char *grid)
{
	int		numy;
	int		numx;
	int		i;
	int		j;
	int		space;

	numx = 0;
	numy = 0;
	i = 0;
	j = 1;
	space = 0;
	while (grid[i] != '\0')
	{
		while (grid[i] != '\n')
		{
			while (list->coord[j] == numy) // j c'est tous les y de la liste, numy c'est le curseur qui concernera les y (un compteur juste)
			{
				if (list->coord[j - 1] == numx)// numx c'est un compteur mais que pour les x
				{
					i = i + list->coord[j - 1];//on prepare les espaces necessaires pour la piece a placer (utile si le xmin n'est pas le 1erx)
					while (grid[i] == '#' && j == 0)//si la case ou on est est un # on avance, on peut rien placer, on avance pas si on a deja place une piece
						i++;
						space++;
					if (grid[i] != '#')
						grid[i] = '#';
						
					j = j + 2;
				}
				numx++;
			}
			numy++;
		}
		if ()
			list->flag = 1;
	}
	return (grid);
}
*/
void	ft_placement(int nbpiece, t_tetri *list)
{
	t_var	*var;
	//char	*grid;
	char	**tab;

	tab = (char**)malloc(sizeof(char*) * nbpiece + 1);
	list->flag = 0;
	var = malloc(sizeof(t_var));
	/*grid*/ tab[0] = create_grid(nbpiece);
	ft_putstr(tab[0]);
	//tab[0] = grid;
	//on essaye de placer le premier tetri
	//si ca ne marche pas on revient en arriere
	//si on peut pas aller en arriere on agrandit la grid
	//et on reessaye
	get_coord(*list, var);
	list = list->next;
	//place_tetri(list, grid);
}
