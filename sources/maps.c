#include "so_long.h"

static int add_line_to_map(t_game *game, char *line)
{
    char    **new_map;
    int     i;

    i = 0;
    game->height++;
    new_map = (char*)malloc(sizeof(char) * (game->height + 1));
    new_map[game->height] = NULL; //el ultimo str del char** tiene que ser un NULL
    while ()
    {
        game->map[i] = new_map[i];
        i++;
    }
    new_map[i] = line;
    if(game->map) //se libera el antiguo para copiar el nuevo (new_map no se libera porque lo necesitas para la siguiente llamada)
        free(game->map);
    game->map = new_map;
    game->width = ft_strlen(game->map[0]); //Le doy el valor de la primera linea y luego ya compruebo
    return (1);
}

int read_map(t_game *game, char **argv)
{
    char    *line;
    int     i;

    i = 0;
    game->fd = open(argv[1], O_RDONLY);
    while()
    {
        line = get_next_line(game->fd);
        add_line_to_map(game->map, line);
        if...
    }
    close(game->fd);
    return (1);
}