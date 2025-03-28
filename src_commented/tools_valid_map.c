/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:57:11 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 14:00:12 by bobydear         ###   ########.fr       */
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
	while (j < a_cols)								// check first & final row has only 1
	{
		if (game->map[0][j] != '1' || game->map[a_rows - 1][j] != '1')
			return (write(1, "1 ERROR : invalid map surrounded walls\n" , 39), 0);
		j++;
	}
	i = 1;
	while (i < a_rows - 1)								// check first & last columne has only 1
	{
		if (game->map[i][0] != '1' || game->map[i][a_cols - 1] != '1')
			return (write(1, "2 ERROR : invalid map surrounded walls\n" , 39), 0);
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

// TODO erase 
// // // // Will check if maps rules are respected: has collectibles & only 1 player & only 1 exit
// // // //! I don't like that is doing 2 things adding data to game struct and checking later. 
// // // // TODO create 2 functions.
// // // static int	are_map_rules_respected(t_game *game)
// // // {
// // // 	int	i;
// // // 	int	j;
// // // 	int	exit;

// // // 	i = 0;
// // // 	exit = 0;
// // // 	while (game->map[i])		
// // // 	{
// // // 		j = 0;
// // // 		//printf("%s\n", game->map[i]);					// only for testing mode
// // // 		while (game->map[i][j] != '\0')
// // // 		{
// // // 			if (game->map[i][j] == 'C')
// // // 				game->amount_c++;
// // // 			else if (game->map[i][j] == 'P')
// // // 				game->player++;
// // // 			else if (game->map[i][j] == 'E')
// // // 				exit++;
// // // 			j++;
// // // 		}
// // // 		i++;
// // // 	}
// // // 	if (game->amount_c == 0 || game->player != 1 || exit != 1)
// // // 		return (write(1, "ERROR : map rules not respected.\n", 33), 0);
// // // 	return (1);
// // // }

// A handler of above functions.
int	is_map_format_correct(t_game *game)
{
	//! print_game_struct(game);
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
	if (game->amount_c == 0 || game->player != 1 || game->exit != 1)	// Will check if are map rules are respected
	{
		write(1, "ERROR : map rules not respected.\n", 33);
		return (free_map(game->map, game), exit(1), 0);
	}
	return (1);
}

// Test main is_map_format_correct
// int main(int argc, char **argv)
// {
// 	t_game game;
// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <map_file>\n", argv[0]);
// 		return 1;
// 	}
// 	init_struct_game(&game);
// 	game.amount_rows = count_lines(argv[1]);
// 	if (game.amount_rows == -1)
// 	{
// 		perror("Error counting lines in file");
// 		return 1;
// 	}
// 	if (!init_map(argv[1], &game, game.amount_rows))
// 	{
// 		perror("Error initializing map");
// 		return 1;
// 	}
// 	game.amount_cols = ft_strlen(game.map[0]);                      // Set the amount_cols based on the first row length
// 	count_pecs(&game);												// Will count amount of : Player, Exit, Collectibles
// 	get_player_coordinates(&game);
// 	//	print_game_struct(&game);
// 	// Test the functions
// 	is_map_format_correct(&game);
// 	free_map(game.map, &game);
// 	printf("map is correct\n");
// 	return (0);
// }