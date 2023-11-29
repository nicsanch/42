/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:29:00 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 17:20:07 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <../../libft/inc/libft.h>
# include "MLX42/MLX42.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

# define WIDTH 50
# define HEIGHT 50

/*brief Brief description.
 *         Brief description continued.
 *
 * @param description starts here.
 */
typedef struct s_element
{
	mlx_image_t	*pj;
	mlx_image_t	*end;
	mlx_image_t	*collect;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
}	t_element;

typedef struct s_map
{
	int		width;
	int		height;
	char	**rawmap;
	int		pos[2];
}	t_map;

typedef struct s_game
{
	t_element	*elements;
	t_map		*map;
	mlx_t		*mlx;
}	t_game;

// ERRORS.C //

/**
 * @brief this functions checks the number of arguments given and the extension.
 * @param argc number of arguments that the program gets (must be 2).
 * @param argv the string of the arguments.
 */
void	ft_arg_errors(int argc, char *argv);
/**
 * @brief this functions prints the error found and exit.
 */
void	ft_error(void);
/**
 * @brief this functions prints "Wrong map" and exit in case map is not valid.
 */
void	ft_error_map(void);

// UTILS.C //
/**
 * @brief this functions counts how many items of one kind there are in the map.
 * @param map the map that you are going to check.
 * @param flag the character that represent the element you are looking for.
 * @return the copied array.
 */
int		ft_count_items(char **map, int flag);
/**
 * @brief this functions sets the coordenates of the starting pos.
 * @param map the map that you are going to check.
 */
void	ft_get_pos(t_map *map);
/**
 * @brief this functions copies an array of strings.
 * @param array the array you want to copy.
 * @return the copied array.
 */
char	**ft_copy_array_str(char **array);
/**
 * @brief this functions reads map and generates a matrix that represent the map.
 * @param mapfd the fd of the map file you want to open.
 * @return the array of strings that represent the map.
 */
char	**ft_get_rows(int mapfd);

// MAP.C //
/**
 * @brief this functions prints on the coordinates given the correct image.
 * @param game the structure that contains all the data of the game.
 * @param x the 'x' coordinate of the cell.
 * @param y the 'y' coordinate of the cell.

 */
void	ft_print_cell(t_game *game, int y, int x);
/**
 * @brief this functions gets a texture for 'C' and make and image with it.
 * @param game the structure that contains all the data of the game.
 */
void	ft_print_elements(t_game *game);

// CHECKS.C //

/**
 * @brief this functions checks if there is something wrong with the arguments.
 * @param argc the number of values.
 * @param argv the value of the argcs.
 */
void	ft_check_args(int argc, char **argv, t_map *map);
/**
 * @brief this functions checks if there is something wrong with the map.
 * @param mapfd the fd of the opened map.
 * @param map the structure that keeps allocated all the data of the map.
 */
void	ft_map_check(int mapfd, t_map *map);
/**
 * @brief this functions checks if there is something wrong with the map.
 * @param reachmap a copy of the original map to do flood fill on it.
 * @param x the "x" coordenate of the 'P'.
 * @param y the "y" coordenate of the 'P'.
 * @param map the structure that has all the data related with the map.
 */
void	ft_check_if_reachable(char **reachmap, int y, int x, t_map map);
/**
 * @brief this functions checks if there are on the map 1 'P', 1 'E', and 1+ 'C'.
 * @param map matrix that represent the map.
 */
void	ft_check_min_items(char **map);
/**
 * @brief checks if any char does not represent an "element" on the map.
 * @param map matrix that represent the map.
 * @param elements the string that contains all the letters of our elements.
 */
void	ft_check_unknow_char(char **map, char *elements);

//	CHECKS2.C	//
/**
 * @brief this functions checks if there are empty lines in our map.
 * @param map all the text inside the map file.
 * @param split_len the number of string there are on the matrix.
 */
void	ft_check_empty_lines(char *map, int split_len);
/**
 * @brief this functions checks if the elements items are reachable.
 * @param map the map that you are going to check.
 */
void	ft_check_all_reachable(char **map);
/**
 * @brief this functions checks if the borders of the maps are walls ()'1').
 * @param map the map that you are going to check.
 * @param height the height of the map.
 * @param width the width of the map.
 */
void	ft_check_borders(char **map, int height, int width);
/**
 * @brief this functions checks the rows has the same length.
 * @param map the map that you are going to check.
 * @param height the height of the map.
 * @param width the width of the map.
 */
void	ft_check_shape(char **map, unsigned int height, unsigned int width);

// ELEMENTS.C //
/**
 * @brief this functions gets a texture for 'C' and make and image with it.
 * @param game the structure that contains all the data of the game.
 */
void	ft_get_collect_image(t_game *game);
/**
 * @brief this functions gets a texture for 'E' and make and image with it.
 * @param game the structure that contains all the data of the game.
 */
void	ft_get_end_image(t_game *game);
/**
 * @brief this functions gets a texture for 'P' and make and image with it.
 * @param game the structure that contains all the data of the game.
 */
void	ft_get_pj_image(t_game *game);
/**
 * @brief this functions gets a texture for '0' and make and image with it.
 * @param game the structure that contains all the data of the game.
 */
void	ft_get_floor_image(t_game *game);
/**
 * @brief this functions gets a texture for '1' and make and image with it.
 * @param game the structure that contains all the data of the game.
 */
void	ft_get_wall_image(t_game *game);

// INIT.C //
/**
 * @brief this functions mallocs memory for the map struct and init it.
 * @param game the structure that contains all the data of the game.
 * @param argc the numbers of arguments given.
 * @param argv the value of the arguments.
 */
void	ft_init_map(t_game *game, int argc, char **argv);
/**
 * @brief this functions init the mlx that game will use.
 * @param game the structure that contains all the data of the game.
 */
void	ft_init_mlx(t_game *game);
/**
 * @brief this functions gets a texture for 'C' and make and image with it.
 * @param game the structure that contains all the data of the game.
 */
void	ft_init_game(t_game *game, int argc, char **argv);
/**
 * @brief this functions gets all the textures of the elements into images.
 * @param game the structure that contains all the data of the game.
 */
void	ft_init_elements(t_game *game);

// MOVE.C //
/**
 * @brief this functions will trigger the action related to the pressed key.
 * @param key_data the struct that contains all the data related with the key.
 * @param game the structure that contains all the data of the game.
 */
void	ft_key_response(struct mlx_key_data key_data, t_game *game);
/**
 * @brief this functions moves the char to the dest if its possible.
 * @param game the structure that contains all the data of the game.
 * @param x the movement on the 'x' axis.
 * @param y the movement on the 'y' axis.
 */
void	ft_move(t_game *game, int y, int x);
/**
 * @brief this functions updates the images after a movement.
 * @param game the structure that contains all the data of the game.
 */
void	ft_update(t_game *game);

//	CLOSE.C	//
/**
 * @brief this functions close the window and free the data you dont need.
 * @param game the structure that contains all the data of the game.
 */
void	ft_close_window_callback(void *game);

#endif
