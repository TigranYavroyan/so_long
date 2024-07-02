/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:32:26 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/24 15:51:41 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	move_handler(int key, t_game *game)
{
	if (key == KEY_A)
		go_left(game);
	else if (key == KEY_D)
		go_right(game);
	else if (key == KEY_S)
		go_down(game);
	else if (key == KEY_W)
		go_up(game);
}

static int	key_handler(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
		exit_game(game, INSTANT);
	else if (!game->endgame)
		move_handler(key, game);
	else if (game->endgame)
		exit_game(game, INSTANT);
	return (0);
}

void	event_handler(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_handler, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
