/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:56:17 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/08 13:07:15 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_len(char *str, t_decal *td)
{
	td->i = 0;
	td->flag = 0;
	td->count = 0;
	td->taille = 0;
	while (td->count < 4)
		find_len_2(str, td);
	return (td->taille);
}

void	find_len_2(char *str, t_decal *td)
{
	while (str[td->i] != '\n')
	{
		if (str[td->i] == '#')
		{
			td->taille++;
			td->flag = 1;
			td->count++;
		}
		if (str[td->i] == '.')
		{
			if (td->flag == 0)
				td->taille++;
		}
		td->i++;
	}
	if (td->flag == 1)
	{
		td->taille++;
		td->flag = 0;
	}
	td->i++;
}
