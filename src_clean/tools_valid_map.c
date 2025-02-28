/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 88888888 <88888888@contact.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:57:11 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:41:47 by 88888888         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will check the length of each row if they have the same TRUE 
static int	are_map_rows_same_length(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
		{
			write(1, "ERROR : map has rows with iregular lenth.\n", 42);
			return (0);
		}
		i++;
	}
	return (1);
}

// Will check if the map has sorrounded walls (1) 
static int	is_map_surrounded_by_1(t_game *game)
{
	int	i;
	int	j;
	int	a_rows;
	int	a_cols;

	i = 0;
	j = 0;
	a_rows = game->amount_rows;
	a_cols = game->amount_cols;
	while (game->map[i])
		i++;
	while (j < a_cols)
	{
		if (game->map[0][j] != '1' || game->map[a_rows - 1][j] != '1')
			return (write(1, "1 ERROR : invalid surrounded walls\n", 35), 0);
		j++;
	}
	i = 1;
	while (i < a_rows - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][a_cols - 1] != '1')
			return (write(1, "2 ERROR : invalid surrounded walls\n", 35), 0);
		i++;
	}
	return (1);
}

// Will check if the map has only valid attributs ('P', 'E', 'C', '0', '1')
static int	are_map_attributs_valide(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j]
				!= 'C' && map[i][j] != '0' && map[i][j] != '1')
			{
				write(1, "ERROR : map has invalide attributs.\n", 36);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// A handler of above functions.
int	is_map_format_correct(t_game *game)
{
	if (game->amount_cols == game->amount_rows)
	{
		write(1, "ERROR : map must be rectangular.\n", 33);
		return (free_map(game->map, game), exit(1), 0);
	}
	if (are_map_rows_same_length(game->map) == 0)
		return (free_map(game->map, game), exit(1), 0);
	if (is_map_surrounded_by_1(game) == 0)
		return (free_map(game->map, game), exit(1), 0);
	if (are_map_attributs_valide(game->map) == 0)
		return (free_map(game->map, game), exit(1), 0);
	if (game->amount_c == 0 || game->player != 1 || game->exit != 1)
	{
		write(1, "ERROR : map rules not respected.\n", 33);
		return (free_map(game->map, game), exit(1), 0);
	}
	return (1);
}
