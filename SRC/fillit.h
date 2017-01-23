/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:21:55 by yarypert          #+#    #+#             */
/*   Updated: 2017/01/23 14:05:52 by jorobin          ###   ########.fr       */
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
# define BUFF_SIZE 21

typedef struct		s_tetri
{
	char *tetri;
	int  coord[8];
	struct s_tetri *next;
}					t_tetri;

typedef struct		s_var
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		xmin;
	int		ymin;
}					t_var;

void		ft_adjust(int xmin, int ymin, t_tetri *list);
int			check_char(char *str);
int			check_links(char *str);
int			check_lines(char *str);
int			check_final(char *str);
void		print_list(t_tetri *start);
t_tetri		*add_to_list(char *str);
char		*create_grid(int piece);

#endif
