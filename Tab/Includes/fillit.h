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

typedef	struct	s_var
{
	int		fd;
	int		ret;
	int		flag;
	int		piece_nb;
	char	str[BUFF_SIZE];
	int		coord[8];
	char	**tab_tetri[26];
}				t_var;

int			check_char(char *str);
int			check_links(char *str);
int			check_lines(char *str);
int			check_final(char *str);
int			ft_fillit(char **argv);
void		get_coord(char ***tetri, int piece_nb);

char		**grid_1_up(int piece);
char		**create_grid(int piece);
char		**str_to_tab(char *str);

void		ft_print_int_tab(int **coord, int piece_nb);
void		print_tab(char ***tab_tetri,int piece_nb);
void		ft_error(char *str);
void		ft_close(int fd);
void		ft_open(int fd);
void		ft_flag_err(int flag, int ret);

#endif
