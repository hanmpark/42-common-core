/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:03:35 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/16 12:14:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*count_malloc(int n, int nbr, int  count)
{
	char	*a;

	count = 0;
	nbr = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n / nbr * 10)
	{
		nbr *= 10;
		count++;
	}
	a = malloc((count + 1) * sizeof(char));
	if (!a)
		return (0);
	return (a);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		nbr;
	int		count;
	int		i;
	
	if (!(n >= -2147483647 && n <= 2147483647))
		return (0);
	i = 0;
	a = count_malloc(n, nbr, count);
	if (n < 0)
	{
		a[i] = '-';
		i++;
	}
	while (count-- && nbr)
	{
		a[i] = n / nbr + '0';
		n %= nbr;
		nbr /= 10;
		i++;
	}
	a[i] = 0;
	return (a);
}
#include <stdio.h>
int	main()
{
	int	n = -19999992;

	printf("%s\n", ft_itoa(n));
	return (0);
}