#include "../Includes/fillit.h"

void	print_tab(char ***tab_tetri,int piece)
{
	int i;
	int j;
	int k;

	k = 0;
	while (k <= piece - 1)
	{
		j = 0;
		while (j < 4)
		{
			i = 0;
			while (i < 5)
			{
				ft_putchar(tab_tetri[k][j][i]);
				i++;
			}
			j++;
		}
		k++;
	}
}


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
