/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:19 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 13:27:58 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_player_coordinates(t_game *game, int x, int y) // DONE : "tools_player".c
{
	game->coor_x = x;
	game->coor_y = y;
}

static int	is_next_position_valid(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		return (1);
	}
	if (game->map[y][x] == 'E' && (game->collected != game->amount_c))
		return (0);
	if (game->map[y][x] == 'E' && (game->collected == game->amount_c))
	{
		ft_printf("\033[0;32mYOU HELPED THOR TO SAVE THE WORLD FROM THANOS!\n");
		handler_exit_game(game);
	}
	return (0);
}
//! ..:: Testing mode ::..
// Will need to be moved away 
static void	update_p_move_img(t_game *game, int nx, int ny, char key) // DONE : "tools_player_moves"
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	
	nx = nx * SIZE;
	ny = ny * SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->img_bg, x, y);
	if (key == 'W')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_w, nx, ny);
	if (key == 'A')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_a, nx, ny);
	if (key == 'S')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_s, nx, ny);	
	if (key == 'D')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_d, nx, ny);
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n: ", 1);
}

static void	move(t_game *game, char key, int x, int y)
{
    if (key == 'W')
    {
        update_p_move_img(game, x, (y - 1), 'W');
        update_player_coordinates(game, x, (y - 1));
        ////game->map[y][x] = '0';
    }
    else if (key == 'A')
    {
        update_p_move_img(game, (x - 1), y, 'A');
        update_player_coordinates(game, (x - 1), y);
        ////game->map[y][x] = '0';
    }
    else if (key == 'S')
    {
        update_p_move_img(game, x, (y + 1), 'S');
        update_player_coordinates(game, x, (y + 1));
        ////game->map[y][x] = '0';
    }
    else if (key == 'D')
    {
        update_p_move_img(game, (x + 1), y, 'D');
        update_player_coordinates(game, (x + 1), y);
        ////game->map[y][x] = '0';
    }
	game->map[y][x] = '0';
}

//!  testing mode : 
void	handler_player_moves(char key, t_game *game)	// DONE 
{
	int	x;
	int	y;

	x = game->coor_x;
	y = game->coor_y;
	if (key == 'W'  && is_next_position_valid(game, x, (y - 1)) == 1)
		move(game, 'W', x, y);
	if (key == 'A' && is_next_position_valid(game, (x - 1), y) == 1)
		move(game, 'A', x, y);
	if (key == 'S' && is_next_position_valid(game, x, (y + 1)) == 1)
		move(game, 'S', x, y);
	if (key == 'D' && is_next_position_valid(game, (x + 1), y) == 1)
		move(game, 'D', x, y);
	return ;
}
