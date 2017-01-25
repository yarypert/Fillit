/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:24:09 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/25 19:37:27 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_read(char **argv)
{
	int fd;
	int ret; // retour de read (nb d'octets lus ou -1 en cas d'erreur)
	char str[BUFF_SIZE];
	int flag;
	int piece;

	piece = 0;
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		ft_putstr("open failed\n");
		return (1);
	}
	while ((ret = read(fd, &str, BUFF_SIZE)) >= 20)//le fichier est stocke dans buf
	{
		if (check_final(str) != 0)
		{
			ft_putstr("error\n");
			return (1);
		}
		if (ret == 20)
			flag = 1;
		else if (str[20] != '\n')
		{
			ft_putstr("error\n");
			return (1);
		}
		str[20] = '\0';
		add_to_list(str);
		piece++;
	}
	printf("%s%d%s\n","il y a ", piece, " pieces");
	if (flag != 1 || ret != 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close failed\n");
		return (1);
	}
	ft_putstr("OK\n");
	ft_putstr("grille minimale necessaire\n");
	printf("%s\n", create_grid(piece));
	//ft_placement(piece, *list);
	return (0);
}
