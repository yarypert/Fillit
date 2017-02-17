#include "../Includes/fillit.h"

void	print_2dim_tab(char **tab_tetri)
{
	int i;
	int j;


	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 5)
		{
			ft_putchar(tab_tetri[j][i]);
			i++;
		}
		j++;
	}
}

void	ft_putdoubletab(char **tab_tetri)
{
	int t1;
	int t2;

	t1 = 0;
	t2 = 0;
	while (tab_tetri[t1] != NULL)
	{
		while (tab_tetri[t1][t2] != '\n')
		{
			ft_putchar(tab_tetri[t1][t2]);
			t2++;
		}
			ft_putchar(tab_tetri[t1][t2]);
		t2 = 0;
		t1++;
	}
}
