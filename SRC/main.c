/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:39:56 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/07 14:40:11 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*tetris;
	char	*solved;
	char	**test;

	if (argc == 2)
	{
		tetris = read_tetri(argv[1]);
		test = str_to_tab(tetris);
		test = move_all_tetri(test, (count_piece(ft_strlen(tetris) - 1)));
		solved = solve(test);
		ft_putstr(solved);
		return (0);
	}
	else
		ft_error("usage: ./fillit <test_file>");
	return (0);
}
