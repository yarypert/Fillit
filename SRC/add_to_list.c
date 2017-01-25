/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/25 19:45:15 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

t_tetri		*add_to_list(char *str)
{
	t_tetri *start;

	start = malloc(sizeof(*start));
	start->tetri = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strcpy(start->tetri, str);
	start->next = NULL;
	printf("%s\n", start->tetri);
	return (start);
}
