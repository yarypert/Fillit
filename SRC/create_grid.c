/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:56:38 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/23 10:22:35 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *create_grid(int val, int piece)
{
	int val;
	int i;
	int j;
	int k;
	char *grid;
	size_t size;
	
	val = ()
	size = ((3 + val) * (2 + val));
	j = 1;
	i = 0;
	grid = malloc(sizeof((char)(size)));
	ft_memset((void *)grid, 46 ,size);
	grid[size] = '\0';

	while (j != 3 + val)
	{
		k = ((3 * j) + (val * j) - 1);
		grid[k] = '\n';
		j++;
	}
	return (grid);
}
