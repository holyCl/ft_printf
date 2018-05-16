#include "ft_printf.h"
#include <stdio.h>

int ft_reading(t_flags *fl);
void flags_check(t_flags *fl);
int ft_reading(t_flags *fl);
void ft_read2(t_flags *fl);

void			pf_write(const char *str, int len, int count)
{
    while(count--)
        write(1, str, len);
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

int ft_printf(char *str, ...) {
    
    t_flags fl;

    fl.string = (char *)str;
    va_start(fl.arg_ptr, fl.string);
    fl.i = 0;
    fl.flen = ft_strlen(fl.string);
    while (fl.string[fl.i])
    {
        if (fl.string[fl.i] == '%') {
            fl.i++;
            ft_reading(&fl);
            if (!fl.i)
                break ;
        }
        if (fl.string[fl.i])
            ft_putchar(fl.string[fl.i]);
        fl.i++;
    }
//    printf("\n");
//     printf(" width :%d\n", fl.width);
//     printf(" widthlen :%d\n", fl.widthlen);
    return(ret);
}

void ft_checkfalgs(t_flags *fl)
{
    fl->string[fl->i] == '#' ? fl->hash = 1 : 0;
    fl->string[fl->i] == '-' ? fl->minus = 1 : 0;
    fl->string[fl->i] == '+' ? fl->plus = 1 : 0;
    fl->string[fl->i] == ' ' ? fl->blank = 1 : 0;
    fl->string[fl->i] == '0' ? fl->blank = 1 : 0;
    fl->string[fl->i] == 'h' ? fl->len_h = 1 : 0;
    fl->string[fl->i] == 'l' ? fl->len_l = 1 : 0;
    fl->string[fl->i] == 'j' ? fl->len_j = 1 : 0;
    fl->string[fl->i] == 'z' ? fl->len_z = 1 : 0;
}

void ft_findlp(t_flags *fl)
{
    int len;
    int flag;

    fl->width = 0;
    len = -1;
    if (fl->string[++len] == ".")
    {
        fl->precision = 0;
        flag = 1;
    }
    if(ft_isdigit(fl->string[fl->i]) != 1)
        return ;
    while (ft_isdigit(fl->string[len] == 1)) {
        fl->width = fl->width * 10 + fl->string[fl->si] - '0';
        fl->si++;
        len++;
    }
    if (flag == 1) {
        fl->precision = fl->width;
        fl->width = 0;
    }

}

int ft_parse_arg(t_flags *fl)
{
    long long int	nbr;

    if (fl->len_h > 1)
        nbr = (signed char)va_arg(fl->arg_ptr, long long int);
    else if (fl->len_h == 1)
        nbr = (short)va_arg(fl->arg_ptr, long long int);
    else if (fl->len_l == 1)
        nbr = (long)va_arg(fl->arg_ptr, long long int);
    else if (fl->len_l >1)
        nbr = (long long)va_arg(fl->arg_ptr, long long int);
    else if (fl->len_j == 1)
        nbr = (intmax_t)va_arg(fl->arg_ptr, long long int);
    else if (fl->len_z == 1)
        nbr = (size_t)va_arg(fl->arg_ptr, long long int);
    else
        nbr = (int)va_arg(fl->arg_ptr, long long int);
    return(nbr);

}

void ft_parsewidth(t_flags *fl)
{
    if (fl->precision - fl->widthlen <= 0)
        fl->width = fl->width - fl->widthlen;

}

void ft_numbers(t_flags *fl)
{
    long long int   arg;
    ssize_t len;

    fl->widthlen = 0;
    arg = ft_parse_arg(fl);
    len = arg;
    if (len < 0)
        fl->widthlen++;
    while ((len = len / 10) != 0)
        fl->widthlen++;
    ft_parsewidth(fl);
}

void ft_parseconv(t_flags *fl)
{
    if (fl->conv == 'd' || fl->conv == 'i')
        ft_numbers(fl);


}

void ft_conv(t_flags *fl)
{
    if (fl->string[fl->i] == 'C' || fl->string[fl->i] == 'U' || fl->string[fl->i] == 'S' || fl->string[fl->i] == 'D' || fl->string[fl->i] == 'C' || 'O')
        fl->len_l = 1;
    ft_tolow(fl->string[fl->i]);
    (fl->string[fl->i] == 'X') ? fl->conv = 'X' : 0;
    ft_parseconv(fl);
}

void ft_read2(t_flags *fl)
{
    while(fl->string[fl->i])
    {
        if (ft_strchr(FLAGS, fl->string[fl->i]))
            ft_checkfalgs(fl);
        if (strchr(DIGITS, fl->string[fl->i]) && fl->string[fl->i] != '0')
            ft_findlp(fl);
        if (strchr(CONV, fl->string[fl->i]) && fl->string[fl->i] != '0')
            ft_conv(fl);
            fl-> i++;
    }
}

int ft_reading(t_flags *fl)
{
    if (fl->string[fl->i] == '%'){
        pf_write('%',1,1);
        fl->i++;
        return(0);
    }
    ft_bzero(&fl, sizeof(fl));
    ft_read2(fl);

}

void ft_blank(t_flags *fl) {
    //some shit code//

    if (fl->data > -1) {
        if (fl->string[fl->i + 1] == '-') {
            pf_write(" ", 1, 1);
            ft_putnbr(fl->data);
            if (fl->n != 0)
                pf_write(" ", 1, fl->n - 1);
            fl->i++;
        } else {
            pf_write(" ", 1, 1);
            if (fl->zeros == 1) {
                if (fl->n != 0)
                    pf_write("0", 1, fl->n - 1);
            } else {
                if (fl->n != 0)
                    pf_write(" ", 1, fl->n - 1);
            }
            ft_putnbr(fl->data);
        }
    } else {
        if (fl->string[fl->i + 1] == '-') {
            ft_putnbr(fl->data);
            if (fl->n != 0) {
                pf_write(" ", 1, fl->n);
            }
            fl->i+=2;
        } else {
            if (fl->string[fl->i + 1] == '0') {
                if (fl->n != 0)
                    pf_write("0", 1, fl->n);
                pf_write("-", 1, 1);
            } else {
                if (fl->n != 0)
                    pf_write(" ", 1, fl->n);
                pf_write("-", 1, 1);
            }
            ft_putnbr(ABS(fl->data));
            fl->i++;
        }
    }
}
void ft_operplus(t_flags *fl) {
    if (fl->data > -1) {
        if (fl->string[fl->i + 1] == '-') {
            pf_write("+", 1, 1);
            ft_putnbr(fl->data);
            if (fl->n != 0)
                pf_write(" ", 1, fl->n - 1);
            fl->i+=2;
        }else {
            if (fl->string[fl->i + 1] == '0') {
                pf_write("+", 1, 1);
                if (fl->n != 0)
                    pf_write("0", 1, fl->n - 1);
                ft_putnbr(fl->data);
            } else {
                if (fl->n != 0)
                    pf_write(" ", 1, fl->n-1);
                pf_write("+", 1, 1);
                ft_putnbr(fl->data);
            }
        }
    } else {
        if (fl->string[fl->i + 1] == '-') {
            ft_putnbr(fl->data);
            if (fl->n != 0)
                pf_write(" ", 1, fl->n);
            fl->i+=2;
        } else {
            if (fl->string[fl->i + 1] == '0') {
                if (fl->n != 0)
                    pf_write("0", 1, fl->n - 1);
                pf_write("-", 1, 1);
                ft_putnbr(ABS(fl->data));
            } else {
                if (fl->n != 0)
                    pf_write(" ", 1, fl->n - 1);
                pf_write("-", 1, 1);
                ft_putnbr(ABS(fl->data));
            }
        }
    }
}
void ft_operzero(t_flags *fl) {
    if (fl->data < 0){
        pf_write("-", 1, 1);
        if (fl-> n!= 0)
            pf_write("0", 1, fl->n);
        ft_putnbr(ABS(fl->data));
        }
    else{
        if(fl->n != 0)
            pf_write("0", 1, fl->n);
        ft_putnbr(fl->data);
    }
}
void ft_operminus(t_flags *fl)
{
    ft_putnbr(fl->data);
    if(fl->n != 0)
        pf_write(" ", 1, fl->n);
}

void flags_check(t_flags *fl)
{
    if (ft_isdigit(fl->string[fl->i])) {
        if (fl->n != 0)
            pf_write(" ", 1, fl->n);
        ft_putnbr(fl->data);
        fl->i++;
    }
    if (fl->string[fl->i] == '0') {
        fl->zeros = 1;
        ft_operzero(fl);
        fl->i++;
    }
    if (fl->string[fl->i] == ' ') {
        fl->blank = 1;
        ft_blank(fl);
        fl->i++;
    }
    if (fl->string[fl->i] == '-'){
        fl->minus = 1;
        ft_operminus(fl);
        fl->i++;
    }
    if (fl->string[fl->i] == '+'){
        fl->plus = 1;
        ft_operplus(fl);
        fl->i++;
    }
    if (fl->string[fl->i] == 'd')
        ft_putnbr(fl->data);
    fl->i+=1;
}

void ft_spaces(t_flags *fl) {

    int len;
    if (ft_strchr(fl->string, 'd'))
        fl->data = va_arg(fl->arg_ptr, int);
    fl->si = fl->i;
    fl->n = 0;
    fl->widthlen = 1;
    fl->width = 0;
    while (!ft_isdigit(fl->string[fl->si]) && fl->si != fl->flen)
        fl->si++;
    if (fl->data < 0) {
        fl->widthlen++;
        fl->minus = 1;
    }
    while (ft_isdigit(fl->string[fl->si])) {
        fl->width = fl->width * 10 + fl->string[fl->si] - '0';
        fl->si++;
    }
    len = fl->data;
    while ((len = len / 10) != 0)
        fl->widthlen++;
    fl->n = ((fl->width - fl->widthlen) > 0) ? fl->width - fl->widthlen : 0;
    flags_check(fl);
}

int main(void)
{
//    ft_printf("PRIVET %6d ANDREY", 42232);
//    ft_printf("%d\n", -42);
    printf("%24d\n", 26776);
    //ft_printf("% -5d\n", -43242340);
//    printf("%5.1d\n", -43242340);
    //printf("% -1d\n",-13232);
    //printf("% -10d",-10);
//    printf("%050d",2035065302);
    return(0);
}