#include "../inc/ft_printf.h"
#include <limits.h>
#include <locale.h>

int ft_printf(char *format, ...) {
    
    va_list arg_ptr;
    t_conv fl;
    int step;
    char *str;
    //ft_bzero(&fl, sizeof(t_format));
    str = ft_strdup(format);
    step = 0;
    va_start(arg_ptr, format);
    while (*str) {
        if (*str == '%') {
            str += ft_reading(&str, &arg_ptr, &step);
            if (!(*str))
                break;
        } else {
            if(*str) {
                ft_putchar(*str);
                step++;
                str++;
            }
        }
    }
    va_end(arg_ptr);
    return (step);
}

int main()
{
    int ret_1, ret_2;

    setlocale(LC_ALL, "");
//    char *l = L"1F426";
//    ft_printf("%C\n",l);
//
//    ret_1 = printf("%S", " ");
//    ret_2 = ft_printf("%S", " ");
//    ret_1 = printf("% Zoo\n");
//    ret_2 = ft_printf("% Zoo\n");
//    printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);
//
//


//    ret_1 = printf("%4.15s", "I am 42");
//    ret_2 = ft_printf("%4.15s", "I am 42");
//    printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);
//
//    ret_1 = printf("{%+2.5d}\n", 20);
//    ret_2 = ft_printf("{%+2.5d}\n", 20);
//    printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);


//    ret_1 = printf("{%-15p}\n", 0);
//    ret_2 = ft_printf("{%-15p}\n", 0);
//    printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);
//    printf("%d", INT_MIN);
//    ft_printf("%d", INT_MIN);

#define CNV "d"
    int nmb = 4230;
//    POINTERS
//    printf("%d\n",printf("%S",NULL));
//    printf("%d\n",ft_printf("%S",NULL));
//    printf("%s", "NU CHE AA");
    ret_1 = printf("%#08x", 42);
    ret_2 = ft_printf("%#08x", 42);
    printf("\nret_1 = %i\nret_2 = %i\n\n", ret_1, ret_2);


//FAIL
//    ret_1 = printf("%#.1O\n", 0);
//    ret_2 = ft_printf("%#.1O\n", 0);
//    printf("\nret_1 = %i\nret_2 = %i\n\n", ret_1, ret_2);
//
//    ret_1 = printf("{%4.15s} {%4.s}\n", "42","42");
//    ret_2 = ft_printf("{%4.15s} {%4.s}\n", "42","42");
//    printf("\nret_1 = %i\nret_2 = %i\n\n", ret_1, ret_2);
//
//
//    ret_1 = printf("%15.4s\n", "42 is the answer");
//    ret_2 = ft_printf("%15.4s\n", "42 is the answer");
//    printf("ret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

//    ret_1 = printf("%030.S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//    ret_2 = ft_printf("%030.S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//    printf("ret_1 = %i\nret_2 = %i\n\n", ret_1, ret_2);

//    printf("%d\n",printf("{%+03d}", 0));
//    printf("%d\n",ft_printf("{%+03d}", 0));
//    printf("%d\n",printf("%16.4d ",8));
//    printf("%d\n",ft_printf("%16.4d ",8));


//        printf("%S\n","$");
//    ft_printf("|%S|  |%S|\t|%S|",L"বিড়াল এবং খাওয়া তিমি ঘুঘু", L"合気道",L"ድመቶች ሰዎች አልወደውም.");
//    printf("|%S|  |%S|\t|%S|",L"বিড়াল এবং খাওয়া তিমি ঘুঘু", L"合気道",L"ድመቶች ሰዎች አልወደውም.");


//     UNSIGNED CHARS
//    ft_printf("%d\n",printf("|%11"CNV"|\t\t|%1"CNV"|\t\t|%3"CNV"|\t\t|%5"CNV"|\t\n",-nmb, nmb, -nmb, nmb));
//    printf("%d\n", ft_printf("|%11"CNV"|\t\t|%1"CNV"|\t\t|%3"CNV"|\t\t|%5"CNV"|\t\n",-nmb, nmb, -nmb, nmb));
//
//    printf("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t\n",nmb, nmb, nmb, nmb);
//    ft_printf("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t\n",nmb, nmb, nmb, nmb);
//
//    printf("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t\n",-nmb, -nmb, -nmb, -nmb);
//    ft_printf("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t\n",-nmb, -nmb, -nmb, -nmb);

//    printf("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|\n",nmb, -nmb, nmb, -nmb);
//    ft_printf("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|\n",nmb, -nmb, nmb, -nmb);
//
//    printf("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|\n",nmb, -nmb, nmb, -nmb);
//    ft_printf("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|\n",nmb, -nmb, nmb, -nmb);

//    ft_printf("%d\n",printf("%x%X\n",-23,-23));
//    printf("%d\n",printf("%x%X\n",-23,-23));
//

//    ft_printf("%1.5u\n",-2);
//    printf("%1.5u\n\n",-2);
//
//    ft_printf("%i", 42);
//    printf("%i", 42);
//    ft_printf("%14.3o\n",2);
//    printf("%14.3o\n\n",2);


//    ft_printf("%5u\n",-2);
//    ft_printf("%14u\n",-2);
//    printf("%5u\n",-2);
//    printf("%14u\n\n",-2);
//
//    ft_printf("%5x\n",-2);
//    ft_printf("%14x\n",-2);
//    printf("%5x\n",-2);
//    printf("%14x\n",-2);


    // CHARS

//    printf("%5c %4c %02c %-9c %1c\n",'p','i','z','d','a');
//    ft_printf("%5c %4c %02c %-9c %1c\n",'p','i','z','d','a');

//
//    ft_printf("%-5c\n",'a');
//
//    ft_printf("%5c\n",'a');
//    ft_printf("%-5c\n",'a');
//
//    printf("%05c\n",'a');
//    ft_printf("%05c\n",'a');
//
//    printf("%+-4c\n",'a');
//    ft_printf("%+-4c\n",'a');

    // STRINGS

//    printf("%9.3s\n" ,"privet");
//    ft_printf("%9.3s" ,"privet");
//    printf("\n");
//
//    printf("%5.3s\n" ,"privet");
//    ft_printf("%5.3s" ,"privet");
//    printf("\n");

//    printf("%d",ft_printf("%s%s","d32s","a1m"));
//    printf("%d",printf("%s%s","d23s","am1"));
//    printf("%d\n",ft_printf("seichas  %s\n" ,"god"));
//    printf("%d\n",printf("seichas  %s\n" ,"god"));
//





    // DIGITS
//    int nmb = 4235;

//    ft_printf("%07.5d%07.5d",nmb, -nmb);
//    printf("\n%07.5d%07.5d\n\n",nmb, -nmb);


//    printf("\n%07.5d\n", -4235);
    //ft_printf("%07.5d", -4235);
//    printf("\n\n");
//
//    printf("\n%5.3d\n", 4235);
//    ft_printf("%5.3d", 4235);
//    printf("\n");
//
//    ft_printf("%07.5d", 4235);
//    printf("\n\n%07.5d\n", 4235);

//    printf("%+-5d% 07d\n", nmb, -nmb);
//    ft_printf("%+-5d% 07d", nmb, -nmb);
//
//    printf("\n%05d%07d\n", nmb, nmb);
//    ft_printf("%05d%07d", nmb, nmb);
//
//    printf("\n%+5d%-7d\n", nmb, nmb);
//    ft_printf("%+5d-7d", nmb, nmb);
//    printf("\n");

//    printf("%.10d\n", 42);
//    ft_printf("%.10d", 42);
//    printf("\n");
//

//    ft_printf("%1.1d%5.1d%5.3d%1.5d ",nmb, nmb, nmb, nmb);
//
//    printf("\n%1.1d%5.1d%5.3d%1.5d \n",nmb, nmb, nmb, nmb);

//    ft_printf("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
//    ft_printf("%+.10d%+.10d%+.15d%+10d%.10d",1,-2,3,4,5);
//    printf("\n%+.10d%+.10d%+.15d%+10d%.10d",1,-2,3,4,5);
//
//    printf("\n%+10d\n",5);
//    ft_printf("%+10d",5);
//    ft_printf("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
//    ft_printf("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
//    ft_printf("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
//    ft_printf("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
}