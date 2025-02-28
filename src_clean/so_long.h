/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 88888888 <88888888@contact.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:00:10 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:58:30 by 88888888         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>	
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

//	------------
//	::  imgs  ::
//	------------
# define PLAYER_W "./images/PW.xpm"
# define PLAYER_S "./images/PS.xpm"
# define PLAYER_A "./images/PA.xpm"
# define PLAYER_D "./images/PD.xpm"
# define IMG_EXIT "./images/E.xpm"
# define IMG_C "./images/C.xpm"
# define IMG_WALL "./images/1.xpm"
# define IMG_BG "./images/0.xpm"

//	------------------
//	::  parameters  ::
//	------------------
# define SIZE 32
# define HEIGHT 32
# define WIDTH 32

//	--------------
//	::  Struct  ::
//	--------------
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_p_w;
	void	*img_p_a;
	void	*img_p_s;
	void	*img_p_d;
	void	*img_exit;
	void	*img_collect;
	void	*img_wall;
	void	*img_bg;
	char	**map;
	char	**temp_map;
	int		amount_rows;
	int		amount_cols;
	int		player;
	int		coor_x;
	int		coor_y;
	int		amount_c;
	int		collected;
	int		moves;
	int		exit;
}	t_game;

//	----------------
//	::  Handlers  ::
//	----------------
void	handler_map_validator(char **av, t_game *game);
void	handler_map_draw(t_game *game);
int		handler_player_moves(int key, void *param);
int		handler_exit_game(t_game *game);
void	handler_game(t_game *game);

//	-------------
//	::  Tools  ::
//	-------------

// Tools_init
void	init_struct_game(t_game *game);
int		init_map(char *av, t_game *game, int amount_rows);
void	init_images(t_game *game);

// Tools_map
int		count_lines(char *av);
void	count_pecs(t_game *game);

// Tools_valid_map | validators | Parsers
int		validator_xs(int ac, char **av);
int		is_map_format_correct(t_game *game);
int		are_map_paths_valid(char **av, t_game *game);

// Tools_player
void	get_player_coordinates(t_game *game);
void	update_player_coordinates(t_game *game, int x, int y);

// tools_player_moves
int		is_next_pos_ok(t_game *game, int x, int y);
void	move_player(t_game *game, char key, int x, int y);

//	------------
//	::  Free  ::
//	------------
void	free_map(char **map, t_game *game);

#endif