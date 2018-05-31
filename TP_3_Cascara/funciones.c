#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    int cantidadEscrita;
    int cierraArchivo;
    FILE* pArchivoPeliculas = NULL;

    pArchivoPeliculas = fopen(PATH_ARCHIVO_PELICULAS, MODO_APPEND_BINARIO);
    if(pArchivoPeliculas != NULL)
    {
        cantidadEscrita = fwrite(&movie, sizeof(EMovie), 1, pArchivoPeliculas);

        if(cantidadEscrita == 1)
        {
            agregoPelicula = 1;
        }

        cierraArchivo = fclose(pArchivoPeliculas); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo");
        }
    }

    return agregoPelicula;
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

int pedirEntero(char* mensaje, int minimo, int maximo)
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

void cargarPelicula(const char* tituloPelicula, EMovie* pMovie)
{
    strcpy(pMovie->titulo, tituloPelicula);

    do
    {
        pedirString("Ingrese genero: ", pMovie->genero, TAM_GENERO);
        if(strcmp(pMovie->genero, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
        }
    } while(strcmp(pMovie->genero, "") == 0);

    do
    {
        pMovie->duracion = pedirEnteroSinValidar("Ingrese duracion en minutos: ");
        if(pMovie->duracion <= 0)
        {
            printf("La duracion en minutos debe ser un numero positivo, por favor reingrese\n");
        }
    } while(pMovie->duracion <= 0);

    do
    {
        pedirString("Ingrese descripcion: ", pMovie->descripcion, TAM_DESCRIPCION);
        if(strcmp(pMovie->descripcion, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
        }
    } while(strcmp(pMovie->descripcion, "") == 0);

    do
    {
        pedirString("Ingrese link de la imagen: ", pMovie->linkImagen, TAM_LINK);
        if(strncmp(pMovie->linkImagen, "http://", 7) != 0 && strncmp(pMovie->linkImagen, "https://", 8) != 0)
        {
            printf("No es una URL valida, por favor reingrese\n");
        }
    } while(strncmp(pMovie->linkImagen, "http://", 7) != 0 && strncmp(pMovie->linkImagen, "https://", 8) != 0);

    pMovie->puntaje = pedirEntero("Ingrese puntaje del 1 al 100: ", 1, 100);
}

int buscarPelicula(const char* tituloPelicula, EMovie* pMovie)
{
    FILE* pArchivoPeliculas = NULL;
    int retorno = -1;
    int cantidadLeida;
    int cierraArchivo;

    pArchivoPeliculas = fopen(PATH_ARCHIVO_PELICULAS, MODO_LECTURA_BINARIO);
    if(pArchivoPeliculas != NULL)
    {
        retorno = 0;

        while(!feof(pArchivoPeliculas))
        {
            cantidadLeida = fread(pMovie, sizeof(EMovie), 1, pArchivoPeliculas);
            if(cantidadLeida == 1)
            {
                if(stricmp(tituloPelicula, pMovie->titulo) == 0)
                {
                    retorno = 1;
                    break;
                }
            }
            else
            {
                if(feof(pArchivoPeliculas))
                {
                    break;
                }
            }
        }

        cierraArchivo = fclose(pArchivoPeliculas); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo");
        }
    }

    return retorno;
}

int borrarPelicula(EMovie movie)
{
    int borroPelicula = 0;
    int cantidadLeida;
    int cantidadEscrita;
    int cierraArchivo;
    FILE* pArchivoPeliculas = NULL;
    FILE* pArchivoTemporal = NULL;
    EMovie temporal;

    pArchivoPeliculas = fopen(PATH_ARCHIVO_PELICULAS, MODO_LECTURA_BINARIO);
    pArchivoTemporal = fopen(PATH_ARCHIVO_TEMPORAL, MODO_ESCRITURA_BINARIO);
    if(pArchivoPeliculas != NULL && pArchivoTemporal != NULL)
    {
        while(!feof(pArchivoPeliculas))
        {
            cantidadLeida = fread(&temporal, sizeof(EMovie), 1, pArchivoPeliculas);
            if(cantidadLeida == 1)
            {
                if(stricmp(movie.titulo, temporal.titulo) != 0)
                {
                    cantidadEscrita = fwrite(&temporal, sizeof(EMovie), 1, pArchivoTemporal);
                    if(cantidadEscrita < 1)
                    {
                        //Hubo un error en la escritura
                        break;
                    }
                }
                else
                {
                    borroPelicula = 1;
                }
            }
            else
            {
                //Hubo un error en la lectura
                break;
            }
        }

        cierraArchivo = fclose(pArchivoPeliculas); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo de peliculas");
        }
        cierraArchivo = fclose(pArchivoTemporal); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo temporal");
        }
    }

    return borroPelicula;
}

void pedirTituloPelicula(char* tituloPelicula, char* mensaje)
{
    do
    {
        printf("\n");
        pedirString(mensaje, tituloPelicula, TAM_TITULO);
        if(strcmp(tituloPelicula, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
        }
    } while(strcmp(tituloPelicula, "") == 0);
}

int restaurarArchivoPeliculas(int borroPelicula)
{
    int operacionArchivo;

    if(borroPelicula == 1)
    {
        //borro archivo de peliculas
        operacionArchivo = remove(PATH_ARCHIVO_PELICULAS);
        if(operacionArchivo != 0)
        {
            borroPelicula = 0;
        }
        else
        {
            //renombro archivo temporal que no contiene la pelicula eliminada, como nuevo archivo de peliculas
            operacionArchivo = rename(PATH_ARCHIVO_TEMPORAL, PATH_ARCHIVO_PELICULAS);
            if(operacionArchivo != 0)
            {
                borroPelicula = 0;
            }
        }
    }
    else
    {
        //No se efectuó el borrado, borro el archivo temporal
        operacionArchivo = remove(PATH_ARCHIVO_TEMPORAL);
    }

    return operacionArchivo;
}

int listarPeliculas(EMovie* pMovie)
{
    FILE* pArchivoPeliculas = NULL;
    int retorno = -1;
    int cantidadLeida;
    int cierraArchivo;

    pArchivoPeliculas = fopen(PATH_ARCHIVO_PELICULAS, MODO_LECTURA_BINARIO);
    if(pArchivoPeliculas != NULL)
    {
        retorno = 0;

        while(!feof(pArchivoPeliculas))
        {
            cantidadLeida = fread(pMovie, sizeof(EMovie), 1, pArchivoPeliculas);
            if(cantidadLeida == 1)
            {
                printf("\n %s - %s - %d - %s - %d - %s", pMovie->titulo, pMovie->genero, pMovie->duracion, pMovie->descripcion, pMovie->puntaje, pMovie->linkImagen);
                retorno = 1;
            }
            else
            {
                if(feof(pArchivoPeliculas))
                {
                    break;
                }
            }
        }

        cierraArchivo = fclose(pArchivoPeliculas); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo");
        }
    }

    return retorno;
}

int modificarPelicula(EMovie movie)
{
    int modificoPelicula = 0;
    int cantidadLeida;
    int cantidadEscrita;
    int cierraArchivo;
    FILE* pArchivoPeliculas = NULL;
    FILE* pArchivoTemporal = NULL;
    EMovie temporal;

    pArchivoPeliculas = fopen(PATH_ARCHIVO_PELICULAS, MODO_LECTURA_BINARIO);
    pArchivoTemporal = fopen(PATH_ARCHIVO_TEMPORAL, MODO_ESCRITURA_BINARIO);
    if(pArchivoPeliculas != NULL && pArchivoTemporal != NULL)
    {
        while(!feof(pArchivoPeliculas))
        {
            cantidadLeida = fread(&temporal, sizeof(EMovie), 1, pArchivoPeliculas);
            if(cantidadLeida == 1)
            {
                if(stricmp(movie.titulo, temporal.titulo) != 0)
                {
                    cantidadEscrita = fwrite(&temporal, sizeof(EMovie), 1, pArchivoTemporal);
                    if(cantidadEscrita < 1)
                    {
                        //Hubo un error en la escritura
                        break;
                    }
                }
                else
                {
                    modificoPelicula = 1;
                    cantidadEscrita = fwrite(&movie, sizeof(EMovie), 1, pArchivoTemporal);
                    if(cantidadEscrita < 1)
                    {
                        //Hubo un error en la escritura
                        break;
                    }
                }
            }
            else
            {
                //Hubo un error en la lectura
                break;
            }
        }

        cierraArchivo = fclose(pArchivoPeliculas); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo de peliculas");
        }
        cierraArchivo = fclose(pArchivoTemporal); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo temporal");
        }
    }

    return modificoPelicula;
}

void generarPagina(EMovie* lista, char* nombre)
{
    FILE* pArchivoPeliculas = NULL;
    FILE* pArchivoHTML = NULL;
    int cantidadLeida;
    int cierraArchivo;
    char confirma = 'S';

    pArchivoHTML = fopen(nombre, MODO_LECTURA_TEXTO);
    if(pArchivoHTML != NULL) //El archivo existe y pido confirmación de sobreescritura
    {
        do
        {
            printf("\nEl archivo %s ya existe. Desea sobreescribir? (S/N)");
            scanf("%c", &confirma);
            if(toupper(confirma) != 'S' && toupper(confirma) != 'N')
            {
                printf("\nOpcion no valida, debe ingresar S o N");
            }
        } while(toupper(confirma) != 'S' && toupper(confirma) != 'N');

        cierraArchivo = fclose(pArchivoHTML); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
        if(cierraArchivo < 0)
        {
            printf("\nNo se pudo cerrar el archivo");
            confirma = 'N';
        }
    }

    if(confirma == 'S')
    {
        pArchivoPeliculas = fopen(PATH_ARCHIVO_PELICULAS, MODO_LECTURA_BINARIO);
        pArchivoHTML = fopen(nombre, MODO_ESCRITURA_TEXTO);
        if(pArchivoPeliculas != NULL && pArchivoHTML != NULL)
        {
            while(!feof(pArchivoPeliculas))
            {
                cantidadLeida = fread(lista, sizeof(EMovie), 1, pArchivoPeliculas);
                if(cantidadLeida == 1)
                {
                }
                else
                {
                    break;
                }
            }

            cierraArchivo = fclose(pArchivoPeliculas); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
            if(cierraArchivo < 0)
            {
                printf("\nNo se pudo cerrar el archivo de peliculas");
            }
            cierraArchivo = fclose(pArchivoHTML); //Si el archivo es cerrado exitosamente se retorna un 0, en caso contrario se devuelve –1
            if(cierraArchivo < 0)
            {
                printf("\nNo se pudo cerrar el archivo HTML");
            }
        }
    }
}
