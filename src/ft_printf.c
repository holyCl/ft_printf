/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:28:46 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/21 14:33:47 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_printf(char *format, ...)
{
	va_list	arg_ptr;
	int		step;
	char	*str;

	str = ft_strdup(format);
	step = 0;
	va_start(arg_ptr, format);
	while (*str)
	{
		if (*str == '%')
		{
			str += ft_reading(&str, &arg_ptr, &step);
			if (!(*str))
				break ;
		}
		else if (*str)
		{
			ft_putchar(*str);
			step++;
			str++;
		}
	}
	va_end(arg_ptr);
	return (step);
}

//int main(void)
//{
//    ft_printf("%-5d",43);
//}
