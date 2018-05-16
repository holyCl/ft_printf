#include "ft_printf.h"

int ft_parseconv(t_conv *fl, va_list *arg_ptr)
{
    int ret;

    ret = 0;
    if (fl->conv == 'd' || fl->conv == 'i')
        ret = ft_numbers(fl, arg_ptr);
    else if (fl->conv == 's')
        ret = ft_str(fl, arg_ptr);
    else if (fl->conv == 'c')
        ret = ft_chars(fl, arg_ptr);
    else if (fl->conv == 'o')
        ret = fl_unsconv(fl, arg_ptr, 8);
    else if (fl->conv == 'u')
        ret = fl_unsconv(fl, arg_ptr, 10);
    else if (fl->conv == 'x' || fl-> conv == 'X')
        ret = fl_unsconv(fl, arg_ptr, 16);
    else if (fl->conv == 'p')
        ret = ft_point(fl, arg_ptr, 16);

    return(ret);
}

char	ft_tolow(char a)
{
    char r;

    if (a >= 'A' && a <= 'Z')
    {
        r = a + 32;
        return (r);
    }
    return (a);
}

int ft_conv(char str, t_conv *fl, va_list *arg_ptr)
{
    int ret;
    ret = 0;
    if (str == 'C' || str == 'U' || str == 'S' || \
    	str == 'D' || str == 'O') {
        fl->lenght.len_l = 1;
        fl->conv = ft_tolow(str);
    }
    else
        fl->conv = str;
    ret = ft_parseconv(fl, arg_ptr);
    if ((str) == '%')
    {
        ft_putchar('%');
        ret += 1;
    }
    return (ret);
}