/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:49:21 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/24 15:51:01 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <ft_printf.h>
# include <libft.h>
# include <mlx.h>
# include <stdio.h>

enum		e_Mode
{
	WAIT = 1,
	INSTANT = 0
};

# define WALL '1'
# define SPACE '0'
# define PLAYER 'P'
# define COIN 'C'
# define EXIT 'E'
# define OPPONENT 'O'
# define MIN_MAP_SIZE 3
# define ON_EXIT 1
# define FROM_EXIT 2
# define DEAD 4
# define END_GAME 8

# define MAX_ROW 16
# define MAX_COL 30
# define IMG_S 64

// ---------- for event-handling ---------
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_for_check
{
	int		i;
	int		j;
	int		exit;
	int		player;
}			t_for_check;

typedef struct s_point
{
	int		row;
	int		col;
}			t_point;

typedef struct s_game
{
	t_point	*player;
	t_point	*exit;
	t_point	*map_size;
	t_point	*enemy;
	char	**map;
	int		endgame;
	int		coins_count;
	int		moves_count;
	int		win_height;
	int		win_width;
	int		img_height;
	int		img_width;
	int		on_exit;
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_coin_back;
	void	*img_exit;
	void	*img_exit_open;
	void	*img_opponent;
}			t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int			file_checker(char *file);
char		**save_file(char *file, t_game *game);
//------------------------------ validate_map ------------------------------
void		check_map_size(t_game *game);
void		check_maps_elements(t_game *game);
//------------------------------ validate_map2 -----------------------------
void		is_valid_map(t_game *game);
void		is_map_open(t_game *game);
int			check_path(char **map, t_point player, int count_e_c);
//----------------------------- exit ---------------------------------------
// in alloc_map function I am removing
// \n from original map adding '\0' where needed
char		**alloc_map(t_game *game);
void		_err(t_game *game);
void		dealloc(t_game *game);
void		dealloc_map(char **map);
int			exit_game(t_game *game, int mode);
// --------------------------- mlx_init ------------------------------------
int			printing_images(t_game *game);
void		open_window(t_game *game);
void		put_image(t_game *game, void *img, int row, int col);
void		init_images(t_game *game);
// --------------------------- event_handler -------------------------------
void		event_handler(t_game *game);
// -------------------------- moving ---------------------------------------
void		go_down(t_game *game);
void		go_up(t_game *game);
void		go_left(t_game *game);
void		go_right(t_game *game);
// ----------------------- moving_utils ------------------------------------
void		put_player(t_game *game);
void		put_coin(t_game *game, int i, int j);
int			checker_coin_exit_counter(t_game *game, int x, int y);
#endif // SO_LONG_H
