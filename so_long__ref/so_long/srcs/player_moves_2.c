/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:56:15 by lbordona          #+#    #+#             */
/*   Updated: 2025/02/22 15:13:08 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_w(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_bg, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_w, new_x, new_y);
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

void	player_move_a(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_bg, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_a, new_x, new_y);
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

void	player_move_s(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_bg, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_s, new_x, new_y);
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

void	player_move_d(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_bg, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_d, new_x, new_y);
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}
