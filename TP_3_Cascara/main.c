#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie movie;
    EMovie movieNueva;
    int agregoPelicula;
    int existePelicula;
    int borroPelicula;
    char tituloPelicula[TAM_TITULO];
    int operacionArchivo;
    int hayPeliculas;
    int modificoPelicula;
    char nombreHTML[50];
    char archivoHTML[50];

    while(seguir=='s')
    {
        limpiarPantalla();

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Listar por pantalla\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pedirTituloPelicula(tituloPelicula, "Ingrese titulo a agregar: ");
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
                hayPeliculas = listarPeliculas(&movie);
                if(hayPeliculas == 1)
                {
                    pedirTituloPelicula(tituloPelicula, "Ingrese titulo a borrar: ");
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
                }
                else
                {
                    printf("\nNo hay peliculas en el catalogo");
                }
                break;
            case 3:
                hayPeliculas = listarPeliculas(&movie);
                if(hayPeliculas == 1)
                {
                    pedirTituloPelicula(tituloPelicula, "Ingrese titulo a modificar: ");
                    existePelicula = buscarPelicula(tituloPelicula, &movie);
                    if(existePelicula == 1)
                    {
                        cargarPelicula(tituloPelicula, &movieNueva);
                        modificoPelicula = modificarPelicula(movieNueva);
                        operacionArchivo = restaurarArchivoPeliculas(modificoPelicula);
                        if(modificoPelicula == 1 && operacionArchivo == 0)
                        {
                            printf("\nModificacion de pelicula OK");
                        }
                        else
                        {
                            printf("\nNo se pudo modificar la pelicula");
                        }
                    }
                    else
                    {
                        printf("\nLa pelicula no existe en el catalogo");
                    }
                }
                else
                {
                    printf("\nNo hay peliculas en el catalogo");
                }
               break;
            case 4:
                do
                {
                    pedirString("Ingrese nombre del archivo html: ", nombreHTML, 50);
                    if(strcmp(nombreHTML, "") == 0)
                    {
                        printf("El dato es obligatorio, por favor reingrese\n");
                    }
                } while(strcmp(nombreHTML, "") == 0);

                strcpy(archivoHTML, PATH_HTML); //Asigno el path
                strcat(archivoHTML, nombreHTML); //Le concateno el nombre.
                strcat(archivoHTML, ".html"); //Le concateno la extensión.
                generarPagina(&movie, archivoHTML);
               break;
            case 5:
               hayPeliculas = listarPeliculas(&movie);
               if(hayPeliculas != 1)
               {
                   printf("\nNo hay peliculas en el catalogo");
               }
               break;
            case 6:
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
