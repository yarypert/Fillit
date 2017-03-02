#include "../Includes/fillit.h"

int main(int argc, char **argv)
{
	char	*tetris;
	char	*solved;
	char	**test;
	int i = 0;

	ft_putendl("entre dans le main");
	if (argc == 2)
	{
		tetris = read_tetri(argv[1]);//je lis le fichier
		test = str_to_tab(tetris);//je coupe le str de tous les tetris en char ** contenant chaque tetri dous la forme de char*
		/*while (i <= (count_piece(ft_strlen(tetris))))
		{
			ft_putendl(test[i]);
			i++;
		}*/
		ft_putendl("appel de la fonction move_all_tetri");
		test = move_all_tetri(test, count_piece(ft_strlen(tetris)));// je les move en utilisant ta fonction et je cnage le charactere.
		ft_putendl("appel de la fonction solve");
		solved = solve(test);// je resous
		ft_putendl("TABLEAU FINAL !");
		ft_putstr(solved);//je print le resultat
		return(0);
	}
	else
		ft_error("error_argument");
	return 0;
}
