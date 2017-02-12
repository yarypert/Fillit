#include "../Includes/fillit.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		ft_error("CAN'T CLOSE FILE");
}

void	ft_open(int fd)
{
	if (fd == -1)
		ft_error("CAN'T OPEN FILE");

}

void	ft_flag_err(int flag, int ret)
{
	if (flag != 1 || ret != 0)
		ft_error("FLAG ERROR");
}
