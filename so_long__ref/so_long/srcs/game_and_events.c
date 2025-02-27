/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_and_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:33:32 by lbordona          #+#    #+#             */
/*   Updated: 2025/02/27 15:27:23 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	start_game(t_game *game)
{
	// // int	rows;
	// // int	cols;

	// // rows = game->amount_rows * SIZE;
	// // cols = game->amount_cols * SIZE;
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window(game->mlx, game->amount_cols * SIZE, 
		game->amount_rows * SIZE, "so long my dear");
	draw_map(game);

	mlx_hook(game->win, KeyPress, KeyPressMask, handler_player_moves, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, &handler_exit_game, game);
	mlx_loop(game->mlx);
	//gameplay(game);
}

// // int	handle_exit(t_game *game)
// // {
// // 	handler_exit_game(game);
// // 	exit(0);
// // }

// // int	handle_keypress(int key, t_game *game)
// // {
// // 	if (key == XK_Escape)
// // 		handler_exit_game(game);
// // 	else if (key == XK_w || key == XK_Up)
// // 		handler_player_moves('W', game);
// // 	else if (key == XK_a || key == XK_Left)
// // 		handler_player_moves('A', game);
// // 	else if (key == XK_s || key == XK_Down)
// // 		handler_player_moves('S', game);
// // 	else if (key == XK_d || key == XK_Right)
// // 		handler_player_moves('D', game);
// // 	return (0);
// // }

// // void	gameplay(t_game *game)
// // {
// // 	mlx_hook(game->win, KeyPress, KeyPressMask, handler_player_moves, game);
// // 	mlx_hook(game->win, DestroyNotify, ButtonPressMask, &handler_exit_game, game);
// // 	mlx_loop(game->mlx);
// // }
