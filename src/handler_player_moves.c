/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_player_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:29:50 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 15:30:57 by bobydear         ###   ########.fr       */
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
	if (key == 'W' && is_next_position_valid(game, x, (y - 1)) == 1)
		move(game, 'W', x, y);
	if (key == 'A' && is_next_position_valid(game, (x - 1), y) == 1)
		move(game, 'A', x, y);
	if (key == 'S' && is_next_position_valid(game, x, (y + 1)) == 1)
		move(game, 'S', x, y);
	if (key == 'D' && is_next_position_valid(game, (x + 1), y) == 1)
		move(game, 'D', x, y);
	return ;
}
