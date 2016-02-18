# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhote <alhote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 10:10:16 by nmougino          #+#    #+#              #
#    Updated: 2016/02/18 13:24:25 by alhote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_getlinesize.c \
		ft_getlline.c \
		ft_getnbrline.c \
		ft_gotoline.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islow.c \
		ft_isprint.c \
		ft_isup.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_nbrlen.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbrendl.c \
		ft_putnbr_fd.c \
		ft_putnbrendl_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_swapchar.c \
		ft_swapint.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		ft_realloc.c \

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME):
	@echo "creation des fichier objet ..."
	@gcc $(CFLAGS) -c $(SRC) -Iincludes
	@echo "ecriture et indexation de la librairie ..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

glu: fclean
	@echo "creation des fichier objet ..."
	@gcc -c $(CFLAGS) $(SRC) -Iincludes
	@echo "ecriture et indexation de la librairie ..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make clean

clean:
	@echo "suppression des objets ..."
	@rm -f $(OBJ)

fclean: clean
	@echo "suppression de la librairie ..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all glu clean fclean re
