/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:52:04 by psambo            #+#    #+#             */
/*   Updated: 2018/08/03 16:55:08 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	bulid_bag(t_flags *bag)
{
	bag->minus = false;
	bag->plus = false;
	bag->space = false;
	bag->hash = false;
	bag->zero = false;
	bag->ifprec = false;
	bag->display = true;
	bag->star = false;
	bag->type = 0;
	bag->width = 0;
	bag->precision = 0;
	bag->argument = 0;
	bag->ret = 0;
	bag->len = 0;
}

void	gather_flags(char *f, int *i, t_flags *bag, va_list ap)
{
	*i += 1;
	while (f[*i] != '\0' && (f[*i] == '.' || f[*i] == '-' || f[*i] == '+' ||
			f[*i] == ' ' || f[*i] == '#' || f[*i] == '0' || f[*i] == '*' ||
			f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'j' || f[*i] == 'z' ||
			f[*i] == 'q' || (f[*i] >= '0' && f[*i] <= '9')))
	{
		flags(f, i, bag);
		width(f, i, bag, ap);
		precision(f, i, bag, ap);
		arguments(f, i, bag);
	}
	type(f[*i], bag);
}

void	print_argument(t_flags *bag, va_list ap)
{
	if (TYPE == '%' || TYPE == -1)
		print_perc(bag);
	else if (TYPE == 'S')
		print_wchar_str(bag, ap);
	else if (TYPE == 's')
		print_string(bag, ap);
	else if ((TYPE == 'c' && ARGUMENT == 3) || (TYPE == 'C' && ARGUMENT == 7))
		print_wchar(bag, ap);
	else if (TYPE == 'c' || TYPE == 'C')
		print_char(bag, ap);
	else if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		print_int(bag, ap);
	else if (TYPE == 'p')
		print_pointer(bag, ap);
	else if (TYPE == 'f' || TYPE == 'F')
		print_float(bag, ap);
	else if (TYPE == 'o' || TYPE == 'O' || TYPE == 'u' || TYPE == 'U' ||
			TYPE == 'x' || TYPE == 'X' || TYPE == 'b')
		print_unsigned_int(bag, ap);
}

int		solve(char *format, va_list ap)
{
	int		i;
	int		ret;
	int		start;
	t_flags bag;

	i = 0;
	start = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			print(start, i, format);
			ret += i - start;
			bulid_bag(&bag);
			gather_flags(format, &i, &bag, ap);
			bag.type == 0 || bag.type == -1 ? i : i++;
			print_argument(&bag, ap);
			ret += bag.ret;
			start = i;
		}
		format[i] != '\0' && format[i] != '%' ? i++ : i;
	}
	print(start, i, format);
	return (ret + i - start);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = solve((char *)format, ap);
	va_end(ap);
	return (ret);
}
