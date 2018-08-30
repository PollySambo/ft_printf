/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_and_ulltoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:36:57 by psambo            #+#    #+#             */
/*   Updated: 2018/08/03 16:10:37 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

long int	ft_atoi(char *s)
{
	long int	nb;
	int			i;

	i = 0;
	nb = 0;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	s[i] == '-' || s[i] == '+' ? i++ : i;
	while (s[i] > 47 && s[i] < 58)
	{
		nb *= 10;
		nb += s[i++] - 48;
	}
	nb = s[0] == '-' ? nb * -1 : nb;
	return (nb);
}

void		ucount(unsigned long long int nb, int *size)
{
	while (nb != 0)
	{
		*size += 1;
		nb /= 10;
	}
}

char		*ft_ulltoa(unsigned long long int nb)
{
	char	*str;
	int		size;

	size = 0;
	ucount(nb, &size);
	str = (char *)malloc(size);
	str[size--] = '\0';
	while (size > -1)
	{
		str[size--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
