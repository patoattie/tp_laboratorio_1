#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TAM_NOMBRE 50
#define CANTIDAD 20
#define OCUPADO 0
#define LIBRE 1
#define BAJA 2
#define STR_BUFFER 100

typedef struct {

    char nombre[TAM_NOMBRE];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Inicializa el vector de personas, estableciendo el flag de estado como LIBRE,
 *         para dejar listas todas las posiciones del vector en condiciones de albergar datos.
 * \param lista[] EPersona -> Vector de personas a inicializar.
 * \return void
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

/** \brief Muestra por pantalla un elemento del vector de personas, siempre que no est� dado de BAJA ni que sea un elemento LIBRE.
 *         Formato: DNI - Nombre - Edad
 * \param parametro EPersona -> Elemento a mostrar por pantalla.
 * \return void
 *
 */
void EPersona_mostrarUno(EPersona parametro);

/** \brief Muestra por pantalla un elemento del vector de personas. Muestra tanto elementos OCUPADOS como dados de BAJA.
 *         Formato, si el estado del elemento es OCUPADO: DNI - Nombre - Edad
 *         Formato, si el estado del elemento es BAJA: DNI - Nombre - Edad - [Estado]
 * \param parametro EPersona -> Elemento a mostrar por pantalla.
 * \return void
 *
 */
void EPersona_mostrarUnoConEstado(EPersona parametro);

/** \brief Recorre el vector de personas en forma secuencial desde la primera posici�n hasta la �ltima,
 *         imprimiendo en ese orden por pantalla los elementos con estado OCUPADO mediante la invocaci�n
 *         a la funci�n EPersona_mostrarUno.
 * \param lista[] EPersona -> Vector de personas a mostrar por pantalla.
 * \return int 0 -> Si no encontr� personas para mostrar, imprime por pantalla mensaje indicando tal situaci�n.
 *             1 -> Se muestra al menos una persona.
 */
int EPersona_mostrarListadoConOcupados(EPersona lista[]);

/** \brief Recorre el vector de personas en forma secuencial desde la primera posici�n hasta la �ltima,
 *         imprimiendo en ese orden por pantalla tanto elementos OCUPADOS como dados de BAJA mediante
 *         la invocaci�n a la funci�n EPersona_mostrarUnoConEstado.
 * \param lista[] EPersona -> Vector de personas a mostrar por pantalla.
 * \return int 0 -> Si no encontr� personas para mostrar, imprime por pantalla mensaje indicando tal situaci�n.
 *             1 -> Se muestra al menos una persona.
 */
int EPersona_mostrarListado(EPersona lista[]);

/** \brief Da de alta una persona en la primera posici�n del vector con estado LIBRE que haya disponible.
 *         Si no hay disponible utiliza la primera posici�n del vector con una persona dada de BAJA.
 *         Si tampoco hay disponibilidad muestra un mensaje de error informando que no hay lugar disponible.
 *         Para el alta se pide el ingreso al usuario por teclado de los tres campos editables de la estructura:
 *         dni -> valida que sea un numero mayor a cero.
 *         nombre -> valida que no se ingrese una cadena vac�a.
 *         edad -> valida un entero entre 1 y 120.
 *         El estado lo setea la funci�n a OCUPADO.
 * \param lista[] EPersona -> Vector de personas donde se ingresar� el nuevo dato.
 * \return int  0 -> Alta OK.
 *             -1 -> No hay espacio suficiente para agregar personas.
 *             -3 -> Acci�n cancelada por el usuario.
 */
int EPersona_alta(EPersona lista[]);

/** \brief Da de baja l�gica una persona, para ello se le muestra al usuario un listado de las personas
 *         dadas de alta actualmente invocando a la funci�n EPersona_mostrarListadoConOcupados y se le pide al usuario
 *         que ingrese el DNI de la persona a dar de baja. Si el DNI ingresado no existe muestra el error
 *         y se pide reingreso. Una vez ingresado un DNI existente se muestra al usuario los datos de la
 *         persona a dar de baja invocando a la funci�n EPersona_mostrarUno, y se le pide que confirme (S) o
 *         descarte (N) la baja a realizar.
 * \param lista[] EPersona -> Vector de personas desde donde el usuario elegir� el elemento a dar de baja.
 * \return int  0 -> Baja OK.
 *             -1 -> No hay personas disponibles para dar de baja.
 */
int EPersona_baja(EPersona lista[]);

/** \brief Valida si un n�mero pasado por par�metro es entero o decimal.
 *
 * \param double N�mero que se va a validar.
 * \return int Resultado de la validaci�n:
 *             0 -> El n�mero es entero.
 *             1 -> El n�mero es decimal.
 *
 */
int validarEnteroDecimal(double);

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

/** \brief Ordena mediante m�todo de la burbuja un vector de estructura Persona,
 *         usando como criterio de ordenamiento el campo nombre en forma ascendente.
 * \param EPersona[] Vector de personas
 * \return void
 *
 */
void ordenarVectorMenorMayor(EPersona[]);

/** \brief Busca el m�ximo valor en un vector de n�meros enteros.
 *
 * \param int[] Vector de n�meros enteros.
 * \param int Tama�o del vector.
 * \return int M�ximo valor hallado
 *
 */
int buscarMaximo(int[], int);

#endif // FUNCIONES_H_INCLUDED
