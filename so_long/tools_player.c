/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:17:09 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 17:17:09 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will update the coordinates x:y of the player in the struct t_game.
void	update_player_coordinates(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_rows)
	{
		x = 0;
		while (x > game->map_cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->pos_x = x;
				game->pos_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}