/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:15:21 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/13 17:17:43 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char	**str_to_tab(char *str)
{
	//char	*tab[26];
	char	**tab;
	char	**tmp;
	int i;
	int j;
	int start;
	int len;

	j = 0;
	i = 0;
	len = ft_strlen(str);
	tab = (char **)malloc(sizeof(char *) * (count_piece(len)));
	while (j < count_piece(len))
	{
		tab[j] = (char *)malloc(sizeof(char) * 20);
		j++;
	}
	start = 0;
	
	if (len > 545 || len == 0)
		ft_error("error_len");
	while (start < len)
	{
		tab[i] = ft_strsub(str,start,20);
		i++;
		start = start + 21;
	}
	if (check_final(tab,i) != 0)
		ft_error("error_check");
	if (start - 1 > len)
		ft_error("error_len2");
	//tmp =tab;
	//return(tmp);
	return(tab);
}
