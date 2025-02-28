/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:04 by rita              #+#    #+#             */
/*   Updated: 2025/02/27 13:37:57 by bobydear         ###   ########.fr       */
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
	// We finish initing the struct
	game->amount_rows = count_lines(av[1]);
	init_map(av[1], game, game->amount_rows);
	game->amount_cols = ft_strlen(game->map[0]);
	count_pecs(game);
	//! print_game_struct(game);
	//! print_map(game->map, game->amount_rows);

	// We start a full validation of the received map. 
	is_map_format_correct(game);												// (0/1) Will check every caracter in the map
	are_map_paths_valid(av, game);												// (0/1) Will create a temp_map use flood fill test every path then free the 2 temp_maps
}