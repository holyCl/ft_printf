//
// Created by Igor VOLOSHIN on 5/14/18.
//

#include "ft_printf.h"

int ulen(wchar_t *str, t_conv *fl)
{
    int i;
    int len;

    len = 0;
    i = 0;
    while (str[i]) {
        i++;
        len += ft_ucharlen(str[i]);
        if(fl->precision < len)
            return (len - ft_ucharlen(str[i]));
    }
    return(len);
}

void utf_parselenstr(t_conv *fl, int len, wchar_t *wstr)
{
    if (fl->width >= len && fl->width!=0)
        if (fl->precision > 0 && fl->precision < len && fl->width > fl->precision)
            fl->width -= fl->precision;
//        else
//            fl->width -= len;
        else if (fl->precision>0 && fl->width >= fl->precision)
            fl->width -= ulen(wstr,fl);
        else if (fl->dot == FALSE && len >fl->width)
            fl->width = 0;
    if (fl->precision > 0 && fl->precision >= len)
        fl->precision = 0;
}

void    utf_parsestr1(wchar_t *wstr, int len, t_conv *fl, int *ret)
{
    if (fl->flags.zeros == TRUE && fl->width > len) {
        pf_write("0", 1, fl->width - len);
        if (fl->dot == FALSE) {
            while (*wstr) {
                ft_putwchar(*wstr);
                *ret += ft_ucharlen(*wstr++);
            }
        }
        *ret += fl->width - len;
    }
    else {
        if (fl->flags.minus != TRUE && len < fl->width) {
            pf_write(" ", 1, fl->width - len);
            *ret += fl->width - len;
        }
        else if(len > fl->width && fl->dot == TRUE)
        {
            fl->flags.zeros == FALSE?pf_write(" ",1,fl->width):pf_write("0",1,fl->width);
            *ret += fl->width;
        }

        if (fl -> dot == FALSE)
        {
            while(*wstr)
            {
                ft_putwchar(*wstr);
                *ret += ft_ucharlen(*wstr++);
            }
        }
    }
}

void utf_str(wchar_t *wstr, int len, t_conv *fl, int *ret)
{
    utf_parselenstr(fl,len,wstr);
    fl->flags.plus == TRUE && fl->flags.minus == TRUE? fl->flags.plus = FALSE:0;
    if (fl->precision > 0) {
        if (fl->flags.minus == FALSE)
        {
            if(fl->width > fl->precision) {
                fl->flags.zeros == TRUE ? pf_write("0", 1, fl->width - fl->precision) : pf_write(" ", 1, fl->width - fl->precision);
                *ret += fl->width - fl->precision;
            }
            while(fl->precision >= ft_ucharlen(*wstr)) {
                fl->precision -= ft_putwchar(*wstr);
                *ret += ft_ucharlen(*wstr++);
            }
        }
        else {
            while(fl->precision--) {
                ft_putwchar(*wstr);
                *ret += ft_ucharlen(*wstr++);
            }
        }
    }
    else
        utf_parsestr1(wstr,len,fl, ret);
    fl->flags.minus == TRUE && len <= fl->width?pf_write(" ",1,fl->width - len):0;
    fl->flags.minus == TRUE && fl->width >= len?*ret +=fl->width - len:0;
}


