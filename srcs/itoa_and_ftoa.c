/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_and_ftoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 06:55:39 by psambo            #+#    #+#             */
/*   Updated: 2018/08/03 17:01:12 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	count(long long int n, unsigned int *size)
{
	while (n != 0)
	{
		*size += 1;
		n /= 10;
	}
}

void	fill_table(int if_neg, long long int n, char *tab, int size)
{
	tab += size;
	*tab-- = '\0';
	if (n == LL_MIN)
	{
		*tab-- = '8';
		n /= 10;
		size--;
	}
	if (n > LL_MAX)
	{
		n = LL_MIN + (n - LL_MIN) - 1;
		if_neg = 1;
	}
	else
		n = (if_neg == 1 ? n - n - n : n);
	while (size-- > 0)
	{
		if ((if_neg == 1) && (size == 0))
			*tab = '-';
		else
			*tab-- = n % 10 + 48;
		n /= 10;
	}
}

char	*ft_itoa(long long int n)
{
	unsigned int	size;
	char			*tab;
	int				if_neg;

	if_neg = (n < 0 ? 1 : 0);
	size = (n < 0 ? 1 : 0);
	count(n, &size);
	size = (n == 0 ? 1 : size);
	if (!(tab = (char *)malloc(size + 1)))
		return ((char *)'\0');
	fill_table(if_neg, n, tab, size);
	return (tab);
}

void	create_string(double nb, char *rest, int i)
{
	int		afterdots;
	int		dot;

	dot = 0;
	afterdots = 0;
	if (nb < 1)
	{
		rest[i++] = '.';
		dot = i;
		while (afterdots < 6)
		{
			nb *= 10;
			if (((int)(nb + 0.000001)) != 10)
				rest[i++] = (int)(nb + 48 + 0.000001);
			nb -= (int)nb;
			afterdots++;
		}
	}
	while (i - dot < 6)
		rest[i++] = '0';
	rest[i] = '\0';
}

char	*ft_ftoa(double n)
{
	char		*flt;
	char		*first;
	long int	nb;
	int			i;

	i = -1;
	nb = (long int)n;
	first = ft_itoa(nb);
	flt = (char *)malloc(100);
	n -= (double)nb;
	if (n < 0)
		n *= -1;
	while (first[++i])
		flt[i] = first[i];
	create_string(n, flt, i);
	free(first);
	return (flt);
}
