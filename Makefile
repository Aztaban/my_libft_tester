# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 11:27:58 by mjusta            #+#    #+#              #
#    Updated: 2025/05/25 17:53:12 by mjusta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_test
CC = cc
CFLAGS = -Wall -Wextra -Werror -I..
BSD = -lbsd

REAL = $(wildcard ../libft/ft_*.c)
FALLBACKS = $(wildcard fallbacks/ft_*.c)

# Filter out fallback files where a real version already exists
FALLBACKS_FILTERED := $(foreach f,$(FALLBACKS),$(if $(wildcard ../libft/$(notdir $(f))),,${f}))

SRC = $(REAL) $(FALLBACKS_FILTERED) \
		$(wildcard tests/*.c) $(wildcard utils/*.c) main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(BSD) || echo "⚠️ Some functions may be missing."

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean
