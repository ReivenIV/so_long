/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 88888888 <88888888@contact.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:17:09 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:43:49 by 88888888         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Without x:y coordinates we found the player x:y and we update the struct.
void	get_player_coordinates(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->amount_rows)
	{
		x = 0;
		while (x < game->amount_cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->coor_x = x;
				game->coor_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

// With a given x:y we update the game->cordinates of the player position.
void	update_player_coordinates(t_game *game, int x, int y)
{
	game->coor_x = x;
	game->coor_y = y;
}
