/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:24:09 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/30 15:42:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_list(t_tetri *start)
{
	t_tetri *tmp;

	tmp = start;
	while (tmp)
	{
		ft_putstr("piece numero: ");
		ft_putnbr(tmp->index);
		ft_putendl(" ");
		ft_putendl(tmp->tetri);
		tmp = tmp->next;
	}
}

int ft_read(char **argv)
{
	int fd;
	int ret; // retour de read (nb d'octets lus ou -1 en cas d'erreur)
	char str[BUFF_SIZE];
	int flag;
	int piece;

	t_tetri	*start;
	t_tetri *tmp;

	start = NULL;
	piece = 0;
	fd = open(argv[1], O_RDONLY);
	tmp = NULL;
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
		if (piece == 0)
		{
			start = add_to_list(str, piece);
			tmp = start;
		}
		else
		{
			tmp->next = add_to_list(str, piece);
			tmp = tmp->next;
		}
		piece++;
	}
	ft_print_list(start);
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
	printf("%s\n", grid_1_up(piece));
//A OPTIMISER POUR LA VITESSE

/*
//LOLELOLLOLWLOWLWOWLWOLW:IWOWIOWJKDPWJOWHJ
	if (grille pas assez grande)
		grid_1_up(piece);
	create_grid(piece);
	//recursive;
//skjfhskjvksjvhskuhvkshvshvkshvkshdhkgsjhshg
*/

	ft_placement(piece, start);
	return (0);
}
