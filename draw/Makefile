# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhote <alhote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 15:54:26 by alhote            #+#    #+#              #
#    Updated: 2016/02/16 14:03:05 by alhote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = draw.a
SRC = draw_point.c draw_segment.c camera.c convert3dto2d.c world.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation lib Draw"
	@gcc $(CFLAGS) -c $(SRC)
	@echo "Creation"
	@ar rc $(NAME) $(OBJ)
	@echo "Indexation"
	@ranlib $(NAME)

clean:
	@echo "suppression des objets ..."
	@rm -f $(OBJ)

fclean: clean
	@echo "suppression de la librairie ..."
	@rm -f $(NAME)

re: fclean all
