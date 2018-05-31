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
    int existePelicula;
    int borroPelicula;
    char tituloPelicula[TAM_TITULO];
    int operacionArchivo;

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
                pedirTituloPelicula(tituloPelicula);
                existePelicula = buscarPelicula(tituloPelicula, &movie);
                if(existePelicula < 1)
                {
                    cargarPelicula(tituloPelicula, &movie);
                    agregoPelicula = agregarPelicula(movie);
                    if(agregoPelicula == 1)
                    {
                        printf("\nAlta de pelicula OK");
                    }
                    else
                    {
                        printf("\nNo se pudo agregar la pelicula");
                    }
                }
                else
                {
                    printf("\nLa pelicula ya existe en el catalogo");
                }
                break;
            case 2:
                pedirTituloPelicula(tituloPelicula);
                existePelicula = buscarPelicula(tituloPelicula, &movie);
                if(existePelicula == 1)
                {
                    borroPelicula = borrarPelicula(movie);
                    operacionArchivo = restaurarArchivoPeliculas(borroPelicula);
                    if(borroPelicula == 1 && operacionArchivo == 0)
                    {
                        printf("\nBaja de pelicula OK");
                    }
                    else
                    {
                        printf("\nNo se pudo borrar la pelicula");
                    }
                }
                else
                {
                    printf("\nLa pelicula no existe en el catalogo");
                }
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
