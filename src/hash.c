//
// Created by Igor VOLOSHIN on 5/12/18.
//

#include "../inc/ft_printf.h"

void print_hash(t_conv *fl, size_t len, int *ret, char *value)
{
    if (fl->flags.minus == FALSE)
    {
        if (fl->flags.zeros == TRUE)
        {
            fl->precision == 0 && *value != '0'? ft_putchar('0'):0;
            fl->precision == 0 && *value != '0'? *ret += 1:0;
            fl ->conv != 'o'?ft_putchar(fl->conv):0;
            fl ->conv != 'o'?*ret += 1:0;
        }
        if(fl->flags.zeros == FALSE || (fl->dot == TRUE && fl->width > 0))
            pf_write(" ",1,fl->width);
        else
            fl->dot == 0?pf_write("0",1,fl->width):0;
        *ret += fl->width;
    }
    (fl->dot == FALSE || fl->dot == TRUE) && fl->precision == FALSE? 0:ft_putchar('0');
    *ret += ((fl->dot == FALSE || fl->dot == TRUE) && fl->precision == FALSE)?0:1;
    if((fl->flags.zeros == FALSE || fl->flags.minus == TRUE) && ft_strcmp("0", value) != 0)
    {
        fl->precision == 0 && *value != '0' ? ft_putchar('0') : 0;
        fl->precision == 0 && *value != '0' ? *ret += 1 : 0;
        fl->conv != 'o' ? ft_putchar(fl->conv) : 0;
        fl->conv != 'o' ? *ret += 1 : 0;
    }
    write_precision(fl, (int)len, ret, ft_atoi(value));
    if ((*value != '0' && fl->dot != TRUE) || fl->conv == 'o' || (fl->conv != 'o' && fl->dot == FALSE)) {
        ft_putstr(value);
        *ret += (ft_strlen(value));
    }
    if (fl->flags.minus == TRUE)
    {
        pf_write(" ", 1, fl->width);
        *ret += fl->width;
    }
    free(value);
}

void print_unsigned_hash(t_conv *fl, size_t len, int *ret, char *value)
{
    if (fl->conv == 'o')
    {
        len += 1;
        fl->width >= 1 && fl->precision < len?fl->width -= 1:0;
    }
    else if (fl->conv == 'x' || fl->conv == 'X')
    {
        len+=2;
        fl->width >= 2 ?fl->width -=2:0;
//        *ret += 2;
        fl->precision > 0? fl->precision += 2:0;
    }
    print_hash(fl, len, ret, value);

}