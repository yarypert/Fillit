/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/14 20:28:39 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"
/*
void print_list(t_tetri *start)
{
	t_tetri *tmp;
	tmp = start;
	while(tmp != NULL)
	{
		ft_putendl(tmp->tetri);
		tmp = tmp->next;
	}
}
*/

	t_tetri *add_to_list(char *str)
{
	t_tetri *start;

	start= malloc(sizeof(*start));
	start->tetri = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strcpy(start->tetri, str);
	start->next = NULL;
	return (start);
}
/*
int main(int argc, char **argv)
{
	t_tetri *start;
	t_tetri *tmp;
	t_tetri *head;
	int i = 1;

	start = add_to_list("lolelol");
	tmp = start; 
	while(i < argc)
	{
		tmp->next = add_to_list(argv[i]);
		tmp = tmp->next;
		i++;
	}
	print_list(start);
	return (0);
}
*/
