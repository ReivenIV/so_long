/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_player_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:38:25 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 17:51:00 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_next_pos_ok(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
		return (game->collected++, 1);
	if (game->map[y][x] == 'E' && (game->collected != game->amount_c))
		return (0);
	if (game->map[y][x] == 'E' && (game->collected == game->amount_c))
	{
		write(1, "Win my dear win!!\n", 18);
		handler_exit_game(game);
	}
	return (0);
}

/*
In every movement of the player we will will update the images concerned.
and we will count and print every movement into the terminal. 
*/
static void	update_p_move_img(t_game *game, int nx, int ny, char key)
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

/*
Will update the coords in the struct plus in the map + the images
*/
void	move_player(t_game *game, char key, int x, int y)
{
	if (key == 'W')
	{
		update_p_move_img(game, x, (y - 1), 'W');
		update_player_coordinates(game, x, (y - 1));
	}
	if (key == 'A')
	{
		update_p_move_img(game, (x - 1), y, 'A');
		update_player_coordinates(game, (x - 1), y);
	}
	if (key == 'S')
	{
		update_p_move_img(game, x, (y + 1), 'S');
		update_player_coordinates(game, x, (y + 1));
	}
	if (key == 'D')
	{
		update_p_move_img(game, (x + 1), y, 'D');
		update_player_coordinates(game, (x + 1), y);
	}
	game->map[y][x] = '0';
}
