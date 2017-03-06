#include "fillit.h"

int main(int argc, char **argv)
{
	char	*tetris;
	char	*solved;
	char	**test;
	int i = 0;

	if (argc == 2)
	{
		tetris = read_tetri(argv[1]);//je lis le fichier
		test = str_to_tab(tetris);//je coupe le str de tous les tetris en char ** contenant chaque tetri dous la forme de char*
		test = move_all_tetri(test, (count_piece(ft_strlen(tetris) - 1)));
		solved = solve(test);// je resous
		ft_putstr(solved);//je print le resultat
		return(0);
	}
	else
		ft_error("usage: ./fillit <test_file>");
	return 0;
}
