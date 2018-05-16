#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int ft_printf(char *format, ...);

int main(void)
{
//	printf("%o\n",32);
//	ft_printf("%o\n",32);

		int ret_1, ret_2;

		setlocale(LC_ALL, "");
//#define CNV "d"
		int nmb = 4230;

//FAIL
		ret_1 = printf("%4.S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
		ret_2 = ft_printf("%4.S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
		printf("ret_1 = %i\nret_2 = %i\n\n", ret_1, ret_2);

}
