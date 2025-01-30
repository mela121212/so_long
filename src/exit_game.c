/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:46:03 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:06 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"
#include <stdlib.h>

#include "so_long.h"
#include <stdlib.h>

void destroy(t_game *game)
{
    if (game->mlxpointer)
    {
        if (game->winpointer)
            mlx_destroy_window(game->mlxpointer, game->winpointer);
        if (game->floor)
            mlx_destroy_image(game->mlxpointer, game->floor);
        if (game->barrier)
            mlx_destroy_image(game->mlxpointer, game->barrier);
        if (game->player)
            mlx_destroy_image(game->mlxpointer, game->player);
        if (game->exit)
            mlx_destroy_image(game->mlxpointer, game->exit);
        if (game->collectable)
            mlx_destroy_image(game->mlxpointer, game->collectable);

        mlx_destroy_display(game->mlxpointer);
        free(game->mlxpointer);
    }
    if (game->map)
    {
        int i = 0;
        while (game->map[i])
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
    }
    free(game);
}



void	ft_exit(t_game *game, char *error_msg)
{
	destroy(game);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}