/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:53:01 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/07 14:53:03 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_grid(int size)
{
	char	*result;
	size_t	len;
	size_t	index;

	len = (size + 1) * size;
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	index = 0;
	result[len] = '\0';
	while (index < len)
		result[index++] = '.';
	index = size;
	while (index < len)
	{
		result[index] = '\n';
		index += size + 1;
	}
	return (result);
}

int		size_min(char **pieces)
{
	int		nb;
	int		size;

	size = 2;
	nb = 0;
	while (pieces[nb] != NULL)
		nb++;
	while (size * size < nb * 4)
		size++;
	return (size);
}
