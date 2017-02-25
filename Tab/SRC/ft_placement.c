/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:18:47 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/25 14:43:06 by jorobin          ###   ########.fr       */
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

/*char	find_letter(char **tetri)//renvoit la lettre de la piece
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
}*/

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
/*
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
			if (str[j][i] == '#' && temp == 0)
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
}*/

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

char	*double_tab_to_str(char **map)//transforme un char ** en char *
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
	char **tab_solved;
	int		square_size;
	int		i;

	i = 0;
	tab_solved = NULL;
	square_size = 2;
	ft_putchar('a');
	ft_putchar('b');
	while (tetri[i] != NULL)
	{
		printf("tetri 1 moved =\n%s\n", double_tab_to_str(tetri[i]));
		i++;
	}
}

void	test(char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ft_putendl("fonction test");
	while (i < 4)
	{
		while (str[i][j] != '\n')
		{
			ft_putchar(str[i][j]);
			if (str[i][j] == '#')
			{
				str[i][j] = '.';
			}
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
/*
int		main(void)//main de test pour strxlen (strlen avec un char**)
{
	char ***str;//triple tableau de test
	int i;
	int j;
	char *tmp;

	tmp = NULL;
	tmp = (char *)malloc(sizeof(char) * 5);

	while(i < 5)
	{
		tmp[i] = '.';
		i++;
	}
	////////////////// MALLOC DU ***STR DE TEST////////////////////////////////////
	ft_putendl(tmp);
	tmp[0] = '.';
	ft_putstr(tmp);

	i = 0;
	j = 0;
	str = (char***)malloc(sizeof(char**) * 4);

	while (i < 4)
	{
		str[i] = (char**)malloc(sizeof(char*) * 4 + 1);
		i++;
	}
	str[i] = NULL;
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

	str[4] = NULL;

	///////////////////////////////////////////////////////////////////////////////

	str[0][0] = "....\n\0";/////////1ERE PIECE//////////
	str[0][1] = "..##\n\0";
	str[0][2] = "...#\n\0";
	str[0][3] = "...#\n\0";

	test(str[0]);

	str[1][0] = "..##\n\0";////////2EME PIECE//////////
	str[1][1] = "..##\n\0";
	str[1][2] = "....\n\0";
	str[1][3] = "....\n\0";

	str[2][0] = "....\n\0";///////3EME PIECE///////////
	str[2][1] = "..#.\n\0";
	str[2][2] = "###.\n\0";
	str[2][3] = "....\n\0";

	str[3][0] = "....\n\0";//////4EME PIECE///////////
	str[3][1] = "....\n\0";
	str[3][2] = "....\n\0";
	str[3][3] = "####\n\0";

	////////////////// AFFICHAGE DE CHAQUE PIECE (ligne par ligne)/////////////////

	printf("**str est: %s", str[0][0]);
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

	///////////////////////////////////////////////////////////////////////////////

	//ft_placement(4, str);
	printf("le tetri moved =\n%s\n", double_tab_to_str(move_tetri(str[0])));
}*/
