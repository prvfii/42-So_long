/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:48:49 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/25 17:11:04 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_W 32
# define ESC_KEY 53
# define W_KEY 13 // Touche W pour monter
# define A_KEY 0  // Touche A pour gauche
# define S_KEY 1  // Touche S pour descendre
# define D_KEY 2  // Touche D pour droite
# define ON_DESTROY 17
# define MAX_LINES 1024
# define WALL '1'

typedef struct s_map_position
{
	int		x;
	int		y;
}			t_map_position;

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}			t_img;

typedef struct s_coords
{
	int	ptr_x;
	int	ptr_y;
	int	x;
	int	y;
}	t_coords;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*img_back;
	t_img	*img_collectible;
	t_img	*img_wall;
	t_img	*img_exit;
	t_img	*img_player;
	char	**map;
	char	**dupl_map;
	int		height;
	int		width;
	int		collected;
	int		moves;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		total_coll;
	int		exit;
	int		img_width;
	int		img_height;
}			t_game;

typedef struct s_map
{
	int		lines;
	int		colums;
	char	**doublemap;
	int		count_e;
	int		count_c;
}			t_map;

char		*load_map(char *file);
char		*ft_strcat(char *dest, const char *src);
int			ft_strber(const char *haystack, const char *needle);
int			checkber(char *file);
int			count_exit(char *file);
int			count_items(char *file);
int			count_pos(char *file);
int			countlines(char *file);
int			openfile(char *file);
int			countcolumns(char *file);
int			checkrectangle(t_map *data);
int			items(char *file);
void		initmapsplit(t_game *data, char **av, t_map *play);
void		drawmap(t_game *game);
void		initgame(t_game *game, char **av, t_map *play);
void		windowsize(t_game *data, char **av);
int			close_window(t_game *data);
int			handle_closure(int key, t_game *game);
void		move_player(t_game *game, int new_x, int new_y);
int			handle_keymove(int key, t_game *game);
void		windowsize(t_game *data, char **av);
int			is_map_surrounded_by_walls(char **map, int width, int height);
void		find_player(t_game *game);
void		totalofcoll(t_game *game, char *file);
int			is_valid_path(t_game *game);
int			has_only_valid_characters(t_map *game_object);
void		initmapsplit(t_game *data, char **av, t_map *play);
int			checkmap(t_map *game, char **av);
int			initmap(t_map *data, char **av);
void		draw_tile(t_game *game, t_coords coords);
void		draw_row(t_game *game, int x);
int			checkwindow(t_map *map);
void		free_strs(char **strs);

#endif
