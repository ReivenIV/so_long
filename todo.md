# TODO

## GNL & LIBFT
	- [x] bring LIBFT and GNL to the project. 
	- [x] connect GNL to LIBFT, .h, makefile
	- [x] test from so_long projet a function using GNL.

## Main structure:
	- [x]	validator_xs
	- [x]	init_struct	(will create a struct with almost everything empty atributs)
	- [ ]	is_valid_map

	- [ ]	init_map   (show screen, complet game struct)
	- [ ]	start_game (handle events)
	- [ ]	close_game	(at the end will free the game and all the process)

## Checkers: 
	- [x] validator_xs
		- simple checks args, real file
	- [x] define global struct
	- [x] init global struct
	- [ ] map check
		- will need to bring:
		- [x] GNL 
		- [x] LIBFT 
		- [ ] PRINTF ?
			- will try to avoid using printf i prefer write

## [ ] is_valid_map
	- [x] Has same amount of columns ?  -> are_amount_rows_same_length
	- [x] is the map sourrounded by walls ? (1)  -> is_map_sorrounded_by_1
	- [x] the map has only valid caracters ? ('P', 'E', 'C', '0', '1')  -> are_map_attributs_valide
	- [x] are amount of items correct ? -> are_map_rules_respected
		- has collectibles 
		- only 1 player
		- only 1 exit
	- [x] count_lines using GNL
	- [x] flood fill
<!-- TODO validator_map -->
	- [ ] validator_map (we will need init map)
		- [x] create a handler calling all is/are functions.
			- [ ] need testing with valgrind <!-- TODO-->
		- [ ] create a function that checks all the paths (are_map_paths_valid)
			- [ ] test with valgrind
				- report:
				- [x] Is working with small maps
				- [x] Is working with maps that have many rows
				- [ ] <!-- TODO--> Leaks apear when we have many long rows. Need fix
		- [ ] when all above test are passed use flood fill to check if the paths are possible to play. (avoid using a temp_map in the struct).


## Inits 
	- [x] init_struct
	- [x] init_map
	- [ ] init_map_temp (i want to avoid using a temp_map in the struct)
		- map_temp only is used to check the map with flood fill
	- [ ] init_imgs (will need mlx)