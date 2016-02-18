# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhote <alhote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/19 15:42:18 by alhote            #+#    #+#              #
#    Updated: 2016/02/18 13:23:45 by alhote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS       = -Wall -Wextra -Werror
INC_DIR = -Ilibft/includes \
			-Idraw \

SRCS = main.c fdf.c
OBJECTS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/
	@make -C draw/
	@echo "Compiling.."
	@clang $(CFLAGS) $(OBJECTS) -Llibft/ -lft -lm -lmlx -framework OpenGL -framework AppKit draw/draw.a -o $(NAME)

%.o: %.c
	@gcc $(CFLAGS) $(INC_DIR) -c $<

clean:
	@make -C libft/ clean
	@make -C draw/ clean
	@rm -rf *.o
	@echo "Clean"

fclean: clean
	@make -C libft/ fclean
	@make -C draw/ fclean
	@rm -f $(NAME)
	@echo "Fclean"

re: fclean all
