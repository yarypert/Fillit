/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:21:55 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/14 20:14:38 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# define BUF_SIZE 21

typedef struct		s_tetri
{
	char *tetri;
	int x;
	int y;
	struct s_tetri *next;
}					t_tetri;

int		check_char(char *str);
int		check_links(char *str);
int		check_lines(char *str);
int		check_final(char *str);
void	print_list(t_tetri *start);
t_tetri	*add_to_list(char *str);

#endif
