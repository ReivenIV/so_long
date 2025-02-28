/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:51:14 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:05:34 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will free the map (Very usefull)
void	free_map(char **map, t_game *game)
{
	int i;

	if (!map)
	{
		write(1, "ERROR: free_map, empty map\n", 27);
		return ;
	}
	i = 0;
	while (i < game->amount_rows)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}
