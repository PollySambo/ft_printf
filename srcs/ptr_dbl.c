/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_dbl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:28:17 by psambo            #+#    #+#             */
/*   Updated: 2018/08/03 17:02:13 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	parse_ptr(t_flags *bag)
{
	DISPLAY = (IF_PREC == true && PRECISION == 0) ? false : true;
	HASH = true;
	if (PRECISION < 0)
	{
		MINUS = true;
		WIDTH = PRECISION * -1;
	}
	PRECISION -= LEN;
	WIDTH -= (PRECISION > 0) ? (PRECISION + LEN + 2) : (LEN + 2);
	ZERO = (IF_PREC == true) ? false : ZERO;
}

void	print_pointer(t_flags *bag, va_list ap)
{
	unsigned long long int	nb;
	char					*print;

	nb = va_arg(ap, unsigned long long int);
	print = convert(bag, nb);
	LEN = ft_strlen(print);
	parse_ptr(bag);
	if (ZERO == true)
		print_hash(bag, nb);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
	print_hash(bag, nb);
	while (PRECISION-- > 0)
		ft_putchar('0', bag);
	if (DISPLAY == true)
		ft_putstr(print, bag);
	while (WIDTH-- > 0)
		ft_putchar(' ', bag);
	free(print);
}

char	*round_up(char *print)
{
	int	i;
	int nb;

	i = 0;
	nb = ft_atoi(print);
	while (print[i++] != '.')
		;
	print[i] > '4' ? nb++ : nb;
	free(print);
	print = ft_itoa(nb);
	return (print);
}

char	*parse_flt(t_flags *bag, char *print)
{
	print = (PRECISION < 1 && IF_PREC == true) ? round_up(print) : print;
	WIDTH = PRECISION < 0 ? PRECISION * -1 : WIDTH;
	IF_PREC == true && PRECISION != 0 ? PRECISION++ : PRECISION;
	PRECISION = IF_PREC == false ? 7 : PRECISION;
	LEN = PRECISION < 0 ? LEN - 7 : LEN - 7 + PRECISION;
	MINUS = PRECISION < 0 ? true : MINUS;
	WIDTH -= LEN;
	SPACE == true && WIDTH < 1 ? WIDTH = 1 : WIDTH;
	PLUS == true ? WIDTH-- : WIDTH;
	return (print);
}

void	print_float(t_flags *bag, va_list ap)
{
	double	nb;
	char	*print;
	int		i;

	i = 1;
	nb = va_arg(ap, double);
	print = ft_ftoa(nb);
	LEN = ft_strlen(print);
	print = parse_flt(bag, print);
	nb < 0 ? WIDTH++ : i--;
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
	print_plus(bag, (long int *)&nb);
	while (print[i] != '.' && print[i] != '\0')
		ft_putchar(print[i++], bag);
	while (PRECISION-- > 0)
		ft_putchar(print[i++], bag);
	while (WIDTH-- > 0)
		ft_putchar(' ', bag);
	free(print);
}
