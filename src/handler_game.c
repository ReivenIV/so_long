/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:38:40 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 16:06:47 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handler_game(t_game *game)
{
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window(game->mlx, game->amount_cols * SIZE, game->amount_rows * SIZE, "So long Baby !");
	handler_map_draw(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, handler_player_moves, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, &handler_exit_game, game);
	mlx_loop(game->mlx);
}