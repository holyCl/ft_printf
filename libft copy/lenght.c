//
// Created by Igor VOLOSHIN on 5/12/18.
//

#include "ft_printf.h"

intmax_t   ft_parse_sign(t_conv *fl, va_list *arg_ptr)
{
    intmax_t   nbr;

    if (fl->lenght.len_z == 1)
        nbr = va_arg(*arg_ptr, ssize_t);
    else if (fl->lenght.len_j == 1)
        nbr = (intmax_t)va_arg(*arg_ptr, intmax_t);
    else if (fl->lenght.len_l >1)
        nbr = va_arg(*arg_ptr, long long);
    else if (fl->lenght.len_l == 1)
        nbr = va_arg(*arg_ptr, long);
    else if (fl->lenght.len_h == 1)
        nbr = (short int)va_arg(*arg_ptr, int);
    else if (fl->lenght.len_h > 1)
        nbr = (signed char)va_arg(*arg_ptr, int);
    else
        nbr = (int)va_arg(*arg_ptr, long long int);
    return(nbr);
}

char *cast_unsigned(va_list *arg_ptr, int base, t_conv *fl, int capitilise)
{
    if (fl->lenght.len_z == TRUE)
        return (ft_itoa_base(va_arg(*arg_ptr, size_t),base,capitilise));
    else if (fl->lenght.len_j == TRUE)
        return (ft_itoa_base(va_arg(*arg_ptr, uintmax_t),base,capitilise));
    else if (fl->lenght.len_l > TRUE)
        return (ft_itoa_base(va_arg(*arg_ptr, unsigned long long),base,capitilise));
    else if (fl->lenght.len_l == TRUE)
        return (ft_itoa_base(va_arg(*arg_ptr, unsigned long),base,capitilise));
    else if (fl->lenght.len_h == TRUE)
        return (ft_itoa_base((unsigned short)va_arg(*arg_ptr, int),base,capitilise));
    else if (fl->lenght.len_h > TRUE)
        return (ft_itoa_base((unsigned char)va_arg(*arg_ptr, int),base,capitilise));
    else
        return (ft_itoa_base(va_arg(*arg_ptr,unsigned int),base,capitilise));
}

