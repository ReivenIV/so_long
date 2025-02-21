/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:51:14 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/21 15:51:14 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, t_game *game)
{
	int i;

	i = 0;
	while (i < game->map_rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}