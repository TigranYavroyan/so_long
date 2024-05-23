/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:40:52 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/23 18:11:12 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	_log(void)
{
	ft_putendl_fd("aper ekar ste", 2);
}

void	map_print(t_game *game)
{
	for (int i = 0; i < game->map_size->row; ++i) {
		printf("%s\n", game->map[i]);
	}
}
