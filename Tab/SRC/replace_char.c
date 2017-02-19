/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 04:47:58 by yarypert          #+#    #+#             */
/*   Updated: 2017/02/02 06:08:25 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char **ft_replace_char(char **s, char find, char repl)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
		if (s[i][j] == find)
			s[i][j] = repl;
		j++;
		}
	i++;
	}
	ft_putdoubletab(s);
	return (s);
}
/*
int main(int argc, const char *argv[])
{
	char *test;
	char **tmp;

	tmp = NULL;
	test = (char *)malloc(sizeof(char) * 24 + 1);
	test = "....\ni....\ni.##.\ni.##.\ni\0";
	tmp = ft_strsplit(test, 'i');
	
	ft_replace_char(tmp, '#', 'A');
	return 0;
}
*/
