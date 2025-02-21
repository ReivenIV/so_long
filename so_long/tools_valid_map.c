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
int are_map_rows_same_length(char **map) //* map_is_rectangular
{
	int i;

	if (!map)
		return (0);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
		{
			write(1, "ERROR : map has no sorrounded walls\n", 36);
			return (0);
		}
		i++;
	}
	return (1);
}
// Will check if the map has sorrounded walls (1)
// TODO is_map_sorrounded_by_1
int	is_map_sorrounded_by_1(char **map) //* map_wall_is_valid 
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
	while (j < len)			// check first & final row has only 1
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (write(1, "ERROR : invalid sorrounded walls\n" , 33), 0);
		j++;
	}
	i = 1;
	while (map[i])								// check first & last columne has only 1
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (write(1, "ERROR : invalid sorrounded walls\n" , 33), 0);
		i++;
	}
	return (1);
}

// test is_map_sorrounded_by_1
// // int main(void)
// // {
// //     // Example map
// //     char *map[] = {
// //         "111111",
// //         "100001",
// //         "101001",
// //         "100001",
// //         "111111",
// //         NULL
// //     };

// //     // Test the function
// //     if (is_map_sorrounded_by_1(map))
// //         printf("The map is correctly surrounded by walls.\n");
// //     else
// //         printf("The map is not correctly surrounded by walls.\n");

// //     return 0;
// // }

// Will check if the map has only valid attributs ('P', 'E', 'C', '0', '1')
int	are_map_attributs_valide(char **map) // map_is_correct
{
	int i;
	int j;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '0' && map[i][j] != '1')
			{
				write(1, "ERROR : map has invalide attributs\n", 34);
				return (0);
			}
			j++;
		}
		i++;
	}
}

// Will check if maps rules are respected: has collectibles & only 1 player & only 1 exit
int are_map_rules_respected(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] == '\0')
		{
			if (game->map[i][j] == 'C')
				game->collect++;
			else if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (game->collect == 0 || game->player != 1 || game->exit != 1)
	{
		write(1, "ERROR : map rules not respected\n", 32);
		return (0);
	}
	return (1);
}
