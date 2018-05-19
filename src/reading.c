#include "../inc/ft_printf.h"

void ft_findlp(char *str, t_conv *fl, size_t *pos)
{
    int len;

    len = 0;
    fl->dot = 0;
    if (str[len] == '.')
    {
        fl->precision = 0;
        fl->dot = 1;
        len++;
    }
    if(ft_isdigit(str[len]) != 1)
        return ;
    if (fl->dot == 0)
    {
        fl->width = 0;
        while (ft_isdigit(str[len]) == 1) {
            fl->width = fl->width * 10 + str[len] - '0';
            len++;
        }
        *pos += len-1;
        return ;
    }
    else
        while(ft_isdigit(str[len]) == 1)
        {
            fl->precision = fl->precision * 10 + str[len] - '0';
            len++;
        }
    *pos += len-1;
}

static t_conv ft_checkfalgs(char str, t_conv *fl)
{

    str == '#' ? fl->flags.hash += TRUE : FALSE;
    str == '-' ? fl->flags.minus+= TRUE : FALSE;
    str == '+' ? fl->flags.plus += TRUE : FALSE;
    str == ' ' ? fl->flags.blank += TRUE : FALSE;
    str == '0' ? fl->flags.zeros += TRUE : FALSE;
    str == 'h' ? fl->lenght.len_h += TRUE : FALSE;
    str == 'l' ? fl->lenght.len_l += TRUE : FALSE;
    str == 'j' ? fl->lenght.len_j += TRUE : FALSE;
    str == 'z' ? fl->lenght.len_z += TRUE : FALSE;

    return(*fl);
}

size_t  ft_read2(char **str, va_list *arg_ptr, int *step)
{
    t_conv new;
    size_t i;

    i = 0;
    ft_bzero(&new, sizeof(t_conv));
    while(*(*str+i))
    {
        if (ft_strchr(FLAGS, *(*str + i))) {
            if (*(*str + i - 1) == '+' && *(*str + i) == '+')
                new.flags.plus = TRUE;
            else
                new = ft_checkfalgs(*(*str + i), &new);
        }
        if (strchr(DIGITS, *(*str + i)) && *(*str + i) != '0')
            ft_findlp(*str + i, &new, &i);
        if (strchr(CONV, *(*str + i))) {
            *step += ft_conv(*(*str + i), &new, arg_ptr);
            ft_bzero(&new, sizeof(t_conv));
            i++;
            break;
        }
        if (isascii(*(*str + i)))
        {
            if((ft_strchr(FLAGS, *(*str + i)) == NULL) &&
               (ft_strchr(DIGITS, *(*str + i)) == NULL))
            {
                another_symb(*(*str + i), &new, step);
                i += 1;
                break;
            }

        }
        i++;
    }
    return(i);
}

size_t ft_reading(char **str, va_list *arg_ptr ,int *step)
{
    size_t pos;
    pos = 0;

    if (*(*str+=1) == '%')
    {
        pf_write("%",1,1);
        *step +=1;
        *str += 1;
        return(0);
    }
    pos = ft_read2(str, arg_ptr, step);
    return(pos);
}