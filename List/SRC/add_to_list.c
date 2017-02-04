/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/02 07:49:06 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

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
