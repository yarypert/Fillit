/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/19 13:18:49 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char	*clr_place_grid(char *grid)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		while (grid[i] != '\n')
		{
			grid[i] = '.';
		}
		i++;
	}
	return(grid);
}

char	*ft_place(char *grid, char **tab_tetri, int place)
{
	int		i;
	int		j;
	int		k;
/*
	i = place;
	j = 0;
	k = 0;
	while (grid[i] != '\0')
	{
		while (k != 4)
		{
			if (grid[i] == '.')
			{
				while (*tab_tetri[j] == '.')
					j++;
				grid[i] = *tab_tetri[j];
				i++;
				j++;
				k++;
			}
			if (grid[i] == '\n')
				i++;
		}
	}*/
	return(grid);
}

int		ft_check(char *grid, char **tab_tetri, int place)
{//fonction check si la place "int place" est valide
//c'est a dire si on peut placer le tetri **tab_tetri a cet endroit
//si on ne peut pas on renvoit 1
//si on peut on renvoit 0

	int i;
	int j;
	int k;

	i = place;
	j = 0;
	k = 0;
	while (grid[i] != '\0')
	{
		while (k < 4 || *tab_tetri[j])
		{
			if (grid[i] == '.')
			{
				while (*tab_tetri[j] == '.')
					j++;
				grid[i] = *tab_tetri[j];
				if (k != 0)//si une partie de piece est deja placee
				{
					//regarder si ca forme un motif de tetri valide
					if (grid[i - 1] != '#' || grid[i + 1] != '#' || grid[i + 5] != '#')
						return(1);
				}
				k++;
				i++;
			}
			if (grid[i] == '\n')
				if (*tab_tetri[j + 1] != '.' || *tab_tetri[j + 1] != '\n')
					return(1);
				i++;
		}
		return(0);
	}
	return(1);
}

int		place_tetri(char **tab_tetri, char *grid, int n)
{
	int i;
	int j;
	char	**place_grid;

	place_grid = (char**)malloc(sizeof(char*) * n + 1);
	place_grid[j] = grid;
	i = 0;
	while (place_grid[j])
	{
		while (grid[i] == '#' || place_grid[j][i] == 'x')
		{
			if (grid[i] == '#')
				place_grid[j][i] = 'x';
			i++;
		}
		if (ft_check(grid, tab_tetri, i) == 0)
			grid = ft_place(grid, tab_tetri, i);//on place le tetri
			j++;
			return(0);
		if (ft_check(grid, tab_tetri, i) == 1)//pas bon placement
			place_grid[j][i] = 'x';
		if (ft_check(grid, tab_tetri, i) == -1)//la map des x a que des x
		{
			clr_place_grid(place_grid[j]);//clean la map_x
			if (!(j - 1))//si ya pas de piece avant
				return(1);//agrandir la map
			j--; //map_x d'avant
			return(-1);//passer a la piece d'avant
		}
	}
	return(1);
}



void	ft_placement(int nbpiece, char ***tab_tetri)
{
	t_var	*var;
	char	**grid = NULL;
	int		i;

	grid = create_grid(nbpiece);
	i = 0;
	while (tab_tetri[i] != NULL)
	{
		move_tetri(tab_tetri[i]);
		while (place_tetri(tab_tetri[i], *grid, i) != 0)//tant qu'on a pas bien place une piece
		{
			if (place_tetri(tab_tetri[i], *grid, i) == 1)//plus de possibilite d'aller une piece en arriere
				grid_1_up(i);//agrandir la map de 1
			if (place_tetri(tab_tetri[i], *grid, i) == -1)
				i--;
		}
		i++;
	}
}
