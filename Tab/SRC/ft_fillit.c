#include "../Includes/fillit.h"

int ft_fillit(char **argv)
{
	t_var	var;
	var.flag = 0;
	var.piece_nb = 0;
	var.fd = open(argv[1], O_RDONLY);
	ft_open(var.fd);

	while ((var.ret = read(var.fd, &var.str, BUFF_SIZE)) >= 20)
	{
		if (check_final(var.str) != 0)
			ft_error("FILE NOT VALID");
		if (var.ret == 20)
			var.flag = 1;
		else if (var.str[20] != '\n')
			ft_error("FILE NOT VALID");
		var.str[20] = '\0';
		var.tab_tetri[var.piece_nb] = str_to_tab(var.str);
		var.piece_nb++;
	}
	ft_flag_err(var.flag, var.ret);
	
	get_coord(var.tab_tetri, var.piece_nb);
	//print_tab(var.tab_tetri, var.piece_nb);
	ft_close(var.fd);
	return (0);
}
