/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:04:15 by tyavroya          #+#    #+#             */
/*   Updated: 2024/06/25 12:42:30 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_image(t_game *game, void *img, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, img, col, row);
}

static void	validate_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == WALL)
		put_image(game, game->img_wall, i * IMG_S, j * IMG_S);
	else if (game->map[i][j] == EXIT && game->coins_count)
		put_image(game, game->img_exit, i * IMG_S, j * IMG_S);
	else if (game->map[i][j] == EXIT && !game->coins_count)
		put_image(game, game->img_exit_open, i * IMG_S, j * IMG_S);
	else if (game->map[i][j] == PLAYER)
	{
		if (game->on_exit)
		{
			game->on_exit = FROM_EXIT;
			put_image(game, game->img_exit, i * IMG_S, j * IMG_S);
		}
		else
			put_image(game, game->img_floor, i * IMG_S, j * IMG_S);
		put_image(game, game->img_player, i * IMG_S, j * IMG_S);
	}
	else if (game->map[i][j] == COIN)
		put_coin(game, i, j);
	else if (game->map[i][j] == SPACE)
		put_image(game, game->img_floor, i * IMG_S, j * IMG_S);
	else if (game->map[i][j] == OPPONENT)
		put_image(game, game->img_opponent, i * IMG_S, j * IMG_S);
}

void	init_images(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Player/Player_0_empty.xpm", &game->img_width,
			&game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Wall/Wall_0.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Gate/Gate_0.xpm", &game->img_width, &game->img_height);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Gate/Gate_3.xpm", &game->img_width, &game->img_height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Coin/Coin_0.xpm", &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Floor/Floor_0.xpm", &game->img_width,
			&game->img_height);
	game->img_coin_back = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Floor/Floor_0.xpm", &game->img_width,
			&game->img_height);
	game->img_opponent = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Opponent/Opponent_2.xpm", &game->img_width,
			&game->img_height);
	if (!check_imgs(game))
		_err(game);
}

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		_err(game);
	game->win_height = game->map_size->row * IMG_S;
	game->win_width = game->map_size->col * IMG_S;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"So_long");
}

int	printing_images(t_game *game)
{
	int		row;
	int		col;
	char	*str;

	row = -1;
	while (++row < game->map_size->row)
	{
		col = -1;
		while (++col < game->map_size->col)
			validate_image(game, row, col);
	}
	str = ft_itoa(game->moves_count);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFF00BBFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 80, 10, 0xFF00BBFF, str);
	if (game->endgame)
		mlx_string_put(game->mlx, game->win, game->map_size->col / 3 * IMG_S,
			game->map_size->row / 2 * IMG_S, 0xFF00BBFF, "The game is ended, \
			press any button ");
	free(str);
	event_handler(game);
	return (0);
}
