#include "ft_printf.h"

void    ft_parseflags1(t_conv *fl, int widhlen, intmax_t arg, int *ret, char *value)
{
    if((fl->flags.plus == TRUE && fl->flags.minus == FALSE )||
       arg < 0) {
        arg > -1 ? pf_write("+", 1, 1) : pf_write("-", 1, 1);
        fl->width--;
        *ret += 1;
    }
    if(arg == 0 )
    {
        if(fl->dot == TRUE && fl->precision <= 0)
            return;
    }
    fl->flags.minus != FALSE?write_precision(fl, widhlen, ret, arg):0;
    fl->flags.minus != FALSE?ft_putstr(value):0;
    fl->flags.minus != FALSE? *ret += widhlen:0;
    fl->flags.plus == TRUE && fl->flags.zeros == TRUE?write_zero_blank(fl,ret,arg, widhlen):0;
    fl->flags.plus == FALSE && fl->precision > widhlen?write_zero_blank(fl, ret, arg, widhlen):0;
    fl->flags.zeros == TRUE && fl->flags.plus == FALSE?write_zero_blank(fl, ret, arg, widhlen):0;
    fl->flags.zeros == TRUE && fl->flags.minus == FALSE && fl->precision>0?pf_write("0",1,fl->precision):0;
    fl->flags.zeros == TRUE && fl->flags.minus == FALSE && fl->precision>0?*ret += fl->precision:0;
    if(fl->precision == 0 && arg == 0 && fl->width == 0)
    {
        write_precision(fl,widhlen, ret, arg);
        ft_putstr(value);
        *ret += widhlen;
        return ;
    }
    fl->width > fl->precision && widhlen > fl->width?write_precision(fl,widhlen,ret, arg):0;
    (fl->width <= 0 && fl->precision > 0 && fl->flags.minus == FALSE) > 0? write_precision(fl,widhlen,ret,arg): 0;
    (fl->flags.plus == FALSE && fl->precision < widhlen)?write_precision(fl,widhlen, ret, arg):0;
    if (fl->flags.minus == FALSE)
    {
        ft_putstr(value);
        *ret += widhlen;
    }
    else
    {
        if(widhlen <= fl->width) {
            pf_write(" ", 1, fl->width);
            *ret += fl->width;
        }
    }
}


void ft_parseflags(t_conv * fl, int widhlen, intmax_t arg, int *ret, char *value) {
    if (fl->flags.blank == TRUE && fl->flags.plus == FALSE) {
        arg >= 0 ? ft_putchar(' ') : 0;
        arg >= 0 ? *ret += 1 : 0;
    }
    fl->flags.blank == TRUE && fl->dot == FALSE? fl->width-- : 0;
    fl->flags.plus == TRUE && fl->flags.minus == TRUE && arg > -1 ? pf_write("+", 1, 1) : 0;
    fl->flags.plus == TRUE && fl->flags.minus == TRUE ? *ret += 1 : 0;
    if ((fl->flags.zeros == FALSE && fl->flags.minus == FALSE && fl->width > 0) ||
        (fl->flags.minus == FALSE && fl->precision > 0 && fl->width > 0))
        if(fl->precision <= fl->width) {
            if (arg == 0) {
                pf_write(" ", 1, fl->width+1);
                *ret += fl->width+1;
            } else {
                (arg < 0 || fl->flags.plus == TRUE) ?
                pf_write(" ", 1, fl->width - 1 - fl->precision) : pf_write(" ", 1, fl->width - fl->precision);
                *ret += (arg < 0 || fl->flags.plus == TRUE) ? fl->width - 1 - fl->precision : fl->width - fl->precision;
            }
        }
    if (fl->flags.plus == TRUE && fl->flags.zeros == TRUE && fl ->width < fl->precision) {
        pf_write(" ", 1, fl->width);
        *ret += fl->width;
    }
    ft_parseflags1(fl,widhlen,arg,ret,value);
}

void ft_parsewidth(t_conv *fl, int widhlen) {
    if (fl->width == 0 && fl->precision > 0)
    {
        if (fl->precision - widhlen)
            return;
    }
    if (fl->precision > widhlen) {
        if (fl->width < fl->precision)
            fl->width = 0;
//        else {
//            fl->width = fl->width - widhlen - (fl->precision - widhlen);
//            fl->precision = fl->precision - widhlen;
//        }
    }
    else if (fl->precision <= widhlen) {
        if (widhlen <= fl->width)
            fl->width = fl->width - widhlen;
        else
            fl->width = 0;
        fl->precision = 0;
    }
}

int ft_numbers(t_conv *fl, va_list *arg_ptr)
{
    intmax_t   arg;
    intmax_t   narg;
    int     len;
    int     ret;
    char    *value;

    ret = 0;
    len = 0;
    arg = ft_parse_sign(fl, arg_ptr);
    narg = (arg < 0)?arg* -1: arg*1;
    value = ft_itoa_base(narg,10,0);
    len += ft_strlen(value);
    ft_parsewidth(fl, len);
    ft_parseflags(fl, len, arg, &ret, value);
    free(value);
    return(ret);
}