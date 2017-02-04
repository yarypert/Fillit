/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 04:47:58 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/02 06:08:25 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char *ft_replace_char(char *s, char find, char repl)
{
	int i;

	i	= 0;
	while (s[i])
	{
		if (s[i] == find)
			s[i] = repl;
		i++;
	}
	return (s);
}
