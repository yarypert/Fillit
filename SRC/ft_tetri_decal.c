/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_decal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:09:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/03/02 15:02:46 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_tetri_decal(char *tetri_before)
{
	int		i;
	int		j;
	int		taille;
	int		flag;
	int		count;
	char	*tetri_next;

	i = 0;
	j = 0;
	taille = 0;
	flag = 0;
	count = 0;
	tetri_next = NULL;
	tetri_before = move_tetri_char(tetri_before);
	tetri_next = (char*)malloc(sizeof(char) * find_len(tetri_before) + 1);

	while (count <= 3)
	{
		while (tetri_before[i] != '\n')
		{
			if (tetri_before[i] == '#')
			{
				tetri_next[j] = tetri_before[i];
				j++;
				flag = 1;
				count++;
			}
			if (tetri_before[i] == '.')
			{
				if (flag == 0)
				{
					tetri_next[j] = ' ';
					j++;
				}
			}
			i++;
		}
		if (flag == 1)
		{
			flag = 0;
			tetri_next[j] = tetri_before[i];
			j++;
		}
		i++;
	}
	tetri_next[j] = '\0';
	return(tetri_next);
}

int		find_len(char *str)
{
	int		i;
	int		taille;
	int		flag;
	int count;

	i = 0;
	taille = 0;
	flag = 0;
	count = 0;
	while (count < 4)
	{
		while (str[i] != '\n')
		{
			if (str[i] == '#')
			{
				taille++;
				flag = 1;
				count++;
			}
			if (str[i] == '.')
			{
				if (flag == 0)
					taille++;
			}
			i++;
		}
		if (flag == 1)
		{
			taille++;
			flag = 0;
		}
		i++;
	}
	return(taille);
}

/*
int		main()
{
char	*test;

	test = (char*)malloc(sizeof(char) * 19 + 1);

	test[0] = '.';
	test[1] = '#';
	test[2] = '.';
	test[3] = '.';
	test[4] = '\n';
	test[5] = '.';
	test[6] = '#';
	test[7] = '.';
	test[8] = '.';
	test[9] = '\n';
	test[10] = '.';
	test[11] = '#';
	test[12] = '#';
	test[13] = '.';
	test[14] = '\n';
	test[15] = '.';
	test[16] = '.';
	test[17] = '.';
	test[18] = '.';
	test[19] = '\n';
	test[20] = '\0';
	printf("avant :\n%s\n", test);

	ft_putchar('\n');
	ft_putendl("apres");
	ft_putstr(ft_tetri_decal(test));
	return 0;
	return(0);
}*/
