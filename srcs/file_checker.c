/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:57:30 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/23 21:55:52 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	file_checker(char *file)
{
	if (!ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4))
		return (0);
	return (1);
}

static int	row_count(char *file, t_game *game)
{
	int		fd;
	char	*file_info;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		_err(game);
	file_info = get_next_line(fd);
	while (file_info)
	{
		free(file_info);
		file_info = get_next_line(fd);
		++(game->map_size->row);
	}
	close(fd);
	if (game->map_size->row > MAX_ROW)
		return (0);
	return (1);
}

char	**save_file(char *file, t_game *game)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		_err(game);
	if (!row_count(file, game))
	{
		close(fd);
		_err(game);
	}
	game->map = (char **)malloc(sizeof(char *) * (game->map_size->row + 1));
	if (game->map == NULL)
		_err(game);
	i = 0;
	game->map[game->map_size->row] = NULL;
	while (i < game->map_size->row)
	{
		game->map[i] = get_next_line(fd);
		++i;
	}
	close(fd);
	return (game->map);
}
