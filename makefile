# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 11:49:14 by bobytrap          #+#    #+#              #
#    Updated: 2025/02/20 11:49:14 by bobytrap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
EXTRA = -lXext -lX11
RM = rm -rf
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
SRCS = src/main.c src/tools_free.c src/tools_map.c src/tools_player.c \
src/valid_xs.c src/tools_inits.c src/tools_map_valid.c src/tools_str.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	$(MAKE) clean

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(EXTRA) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
#	@$(MAKE) fclean -C ./minilibx-linux
	$(RM) $(NAME)

re: fclean all
	$(MAKE) clean
