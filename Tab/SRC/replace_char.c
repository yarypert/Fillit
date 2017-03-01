/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 04:47:58 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/28 13:31:54 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char **ft_replace_char(char **s, int numtetri)
{
	int i;
	int j;
	char alph;

	i = 0;
	alph = 'A';
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
		if (s[i][j] == '#')
			s[i][j] = alph + numtetri;
		j++;
		}
	printf("%s", s[i]);
	i++;
	}
	return (s);
}
/*
int main(void)
{
	char *test;
	char **tmp;
	int i;

	i = 1;
	tmp = NULL;
	test = (char *)malloc(sizeof(char) * 24 + 1);
	test = "....\ni....\ni.##.\ni.##.\ni\0";
	tmp = ft_strsplit(test, 'i');
	ft_replace_char(tmp, i);
	return 0;
}
*/
