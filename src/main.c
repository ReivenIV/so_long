/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:48:42 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/25 18:00:15 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (exit(1), 0);  
	validator_xs(ac, av);
	init_struct_game(&game);
	handler_map_validator(av, &game);			// Step: parser finit
	free_map(game.map, &game);
	return (0);
}
