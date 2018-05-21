#include "ft_printf.h"

void parselenstr(t_conv *fl, int len, char *str)
{
    if(len > fl->width && fl->width + fl->precision < len)
        fl->width = 0;
    if(fl->precision > fl->width && fl->precision >len)
        fl->precision = -1;
    if(fl->dot == TRUE && fl->precision == FALSE)
        fl->dot = -1;
    if (fl->precision > 0 && fl->precision >= len && fl->dot == FALSE)
        fl->precision = 0;
}
void    parsestr1(char *str, int len, t_conv *fl, int *ret)
{
    if (ft_strcmp("(null)",str) && fl->width == TRUE)
        str = "0";
    if (fl->flags.zeros == TRUE) {
        if (fl->width >= len) {
            pf_write("0", 1, fl->width - len);
            pf_write(str, len, 1);
            *ret += fl->width;
        }
//        else
//            pf_write("0",1,fl->width);
    }
    else
    {
        if (fl->flags.minus != TRUE) {
            if (fl->width > len && fl->precision <= 0)
                if (fl->precision == 0 && fl->dot != FALSE) {
                    pf_write(" ", 1, fl->width);
                    *ret += fl->width;
                }else {
                    pf_write(" ", 1, fl->width - len);
                    *ret += fl->width - len;
                }
        }
        if(fl->flags.minus == FALSE && fl->width > len && fl->precision > 0) {
            pf_write(" ", 1, fl->width - len);
            *ret += fl->width - len;
        }
        fl->dot != -1?pf_write(str, len, 1):0;
        fl->dot != -1?*ret += len:0;
    }
}


void ft_parsestr(char *str, int len, t_conv *fl, int *ret)
{
    fl->flags.plus == TRUE && fl->flags.minus == TRUE? fl->flags.plus = FALSE:0;
    if (fl->precision > 0) {
        if (fl->flags.minus == FALSE) {
            fl->width < 0?pf_write(" ", 1, fl->width + fl->precision):0;
            fl->width < 0?(*ret += fl->width + fl->precision):0;
            fl->width > fl->precision && len> fl->precision && fl->dot == TRUE? pf_write(" ",1,fl->width-fl->precision):0;
            fl->width > fl->precision && len> fl->precision && fl->dot == TRUE? *ret +=fl->width-fl->precision:0;
            fl->width > fl->precision && len < fl->precision && fl->dot == TRUE?pf_write(" ",1,fl->width - len):0;
            fl->width > fl->precision && len < fl->precision && fl->dot == TRUE?*ret +=fl->width - len:0;
            (fl->precision >= len)?pf_write(str, len, 1):pf_write(str, fl->precision,1);
            *ret += (fl->precision >= len)?len:fl->precision;
        }
        else {
            (fl->precision >= len)?pf_write(str, len, 1):pf_write(str, fl->precision,1);
            *ret += (fl->precision >= len)?len:fl->precision;
        }
    }
    else
        parsestr1(str,len,fl, ret);
    fl->flags.minus == TRUE && fl->precision == -1?pf_write(" ",1,fl->width):0;
    fl->flags.minus == TRUE && fl->precision == -1?*ret +=fl->width:0;
    if (fl->precision > len || fl->dot == FALSE) {
        fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width ? pf_write(" ", 1, fl->width - len) : 0;
        fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width ? *ret += fl->width - len : 0;
    }
    else
    {
        fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width ? pf_write(" ", 1, fl->width - fl->precision) : 0;
        fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width ? *ret += fl->width - fl->precision : 0;
    }
}

int lentype(t_conv *fl, va_list *arg_ptr, char *str, wchar_t *wstr)
{
    int ret;
    int len;

    ret = 0;
    if (fl->lenght.len_l == FALSE)
    {
        str = va_arg(*arg_ptr, char *);
        if (str == NULL && fl->width == 0)
            str = "(null)";
        else if(str == NULL && fl->width > 0)
            str = "0";
        len =  (int)ft_strlen(str);
        parselenstr(fl,len, str);
        ft_parsestr(str, len, fl, &ret);
    }
    else
    {
        wstr = va_arg(*arg_ptr, wchar_t *);
        wstr == NULL?wstr = L"(null)":0;
        len = ft_ustrlen(wstr);
        utf_str(wstr, len, fl, &ret);
    }
    return(ret);
}

int ft_str(t_conv *fl, va_list *arg_ptr)
{
    int ret;
    char *str;
    wchar_t *wstr;

    str = NULL;
    wstr = NULL;
    ret = 0;
    ret += lentype(fl, arg_ptr, str, wstr);

    return (ret);
}