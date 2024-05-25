/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:47:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/24 13:57:14 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_player(t_game *game)
{
	if (game->endgame == DEAD)
		game->map[game->player->row][game->player->col] = OPPONENT;
	else if (game->endgame == END_GAME)
		game->map[game->player->row][game->player->col] = EXIT;
	else
		game->map[game->player->row][game->player->col] = PLAYER;
}

static int	do_stuff(t_game *game)
{
	game->endgame = DEAD;
	++(game->moves_count);
	mlx_clear_window(game->mlx, game->win);
	return (1);
}

int	checker_coin_exit_counter(t_game *game, int x, int y)
{
	if (game->map[game->player->row + x][game->player->col + y] == OPPONENT)
		return (do_stuff(game));
	if (game->map[game->player->row + x][game->player->col + y] == WALL)
		return (0);
	else if (game->coins_count == 0 && game->map[game->player->row
			+ x][game->player->col + y] == EXIT)
		game->endgame = 1;
	if (game->map[game->player->row + x][game->player->col + y] == EXIT
		&& !game->endgame)
	{
		game->on_exit = ON_EXIT;
		mlx_clear_window(game->mlx, game->win);
		++(game->moves_count);
		return (1);
	}
	if (game->map[game->player->row + x][game->player->col + y] == COIN)
		--(game->coins_count);
	else if (game->map[game->player->row + x][game->player->col + y] == EXIT
		&& game->endgame)
		game->endgame = END_GAME;
	++(game->moves_count);
	mlx_clear_window(game->mlx, game->win);
	return (1);
}

void	put_coin(t_game *game, int i, int j)
{
	put_image(game, game->img_coin_back, i * IMG_S, j * IMG_S);
	put_image(game, game->img_coin, (i * IMG_S) + 15, (j * IMG_S) + 15);
}
