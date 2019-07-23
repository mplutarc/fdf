# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 14:05:39 by mplutarc          #+#    #+#              #
#    Updated: 2019/07/20 16:27:29 by mplutarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = fdf.c valid.c draw_map.c events.c mouse_events.c puts.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror


all: lib fdf


lib:
	@make -C libft

fdf: $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) -framework Appkit -framework OpenGL -lmlx

%.o: %.c
	gcc -c -I./libft $< -o $@

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
