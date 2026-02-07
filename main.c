/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:23:11 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/07 14:46:35 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *game)
{
	free_mlx(game);
	exit(0);
}

int	update(t_game *game)
{
	move(game);
	graphic_update(game);
	game->last_update = get_time();
	return (0);
}

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_mlx(game);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game->win)
	{
		free_mlx(game);
		return (0);
	}
	game->key_a = 0;
	game->key_d = 0;
	game->key_s = 0;
	game->key_w = 0;
	game->key_left = 0;
	game->key_right = 0;
	game->last_update = get_time();
	game->skip_line_data = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	ft_bzero(&game, sizeof(t_game));
	parse(&game, av[1]);
	if (!game.map)
		return (0);
	if (!start(&game))
		return (0);
	init_assets(&game);
	if (!check_map_closed(&game))
		free_mlx(&game);
	game.img.img = mlx_new_image(game.mlx, SCREEN_W, SCREEN_H);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel,
			&game.img.line_len, &game.img.endian);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
