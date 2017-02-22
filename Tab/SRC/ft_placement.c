/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/21 17:59:19 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"


char	*clr_map(char *map)//clear la map
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '\n')
			map[i] = '.';
		i++;
	}
	return(map);
}

char	**ft_place(char **grid, char **tetri, int place)//placement a relier a check
{
	return(grid);
}

char	find_letter(char **tetri)//renvoit la lettre de la piece
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
			if (ft_isalpha(tetri[j][i]) == 1)
				return(tetri[j][i]);
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
/*
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
	}*/
	return(0);
}

int		*find_x(char **str, int *decal)//trouve le xmin de chaque ligne
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

int		ft_strxlen(char **str)//long d'un char **
{
	int		i;
	int		j;
	int		k;

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

char	*str(char **map)//transforme un char ** en char *
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

int		*place_zero(int *place)//met des 0 dans un char*
{
	int		i;

	i = 0;
	while (place[i] != '\0')
	{
		place[i] = 0;
		i++;
	}
	return (place);
}

void	ft_placement(int nbpiece, char ***tetri)//algo
{
	char	**grid = NULL;
	int		i;
	int		j;
	int		k;
	int		*place;

	place = (int*)malloc(sizeof(int) * nbpiece + 1);
	place = place_zero(place);
	grid = create_grid(nbpiece);
	printf("la map cree dans ft_placement est: \n%s%s%s%s%s\n", grid[0], grid[1], grid[2], grid[3], grid[4]);
	i = 0;
	j = 0;
	while (i != nbpiece)
	{
		ft_putstr("tetri de i: ");
		ft_putstr(str(tetri[i]));
		ft_putstr(" \n");
		move_tetri(tetri[i]);
		while (grid[j][k] != '\0')
		{
			while (grid[j][k] != '\n')
			{
				while (grid[j][k] == '.')
				{
					if (ft_check(grid, tetri[i], (place[i] + k)) == 0)//placement valide
					{
						//grid = ft_place();//on place la piece 
						place[i] = k;//on save le placement a dans le tab 
						printf("place de [i] est: %d\n", place[i]);
						i++;
						printf("i = %d\n", i); 
						printf("on avance d'une piece\n"); 
						k = 0;
					}
					else if (ft_check(grid, tetri[i], k) == 1)//placement invalide
					{
						k++;//on avance
					}
				}
				k++;
			}
			j++;
			k = 0;
		}
		place[i] = 0;
		if (i == 0)
		{
			printf("grid avant 1up : %s\n", str(grid));
			//grid = grid_1_up(i);
			printf("grid apres 1up : %s\n", str(grid));
		}
		else if (i != 0)
			i--;
	}
	printf("olol\n");
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

/*	printf("**str est: %s", str[0][0]);
	printf("**str est: %s", str[0][1]);
	printf("**str est: %s", str[0][2]);
	printf("**str est: %s", str[0][3]);
	printf("**str est: %s\n\n\n", str[0][4]);
	printf("**str est: %s", str[1][0]);
	printf("**str est: %s", str[1][1]);
	printf("**str est: %s", str[1][2]);
	printf("**str est: %s\n\n\n", str[1][3]);
	printf("**str est: %s", str[2][0]);
	printf("**str est: %s", str[2][1]);
	printf("**str est: %s", str[2][2]);
	printf("**str est: %s\n\n\n", str[2][3]);
	printf("**str est: %s", str[3][0]);
	printf("**str est: %s", str[3][1]);
	printf("**str est: %s", str[3][2]);
	printf("**str est: %s\n\n\n", str[3][3]);


	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[0]));
	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[1]));
	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[2]));
	printf("la longueur du char **str est: %d\n\n", ft_strxlen(str[3]));
*/
///////////////////////////////////////////////////////////////////////////////

	ft_placement(4, str);
}
