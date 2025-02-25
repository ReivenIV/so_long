/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:04 by rita              #+#    #+#             */
/*   Updated: 2025/02/25 15:00:57 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handler_map_validator(char **av, t_game *game)
{
	game->amount_rows = count_lines(av[1]);
	init_map(av[1], game, game->amount_rows);
	game->amount_cols = ft_strlen(game->map[0]);
	count_pecs(game);
	//! print_game_struct(game);
	//! print_map(game->map, game->amount_rows);
	is_map_format_correct(game);
	are_map_paths_valid(av, game);
	printf("looks good my dear\n");
}