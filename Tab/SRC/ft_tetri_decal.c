/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_decal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:09:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/02/28 17:21:26 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char	*ft_tetri_decal(char *tetri_before)
{
	int		i;
	int		j;
	int		taille;
	int		flag;
	char	*tetri_next;

	i = 0;
	j = 0;
	taille = 0;
	flag = 0;
	tetri_next = (char*)malloc(sizeof(char) * find_len(tetri_before) + 1);

	while (tetri_before[i] != '\0')
	{
		if (tetri_before[i] == '.')
		{
			if (taille != 0 && flag != 1)
				tetri_next[j] = tetri_before[i];
		}
		else if (tetri_before[i] == '#' || (tetri_before[i] == '\n' && flag == 1))
		{
			tetri_next[j] = tetri_before[i];
			flag = 1;
		}
		if (tetri_before[i] == '\n')
			flag = 0;
		i++;
	}
	return(tetri_next);
}

int		find_len(char *str)
{
	int		i;
	int		taille;
	int		flag;

	i = 0;
	taille = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (taille != 0 && flag != 1)
				taille++;
		}
		else if (str[i] == '#' || (str[i] == '\n' && flag == 1))
		{
			taille++;
			flag = 1;
		}
		if (str[i] == '\n')
			flag = 0;
		i++;
	}
	return(taille);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("resultat = %s\n", ft_tetri_decal(argv[1]));
	}
	return(0);
}
