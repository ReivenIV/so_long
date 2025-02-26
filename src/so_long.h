/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:00:10 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/26 15:10:51 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>									//! printf just for testing 
# include <unistd.h>								// Write
# include <stdlib.h>								// Mallocs
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
# define EXIT_IMG "./images/E.xpm"
# define COLLECT_IMG "./images/C.xpm"
# define WALL_IMG "./images/1.xpm"
# define BACKGROUND_IMG "./images/0.xpm"

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
	void	*win;					// win = window
	void	*img_player_w;			// front
	void	*img_player_a;			// right
	void	*img_player_s;			// left
	void	*img_player_d;			// back
	void	*img_exit;
	void	*img_collect;
	void	*img_wall;
	void	*img_bg;
	char 	**map;
	char	**temp_map;
	int		img_width;
	int		img_height;
	int		amount_rows;
	int		amount_cols;
	int		player;
	int		coor_x;					// i prefere cor_x (pos = position)
	int		coor_y;					// i prefere cor_y
	int		amount_c;
	int		collected;
	int		moves;
	int		exit;
	// // int		wall;
	// // int		background;
}	t_game;




//	------------
//	::  keys  ::
//	------------
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

//	----------------
//	::  Handlers  ::
//	----------------
void	handler_map_validator(char **av, t_game *game);
void	handler_map_draw(t_game *game);


//	-------------
//	::  Tools  ::
//	-------------

// Tools_init
void	init_struct_game(t_game *game);
int		init_map(char *av, t_game *game, int amount_rows);

// Tools_map
int		count_lines(char *av);
void	count_pecs(t_game *game);

// Tools_valid_map | validators | Parser
int		validator_xs(int ac, char **av);
int		is_map_format_correct(t_game *game);
int		are_map_paths_valid(char **av, t_game *game);

// Tools_player
void	update_player_coordinates(t_game *game);

//	------------
//	::  Free  ::
//	------------
void	free_map(char **map, t_game *game);

//! Tools print just for testing mode
void	print_game_struct(t_game *game);				//!-- To erase. --//
void	print_map(char **map, int rows);				//!-- To erase. --//

#endif