# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 17:15:07 by kdune             #+#    #+#              #
#    Updated: 2019/04/23 15:15:49 by mplutarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_C = ft_isdigit.c ft_lstnew.c ft_memset.c ft_putstr_fd.c ft_strequ.c \
ft_strncat.c ft_strsplit.c ft_isprint.c ft_memalloc.c ft_putchar.c \
ft_strcat.c ft_striter.c ft_strncmp.c ft_strstr.c ft_itoa.c ft_memccpy.c \
ft_putchar_fd.c ft_strchr.c ft_striteri.c ft_strncpy.c ft_strsub.c ft_atoi.c \
ft_lstadd.c ft_memchr.c ft_putendl.c ft_strclr.c ft_strjoin.c ft_strndup.c \
ft_strtrim.c ft_bzero.c ft_lstdel.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c \
ft_strlcat.c ft_strnequ.c ft_tolower.c ft_isalnum.c ft_lstdelone.c ft_memcpy.c \
ft_putnbr.c ft_strcpy.c ft_strlen.c ft_strnew.c ft_toupper.c ft_isalpha.c \
ft_lstiter.c ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strnstr.c \
ft_isascii.c ft_lstmap.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c \
ft_strrchr.c ft_free.c ft_lstfree.c ft_isspace.c ft_strnchr.c

SRCS_O = ft_isdigit.o ft_lstnew.o ft_memset.o ft_putstr_fd.o ft_strequ.o \
ft_strncat.o ft_strsplit.o ft_isprint.o ft_memalloc.o ft_putchar.o \
ft_strcat.o ft_striter.o ft_strncmp.o ft_strstr.o ft_itoa.o ft_memccpy.o \
ft_putchar_fd.o ft_strchr.o ft_striteri.o ft_strncpy.o ft_strsub.o ft_atoi.o \
ft_lstadd.o ft_memchr.o ft_putendl.o ft_strclr.o ft_strjoin.o ft_strndup.o \
ft_strtrim.o ft_bzero.o ft_lstdel.o ft_memcmp.o ft_putendl_fd.o ft_strcmp.o \
ft_strlcat.o ft_strnequ.o ft_tolower.o ft_isalnum.o ft_lstdelone.o ft_memcpy.o \
ft_putnbr.o ft_strcpy.o ft_strlen.o ft_strnew.o ft_toupper.o ft_isalpha.o \
ft_lstiter.o ft_memdel.o ft_putnbr_fd.o ft_strdel.o ft_strmap.o ft_strnstr.o \
ft_isascii.o ft_lstmap.o ft_memmove.o ft_putstr.o ft_strdup.o ft_strmapi.o \
ft_strrchr.o ft_free.o ft_lstfree.o ft_isspace.o ft_strnchr.o

all: $(NAME)

$(NAME): $(SRCS_C)
	@gcc -Wall -Wextra -Werror -c $(SRCS_C)  
	@ar rc libft.a $(SRCS_O)
clean:
	@rm -rf $(SRCS_O)

fclean: clean
	@rm -rf libft.a

re: fclean all
