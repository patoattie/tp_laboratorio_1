#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie movie;
    int agregoPelicula;

    while(seguir=='s')
    {
        limpiarPantalla();

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                movie = cargarPelicula();
                agregoPelicula = agregarPelicula(movie);
                if(agregoPelicula == 1)
                {
                    printf("\nAlta de pelicula OK");
                }
                else
                {
                    printf("\nNo se pudo agregar la pelicula");
                }
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
               break;
            case 5:
                seguir = 'n';
                break;
        }

        if(seguir=='s')
        {
            printf("\n");
            pausarEjecucion();
        }
    }

    return 0;
}
