#ifndef FILLIT_H
# define FILLIT_H

int		check_char(char *str);
int		check_links(char *str);
int		check_lines(char *str);
int		check_final(char *str);

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

# define BUF_SIZE 21

#endif
