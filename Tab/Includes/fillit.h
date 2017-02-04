/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:21:55 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/02 08:23:28 by yarypert         ###   ########.fr       */
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
	int		flag;
	int		index;
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
void		ft_placement(int nbpiece, t_tetri *list);
void		print_list(t_tetri *start);

int			check_place(t_tetri list, char *grid);
int			check_char(char *str);
int			check_links(char *str);
int			check_lines(char *str);
int			check_final(char *str);
int			ft_read(char **argv);

t_tetri		*add_to_list(char *str, int piece, int letter);
t_tetri		*get_coord(t_tetri	*list, t_var *var);

char		*grid_1_up(int piece);
char		*create_grid(int piece);
char		*place_tetri(t_tetri list, char *grid);
char		*ft_replace_char(char *s, char find,char repl);

#endif
