/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:00:10 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 13:00:10 by bobytrap         ###   ########.fr       */
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
	// // int		exit;
	// // int		wall;
	// // int		background;
}	t_game;


//	--------------
//	::  Assets  ::
//	--------------

//	------------
//	::  keys  ::
//	------------
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

//	------------------
//	::  Validators  ::
//	------------------
int		validator_xs(int ac, char **av);

//	-------------
//	::  Tools  ::
//	-------------

// Tools_init
void	init_struct_game(t_game *game);
int		init_map(char *av, t_game *game);

// Tools_map
// // int		count_cols(char *line);
// // void	update_map_data(t_game *game);
int	count_lines(char *av);

// Tools_valid_map
int are_amount_rows_same_length(char **map);
int	is_map_sorrounded_by_1(char **map);
int	are_map_attributs_valide(char **map);
int are_map_rules_respected(t_game *game);

// Tools_player
void	update_player_coordinates(t_game *game);

// Tools_str
// // int	ft_strlen(char *str);

//	------------
//	::  Free  ::
//	------------
void	free_map(char **map, t_game *game);


//! Tools print just for testing mode
void print_game_struct(t_game *game);				//!-- To erase. --//
void print_map(char **map, int rows);				//!-- To erase. --//




#endif