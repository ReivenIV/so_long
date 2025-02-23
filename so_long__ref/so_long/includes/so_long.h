/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:58:08 by lbordona          #+#    #+#             */
/*   Updated: 2025/02/22 16:15:46 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Includes: */
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Define parameters: */
# define SIZE 32
# define HEIGHT 32
# define WIDTH 32

/* Define images: */
# define PLAYER_W "./assets/images/PW.xpm"
# define PLAYER_S "./assets/images/PS.xpm"
# define PLAYER_A "./assets/images/PA.xpm"
# define PLAYER_D "./assets/images/PD.xpm"
# define EXIT_IMG "./assets/images/E.xpm"
# define COLLECT_IMG "./assets/images/C.xpm"
# define WALL_IMG "./assets/images/1.xpm"
# define BACKGROUND_IMG "./assets/images/0.xpm"

/* Define keys: */
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/* Game structure: */
typedef struct s_game
{
	void	*mlx;
	void	*win;				// win = "window" needed to display the window with mlx
	void	*img_player_w;
	void	*img_player_a;
	void	*img_player_s;
	void	*img_player_d;
	void	*img_exit;
	void	*img_collect;
	void	*img_wall;
	void	*img_bg;
	char	**map;
	char	**temp_map;
	int		img_width;
	int		img_height;
	int		amount_rows;
	int		amount_cols;
	int		amount_c;			// amount collectibles
	int		player;
	int		coor_x;				// position: x
	int		coor_y;				// position: y
	// // int		exit;				// amount of exits
	// // int		wall;
	// // int		background;
	int		collected;
	int		moves;
}	t_game;

/* map_checker.c: */
void	check_map_struct(t_game *game);
void	check_map_empty_lines(t_game *game);
void	check_map_path(char *av, t_game *game);
void	full_map_checker(char *av, t_game *game);

/* map_checker_structs.c: */
int		are_amount_rows_same_length(char **map);
int		is_map_sorrounded_by_1(char **map);
int		are_map_attributs_valide(char **map);
int		are_map_rules_respected(t_game *game);


/* initialize.c: */
void	init_struct(t_game *game);
void	init_map(char *av, t_game *game);
void	init_temp_map(char *av, t_game *game);
void	init_imgs(t_game *game);

/* free.c: */
void	free_map(char **map, t_game *game);
void	exit_game(t_game *game);

/* draw.c: */
////void	draw_img(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game);

/* game_and_events.c: */
int		handle_exit(t_game *game);
int		handle_keypress(int key, t_game *game);
void	gameplay(t_game *game);
void	start_game(t_game *game);


/* utils.c: */
int		count_lines(char *av);
////int		count_cols(char *line);
void	player_position(t_game *game);
int		flood_fill(t_game *game, char **map, int x, int y);

/* player_moves.c: */
int		check_next_position(t_game *game, int x, int y);
void	player_new_position(t_game *game, int x, int y);
void	move(t_game *game, char key, int x, int y);
void	player_moves(char key, t_game *game);

/*player_moves_2.c: */
void	player_move_w(t_game *game, int new_x, int new_y);
void	player_move_a(t_game *game, int new_x, int new_y);
void	player_move_s(t_game *game, int new_x, int new_y);
void	player_move_d(t_game *game, int new_x, int new_y);


#endif
