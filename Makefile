# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 14:05:39 by mplutarc          #+#    #+#              #
#    Updated: 2019/06/25 20:24:22 by mplutarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = fdf.c valid.c draw_map.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
HEADER = -c

all: $(NAME)

$(OBJ): %.o: %.c
		gcc -c -I./libft $< -o $@

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	gcc $(OBJ) $(LIBFT) -o $(NAME) -framework Appkit -framework OpenGL -lmlx

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
