/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/13 17:17:43 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

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

char	**grid_to_tab(char *str)
{
	char	**tetri;
	int i;

	i = 0;
	tetri = ft_strsplit(str, '\n');

	while(tetri[i])
	{
		tetri[i] = ft_strjoin(tetri[i],"\n");
		i++;
	}
	return (tetri);
}
