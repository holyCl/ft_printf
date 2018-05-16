#include <stdio.h>
#include "printf.h"

int main()
{

    ft_printf("%#d" ,23);
    printf("\n%#d\n" ,23);

    printf("%x %X %#s\n", 99, 99, "32399");

    printf("%9.3s\n" ,"privet");
    ft_printf("%9.3s" ,"privet");
    printf("\n");

    printf("%5.3s\n" ,"privet");
    ft_printf("%5.3s" ,"privet");
    printf("\n");

    ft_printf("%1s" ,"privet");
    printf("\n%1s" ,"privet");
}
