/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/24 18:50:49 by jorobin          ###   ########.fr       */
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

int		ft_check(char **grid, char **tetri, int *place, int n)
{/*fonction check si la place "int place" est valide
	//c'est a dire si on peut placer le tetri **tab_tetri a cet endroit
	//si on ne peut pas on renvoit 1
	//si on peut on renvoit 0
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = place[n +;
	k = 0;
	while ((j != place[n + 1] && k != place[n]) &&(find_letter(tetri) != 'A'))
	
	while (grid[j] != NULL || n != 4)
	{
		while (grid[j][k] != '\n')
		{
		k++;
		}
		j++;
	}*/
	return (1);
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

void	ft_placement(int nbpiece, char ***tetri)//algo
{
	char	**grid = NULL;
	int		i;
	int		j;
	int		k;
	int		l;
	int		n;
	int		*place;// tableau d'int contenant les position max testees de chaque piece(positions invalides)

	place = (int*)malloc(sizeof(int) * nbpiece + 1);
	grid = create_grid(nbpiece);
	printf("la map cree dans ft_placement est: \n%s%s%s%s%s\n", grid[0], grid[1], grid[2], grid[3], grid[4]);
	i = 0;// indique le numero du tetri(quel tetri on est)
	j = 0;// y de la map
	k = 0;// x de la map
	l = 0;// pour avancer dans le tableau d'int de 2 en 2 lole
	n = 1;// nb d'appel du grid 1_up
ft_putchar('a');
	while (tetri[i] != NULL)
	{
ft_putchar('b');
		while (grid[j] && tetri[i])
		{
			while (grid[j][k] != '\n')
			{
		ft_putchar('c');
				if (grid[j][k] == '.')
				{
				ft_putchar('d');
					place[l] = k;
					place[l + 1] = j;
					if ((ft_check(grid, tetri[i], place, i)) == 0)
					{
					ft_putchar('e');
						//grid = place_tetri(grid, tetri[i], j, k, place);
						printf("place[i] =  %d\n", place[i]);
						printf("place[i+1] =  %d\n", place[i + 1]);
						printf("i =  %d\n", i);
						printf("l =  %d\n", l);
						printf("j =  %d\n", j);
						printf("k =  %d\n", k);
						l = l + 2;
						i++;
						k = 0;
						j = 0;
					}
					else if ((ft_check(grid, tetri[i], place, i)) == 1){
						ft_putchar('f');
							k++;}
				}
				else
					k++;
			}
			j++;
			k = 0;
		}
		if (i == 0)
		{
			grid_1_up(nbpiece,n);
			printf("grid apres le 1up :\n%s\n", str(grid));
			n++;
		}
		if (i != 0)
			i--;
	}
ft_putchar('g');
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

		str[0][0] = "....\n\0";/////////1ERE PIECE//////////
		str[0][1] = "..AA\n\0";
		str[0][2] = "...A\n\0";
		str[0][3] = "...A\n\0";
		str[0][4] = "\0";

		str[1][0] = "..BB\n\0";////////2EME PIECE//////////
		str[1][1] = "..BB\n\0";
		str[1][2] = "....\n\0";
		str[1][3] = "....\n\0";
		str[1][4] = "\0";

		str[2][0] = "....\n\0";///////3EME PIECE///////////
		str[2][1] = "..C.\n\0";
		str[2][2] = "CCC.\n\0";
		str[2][3] = "....\n\0";
		str[2][4] = "\0";

		str[3][0] = "....\n\0";//////4EME PIECE///////////
		str[3][1] = "....\n\0";
		str[3][2] = "....\n\0";
		str[3][3] = "DDDD\n\0";
		str[3][4] = "\0";

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
