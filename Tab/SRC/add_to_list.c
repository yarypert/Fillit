/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/04 18:11:06 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"
#include <stdio.h>
/*
   t_tetri		*add_to_list(char *str, int piece,int letter)
   {
   t_tetri *start;

   start = malloc(sizeof(*start));
   start->index = piece + 1;
   start->tetri = malloc(sizeof(char) * (ft_strlen(str) + 1));
   ft_strcpy(start->tetri, str);
   ft_replace_char(start->tetri, '#', letter);
   start->next = NULL;
   return (start);
   }
   */

char	**str_to_tab(char *str)
{
	char	**tetri;
	int i;
	
	i = 0;
	tetri = ft_strsplit(str, '\n');
	
	while(i < 4)
	{
		tetri[i] = ft_strjoin(tetri[i],"\n");
		i++;
	}
	return (tetri);
}

char	***tab_to_tabtab(char *str, int piece)
{
	int		i;
	char	**tetri;
	char	***tab_tetri;

	tetri = str_to_tab(str);
	tab_tetri = malloc(sizeof(tetri) * piece);

	while (i <= piece)
	{
		tab_tetri[i] = tetri;
	}
	return(tab_tetri);
}
