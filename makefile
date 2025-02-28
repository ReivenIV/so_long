# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 88888888 <88888888@contact.me>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 11:49:14 by bobydear          #+#    #+#              #
#    Updated: 2025/02/28 18:42:42 by 88888888         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
EXTRA = -lXext -lX11
RM = rm -rf
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
SRCS = src_clean/main.c \
		src_clean/handler_exit_game.c \
		src_clean/tools_player.c \
		src_clean/tools_valid_map.c \
		src_clean/handler_game.c \
		src_clean/tools_player_moves.c \
		src_clean/tools_valid_xs.c \
		src_clean/handler_map_draw.c \
		src_clean/tools_free.c \
		src_clean/handler_map_validator.c \
		src_clean/tools_inits.c \
		src_clean/handler_player_moves.c \
		src_clean/tools_map.c \
		src_clean/tools_valid_map_2.c \

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
