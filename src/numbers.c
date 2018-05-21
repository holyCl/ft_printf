/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:14:37 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/21 15:52:04 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_pf2(t_conv *fl, int widhlen, intmax_t arg, int *ret, char *value)
{
	if (fl->precision == 0 && arg == 0 && fl->width == 0)
	{
		write_precision(fl, widhlen, ret, arg);
		ft_putstr(value);
		*ret += widhlen;
		return ;
	}
	fl->width >= fl->precision && widhlen > fl->width ? \
	write_precision(fl, widhlen, ret, arg) : 0;
	(fl->width <= 0 && fl->precision > 0 && fl->flags.minus == FALSE) > 0 ? \
	write_precision(fl, widhlen, ret, arg) : 0;
	(fl->flags.plus == FALSE && fl->precision < widhlen) ? \
	write_precision(fl, widhlen, ret, arg) : 0;
	if (fl->flags.minus == FALSE)
	{
		ft_putstr(value);
		*ret += widhlen;
	}
	else
	{
		if (widhlen <= fl->width && fl->flags.plus != TRUE)
		{
			pf_write(" ", 1, fl->width - fl->temp);
			*ret += fl->width - fl->temp;
		}
	}
}

void		ft_pf1(t_conv *fl, int widhlen, intmax_t arg, int *ret, char *value)
{
	if ((fl->flags.plus == TRUE && fl->flags.minus == FALSE) || \
	arg < 0)
	{
		arg > -1 ? pf_write("+", 1, 1) : pf_write("-", 1, 1);
		fl->width--;
		*ret += 1;
	}
	if (arg == 0)
	{
		if (fl->dot == TRUE && fl->precision <= 0)
			return ;
	}
	fl->flags.minus == TRUE ? write_precision(fl, widhlen, ret, arg) : 0;
	fl->flags.minus == TRUE ? ft_putstr(value) : 0;
	fl->flags.minus == TRUE ? *ret += widhlen : 0;
	fl->flags.plus == TRUE && fl->flags.zeros == TRUE ? \
	write_zero_blank(fl, ret, arg, widhlen) : 0;
	fl->flags.plus == TRUE && fl->flags.zeros == FALSE ? \
	write_zero_blank(fl, ret, arg, widhlen) : 0;
	fl->flags.plus == FALSE && fl->flags.zeros == FALSE && fl->precision > \
	widhlen ? write_zero_blank(fl, ret, arg, widhlen) : 0;
	fl->flags.zeros == TRUE && fl->flags.plus == FALSE ? \
	write_zero_blank(fl, ret, arg, widhlen) : 0;
	fl->flags.zeros == TRUE && fl->flags.minus == FALSE \
	&& fl->precision < fl->width && widhlen <= fl->precision
	? pf_write("0", 1, fl->precision - widhlen) : 0;
	fl->flags.zeros == TRUE && fl->flags.minus == FALSE \
	&& fl->precision < fl->width && widhlen <= fl->precision
	? *ret += fl->precision - widhlen : 0;
	ft_pf2(fl, widhlen, arg, ret, value);
}

void		check(t_conv *fl, intmax_t arg, int *ret, int widhlen)
{
	if ((fl->flags.zeros == FALSE && fl->flags.minus == FALSE && fl->width > \
	0) || (fl->flags.minus == FALSE && fl->precision > 0 && fl->width > 0))
		if (fl->precision <= fl->width)
		{
			if (arg == 0 && fl->precision > 0)
			{
				pf_write(" ", 1, fl->width - fl->temp);
				*ret += fl->width - fl->temp;
			}
			else if (arg == 0 && fl->precision == FALSE)
			{
				pf_write(" ", 1, fl->width + 1);
				*ret += fl->width + 1;
			}
			else if (fl->precision > widhlen)
			{
				pf_write(" ", 1, fl->width - fl->precision);
				*ret += fl->width - fl->precision;
				fl->temp = fl->precision;
			}
			else
			{
				fl->flags.plus == TRUE ? \
				pf_write(" ", 1, fl->width - 1) : pf_write(" ", 1, fl->width);
				*ret += (fl->flags.plus == TRUE) ? fl->width - 1 : fl->width;
			}
		}
}

void		ft_pf(t_conv *fl, int widhlen, intmax_t arg, int *ret, char *value)
{
	if (fl->flags.blank == TRUE && fl->flags.plus == FALSE)
	{
		arg >= 0 ? ft_putchar(' ') : 0;
		arg >= 0 ? *ret += 1 : 0;
	}
	(fl->flags.blank == TRUE || arg < 0 || fl->flags.plus == TRUE) \
	&& fl->width > 1 ? fl->width-- : 0;
	fl->flags.plus == TRUE && fl->flags.minus == TRUE && arg > -1 ? \
	pf_write("+", 1, 1) : 0;
	fl->flags.plus == TRUE && fl->flags.minus == TRUE ? *ret += 1 : 0;
	check(fl, arg, ret, widhlen);
	if (fl->flags.zeros == TRUE && fl->dot == TRUE && \
	fl->precision == FALSE && fl->width > 0)
	{
		pf_write(" ", 1, fl->width);
		*ret += fl->width;
	}
	if (fl->flags.plus == TRUE && fl->flags.zeros == TRUE \
	&& fl->width < fl->precision)
	{
		pf_write(" ", 1, fl->width);
		*ret += fl->width;
	}
	ft_pf1(fl, widhlen, arg, ret, value);
}

void		ft_parsewidth_numb(t_conv *fl, int widhlen)
{
	if (fl->width == 0 && fl->precision > 0)
	{
		if (fl->precision - widhlen)
			return ;
	}
	if (fl->precision > widhlen)
	{
		fl->temp = fl->precision;
		if (fl->width < fl->precision)
			fl->width = 0;
	}
	else if (fl->precision <= widhlen)
	{
		if (widhlen <= fl->width)
			fl->width = fl->width - widhlen;
		else
			fl->width = 0;
		fl->precision = 0;
	}
}

int			ft_numbers(t_conv *fl, va_list *arg_ptr)
{
	intmax_t	arg;
	intmax_t	narg;
	int			len;
	int			ret;
	char		*value;

	ret = 0;
	len = 0;
	arg = ft_parse_sign(fl, arg_ptr);
	narg = (arg < 0) ? arg * -1 : arg * 1;
	value = ft_itoa_base(narg, 10, 0);
	len += ft_strlen(value);
	ft_parsewidth_numb(fl, len);
	ft_pf(fl, len, arg, &ret, value);
	free(value);
	return (ret);
}
