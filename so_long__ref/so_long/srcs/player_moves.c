/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:19 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/26 19:20:10 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_player_coordinates(t_game *game, int x, int y) // done
{
	game->coor_x = x;
	game->coor_y = y;
}

int	is_next_position_valid(t_game *game, int x, int y)
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
void	next_player_move(t_game *game, int nx, int ny, char key)
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	
	nx = nx * SIZE;
	ny = ny * SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->img_bg, x, y);
	// W A S D
	if (key == 'w')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_w, nx, ny);
	if (key == 'a')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_a, nx, ny);
	if (key == 's')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_s, nx, ny);	
	if (key == 'd')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_d, nx, ny);
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

void	move(t_game *game, char key, int x, int y)
{
    if (key == 'W')
    {
        next_player_move(game, x, (y - 1), 'w');
        update_player_coordinates(game, x, y - 1);
        game->map[y][x] = '0';
    }
    else if (key == 'A')
    {
        next_player_move(game, (x - 1), y, 'a');
        update_player_coordinates(game, (x - 1), y);
        game->map[y][x] = '0';
    }
    else if (key == 'S')
    {
        next_player_move(game, x, (y + 1), 's');
        update_player_coordinates(game, x, (y + 1));
        game->map[y][x] = '0';
    }
    else if (key == 'D')
    {
        next_player_move(game, (x + 1), y, 'd');
        update_player_coordinates(game, (x + 1), y);
        game->map[y][x] = '0';
    }
}

void	player_moves(char key, t_game *game)
{
	int	x;
	int	y;

	x = game->coor_x;
	y = game->coor_y;
	if (key == 'W')
		if (is_next_position_valid(game, x, y - 1) == 1)
			move(game, 'W', x, y);
	if (key == 'A')
		if (is_next_position_valid(game, x - 1, y) == 1)
			move(game, 'A', x, y);
	if (key == 'S')
		if (is_next_position_valid(game, x, y + 1) == 1)
			move(game, 'S', x, y);
	if (key == 'D')
		if (is_next_position_valid(game, x + 1, y) == 1)
			move(game, 'D', x, y);
}
