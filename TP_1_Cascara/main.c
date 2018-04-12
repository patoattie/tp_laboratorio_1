#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/** \brief Procesa las opciones 3 a 7 de la calculadora, indicando al finalizar si hubo algún error.
 *         Permite distinguir si la operación requiere un solo operando o dos operandos.
 *         Si la operación requiere de un único operando, la función valida que el operando A haya sido previamente ingresado por el usuario.
 *         Si la operación requiere de ambos operandos, la función valida que los operandos A y B hayan sido previamente ingresados por el usuario.
 *         No incluyo esta función en la librería porque considero que es específica de la Calculadora.
 *
 * \param int Opción de menú:
 *            3 -> Suma (requiere ambos operandos).
 *            4 -> Resta (requiere ambos operandos).
 *            5 -> División (requiere ambos operandos).
 *            6 -> Multiplicación (requiere ambos operandos).
 *            7 -> Factorial (requiere un único operando).
 * \param float Operando A.
 * \param float Operando B.
 * \param int Indica si el operando A fue ingresado previamente por el usuario:
 *            0 -> El operando A aún no fue ingresado por el usuario.
 *            1 -> El operando A ya fue ingresado por el usuario.
 * \param int Indica si el operando B fue ingresado previamente por el usuario:
 *            0 -> El operando B aún no fue ingresado por el usuario.
 *            1 -> El operando B ya fue ingresado por el usuario.
 * \param int Indica cuántos operandos requiere la operación a realizar:
 *            1 -> La operación requiere un único operando.
 *            2 -> La operación requiere ambos operandos.
 * \return int Indica el estado de finalización de la operación:
 *            0 -> La operación finalizó OK.
 *            1 -> La operación finalizó con ERROR.
 *
 */
int procesarCalculo(int, float, float, int, int, int);

/** \brief Retorna la cantidad de operandos requeridas para una operación que se pasa por parámetro.
 *         No incluyo esta función en la librería porque considero que es específica de la Calculadora.
 *
 * \param int Número de operación:
 *            3 -> Suma (requiere ambos operandos).
 *            4 -> Resta (requiere ambos operandos).
 *            5 -> División (requiere ambos operandos).
 *            6 -> Multiplicación (requiere ambos operandos).
 *            7 -> Factorial (requiere un único operando).
 * \return int Cantidad de operandos requeridos por la operación, puede ser 1 o 2.
 *
 */
int obtenerCantidadOperandos(int);

int main()
{
    char seguir = 's';
    int opcion = 0;

    float operandoA = 0;
    float operandoB = 0;
    int esValidoOperandoA = 0;
    int esValidoOperandoB = 0;
    int huboError = 0;
    int contador;
    int cantidadOperandos = 0;

    while(seguir == 's')
    {
        if(esValidoOperandoA == 0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%f)\n", operandoA);
        }
        if(esValidoOperandoB == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%f)\n", operandoB);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        limpiarPantalla(); //Limpio pantalla antes de mostrar el resultado de la opcion

        //Obtengo la cantidad de operandos únicamente para las opciones de cálculo, es decir 3 a 7.
        if(opcion >= 3 && opcion <= 7)
        {
            cantidadOperandos = obtenerCantidadOperandos(opcion);
        }

        switch(opcion)
        {
            case 1:
                operandoA = pedirFlotante("Ingrese un valor para el operando A: ");
                esValidoOperandoA = 1;
                break;
            case 2:
                operandoB = pedirFlotante("Ingrese un valor para el operando B: ");
                esValidoOperandoB = 1;
                break;
            case 3:
                huboError = procesarCalculo(opcion, operandoA, operandoB, esValidoOperandoA, esValidoOperandoB, cantidadOperandos);
                break;
            case 4:
                huboError = procesarCalculo(opcion, operandoA, operandoB, esValidoOperandoA, esValidoOperandoB, cantidadOperandos);
                break;
            case 5:
                huboError = procesarCalculo(opcion, operandoA, operandoB, esValidoOperandoA, esValidoOperandoB, cantidadOperandos);
                break;
            case 6:
                huboError = procesarCalculo(opcion, operandoA, operandoB, esValidoOperandoA, esValidoOperandoB, cantidadOperandos);
                break;
            case 7:
                huboError = procesarCalculo(opcion, operandoA, operandoB, esValidoOperandoA, esValidoOperandoB, cantidadOperandos);
                break;
            case 8:
                //Acumulo para registrar error en operaciones intermedias, y que si la ultima fue exitosa no me pise la variable flag.
                for(contador = 3; contador < 8; contador++)
                {
                    cantidadOperandos = obtenerCantidadOperandos(contador);
                    huboError = huboError + procesarCalculo(contador, operandoA, operandoB, esValidoOperandoA, esValidoOperandoB, cantidadOperandos);
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }

        if(huboError != 0 && opcion >= 3 && opcion <= 8)
        {
            printf("Al menos una opcion devolvio error\n");
            huboError = 0; //Reseteo para que quede listo el flag para el proceso de una nueva operacion.
        }
    }

    return 0;
}

int procesarCalculo(int opcion, float operandoA, float operandoB, int esValidoOperandoA, int esValidoOperandoB, int cantidadOperandos)
{
    int retorno;
    float resultado;
    int esValidoCociente;
    int esValidoFactorial;
    char nombreOperacion[30];

    switch(opcion)
    {
    case 3: //Suma
        strcpy(nombreOperacion, "suma (A+B)");
        break;
    case 4: //Resta
        strcpy(nombreOperacion, "resta (A-B)");
        break;
    case 5: //División
        strcpy(nombreOperacion, "division (A/B)");
        break;
    case 6: //Multiplicación
        strcpy(nombreOperacion, "multiplicacion (A*B)");
        break;
    case 7: //Factorial
        strcpy(nombreOperacion, "factorial (A!)");
        break;
    }

    if(cantidadOperandos != 1 && cantidadOperandos != 2) //Me aseguro de que la función reciba 1 o 2 como cantidad de operandos
    {
        printf("Error al obtener cantidad de operandos\n");
        retorno = 1; //ERROR
    }
    else if(esValidoOperandoA != 1 && esValidoOperandoB != 1 && (cantidadOperandos == 2)) //Ambos operandos no asignados. No aplica a la opcion 7 (Factorial) que utiliza un solo operando.
    {
        printf("Error. Debe asignar valor a los operandos A y B antes de efectuar la operacion %s\n", nombreOperacion);
        retorno = 1; //ERROR
    }
    else if(esValidoOperandoA != 1) //No esta asignado el operando A. Siempre es error independientemente de la cantidad de operandos que use la operacion.
    {
        printf("Error. Debe asignar valor al operando A antes de efectuar la operacion %s\n", nombreOperacion);
        retorno = 1; //ERROR
    }
    else if(esValidoOperandoB != 1 && cantidadOperandos == 2) //No esta asignado el operando B. Es error unicamente si la operacion requiere ambos operandos.
    {
        printf("Error. Debe asignar valor al operando B antes de efectuar la operacion %s\n", nombreOperacion);
        retorno = 1; //ERROR
    }
    else //Operandos en condiciones preliminares para efectuar la operacion requerida.
    {
        switch(opcion)
        {
        case 3: //Suma
            resultado = calcularSuma(operandoA, operandoB);
            retorno = 0; //OK
            break;
        case 4: //Resta
            resultado = calcularResta(operandoA, operandoB);
            retorno = 0; //OK
            break;
        case 5: //Division
            esValidoCociente = validarCociente(operandoA, operandoB);
            switch(esValidoCociente)
            {
            case 2: //indeterminacion -> (0/0)
                printf("Error de division por cero. El resultado de la operacion division (A/B) no se puede calcular y es una indeterminacion\n");
                retorno = 1; //ERROR
                break;
            case 1: //infinito -> (A/0)
                printf("Error de division por cero. El resultado de la operacion division (A/B) no se puede calcular\n");
                retorno = 1; //ERROR
                break;
            case 0: //OK
                resultado = calcularCociente(operandoA, operandoB);
                retorno = 0; //OK
                break;
            default:
                printf("Caso no contemplado en la funcion validarCociente. Devolvio %d\n", esValidoCociente);
                retorno = 1; //ERROR
                break;
            }
            break;
        case 6: //Cociente
            resultado = calcularProducto(operandoA, operandoB);
            retorno = 0; //OK
            break;
        case 7: //Factorial
            esValidoFactorial = validarFactorial(operandoA);
            switch(esValidoFactorial)
            {
            case 2: //Negativo
                printf("Error. No se puede calcular el factorial de un numero negativo\n");
                retorno = 1; //ERROR
                break;
            case 1: //Decimal
                printf("Error. No se puede calcular el factorial de un numero decimal\n");
                retorno = 1; //ERROR
                break;
            case 0: //OK
                resultado = calcularFactorial(operandoA);
                retorno = 0; //OK
                break;
            default:
                printf("Caso no contemplado en la funcion validarFactorial. Devolvio %d\n", esValidoFactorial);
                retorno = 1; //ERROR
                break;
            }
            break;
        default:
            printf("Caso no contemplado en la funcion procesarCalculo. Parametro = %d", opcion);
            retorno = 1; //ERROR
            break;
        }
    }

    if(retorno == 0) //No hubo error, muestro por pantalla el resultado de la operacion.
    {
        printf("Resultado de la operacion %s: %f\n", nombreOperacion, resultado);
    }

    return retorno;
}

int obtenerCantidadOperandos(int opcion)
{
    int retorno = 0;

    if(opcion >= 3 && opcion <= 6) //Para operaciones 3 a 6 se requieren 2 operandos
    {
        retorno = 2;
    }
    else if(opcion == 7) //Para la operación 7 se requiere un solo operando.
    {
        retorno = 1;
    }

    return retorno;
}
