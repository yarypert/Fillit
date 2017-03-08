/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:22:29 by jorobin           #+#    #+#             */
/*   Updated: 2017/03/07 14:22:34 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	freeall(char *file, char **pieces, int i)
{
	if (i == -1)
		while (pieces && pieces[++i])
			;
	while (i)
		ft_memdel((void *)&pieces[i--]);
	ft_memdel((void *)&file);
	ft_memdel((void **)pieces);
	ft_error("error");
}
