//
// Created by Igor VOLOSHIN on 5/11/18.
//
#include "../inc/ft_printf.h"

void print_unsigned1(t_conv *fl, size_t len, int *ret, char *value)
{
    if (fl->flags.minus == FALSE)
    {
        if(fl->flags.zeros == FALSE || (fl->dot == TRUE && fl->width > 0)) {
            fl->width -= (fl->width != 0 && fl->dot == TRUE && fl->precision != 0) ? 2 : 0;
            pf_write(" ", 1, fl->width);
            ft_putstr("0x");
        }else {
            ft_putstr("0x");
            fl->dot == 0 ? pf_write("0", 1, fl->width) : 0;
        }
            *ret += fl->width;
    }
    else
        ft_putstr("0x");
        write_precision(fl, (int)len, ret, ft_atoi(value));
    if (*value == '0') {
        if(fl->dot == TRUE && fl->precision <= 0)
            return;
        *value == '0' && fl->precision >= 0 ? ft_putstr(value) : 0;
        *ret += (*value == '0' && fl->precision >= 0) ? (ft_strlen(value)) : 0;
//        *value == '0' && fl->precision == 0 && fl->width < len ? ft_putstr(value) : 0;
//        *ret += (*value == '0' && fl->precision == 0 && fl->width < len) ? (ft_strlen(value)) : 0;
    }
    else {
        ft_putstr(value);
        *ret += ft_strlen(value);
    }
        if (fl->flags.minus == TRUE)
    {
        pf_write(" ", 1, fl->width);
        *ret += fl->width;
    }
}

void manage_unlen1(t_conv *fl, int len, int *ret, char *value)
{
    fl->precision > fl->width? fl->width = 0:0;
    fl->precision<len-2? fl->precision = 0:0;
    if(fl->width >= len){
        if (fl->dot == TRUE && fl->precision > 0)
            fl->width -= fl->precision;
        else
            fl->width -= len;
    }
    else
        fl->width = 0;
    fl->precision > 0?fl->precision += 2:0;
}

int     ft_point(t_conv *fl, va_list *arg_ptr, int base)
{
    char *value;
    int ret;
    size_t len;
    uintmax_t numb;

    ret = 0;
    numb = va_arg(*arg_ptr, uintmax_t);
    value = ft_itoa_base(numb, base, 0);
    len = ft_strlen(value);
    len +=2;
    manage_unlen1(fl, len, &ret, value);
    print_unsigned1(fl, len, &ret, value);
    free(value);
    return (ret+2);
}