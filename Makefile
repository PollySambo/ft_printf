# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psambo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 10:58:02 by psambo            #+#    #+#              #
#    Updated: 2018/07/27 07:01:12 by psambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
SRC_DIR = srcs/
FILES =	atoi_and_ulltoa.c \
		ft_printf.c \
		print.c \
		conversion.c \
		gather_flags.c \
		itoa_and_ftoa.c \
		str_chr.c \
		ptr_dbl.c \
		int_uint.c \
		indirect_ft.c \
		ft_libft1.c \
		ft_libft2.c \
		ft_libftprintf.c \
		

CFLAGS = -Wall -Wextra -Werror
HEAD = ./includes
SRC	:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(SRC:.c=.o)

BUILD_PRINT = @echo "\033[0;33mBuilding \"$<\"..."
DONE = @echo "\033[0;32mFt_printf ready to use!"
CLEAN_O = @echo "\033[0;32mObject files removed!"
CLEAN_A = @echo "\033[0;32mExecutable removed!"

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	$(DONE)

$(OBJ): %.o: %.c
	$(BUILD_PRINT)
	gcc $(CFLAGS) -I $(HEAD) -c $< -o $@


clean:
	/bin/rm -rf $(OBJ)
	$(CLEAN_O)

fclean: clean
	/bin/rm -rf $(NAME)
	$(CLEAN_A)

re: fclean all

.PHONY: all clean fclean re
