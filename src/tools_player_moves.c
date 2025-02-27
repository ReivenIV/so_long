/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_player_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:38:25 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 13:40:10 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_next_position_valid(t_game *game, int x, int y)
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
		write(1, "Win my dear!!\n", 14);
		handler_exit_game(game);
	}
	return (0);
}

// ny = new_y & nx = new_x 
void	update_p_move_img(t_game *game, int nx, int ny, char key)
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	
	nx = nx * SIZE;
	ny = ny * SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->img_bg, x, y);
	if (key == 'w')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_w, nx, ny);
	if (key == 'a')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_a, nx, ny);
	if (key == 's')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_s, nx, ny);	
	if (key == 'd')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_d, nx, ny);
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n: ", 1);
}

void	move(t_game *game, char key, int x, int y)
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
