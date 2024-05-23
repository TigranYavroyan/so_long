/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:57:33 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/23 21:55:29 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	go_down(t_game *game)
{
	if (!checker_coin_exit_counter(game, 1, 0))
		return ;
	++(game->player->row);
	if (game->on_exit == FROM_EXIT)
	{
		game->map[game->player->row - 1][game->player->col] = EXIT;
		game->on_exit = 0;
	}
	else
		game->map[game->player->row - 1][game->player->col] = SPACE;
	put_player(game);
	printing_images(game);
}

void	go_up(t_game *game)
{
	if (!checker_coin_exit_counter(game, -1, 0))
		return ;
	--(game->player->row);
	if (game->on_exit == FROM_EXIT)
	{
		game->map[game->player->row + 1][game->player->col] = EXIT;
		game->on_exit = 0;
	}
	else
		game->map[game->player->row + 1][game->player->col] = SPACE;
	put_player(game);
	printing_images(game);
}

void	go_left(t_game *game)
{
	if (!checker_coin_exit_counter(game, 0, -1))
		return ;
	--(game->player->col);
	if (game->on_exit == FROM_EXIT)
	{
		game->map[game->player->row][game->player->col + 1] = EXIT;
		game->on_exit = 0;
	}
	else
		game->map[game->player->row][game->player->col + 1] = SPACE;
	put_player(game);
	printing_images(game);
}

void	go_right(t_game *game)
{
	if (!checker_coin_exit_counter(game, 0, 1))
		return ;
	++(game->player->col);
	if (game->on_exit == FROM_EXIT)
	{
		game->map[game->player->row][game->player->col - 1] = EXIT;
		game->on_exit = 0;
	}
	else
		game->map[game->player->row][game->player->col - 1] = SPACE;
	put_player(game);
	printing_images(game);
}
