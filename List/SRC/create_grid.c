/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:56:38 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/01 22:43:42 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

int		get_val(int piece)
{
	if (piece == 1)
		return (0);
	else if (piece == 2)
		return (1);
	else if (piece >= 2 && piece <= 4)
		return (2);
	else if (piece >= 5 && piece <= 6)
		return (3);
	else if (piece >= 7 && piece <= 9)
		return (4);
	else if (piece >= 10 && piece <= 12)
		return (5);
	else if (piece >= 13 && piece <= 16)
		return (6);
	else if (piece >= 17 && piece <= 20)
		return (7);
	else if (piece >= 21 && piece <= 25)
		return (8);
	else if (piece == 26)
		return (9);
	else
		return (-1);
}

char	*grid_1_up(int piece)
{
	int		val;
	int		j;
	int		k;
	char	*grid;
	size_t	size;

	val = get_val(piece) + 1;
	size = ((3 + val) * (2 + val));
	j = 1;
	grid = malloc((sizeof(char) * (size)));
	ft_memset((void *)grid, 46, size);
	grid[size - 1] = '\0';
	while (j != 3 + val)
	{
		k = ((3 * j) + (val * j) - 1);
		grid[k] = '\n';
		j++;
	}
	return (grid);
}


char	*create_grid(int piece)
{
	int		val;
	int		j;
	int		k;
	char	*grid;
	size_t	size;

	val = get_val(piece);
	size = ((3 + val) * (2 + val));
	j = 1;
	grid = malloc((sizeof(char) * (size)));
	ft_memset((void *)grid, 46, size);
	grid[size - 1] = '\0';
	while (j != 3 + val)
	{
		k = ((3 * j) + (val * j) - 1);
		grid[k] = '\n';
		j++;
	}
	return (grid);
}

int main()
{
	char *str;

	str = create_grid(15);
	ft_putstr(str);
	return 0;
}
