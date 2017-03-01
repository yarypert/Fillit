/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:29:49 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/28 13:26:06 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

////////////////////////  AFFICHAGE TRIPLE TABLO  /////////////////////////////

static void	ft_put_triple_tab(char ***tab)
{
//segfault a la fin de la fonction
	int i;
	int j;
	int k;

	ft_putendl("ft_put_triple_tab");
	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			ft_putstr(tab[i][j]);
			j++;
		}
	ft_putchar('\n');
		j = 0;
		i++;
	}
}

////////////// CREATION DE LA MAP (en fonction de square_size) ///////////////

char **create_tab_solved(int square_size)
{
	int i;
	char **tab_solved;
	int j;

	ft_putendl("fonction create_tab_solved !");
	j = 0;
	tab_solved = NULL;
	i = 0;
	tab_solved = (char **)malloc(sizeof(char *) * (square_size + 1));
	while (i < square_size)
	{
		tab_solved[i] = (char *)malloc(sizeof(char) * (square_size + 1));
		while (j < square_size)
		{
			tab_solved[i][j] = '.';
			j++;
		}
		tab_solved[i][j] = '\n';
		j = 0;
		i++;
	}
	tab_solved[i] = NULL;
	ft_putendl("fonction create_tab_solved terminee !");
	return (tab_solved);
}

/////////////////////////  ALGORITHME  ///////////////////////////////////////

void	ft_nouveau_placement(char ***tetri)
{
	char **tab_solved;
	int		square_size;
	int		i;
	int		j;
	int		k;

	tab_solved = NULL;
	square_size = 5;
	tab_solved = create_tab_solved(square_size);
	//tant que la map != NULL
	//la parcourir
	//si c'est une place valide (pas un # pas un \n pas NULL)
	//fonction de test (on lui envoie la place a tester et le tetri)
	//si la fontion renvoie 1 placer, changer en lettre, et passer a la piece suivante
	//si elle renvoie zero  position_de_x++, si on peut plus avancer, passer a la piece d'avant,
	//si elle est NULL on free tab_solved, on l'agrandie (square_size ++) et on recreee le tout
	while (tetri[i] != NULL)
	{
		while (tab_solved[j] != NULL)
		{
			while (tab_solved[j][k] != '\n')
			{
				while (check_place(j, k, tetri[i]) != 1)//si le placement est possible
				{
					k++;
				}
				ft_replace_char(tetri[i], i);//on remplace les # par des lettres
				//on place
				i++;
				j = 0;
				k = 0;
			}
			k = 0;
			j++;
		}
		if (i != 0)
			i--;
		else if (i == 0)
			square_size++;
		j = 0;
		k = 0;
	}
	ft_putdoubletab(tab_solved);
	ft_putstr("\ncrokzizi\n");
}

//////////////////////////////////////////////////////////////////////////////

int		ft_fillit(char **argv)
{
	t_var	var;
	var.flag = 0;
	var.piece_nb = 0;
	var.dest = 65;
	var.fd = open(argv[1], O_RDONLY);
	ft_open(var.fd);
	int i;

	i = 0;
	while ((var.ret = read(var.fd, &var.str, BUFF_SIZE)) >= 20)
	{
		if (check_final(var.str) != 0)
			ft_error("FILE NOT VALID");
		if (var.ret == 20)
			var.flag = 1;
		else if (var.str[20] != '\n')
			ft_error("FILE NOT VALID");
		var.str[20] = '\0';
		var.tab_tetri[var.piece_nb] = str_to_tab(var.str);
		/*ft_put_triple_tab(var.tab_tetri);
		ft_putstr("\n\n\n\n\n\n\n");
		move_tetri(var.tab_tetri[var.piece_nb]);
		ft_put_triple_tab(var.tab_tetri);
		*///ft_replace_char(var.tab_tetri[var.piece_nb], '#',var.dest);
		var.piece_nb++;
		var.dest++;
	}
	while (i < var.piece_nb)
	{
		var.tab_tetri[i] = move_tetri(var.tab_tetri[i]);
		i++;
	}
	ft_nouveau_placement(var.tab_tetri);
	ft_flag_err(var.flag, var.ret);
	ft_close(var.fd);
	return (0);
}
