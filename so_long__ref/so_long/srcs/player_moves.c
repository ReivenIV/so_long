/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:19 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/26 18:10:33 by rita             ###   ########.fr       */
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

void	move(t_game *game, char key, int x, int y)
{
	if (key == 'W')
	{
		player_move_w(game, x, (y - 1));
		update_player_coordinates(game, x, y - 1);
		game->map[y][x] = '0';
	}
	if (key == 'A')
	{
		player_move_a(game, (x - 1), y);
		update_player_coordinates(game, (x - 1), y);
		game->map[y][x] = '0';
	}
	if (key == 'S')
	{
		player_move_s(game, x, (y + 1));
		update_player_coordinates(game, x, (y + 1));
		game->map[y][x] = '0';
	}
	if (key == 'D')
	{
		player_move_d(game, (x + 1), y);
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
