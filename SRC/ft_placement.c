/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/30 14:31:26 by yarypert         ###   ########.fr       */
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
				numx++;}
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
	char	*grid = NULL;
	char	**tab;
	int		i;

	tab = (char**)malloc(sizeof(char*) * nbpiece + 1);
	list->flag = 0;
	var = malloc(sizeof(t_var));
	tab[0] = create_grid(nbpiece);
	tab[0] = grid;
	i = 0;
	while (tab[i] != NULL)
	{
		get_coord(*list, var);
		//place_tetri(list, tab[i]);
		if (list->flag == -1)
		{
			if (i == 0)
				//fonction pour agrandir la map de 1
			if (i != 0)
				tab[i] = tab[i - 1];
		}
		if (list->flag == 1)
		{
			list = list->next;
			i++;
		}
	}
	//on cree un tableau qui va contenir chaque etapes de remplissage de la map, on va donc modifier chaque case de ce tableau a chaque placement de piece
	//tab++ si le placement est correct, tab[i] = tab[i - 1], on place la piece actuelle
	//si le placement est incorrect, on essaye autre part, si plus de possibilite on clear la tab et tab --,c'est donc placement incorrect pour celui d'avant,
	//
}
