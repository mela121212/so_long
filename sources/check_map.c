#include "so_long.h"

check_map()
{
    //Rectangular?
    //Rodeado de walls? -> todo tiene que ser = 1
    //una salida = E
    //una entrada = P
    //Al menos un collectible
    //Hay que recoger todos los collectibles
    //La salida es accesible desde la entrada?
}

int is_map_rectangular(t_complete *game)
{
    int width;
    int i = 1;

    if (!game->map || !game->map[0])
        return 0;  // Mapa vacío
    while (game->map[i])
    {
        if (ft_strlen(game->map[i]) != game->width)  // Compara la longitud con la primera //le he dado el valor de long de primera linea a game->width anteriormente
            return(0);  // No es rectangular
        i++;
    }
    return 1;  // Es rectangular
}

int is_map_enclosed(t_complete *game)
{
    int i;
    int last_line = 0;
    int width;

    if (!game->map || !game->map[0])
        return 0;

    // Encuentra la última línea
    while (game->map[last_line])
        last_line++;
    last_line--;

    width = ft_strlen(game->map[0]);

    // Revisar primera y última línea
    for (i = 0; i < width; i++)
    {
        if (game->map[0][i] != '1' || game->map[last_line][i] != '1')
            return 0;  // No está encerrado en paredes
    }

    // Revisar las columnas de los bordes
    for (i = 0; i <= last_line; i++)
    {
        if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
            return 0;  // No está encerrado en paredes
    }
    return 1;  // El mapa está completamente encerrado por paredes
}

int count_elements(t_game *game, char element)
{
    int count = 0;
    int i = 0, j;

    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == element)
                count++;
            j++;
        }
        i++;
    }
    return(count);
}

int validate_map_elements(t_game *game)
{
    int exits = count_elements(game, 'E');
    int starts = count_elements(game, 'P');
    int collectibles = count_elements(game, 'C');

    if (exits != 1)
    {
        printf("Error: Debe haber exactamente un 'E'.\n");
        return 0;
    }
    if (starts != 1)
    {
        printf("Error: Debe haber exactamente un 'P'.\n");
        return 0;
    }
    if (collectibles < 1)
    {
        printf("Error: Debe haber al menos un 'C'.\n");
        return 0;
    }
    return(1);  // Todo está correcto
}

void dfs(t_game *game, int x, int y, int **visited)
{
    if (x < 0 || y < 0 || !game->map[y] || !game->map[y][x] || game->map[y][x] == '1' || visited[y][x])
        return;

    visited[y][x] = 1;

    dfs(game, x + 1, y, visited);  // Derecha
    dfs(game, x - 1, y, visited);  // Izquierda
    dfs(game, x, y + 1, visited);  // Abajo
    dfs(game, x, y - 1, visited);  // Arriba
}

int is_map_fully_accessible(t_game *game)
{
    int **visited;
    int start_x = -1, start_y = -1;
    int i, j;

    // Crear matriz de visitados
    visited = allocate_2d_int_array(game->heightmap, ft_strlen(game->map[0]));

    // Buscar la posición inicial 'P'
    for (i = 0; game->map[i]; i++)
    {
        for (j = 0; game->map[i][j]; j++)
        {
            if (game->map[i][j] == 'P')
            {
                start_x = j;
                start_y = i;
                break;
            }
        }
        if (start_x != -1) break;
    }

    // Iniciar DFS desde 'P'
    dfs(game, start_x, start_y, visited);

    // Verificar si 'E' y 'C' son accesibles
    for (i = 0; game->map[i]; i++)
    {
        for (j = 0; game->map[i][j]; j++)
        {
            if ((game->map[i][j] == 'E' || game->map[i][j] == 'C') && !visited[i][j])
            {
                printf("Error: No todos los elementos son accesibles.\n");
                return 0;
            }
        }
    }
    return 1;  // Todo es accesible
}
