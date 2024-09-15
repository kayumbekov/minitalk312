# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:59:31 by kbekov            #+#    #+#              #
#    Updated: 2024/09/14 23:30:45 by kbekov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := CC
CFLAGS := -Wall -Wextra -Werror

INC_DIR := ./

#PART 1
CFILES := \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c\
	ft_printf.c



OFILES := $(CFILES:.c=.o)
HEADER := $(INC_DIR)/libft.h

NAME := libft.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $(OFILES)

$(OFILES): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
