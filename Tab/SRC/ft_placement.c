/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/21 15:37:07 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

/*
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
	char letter;

	i = 0;
	j = 0;
	letter = 'x';

	while (tetri[j] != NULL)
	{
		while (tetri[j][i] == '\n')
		{
			if (ft_isalpha(tetri[j][i]) == 1 && letter == 'x')
				letter = tetri[j][i];
			i++;
		}
		j++;
	}
	return (letter);
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
*/
int		*find_x(char **str, int *decal)
{
	int		i;
	int		j;
	int		k;
	int		temp;

	i = 0;
	j = 0;
	k = 0;
	temp = 0;

	while (str[j] != NULL)
	{
		while (str[j][i] != '\n')
		{
			if (ft_isalpha(str[j][i]) == 1 && temp == 0)
			{
				decal[k] = i;
				temp = 1;
			}
			i++;
		}
		if (temp == 0)
			decal[k] = 0;
		if (temp != 0)
			temp = 0;
		j++;
		k++;
		i = 0;
	}
	return(decal);
}

int		ft_strxlen(char **str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[j] != NULL && str[j][i] != '\0')
	{
		while (str[j][i] != '\n')
		{
			i++;
			k++;
		}
		i = 0;
		k++;
		j++;
	}
	return(k);
}

char	*str(char **map)
{
	int i;
	int j;
	int k;
	char *str;

	if(!(str = (char*)malloc(sizeof(char) * (ft_strxlen(map)) + 1)))
		ft_putstr("zizi");

	i = 0;
	j = 0;
	k = 0;
	while (map[j] != NULL)
	{
		while (map[j][i] != '\n')
		{
			str[k] = map[j][i];
			i++;
			k++;
		}
		str[k] = map[j][i];
		j++;
		k++;
		i = 0;
	}
	str[k] = '\0';
	return(str);
}

int		place_tetri(char **tetri, char **map, int n)//n est le nb de piece
{
	int		i;
	int		j;
	int		k;
	int		*decal;
	static char		**map_x;

	i = 0;
	j = 0;
	k = 0;
	decal = (int*)malloc(sizeof(int) * 4 + 1);
	decal = find_x(tetri, decal);
	printf("la longueur de la map est: \n%d\n", ft_strxlen(map));
	printf("le tableau de decalage: \n%d\n%d\n%d\n%d\n", decal[0], decal[1], decal[2], decal[3]);
	map_x = (char**)malloc(sizeof(char*) * n  + 1);
	while (k <= n)
	{
		map_x[k] = (char*)malloc(sizeof(char) * ft_strxlen(map) + 1);
		k++;
	}

	k = 0;
	map_x[k] = str(map);//transforme map en char* pour la mettre dans map_x
	printf("la map_x est:\n%s\n%s\n%s\n%s\n%s\n", map_x[0], map_x[1], map_x[2], map_x[3], map_x[4]);
/*
	while (map_x[k][i])
	{
		while (map[j][i] != '\n')
		{
			while (map[j][i] == '#' || map_x[k][i] == 'x')//ce while detecte et remplace les cases invalide par des X
			{
				map_x[j][i] = 'x';
				i++;
			}
			if (ft_check(map, tetri, i) == 0)
			{
				map = ft_place(map, tetri, i);//on place le tetri
				k++;// map_x suivante
				return(0);
			}
			if (ft_check(map, tetri, i) == 1)//pas bon placement
				map_x[j][i] = 'x';
			if (ft_check(map, tetri, i) == -1)//la map des x a que des x
			{
				clr_map_x(map_x[k]);//clean la map_x
				if (!(j - 1))//si ya pas de piece avant
					return(1);//agrandir la map
				k--; //map_x d'avant
				return(-1);//passer a la piece d'avant
			}
		}
		j++;
	}*/
	return(0);
}

void	ft_placement(int nbpiece, char ***tab_tetri)
{
	char	**grid = NULL;
	int		i;

	grid = create_grid(nbpiece);
	printf("la map cree dans ft_placement est: \n%s\n%s\n%s\n%s\n%s\n", grid[0], grid[1], grid[2], grid[3], grid[4]);
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
		printf("On passe dans le i++ de ft_placement\n");
		i++;
	}
}

int		main(void)//main de test pour strxlen (strlen avec un char**)
{
	char ***str;//triple tableau de test
	int i;
	int j;

////////////////// MALLOC DU ***STR DE TEST////////////////////////////////////


	i = 0;
	str = (char***)malloc(sizeof(char**) * 4 + 1);

	while (i < 4)
	{
		str[i] = (char**)malloc(sizeof(char*) * 4 + 1);
		i++;
	}

	i = 0;
	while (i < 4)
	{
		while (j < 5)
		{
			str[i][j] = (char*)malloc(sizeof(char) * 5 + 1);
			j++;
		}
		i++;
	}

	str[i] = NULL;

///////////////////////////////////////////////////////////////////////////////

	str[0][0] = "....\n";/////////1ERE PIECE//////////
	str[0][1] = "..AA\n";
	str[0][2] = "...A\n";
	str[0][3] = "...A\n";

	str[1][0] = "..BB\n";////////2EME PIECE//////////
	str[1][1] = "..BB\n";
	str[1][2] = "....\n";
	str[1][3] = "....\n";

	str[2][0] = "....\n";///////3EME PIECE///////////
	str[2][1] = "..C.\n";
	str[2][2] = "CCC.\n";
	str[2][3] = "....\n";

	str[3][0] = "....\n";//////4EME PIECE///////////
	str[3][1] = "....\n";
	str[3][2] = "....\n";
	str[3][3] = "DDDD\n";

////////////////// AFFICHAGE DE CHAQUE PIECE (ligne par ligne)/////////////////

	printf("**str est: %s\n", str[0][0]);
	printf("**str est: %s\n", str[0][1]);
	printf("**str est: %s\n", str[0][2]);
	printf("**str est: %s\n", str[0][3]);
	printf("**str est: %s\n\n\n", str[0][4]);
	printf("**str est: %s\n", str[1][0]);
	printf("**str est: %s\n", str[1][1]);
	printf("**str est: %s\n", str[1][2]);
	printf("**str est: %s\n\n\n", str[1][3]);
	printf("**str est: %s\n", str[2][0]);
	printf("**str est: %s\n", str[2][1]);
	printf("**str est: %s\n", str[2][2]);
	printf("**str est: %s\n\n\n", str[2][3]);
	printf("**str est: %s\n", str[3][0]);
	printf("**str est: %s\n", str[3][1]);
	printf("**str est: %s\n", str[3][2]);
	printf("**str est: %s\n\n\n", str[3][3]);

/////////// TEST DE LA FONCTION FT_STRXLEN POUR LA LONG D'UN CHAR**////////////

	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[0]));
	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[1]));
	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[2]));
	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[3]));

///////////////////////////////////////////////////////////////////////////////

	ft_placement(4, str);
}
