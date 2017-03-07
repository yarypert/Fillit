/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/07 15:38:21 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**str_to_tab(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	len = ft_strlen(str);
	if (str[len - 2] != '#' && str[len - 2] != '.')
		ft_error("error");
	if (!(tab = (char **)malloc(sizeof(char *) * (count_piece(len)) + 1)))
		return (NULL);
	while (j < count_piece(len))
	{
		if (!(tab[j] = (char *)malloc(sizeof(char) * 20)))
			return (NULL);
		j++;
	}
	tab[j] = NULL;
	if (len > 545 || len == 0)
		ft_error("error");
	tab = str_to_tab_2(len, str, tab);
	return (tab);
}

char	**str_to_tab_2(int len, char *str, char **tab)
{
	int		i;
	int		start;

	start = 0;
	i = 0;
	while (start < len)
	{
		tab[i] = ft_strsub(str, start, 20);
		i++;
		start = start + 21;
	}
	if (check_final(tab, i) != 0)
		ft_error("error");
	if (start - 1 > len)
		ft_error("error");
	return (tab);
}
