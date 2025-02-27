# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 11:49:14 by bobydear          #+#    #+#              #
#    Updated: 2025/02/27 15:58:57 by bobydear         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
EXTRA = -lXext -lX11
RM = rm -rf
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
SRCS = src/main.c \
		src/handler_exit_game.c \
		src/tools_player.c \
		src/tools_valid_map.c \
		src/handler_game.c \
		src/tools_player_moves.c \
		src/tools_valid_xs.c \
		src/handler_map_draw.c \
		src/tools_free.c \
		src/tools_print.c \
		src/handler_map_validator.c \
		src/tools_inits.c \
		src/tools_str.c \
		src/handler_player_moves.c \
		src/tools_map.c \
		src/tools_valid_map_2.c \

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
