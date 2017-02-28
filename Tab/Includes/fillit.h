/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:21:55 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/28 13:26:02 by jorobin          ###   ########.fr       */
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

typedef	struct	s_var
{
	int		fd;
	int		ret;
	int		flag;
	int		piece_nb;
	char	str[BUFF_SIZE];
	char	**tab_tetri[26];
	char	dest;
}				t_var;

int			find_x_min(char **tab_tetri);
int			find_y_min(char **tab_tetri);
int			check_char(char *str);
int			check_links(char *str);
int			check_lines(char *str);
int			check_final(char *str);
int			ft_fillit(char **argv);

char		**move_tetri(char **tab_tetri);
char		**grid_1_up(int piece, int n);
char		**create_grid(int piece);
char		**str_to_tab(char *str);
char		**grid_to_tab(char *str);
char		**ft_replace_char(char **s, int numtetri);

void		ft_print_int_tab(int **coord, int piece_nb);
void		print_2dim_tab(char **tab_tetri);
void		print_tab(char ***tab_tetri,int piece_nb);
void		ft_error(char *str);
void		ft_close(int fd);
void		ft_open(int fd);
void		ft_flag_err(int flag, int ret);
void		ft_putdoubletab(char **tab_tetri);

#endif
