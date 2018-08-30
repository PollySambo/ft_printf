/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 06:46:29 by psambo            #+#    #+#             */
/*   Updated: 2018/08/03 17:07:05 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_format(char x)
{
	write(1, &x, 1);
}

void	print(int start, int end, char *format)
{
	while (start < end && format[start] != '\0')
		print_format(format[start++]);
}

void	print_plus(t_flags *bag, long int *nb)
{
	if (PLUS == true && *nb > -1)
		ft_putchar('+', bag);
	if (*nb < 0 && *nb != (LL_MIN))
	{
		ft_putchar('-', bag);
		*nb *= -1;
	}
	PLUS = false;
}

void	print_hash(t_flags *bag, unsigned long long int nb)
{
	if ((TYPE == 'x' || TYPE == 'X') && HASH == true && nb != 0)
		(TYPE == 'x') ? ft_putstr("0x", bag) : ft_putstr("0X", bag);
	if ((TYPE == 'o' || TYPE == 'O') && HASH == true && PRECISION - LEN < 0)
		ft_putstr("0", bag);
	if (TYPE == 'p' && HASH == true)
		ft_putstr("0x", bag);
	HASH = false;
}

void	print_perc(t_flags *bag)
{
	int	width;

	width = 0;
	while (MINUS == false && width++ < WIDTH - 1)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
	if (bag->type != -1)
		ft_putchar('%', bag);
	while (width++ < WIDTH - 1)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
}
