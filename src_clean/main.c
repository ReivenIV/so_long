/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:48:42 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 15:55:12 by bobydear         ###   ########.fr       */
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
	handler_game(&game);
	handler_exit_game(&game);
	return (0);
}
