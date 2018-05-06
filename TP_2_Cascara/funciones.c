#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void EPersona_init(EPersona lista[])
{
    int i;
    for(i = 0; i < CANTIDAD; i++)
    {
        lista[i].estado = LIBRE;
    }
}

int obtenerEspacioLibre(EPersona lista[])
{
    int retorno = -1;
    int i;
    int posicionLibre = -1; //Guarda la primer posicion con estado LIBRE que encuentra
    int posicionBaja = -1; //Guarda la primer posicion con estado BAJA que encuentra

    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            posicionLibre = i;
            break;
        }
    }

    if(posicionLibre < 0) //No hay posiciones con estado LIBRE, busco la primer posición con estado BAJA
    {
        for(i = 0; i < CANTIDAD; i++)
        {
            if(lista[i].estado == BAJA)
            {
                posicionBaja = i;
                break;
            }
        }

        if(posicionBaja >= 0)
        {
            retorno = posicionBaja; //Retorno la primera posición con estado BAJA
        }
    }
    else
    {
        retorno = posicionLibre; //Retorno la primera posición con estado LIBRE
    }

    return retorno;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int retorno = -1;
    int i;

    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].dni == dni)
        {
            retorno = i;
            //Hallé la persona que buscaba y retorno su indice
            break;
        }
    }

    return retorno;
}

void EPersona_mostrarUno(EPersona parametro)
{
     printf("\n %d - %s - %d", parametro.dni, parametro.nombre, parametro.edad);

}

void EPersona_mostrarUnoConEstado(EPersona parametro)
{
    switch(parametro.estado)
    {
    case LIBRE: //No muestro las posiciones con estado LIBRE porque contienen basura
        break;
    case BAJA:
        printf("\n %d - %s - %d - %s", parametro.dni, parametro.nombre, parametro.edad, "[BAJA]");
        break;
    case OCUPADO:
        printf("\n %d - %s - %d", parametro.dni, parametro.nombre, parametro.edad);
        break;
    default:
        printf("\n %d - %s - %d - %s", parametro.dni, parametro.nombre, parametro.edad, "[N/A]");
        break;
    }
}

int EPersona_mostrarListadoConOcupados(EPersona lista[])
{
    int retorno = 0;
    int i;

    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            retorno = 1;
            //Se muestra al menos un elemento del array
            EPersona_mostrarUno(lista[i]);
        }
    }

    if(retorno == 0)
    {
        printf("\n*** NO HAY PERSONAS PARA MOSTRAR ***");
    }

    return retorno;
}

int EPersona_mostrarListado(EPersona lista[])
{
    int retorno = 0;
    int i;

    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == BAJA || lista[i].estado == OCUPADO)
        {
            retorno = 1;
            //Se muestra al menos un elemento del array
            EPersona_mostrarUnoConEstado(lista[i]);
        }
    }

    if(retorno == 0)
    {
        printf("\n*** NO HAY PERSONAS PARA MOSTRAR ***");
    }

    return retorno;
}

int EPersona_alta(EPersona lista[])
{
    int retorno = -1;
    EPersona temporario;
    int indice;
    char confirma[3];

    //Busca lugar libre en el array
    indice = obtenerEspacioLibre(lista);
    if(indice >= 0)
    {
        //Campos con valores iniciales calculados
        temporario.estado = OCUPADO;

        retorno = -2;
        //Campos con valores pedidos al usuario
        do
        {
            temporario.dni = pedirEnteroSinValidar("Ingrese DNI: ");
            if(temporario.dni <= 0)
            {
                printf("El numero de DNI debe ser positivo, por favor reingrese\n");
            }
        } while(temporario.dni <= 0);

        do
        {
            pedirString("Ingrese nombre: ", temporario.nombre, TAM_NOMBRE);
            if(strcmp(temporario.nombre, "") == 0)
            {
                printf("El dato es obligatorio, por favor reingrese\n");
            }
        } while(strcmp(temporario.nombre, "") == 0);

        temporario.edad = pedirEntero("Ingrese edad: ", 1, 120);

        retorno = -3;
        //Confirmación de la acción por parte del usuario
        do
        {
            printf("\nSe va a dar de alta:");
            EPersona_mostrarUno(temporario);
            pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
            if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
            {
                printf("Debe ingresar S o N. Por favor reingrese\n");
            }
        } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

        if(stricmp(confirma, "S") == 0)
        {
            retorno = 0;
            //OK
            lista[indice] = temporario;
            printf("Alta Exitosa\n");
        }
        else //retorno = -3
        {
            printf("Accion cancelada por el usuario\n");
        }
    }
    else //retorno = -1
    {
        printf("No hay espacio suficiente para agregar personas\n");
    }

    return retorno;
}

int EPersona_baja(EPersona lista[])
{
    int retorno = -1;
    int indice;
    int muestraListado;
    int dni;
    char confirma[3];
    int cancelaAccion = 0;

    do
    {
        muestraListado = EPersona_mostrarListadoConOcupados(lista);

        switch(muestraListado)
        {
        case 0:
            printf("\nNo hay personas para dar de baja"); //retorno = -1
            break;
        case 1:
            dni = pedirEnteroSinValidar("\nIngrese DNI a borrar: ");
            indice = buscarPorDni(lista, dni);
            if(indice < 0)
            {
                printf("No se encontro el DNI ingresado. Por favor reingrese\n");
            }
            else
            {
                retorno = -2;
                //Confirmación de la acción por parte del usuario
                do
                {
                    printf("\nSe va a dar de baja:");
                    EPersona_mostrarUno(lista[indice]);
                    pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                    if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                    {
                        printf("Debe ingresar S o N. Por favor reingrese\n");
                    }
                } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

                if(stricmp(confirma, "S") == 0)
                {
                    retorno = 0;
                    //OK
                    lista[indice].estado = BAJA;
                    printf("Baja Exitosa\n");
                }
                else //retorno = -2
                {
                    printf("Accion cancelada por el usuario\n");
                    cancelaAccion = 1;
                }
            }

            break;
        default:
            printf("\Error al listar...\n"); //retorno = -1
            break;
        }
    } while(indice < 0 && muestraListado == 1 && cancelaAccion == 0);

    return retorno;
}

int validarEnteroDecimal(double numero)
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
    double ingreso;
    int esDecimal;

    printf("%s", mensaje);
    do
    {
        scanf("%lf", &ingreso);
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

int pedirEnteroSinValidar(char mensaje[])
{
    int numero;
    double ingreso;
    int esDecimal;

    printf("%s", mensaje);
    do
    {
        scanf("%lf", &ingreso);
        esDecimal = validarEnteroDecimal(ingreso);
        if(esDecimal == 1)
        {
            printf("ERROR Debe ingresar un numero sin digitos decimales: ");
        }
    } while(esDecimal == 1);

    numero = (int)ingreso;

    return numero;
}

void pedirString(char mensaje[], char cadena[], int longitud)
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

void validarString(char cadena[], int longitud)
{
    while(strlen(cadena) - 1 > longitud)
    {
        printf("ERROR El texto ingresado supera los %d caracteres\npor favor reingrese: ", longitud);
        fflush(stdin);
        fgets(cadena, STR_BUFFER, stdin);
    }
}

void limpiarPantalla(void)
{
    system("cls");
}

void pausarEjecucion(void)
{
    system("pause");
}

void ordenarVectorMenorMayor(EPersona vector[])
{
    int i;
    int j;
    EPersona auxiliar;

    for(i = 0; i < CANTIDAD - 1; i++)
    {
        for(j = i + 1; j < CANTIDAD; j++)
        {
            if(stricmp(vector[i].nombre, vector[j].nombre) > 0) //Criterio de ordenamiento
            {
                auxiliar = vector[i];
                vector[i] = vector[j];
                vector[j] = auxiliar;
            }
        }
    }
}

int buscarMaximo(int vector[], int tamanio)
{
    int i;
    int retorno;
    int flag = 0;

    for(i = 0; i < tamanio; i++)
    {
        if((vector[i] > retorno) || flag == 0)
        {
            retorno = vector[i];
            flag = 1;
        }
    }

    return retorno;
}
