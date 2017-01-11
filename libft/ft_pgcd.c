/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:35:06 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/18 14:45:25 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pgcd(int n1, int n2)
{
	int		k;
	int		div;

	k = 2;
	div = 1;
	while (n1 >= k || n2 >= k)
	{
		if (n1 % k == 0 && n2 % k == 0)
			div = k;
		k++;
	}
	return (div);
}
