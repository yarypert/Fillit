#include "../Includes/fillit.h"

char	*solve(char **pieces)
{
	ft_putendl("fonction solve");
	int		size;
	int		i;
	char	*result;

	ft_putendl("fonction size_min");
	size = size_min(pieces);
	ft_putendl("fonction size_min");
	result = NULL;
	while (!result)
	{
		ft_putendl("fonction create_grid");
		result = create_grid(size);
		ft_putendl("fin create_grid");
		if (!result)
			freeall(NULL, pieces, -1);
		ft_putendl("fonction best_position");
		result = best_position(result, pieces, 0, size);
		ft_putendl("fin best_position");
		size++;
	}
	i = 0;
	while (pieces[i])
		ft_memdel((void *)&pieces[i++]);
	ft_memdel((void *)&pieces);
	return (result);
}

int		can_be_placed(char *result, int index_result, char *piece, int size)
{
	int		i;
	int		tmp_index;

	tmp_index = index_result;
	i = 0;
	while (piece[i])
	{
		if (size * (size + 1) < index_result)
			return (0);
		if (ft_isalpha(piece[i]))
		{
			if (result[index_result] != '.')
				return (0);
			index_result++;
		}
		else if (piece[i] == '\n')
		{
			index_result = tmp_index + size + 1;
			tmp_index = index_result;
		}
		else if (piece[i] == ' ')
			index_result++;
		i++;
	}
	return (1);
}

char	*best_position(char *result, char **pieces, int i, int size)
{
	int		y;
	char	*save;

	y = 0;
	save = NULL;
	if (pieces[i] == NULL)
		return (result);
	while (result[y])
	{
		if (result[y] != '\n')
		{
			if (can_be_placed(result, y, pieces[i], size))
			{
				save = best_position(place_pieces(result, pieces[i], y, size),
					pieces, i + 1, size);
				/*if (save != NULL)
				{
					ft_putendl("tableau final");
					ft_putendl(save);
				}*/
			}
			if (save)
				return (save);
			result = remove_piece(result, 'A' + i);
		}
		y++;
	}
	return (NULL);
}

char	*remove_piece(char *result, char c)
{
	int		i;

	i = 0;
	while (result[i])
	{
		if (result[i] == c)
			result[i] = '.';
		i++;
	}
	return (result);
}

char	*place_pieces(char *result, char *piece, int index_result, int size)
{
	int		i;
	int		tmp_index;


	/*ft_putstr("function place_pieces\n result/ \n");
	ft_putendl(result);
	ft_putstr("piece/ \n");
	ft_putendl(piece);
	ft_putnbr(ft_strlen(piece));
	ft_putchar('\n');*/
	tmp_index = index_result;
	i = 0;
	while (piece[i])
	{
		if (ft_isalpha(piece[i]))
		{
			result[index_result] = piece[i];
			index_result++;
		}
		else if (piece[i] == '\n')
		{
			index_result = tmp_index + size + 1;
			tmp_index = index_result;
		}
		else if (piece[i] == ' ')
			index_result++;
		i++;
	}
	return (result);
}
