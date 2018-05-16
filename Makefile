.PHONY: all, clean, fclean, re

NAME := libftprintf.a

SRC_DIR := ./src/
LIB_DIR := ./libft/

LIB := $(addprefix $(LIB_DIR), ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_tolower.c ft_toupper.c ft_atoi.c ft_bzero.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strnew.c \
ft_strdel.c ft_memalloc.c ft_memdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putendl.c ft_putstr.c \
ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_revprint.c ft_sndr.c ft_countnumb.c ft_sizelist.c ft_pow.c ft_strnchr.c \
ft_pf_write.c ft_isdigit.c ft_isprint.c )

SRC := $(addprefix $(SRC_DIR),ft_printf cnumbers.c reading.c strings.c\
conversions.c chars.c unsignedconv.c pointers.c lenght.c ft_itoa_base.c \
ft_len_u.c hash.c precision_zeros.c )

SRC_OBJ = $(SRC:.c=.o)

LIB_OBJ = $(LIB:.c=.o)

all: $(NAME)

$(NAME):pf.c $(SRC_OBJ) $(LIB_OBJ)
        @ar rc $(NAME) $(SRC_OBJ) $(LIB_OBJ)
		@ranlib $(NAME)
		@echo "\033[0;32mlib compiled.\033[0m "

clean:
		@rm -rf $(SRC_OBJ)
		@rm -rf $(LIB_OBJ)
		@echo "\033[0;32mCLEANED\033[0m "

fclean: clean
		@rm -f $(NAME)

re: fclean all

$(LIB_OBJ): %.o : %.c inc/libft.h
	gcc -o $@ -c $< -Wall -Werror -Wextra -I./inc

$(SRC_OBJ): %.o : %.c inc/libft.h inc/ft_printf.h
	gcc -o $@ -c $< -Wall -Werror -Wextra -I./inc
