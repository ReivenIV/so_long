# TODO

## Main structure: ✅
	- [x]	validator_xs
	- [x]	init_struct	(will create a struct with almost everything empty atributs)
	- [x]	handler_map_validator
	- [x]	handler_show_in_screen 
		- [x] show screen
		- [x] show assets complet
	- [x]	start_game (handle events)
	- [x]	close_game	(f)
		- [x] free the game (map + imgs)
		- [x] end process

## Inits ✅
	- [x] init_struct
	- [x] init_map
	- [x] init_map_temp
		- reminder : I found a way to not do it without using an extra atribut in the struct
	- [x] init_images (will need mlx)


## GNL & LIBFT (done) ✅
	- [x] bring LIBFT and GNL to the project. 
	- [x] connect GNL to LIBFT, .h, makefile
	- [x] test from so_long projet a function using GNL.

## validators:  (done) ✅
	- [x] validator_xs
		- simple checks args, real file
	- [x] define global struct
	- [x] init global struct
	- [x] map check
		- will need to bring:
		- [x] GNL 
		- [x] LIBFT 
		- [x] PRINTF ?
			- will try to avoid using printf i prefer write

##  handler_map_validator (done) ✅
	- [x] Has same amount of columns ?  -> are_amount_rows_same_length
	- [x] is the map sourrounded by walls ? (1)  -> is_map_sorrounded_by_1
	- [x] the map has only valid caracters ? ('P', 'E', 'C', '0', '1')  -> are_map_attributs_valide
	- [x] are amount of items correct ? -> are_map_rules_respected
		- has collectibles 
		- only 1 player
		- only 1 exit
	- [x] count_lines using GNL
	- [x] flood fill
	- [x] **handler_map_validator** (we will need init map)
		- [x] create a handler calling all is/are functions.
			- [x] need testing with valgrind.
			- [x] no leaks.
		- [x] create a function that checks all the paths (are_map_paths_valid)
			- We need 2: 
				- [x] flood_fill_c to check if in all paths we can collect everything
				- [x] flood_fill_e_c to check if in all paths we can collect everything and exit
			- [x] test with valgrind
				- Working with valid maps: 
					- [x] works with XS maps ?
					- [x] works with XXL maps ?
					- [x] works with maps that have many rows ?
					- [x] no leaks
				- Working with invalid maps:
					- [x] BLOCKs when : path are not valid
					- [x] BLOCKs when : wrong map file format
					- [x] BLOCKs when : bad attributs
					- [x] BLOCKs when : not respecting rules of atributs 
						- no square
						- 1 exit
						- 1 player
						- sourounding is all 1 (walls)