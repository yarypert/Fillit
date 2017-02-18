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

int		place_tetri(char **tab_tetri, char *grid, int n, t_var *var)
{
	int i;
	int j;
	char	**place_grid[n];

	*place_grid[j] = grid;
	i = 0;
	while (place_grid[i])
	{
		while (grid[i] == '#' || place_grid[i] == 'x')
		{
			if (grid[i] == '#')
				place_grid[i] = 'x';
			i++;
		}
		if (ft_check(grid, tab_tetri, i) == 0)
			ft_place(grid, tab_tetri, i);//on place le tetri
		if (ft_check(grid, tab_tetri, i) == 1)//pas bon placement
			place_grid[i] = 'x';
		if (ft_check(grid, tab_tetri, i) == -1)//la map des x a que des x
		{
			clr_place_grid(place_grid[j]);//clean la map_x
			if (!(j - 1))//si ya pas de piece avant
				return(1);//agrandir la map
			j--; //map_x d'avant
			return(-1);//passer a la piece d'avant
		}
	}
	return(0);
}



void	ft_placement(int nbpiece, char ***tab_tetri)
{
	t_var	*var;
	char	*grid = NULL;
	int		i;

	create_grid(nbpiece);
	i = 0;
	while (tab_tetri[i] != NULL)
	{
		move_tetri(tab_tetri[i]);
		while (place_tetri((char**)tab_tetri[i], grid, i, var) != 0)//tant qu'on a pas bien place une piece
		{
			if (place_tetri((char**)tab_tetri[i], grid, i, var) == 1)//plus de possibilite d'aller une piece en arriere
				grid_1_up(i);//agrandir la map de 1
			if (place_tetri((char**)tab_tetri[i], grid, i, var) == -1)
				i--;
		}
		i++;
	}
}
