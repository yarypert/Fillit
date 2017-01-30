/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_1_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:46:38 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/30 13:48:40 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

static int		len_line(char *old_grid)
{
	int		i;

	i = 0;
	while (old_grid[i] != '\n')
		i++;
	return(i + 1);
}

char	*grid_1_up(char *old_grid)
{
	int		length;
	int		i;
	int		j;
	char	*new_grid;

	i = 0;
	j = 0;
	length = upper_length(old_grid);
	printf("%s%d\n", "la taille de long x larg = ", length);
	new_grid = (char*)malloc(sizeof(char) * (length) + 1);
	if (!new_grid)
		return (NULL);
	while (old_grid[i])
	{
		while (old_grid[i] != '\n')
		{
			new_grid[j] = old_grid[i];
			i++;
			j++;
		}
		new_grid[j] = '.';
		j++;
		new_grid[j] = '\n';
		j++;
		i++;
	}
	i = 0;
	while (i < length)
	{
		while (i < len_line(old_grid))
		{
			new_grid[j] = '.';
			i++;
			j++;
		}
		if (new_grid[j - 1] == '.')
			new_grid[j] = '\n';
		j++;
		i++;
	}
	new_grid[length] = '\0';
	printf("%s\n", new_grid);
	return (new_grid);
}

int		upper_length(char *old_grid)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;

	while (old_grid[i] != '\n')
	{
		j++;
		i++;
	}
	j++;
	printf("%d\n", j);
	i = 0;
	while (old_grid[i])
	{
		if (old_grid[i] == '\n')
			k++;
		i++;
	}
	k++;
	printf("%d\n", k);
	j = j + 1;
	k = k;
	printf("%s%d\n%s%d\n", "j = ", j, "k = ", k);
	return (j * k);
}

int		main(void)
{
	grid_1_up(".....\n.....\n.....\n.....\n.....\n");
	return (0);
}
