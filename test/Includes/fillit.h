/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:21:55 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/24 16:52:28 by jorobin          ###   ########.fr       */
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

char	**str_to_tab(char *str);
char	**move_all_tetri(char **tab, int piece_nb);
char	*ft_strappend(char *str1,char *str2);
char	*read_tetri(char *file);
char	*ft_tetri_decal(char *tetri_before);
char	*ymin_diff_zero(char *tetri, int i, int ymin);
char	*xmin_diff_zero(char *tetri, int i, int xmin);
char	*move_tetri_char(char *tab_tetri);
char	*solve(char **pieces);
char	*best_position(char *result, char **pieces, int i, int size);
char	*remove_piece(char *result, char c);
char	*place_pieces(char *result, char *piece, int index_result,int size);
char	*create_grid(int size);
char	*ft_replace_char(char *str, char c);

int		count_piece(int len);
int		find_len(char *str);
int		find_x_min_char(char *tab_tetri);
int		find_y_min_char(char *tab_tetri);
int		check_char(char *str);
int		check_links(char *str);
int		check_lines(char *str);
int		check_final(char **str, int piece_nb);
int		can_be_placed(char *result, int index_result, char *piece, int size);
int		size_min(char **pieces);

void	ft_error(char *str);
void	freeall(char *file, char **pieces, int i);

#endif
