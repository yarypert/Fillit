/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_all_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:40:34 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/07 14:41:05 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_replace_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = c;
		i++;
	}
	return (str);
}

char	**move_all_tetri(char **tab, int piece_nb)
{
	int	i;

	i = 0;
	while (i < piece_nb)
	{
		tab[i] = ft_tetri_decal(tab[i]);
		tab[i] = ft_replace_char(tab[i], 'A' + i);
		i++;
	}
	return (tab);
}
