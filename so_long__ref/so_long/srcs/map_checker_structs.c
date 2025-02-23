/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_structs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:55:16 by lbordona          #+#    #+#             */
/*   Updated: 2025/02/22 16:13:38 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


//! Thes is not checking if the map is rectangular is checking if the rows have the same amunt of caracters
int	are_amount_rows_same_length(char **map) //* are_amount_rows_same_length
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			ft_printf("\033[0;31mError → Map isn't rectangular.\n");
			return (0);
		}
		i++;
	}
	return (1);
}
// These is checking if the map is sorrounded by 1
int	is_map_sorrounded_by_1(char **map) //* is_map_sorrounded_by_1
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

// Will check if the map has only valid attributs ('P', 'E', 'C', '0', '1')
int	are_map_attributs_valide(char **map) // are_map_attributs_valide
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
					&& map[i][j] != '0' && map[i][j] != '1')
			{
				ft_printf("\033[0;31mError → Map has invalid character.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Will check if maps rules are respected: has collectibles & only 1 player & only 1 exit
int	are_map_rules_respected(t_game *game)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				game->amount_c++;
			else if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (game->amount_c == 0 || game->player != 1 || exit != 1)
		return (0);
	return (1);
}
