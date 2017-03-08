/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:21:55 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/08 12:42:13 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft//libft.h"
# define BUFF_SIZE 21

typedef struct	s_xymin
{
	int		xmin;
	int		ymin;
	int		i;
	int		j;
	int		count;
}				t_xymin;

typedef struct	s_decal
{
	int		i;
	int		j;
	int		taille;
	int		flag;
	int		count;
	char	*tetri_next;
}				t_decal;

char			**str_to_tab(char *str);
char			**str_to_tab_2(int len, char *str, char **tab);
char			**move_all_tetri(char **tab, int piece_nb);

char			*ft_strappend(char *str1, char *str2);
char			*read_tetri(char *file);
char			*ft_tetri_decal(char *t_before);
char			*ymin_diff_zero(char *tetri, int i, int ymin);
char			*xmin_diff_zero(char *tetri, int i, int xmin);
char			*move_tetri_char(char *tab_tetri);
char			*solve(char **pieces);
char			*best_position(char *result, char **pieces, int i, int size);
char			*remove_piece(char *result, char c);
char			*place_pieces(char *result, char *piece, int i_res, int size);
char			*create_grid(int size);
char			*ft_replace_char(char *str, char c);

int				count_piece(int len);
int				find_len(char *str, t_decal *td);
int				find_x_min_char(char *tab_tetri);
int				find_y_min_char(char *tab_tetri);
int				check_char(char *str);
int				check_links(char *str);
int				check_lines(char *str);
int				check_final(char **str, int piece_nb);
int				can_be_placed(char *result, int i_res, char *piece, int size);
int				size_min(char **pieces);

void			is_diese(t_decal *td, char *tetri_before);
void			flag_zero(t_decal *td);
void			ft_error(char *str);
void			freeall(char *file, char **pieces, int i);
void			find_len_2(char *str, t_decal *td);
void			ft_tetri_decal_2(char *tetri_before, t_decal *td);

#endif
