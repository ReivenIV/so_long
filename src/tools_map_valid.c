/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:57:11 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/21 11:57:11 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will check the length of each row if they have the same TRUE 
static int	are_map_rows_same_length(char **map)
{
	int i;

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
static int	is_map_surrounded_by_1(char **map)
{
	int	i;
	int	j;
	int	len;

	if (!map)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(map[0]);
	while (map[i])
		i++;
	while (j < len)								// check first & final row has only 1
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (write(1, "ERROR : invalid map surrounded walls\n" , 37), 0);
		j++;
	}
	i = 1;
	while (map[i])								// check first & last columne has only 1
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (write(1, "ERROR : invalid map surrounded walls\n" , 37), 0);
		i++;
	}
	return (1);
}

// Will check if the map has only valid attributs ('P', 'E', 'C', '0', '1')
static int	are_map_attributs_valide(char **map)
{
	int i;
	int j;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')				// will check if the map has only valid atributs.
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '0' && map[i][j] != '1')
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

// Will check if maps rules are respected: has collectibles & only 1 player & only 1 exit
//! I don't like that is doing 2 things adding data to game struct and checking later. 
// TODO create 2 functions.
static int	are_map_rules_respected(t_game *game)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (game->map[i])		
	{
		j = 0;
		//printf("%s\n", game->map[i]);					// only for testing mode
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
		return (write(1, "ERROR : map rules not respected.\n", 33), 0);
	return (1);
}

// A handler of above functions.
int	is_map_format_corect(t_game *game)
{
	if (are_amount_rows_same_length(game->map) == 0)
		return (free_map(game->map), exit(1), 0);
	if (is_map_sorrounded_by_1(game->map) == 0)
		return (free_map(game->map), exit(1), 0);
	if (are_map_attributs_valide(game->map) == 0)
		return (free_map(game->map), exit(1), 0);
	if (are_map_rules_respected(game->map) == 0)
		return (free_map(game->map), exit(1), 0);
	return (1);
}

// Test funcs
// int main(void)
// {
//     // Example map
//     char *map[] = {
//         "111111",
//         "10C0C1",
//         "1000E1",
//         "100P01",
//         "111111",
//         NULL
//     };
// 	t_game	game;
// 	init_struct_game(&game);
// 	game.map = map;
//     // Test the functions
// 	are_amount_rows_same_length(map);
//     is_map_sorrounded_by_1(map);
// 	are_map_attributs_valide(map);
// 	are_map_rules_respected(&game);
//     return 0;
// }