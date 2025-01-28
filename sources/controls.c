/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:46:45 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:48 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int y_offset, int x_offset)
{
    int new_y = game->y + y_offset;
    int new_x = game->x + x_offset;
    
    // Comprobar si la nueva casilla no es una pared ('1') ni la salida ('E')
    if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'E') 
    {
        // Si la nueva casilla tiene un coleccionable ('C') o es un espacio vacío ('0')
        if (game->map[new_y][new_x] == 'C' || game->map[new_y][new_x] == '0') 
        {
            if (game->map[new_y][new_x] == 'C') 
                game->count--;  // Decrementar el contador si es un coleccionable
            
            // Mover al jugador a la nueva casilla
            game->map[game->y][game->x] = '0';  // Vaciar la posición anterior
            game->map[new_y][new_x] = 'P';  // Colocar al jugador en la nueva posición
        }
        
        // Actualizar la posición y el número de pasos
        game->y = new_y;
        game->x = new_x;
        game->step++;
        ft_write_itoa(game->step); //es necesario esto de los pasos???
    }
    // Verificar si el jugador llegó a la salida y recogió todos los coleccionables
    else if (game->map[new_y][new_x] == 'E' && game->count == 0) 
    {
        game->finish = 1;
    }
}

int	press_key(int keycode, t_game *game)
{
    if (keycode == ESC)
        ft_exit(game);
    else if (game->finish == 0)
    {
        if (keycode == W) 
            move_player(game, -1, 0);  // Mover hacia arriba
        else if (keycode == S) 
            move_player(game, 1, 0);   // Mover hacia abajo
        else if (keycode == A) 
            move_player(game, 0, -1);  // Mover hacia la izquierda
        else if (keycode == D) 
            move_player(game, 0, 1);   // Mover hacia la derecha
    }
    return (0);
}
