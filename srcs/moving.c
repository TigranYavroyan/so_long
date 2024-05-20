/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:57:33 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/20 14:15:39 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	checker_coin_exit_counter(t_game *game, int x, int y)
{
// 	mlx_string_put(game->mlx, game->win, 100, 100, 0xFF000000, ft_itoa(game->coins_count));
// 	mlx_string_put(game->mlx, game->win, 200, 100, 0xFF000000, ft_itoa(game->endgame));
	if (game->map[game->player->row + x][game->player->col + y] == OPPONENT) // maybe change smth
		exit_game(game);
	if (game->map[game->player->row + x][game->player->col + y] == WALL)
		return (0);
	else if (game->coins_count == 0 && game->map[game->player->row + x][game->player->col + y] == EXIT)
		game->endgame = 1;
	if (game->map[game->player->row + x][game->player->col + y] == EXIT && !game->endgame)
		return (0);
	if (game->map[game->player->row + x][game->player->col + y] == COIN)
		--(game->coins_count);
	else if (game->map[game->player->row + x][game->player->col + y] == EXIT && game->endgame)
		exit_game(game);
	++(game->moves_count);
	mlx_clear_window(game->mlx, game->win);
	return (1);
}

void	go_down(t_game *game)
{
	if (!checker_coin_exit_counter(game, 1, 0))
		return ;

	++(game->player->row);
	game->map[game->player->row - 1][game->player->col] = SPACE;
	game->map[game->player->row][game->player->col] = PLAYER;
	printing_images(game);
}

void	go_up(t_game *game)
{
	if (!checker_coin_exit_counter(game, -1, 0))
		return ;

	--(game->player->row);
	game->map[game->player->row + 1][game->player->col] = SPACE;
	game->map[game->player->row][game->player->col] = PLAYER;
	printing_images(game);
}

void	go_left(t_game *game)
{
	if (!checker_coin_exit_counter(game, 0, -1))
		return ;
	--(game->player->col);
	game->map[game->player->row][game->player->col + 1] = SPACE;
	game->map[game->player->row][game->player->col] = PLAYER;
	printing_images(game);
}

void	go_right(t_game *game)
{
	if (!checker_coin_exit_counter(game, 0, 1))
		return ;
	++(game->player->col);
	game->map[game->player->row][game->player->col - 1] = SPACE;
	game->map[game->player->row][game->player->col] = PLAYER;
	printing_images(game);
}

