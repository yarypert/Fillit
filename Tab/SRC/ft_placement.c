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

char	*clr_map_x(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		while (map[i] != '\n')
		{
			map[i] = '.';
		}
		i++;
	}
	return(map);
}

char	**ft_place(char **grid, char **tetri, int place)
{
	return(grid);
}

char	find_letter(char **tetri)
{
	int i;
	int j;
	char k;

	i = 0;
	j = 0;
	k = 'x';

	while (tetri[j] != NULL)
	{
		while (tetri[j][i] == '\n')
		{
			if ((tetri[j][i] > 'A' && tetri[j][i] < 'Z') && k == 'x')
				k = tetri[j][i];
			i++;
		}
		j++;
	}
	return (k);
}

int		ft_check(char **grid, char **tetri, int place)
{//fonction check si la place "int place" est valide
//c'est a dire si on peut placer le tetri **tab_tetri a cet endroit
//si on ne peut pas on renvoit 1
//si on peut on renvoit 0

	int i;
	int j;
	int k;
	int l;
	char let;

	let = find_letter(tetri);
	i = place;
	j = 0;
	k = 0;
	l = 0;
	while (grid[j] != NULL)
	{
		while (k < 4 || tetri[j][i])
		{
			while (grid[j][i] != '\n')
			{
				if (grid[j][i] == '.')
				{
					while (tetri[j][l] == '.')
						l++;
					grid[j][i] = tetri[j][l];
					if (k != 0)//si une partie de piece est deja placee
					{
						//regarder si ca forme un motif de tetri valide
						if (grid[j][i - 1] != let || grid[j][i + 1] != let || grid[j][i + 5] != let)
							return(1);
					}
					k++;
					l++;
					i++;
				}
			}
			j++;
			if (grid[j][i] == '\n')
			{
				if (tetri[j + 1][i] != '.' || tetri[j + 1][i] != '\n')
					return(1);
				i++;
			}
		}
		return(0);
	}
	return(1);
}

int		ft_strxlen(char **str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[j] != NULL)
	{
		while (str[j][i] != '\n')
		{
			i++;
			k++;
		}
		k++;
		j++;
	}
	return(k);
}

int		place_tetri(char **tetri, char **map, int n)//n est le nb de piece
{
	int		i;
	int		j;
	int		k;
	char	**map_x;

	i = 0;
	j = 0;
	k = 0;
	map_x = (char**)malloc(sizeof(char*) * n  + 1);

	while (k <= n)
	{
		map_x[k] = (char*)malloc(sizeof(char) * ft_strxlen(map) + 1);
		k++;
	}

	k = 0;
	map_x[k] = *map;

	while (map_x[k][i])
	{
		while (map[j][i] != '\n')
		{
			while (map[j][i] == '#' || map_x[k][i] == 'x')//ce while detecte et remplace les cases invalide par des X
			{
				if (map[j][i] == '#')
					map_x[j][i] = 'x';
				i++;
			}
			if (ft_check(map, tetri, i) == 0)
				map = ft_place(map, tetri, i);//on place le tetri
				j++;
				return(0);
			if (ft_check(map, tetri, i) == 1)//pas bon placement
				map_x[j][i] = 'x';
			if (ft_check(map, tetri, i) == -1)//la map des x a que des x
			{
				clr_map_x(map_x[k]);//clean la map_x
				if (!(j - 1))//si ya pas de piece avant
					return(1);//agrandir la map
				j--; //map_x d'avant
				return(-1);//passer a la piece d'avant
			}
		}
		j++;
	}
	return(1);
}

void	ft_placement(int nbpiece, char ***tab_tetri)
{
	char	**grid = NULL;
	int		i;

	grid = create_grid(nbpiece);
	i = 0;
	while (tab_tetri[i] != NULL)
	{
		move_tetri(tab_tetri[i]);
		while (place_tetri(tab_tetri[i], grid, nbpiece) != 0)//tant qu'on a pas bien place une piece
		{
			if (place_tetri(tab_tetri[i], grid, nbpiece) == 1)//plus de possibilite d'aller une piece en arriere
				grid_1_up(i);//agrandir la map de 1
			if (place_tetri(tab_tetri[i], grid, nbpiece) == -1)
				i--;
		}
		i++;
	}
}

int		main(void)//main de test pour strxlen (strlen avec un char**)
{
	char **str;
	int i;

	i = 0;
	str = (char**)malloc(sizeof(char*) * 4 + 1);

	while (i < 4)
	{
		str[i] = (char*)malloc(sizeof(char) * 5 + 1);
		i++;
	}
	str[i] = NULL;

	str[0] = "salut";
	str[1] = "salut";
	str[2] = "salut";
	str[3] = "salut";

	printf("**str est: %s\n", str[0]);
	printf("**str est: %s\n", str[1]);
	printf("**str est: %s\n", str[2]);
	printf("**str est: %s\n", str[3]);
	printf("**str est: %s\n", str[4]);
	printf("la longueur du char **str est: %d\n", ft_strxlen(str));

}
