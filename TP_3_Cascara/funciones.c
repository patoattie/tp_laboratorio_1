#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void limpiarPantalla(void)
{
    system("cls");
}

void pausarEjecucion(void)
{
    system("pause");
}

int agregarPelicula(EMovie movie)
{
    int agregoPelicula = 0;
    int abreArchivo;
    int escribePelicula;
    int cierraArchivo;
    FILE* pArchivoPeliculas = NULL;
    EMovie* pMovie = &movie;

    abreArchivo = abrirArchivo(pArchivoPeliculas, PATH_ARCHIVO_PELICULAS, MODO_ESCRITURA_BINARIO);
    if(abreArchivo == 1)
    {
        escribePelicula = escribirPelicula(pMovie, pArchivoPeliculas);
        if(escribePelicula == 1)
        {
            agregoPelicula = 1;
        }
    }

    cierraArchivo = cerrarArchivo(pArchivoPeliculas);
    if(cierraArchivo < 1)
    {
        printf("\nNo se pudo cerrar el archivo");
    }

    return agregoPelicula;
}

int abrirArchivo(FILE* punteroArchivo, const char* pathArchivo, const char* modoArchivo)
{
    int resultadoAperturaArchivo = -1;

    if(punteroArchivo == NULL)
    {
        resultadoAperturaArchivo = 0;

        punteroArchivo = fopen(pathArchivo, modoArchivo);
        if(punteroArchivo != NULL)
        {
            resultadoAperturaArchivo = 1;
        }
    }

    return resultadoAperturaArchivo;
}

int cerrarArchivo(FILE* punteroArchivo)
{
    int resultadoCierreArchivo = -1;

    if(punteroArchivo != NULL)
    {
        resultadoCierreArchivo = fclose(punteroArchivo); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        resultadoCierreArchivo++; //Para que mi función devuelva 1 con cierre exitoso, y 0 con cierre incorrecto incremento la variable en 1.
    }

    return resultadoCierreArchivo;
}

int pedirEnteroSinValidar(char* mensaje)
{
    int numero;
    float ingreso;
    int esDecimal;

    printf("%s", mensaje);
    do
    {
        scanf("%f", &ingreso);
        esDecimal = validarEnteroDecimal(ingreso);
        if(esDecimal == 1)
        {
            printf("ERROR Debe ingresar un numero sin digitos decimales: ");
        }
    } while(esDecimal == 1);

    numero = (int)ingreso;

    return numero;
}

void pedirString(char* mensaje, char* cadena, int longitud)
{
    char stringBuffer[STR_BUFFER];
    longitud = longitud - 2; //Resto dos para contemplar \n y \0

    if(longitud > STR_BUFFER - 2)
    {
        printf("\nLa longitud de la cadena no puede superar %d caracteres", STR_BUFFER - 2);
    }
    else
    {
        printf("%s", mensaje);
        fflush(stdin);
        fgets(stringBuffer, STR_BUFFER, stdin);

        validarString(stringBuffer, longitud);

        strcpy(cadena, stringBuffer);
        cadena[strlen(cadena) - 1] = '\0'; //Quito el \n que deja antes de \0 el fgets
    }
}

void validarString(char* cadena, int longitud)
{
    while(strlen(cadena) - 1 > longitud)
    {
        printf("ERROR El texto ingresado supera los %d caracteres\npor favor reingrese: ", longitud);
        fflush(stdin);
        fgets(cadena, STR_BUFFER, stdin);
    }
}

int validarEnteroDecimal(float numero)
{
    int numeroEntero = (int)numero;
    int retorno;

    if(numero != numeroEntero)
    {
        retorno = 1; //No es entero
    }
    else
    {
        retorno = 0; //Es entero
    }

    return retorno;
}

int pedirEntero(char mensaje[], int minimo, int maximo)
{
    int numero;
    float ingreso;
    int esDecimal;

    printf("%s", mensaje);
    do
    {
        scanf("%f", &ingreso);
        esDecimal = validarEnteroDecimal(ingreso);
        if(esDecimal == 1)
        {
            printf("ERROR Debe ingresar un numero sin digitos decimales: ");
        }
    } while(esDecimal == 1);

    numero = (int)ingreso;
    numero = validarEntero(numero, minimo, maximo);

    return numero;
}

int validarEntero(int dato, int minimo, int maximo)
{
    while(dato < minimo || dato > maximo)
    {
        printf("ERROR Ingrese un numero entre %d y %d: ", minimo, maximo);
        scanf("%d", &dato);
    }

    return dato;
}

EMovie cargarPelicula(void)
{
    EMovie movie;

    do
    {
        pedirString("Ingrese titulo: ", movie.titulo, TAM_TITULO);
        if(strcmp(movie.titulo, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
        }
    } while(strcmp(movie.titulo, "") == 0);

    do
    {
        pedirString("Ingrese genero: ", movie.genero, TAM_GENERO);
        if(strcmp(movie.genero, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
        }
    } while(strcmp(movie.genero, "") == 0);

    do
    {
        movie.duracion = pedirEnteroSinValidar("Ingrese duracion en minutos: ");
        if(movie.duracion <= 0)
        {
            printf("La duracion en minutos debe ser un numero positivo, por favor reingrese\n");
        }
    } while(movie.duracion <= 0);

    do
    {
        pedirString("Ingrese descripcion: ", movie.descripcion, TAM_DESCRIPCION);
        if(strcmp(movie.descripcion, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
        }
    } while(strcmp(movie.descripcion, "") == 0);

    do
    {
        pedirString("Ingrese link de la imagen: ", movie.linkImagen, TAM_LINK);
        if(strncmp(movie.linkImagen, "http://", 7) != 0 && strncmp(movie.linkImagen, "https://", 8) != 0)
        {
            printf("No es una URL valida, por favor reingrese\n");
        }
    } while(strncmp(movie.linkImagen, "http://", 7) != 0 && strncmp(movie.linkImagen, "https://", 8) != 0);

    movie.puntaje = pedirEntero("Ingrese puntaje del 1 al 100: ", 1, 100);

    return movie;
}

int escribirPelicula(EMovie* movie, FILE* pArchivoPeliculas)
{
    int retorno = -1;
    int cantidadEscrita;

    if(pArchivoPeliculas != NULL)
    {
        retorno = 0;
        cantidadEscrita = fwrite(movie, sizeof(movie), 1, pArchivoPeliculas);

        if(cantidadEscrita == 1)
        {
            retorno = 1;
        }
    }

    return retorno;
}
