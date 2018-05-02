#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TAM_NOMBRE 50
#define CANTIDAD 20

typedef struct {

    char nombre[TAM_NOMBRE];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief
 *
 * \param lista[] EPersona
 * \return void
 *
 */
void EPersona_init(EPersona lista[]);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/** \brief
 *
 * \param parametro EPersona
 * \return void
 *
 */
void EPersona_mostrarUno(EPersona parametro);

/** \brief
 *
 * \param parametro EPersona
 * \return void
 *
 */
void EPersona_mostrarUnoConEstado(EPersona parametro);

/** \brief
 *
 * \param lista[] EPersona
 * \return int
 *
 */
int EPersona_mostrarListadoConOcupados(EPersona lista[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return int
 *
 */
int EPersona_mostrarListado(EPersona lista[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return int
 *
 */
int EPersona_alta(EPersona lista[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return int
 *
 */
int EPersona_baja(EPersona lista[]);

/** \brief Valida si un n�mero pasado por par�metro es entero o decimal.
 *
 * \param float N�mero que se va a validar.
 * \return int Resultado de la validaci�n:
 *             0 -> El n�mero es entero.
 *             1 -> El n�mero es decimal.
 *
 */
int validarEnteroDecimal(float);

/** \brief Pide un n�mero entero al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
int pedirEntero(char[], int, int);

/** \brief Pide un n�mero entero al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
int validarEntero(int, int, int);

/** \brief Pide un n�mero entero al usuario
 *
 * \param Mensaje a mostrar al usuario
 * \return El n�mero ingresado por el usuario
 *
 */
int pedirEnteroSinValidar(char[]);

/** \brief Pide una cadena de caracteres al usuario validando que no supere el tama�o definido
 *         para evitar desbordamiento
 *
 * \param char[] Mensaje a mostrar al usuario
 * \param char[] La cadena ingresada por el usuario y validada
 * \param int Longitud m�xima de la cadena de caracteres
 * \return void
 *
 */
void pedirString(char[], char[], int);

/** \brief Valida que una cadena de caracteres no supere el tama�o definido para evitar desbordamiento
 *
 * \param char[] La cadena ingresada por el usuario
 * \param int Longitud m�xima de la cadena de caracteres
 * \return void
 *
 */
void validarString(char[], int);

/** \brief Llama a la rutina de Windows que limpia la pantalla de la consola.
 *
 * \param void
 * \return void
 *
 */
void limpiarPantalla(void);

/** \brief Llama a la rutina de Windows que pausa la ejecuci�n.
 *
 * \param void
 * \return void
 *
 */
void pausarEjecucion(void);

#endif // FUNCIONES_H_INCLUDED
