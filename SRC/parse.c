/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:21:44 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/11 14:24:04 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//si ya que des '.' et '#' et '\n' XX
//si ya pas plus de 4 lignes XX 
//si ya 4 '#' XX
//si ya 4 charac par ligne XX
//si ya 8 ou 6 "liens" XX
//si ya des '/n' entre chaque piece

int		check_char(char *str)
{
	//TESTEE ET VALIDE
	//ne contient que des '.' '#' et '\n'
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] != 46 && str[i] != 35 && str[i] != 10)
			return(1);
		i++;
	}
	return (0);
}

int		check_links(char *str)
{
	// TESTEE ET VALIDE
	//8 ou 6 liens
	int i;
	int count_links;

	count_links = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 5] == '#' && i < 15)
				count_links++;
			if (str[i - 5] == '#' && i > 4)
				count_links++;
			if (str[i + 1] == '#' && i < 19)
				count_links++;
			if (str[i - 1] == '#' && i > 0)
				count_links++;
		}
		i++;
	}
	return((count_links == 6 || count_links == 8) ? 0 : 1);
}


int		check_lines(char *str) 
{
	// TESTEE ET VALIDE
	// pas plus de 4 lignes
	// pas plus de 4 charac par ligne
	// pas plus de 4 '#'
	int		count_bn;
	int		count_char;
	int		count_hashtags;
	int i;

	i = 0;
	count_hashtags = 0;
	count_char = 0;
	count_bn = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			count_hashtags++;
		if (str[i] != '\n')
			count_char++;
		if (str[i] == '\n')
			count_bn++;
		i++;
	}
	return((count_hashtags == 4 && count_char == 16 && count_bn == 4) ? 0 : 1);
}

int		check_final(char *str)
{
	int a;
	int b;
	int c;

	a = check_char(str);
	b = check_links(str);
	c = check_lines(str);
	return((a == 0 && b == 0 && c == 0) ? 0 : 1);
}
