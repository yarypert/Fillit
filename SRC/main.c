/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:24:30 by jorobin           #+#    #+#             */
/*   Updated: 2017/01/14 18:40:14 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cet algorithme va determiner a partir des tetriminos choisis le plus petit
//carre que ceux-ci peuvent former a partir des differents assemblages
//possibles dans leur ordre d'apparition (les tetriminos ne s'emboitent pas
//forcement, le carre peut donc presenter des trous)
//--------------------------------------------------------------------------
//
//Le tetriminos place sera le plus en haut et a gauche possible.
//Il faut donc:
//- une fonction qui check la position initiale du tetriminos qu'on testera dans
//la fonction test de la meilleure position sauf pour le carre 
//- une fonction qui change la position du tetriminos
//- une fonction qui trouve la meilleure position du tetriminos (moins d'espace etc)
//- une fonction de placement du tetriminos au "carre" et qui passera au tetriminos suivant
//jusqu'a ce qu'il n'y ai plus de tetriminos (fin du fichier ouvert)
//- ma bit


//pas de str[20] = '\0'



#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret; //pour le retour de read (nb d'octets lus ou -1 en cas d'erreur)
	char	str[BUF_SIZE];
	int		flag;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open failed\n");
			return (1);
		}

	flag = 0;
		while ((ret = read(fd, &str, BUF_SIZE)) >= 20)//le fichier est stocke dans buf
		{
			if (check_final(str) != 0)
				{
				write(2, "error\n", 6);
				return (1);
				}
				//FONCTION D'ENCULE QUIAJOUTE TOUTES LES PIECES DANS LA LISTE CHAINEES DE PD'
		//strdup maison
			if (ret == 20)
				flag = 1;
			else if (str[20] != '\n')
			{
				write(2, "error\n", 6);
				return (1);
			}
			str[20] = '\0';
			print_list(add_to_list(str));
		}
		if (flag != 1 || ret != 0)
		{
			write(2, "error\n", 6);
			return (1);
		}
		if (close(fd) == -1)
		{
			ft_putstr("close failed\n");
			return (1);
		}
		printf("OK\n");
		return (0);
	}
	write(2, "error\n", 6);
}
