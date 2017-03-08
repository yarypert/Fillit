/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:25:12 by jorobin           #+#    #+#             */
/*   Updated: 2017/03/07 14:38:18 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strappend(char *str1, char *str2)
{
	char	*tmp;

	if (str1 && str2)
	{
		tmp = ft_strjoin(str1, str2);
		free(str1);
		return (tmp);
	}
	return (NULL);
}

char	*read_tetri(char *file)
{
	int		fd;
	int		ret;
	char	str[BUFF_SIZE];
	char	*tetris;

	tetris = ft_strnew(1);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		tetris = ft_strappend(tetris, str);
	}
	close(fd);
	return (tetris);
}
