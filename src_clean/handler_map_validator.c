/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 88888888 <88888888@contact.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:04 by rita              #+#    #+#             */
/*   Updated: 2025/02/28 19:02:00 by 88888888         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
- Will finish the initiation of the t_game struct
- caracter/format map and if the paths  of the map are 
	possible (flood_fill + 2x temp_maps) because we cannot pass throught the 
	exit if you didn't collect all collectibles.
*/
void	handler_map_validator(char **av, t_game *game)
{
	game->amount_rows = count_lines(av[1]);
	init_map(av[1], game, game->amount_rows);
	game->amount_cols = ft_strlen(game->map[0]);
	count_pecs(game);
	is_map_format_correct(game);
	are_map_paths_valid(av, game);
}
