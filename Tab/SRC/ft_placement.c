/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/20 11:18:57 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char	**clr_place_grid(char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (grid[j][i])
	{
		while (grid[j][i] != '\n')
		{
			grid[j][i] = '.';
			i++;
		}
		grid[j][i] = '.';
		j++;
	}
	return(grid);
}

char	**ft_place(char **grid, char **tab_tetri, int place)
{
	return(grid);
}

char	find_letter(char **tetri)
{
	int		i;
	int		j;
<<<<<<< HEAD
	int		k;

	i = place;
=======
	char	letter;

	letter = 'x';
	i = 0;
>>>>>>> 808a7473d968fb49367ab501e76f03a731e208a0
	j = 0;
	while (tetri[j][i])
	{
<<<<<<< HEAD
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
	}
	return(grid);
=======
		if (ft_isalpha(tetri[j][i]) == 1 && letter == 'x')
			letter = tetri[j][i];
		i++;
	}
	return(letter);
>>>>>>> 808a7473d968fb49367ab501e76f03a731e208a0
}

int		ft_check(char **grid, char **tetri, int place)
{//fonction check si la place "int place" est valide
//c'est a dire si on peut placer le tetri **tab_tetri a cet endroit
//si on ne peut pas on renvoit 1
//si on peut on renvoit 0
		return(0);
}

int		find_x(char *str)//pour trouver le decalage
{
	int x;
	int i;

	x = -1;
	i = 0;
	while (str[i])
	{
		if ((str[i] > 'A' && str[i] < 'Z') && (x = -1))
			x = str[i];
		i++;
	}
	return(x);
}

<<<<<<< HEAD
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
	int		z;
	char	**map_x;

	i = 0;
	j = 0;
	z = 0;
	map_x = (char**)malloc(sizeof(char*) * n  + 1);

	while (z <= n)
	{
		map_x[z] = (char*)malloc(sizeof(char) * ft_strxlen(map) + 1);
		z++;
	}

	map_x[j] = *map;

	while (map_x[j])
=======
int		check_fonction(char **tetri, char **map, int n)//n est le nb de piece
{
	int		i;//compteur
	int		j;//compteur
	int		k;
	char	***map_x;//la map des places invalides

	i = 0;
	j = 0;
	k = 0;

	map_x = (char***)malloc(sizeof(char**) * n + 1);

	map_x[k] = map;

	while (map_x[k][j][i])//un k par piece, j par ligne, i par lettre (cimer le char*** ;))
>>>>>>> 808a7473d968fb49367ab501e76f03a731e208a0
	{
		while (map_x[k][j][i] != '\n')
		{
			while ((map[j][i] > 'A' && map[j][i] < 'Z') || map_x[k][j][i] == 'x')//ce while detecte et remplace les cases invalide par des X
			{
				map_x[k][j][i] = 'x';
				i++;
			}
			if (ft_check(map, tetri, i) == 0)
			{
				map = ft_place(map, tetri, i);//on place le tetri
				k++;
				return(0);
			}
			if (ft_check(map, tetri, i) == 1)//pas bon placement
				map_x[k][j][i] = 'x';
			if (ft_check(map, tetri, i) == -1)//la map des x a que des x
			{
				clr_place_grid(map_x[k]);//clean la map_x
				if (!(j - 1))//si ya pas de piece avant
					return(1);//agrandir la map
				k--; //map_x d'avant
				return(-1);//passer a la piece d'avant
			}
		}
		j++;
		i = 0;
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
		while (check_fonction(tab_tetri[i], grid, nbpiece) != 0)//tant qu'on a pas bien place une piece
		{
			if (check_fonction(tab_tetri[i], grid, nbpiece) == 1)//plus de possibilite d'aller une piece en arriere
				grid_1_up(i);//agrandir la map de 1
			if (check_fonction(tab_tetri[i], grid, nbpiece) == -1)
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
