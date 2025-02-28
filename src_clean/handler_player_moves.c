/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_player_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:29:50 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 16:38:58 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will call tools_player_moves.c & tools_player.C
/*
Will manage during the game : 
	- All images updates, 
	- game->map updates, 
	- key events 
	- IFs the player can or not move in a certain direction.  
*/
int	handler_player_moves(int key, void *param)
{
	int	x;
	int	y;
	t_game	*game;

	game = (t_game *)param;
	x = game->coor_x;
	y = game->coor_y;
	if (key == XK_Escape)
		handler_exit_game(game);
	else if ((key == XK_w || key == XK_Up) && is_next_pos_ok(game, x, (y - 1)) == 1)
		move_player(game, 'W', x, y);
	else if ((key == XK_a || key == XK_Left) && is_next_pos_ok(game, (x - 1), y) == 1)
		move_player(game, 'A', x, y);
	else if ((key == XK_s || key == XK_Down) && is_next_pos_ok(game, x, (y + 1)) == 1)
		move_player(game, 'S', x, y);
	else if ((key == XK_d || key == XK_Right) && is_next_pos_ok(game, (x + 1), y) == 1)
		move_player(game, 'D', x, y);
	return (0);
}
