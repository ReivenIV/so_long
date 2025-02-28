/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:38:40 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:14:03 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
These is a pretty big handler. Will : 
- init mlx struct. 
- through init_images: Will "mount" imgs to the struct.
- through handler_map_draw : Will draw the initial state of the map.
- through handler_player_moves: 
	- listen key events.
	- move player, collect items.
	- print in the terminal moves.
	- update images.
	- If all collected. 
- throught handler_exit_game: 
	- Will free map in struct.
	- Will free images mounted in struct. 
	- end process.
*/
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