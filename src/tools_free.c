/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:51:14 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/25 13:04:20 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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