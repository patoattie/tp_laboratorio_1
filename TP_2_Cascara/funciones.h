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

/** \brief Muestra por pantalla un elemento del vector de personas, siempre que no esté dado de BAJA ni que sea un elemento LIBRE.
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

/** \brief Recorre el vector de personas en forma secuencial desde la primera posición hasta la última,
 *         imprimiendo en ese orden por pantalla los elementos con estado OCUPADO mediante la invocación
 *         a la función EPersona_mostrarUno.
 * \param lista[] EPersona -> Vector de personas a mostrar por pantalla.
 * \return int 0 -> Si no encontró personas para mostrar, imprime por pantalla mensaje indicando tal situación.
 *             1 -> Se muestra al menos una persona.
 */
int EPersona_mostrarListadoConOcupados(EPersona lista[]);

/** \brief Recorre el vector de personas en forma secuencial desde la primera posición hasta la última,
 *         imprimiendo en ese orden por pantalla tanto elementos OCUPADOS como dados de BAJA mediante
 *         la invocación a la función EPersona_mostrarUnoConEstado.
 * \param lista[] EPersona -> Vector de personas a mostrar por pantalla.
 * \return int 0 -> Si no encontró personas para mostrar, imprime por pantalla mensaje indicando tal situación.
 *             1 -> Se muestra al menos una persona.
 */
int EPersona_mostrarListado(EPersona lista[]);

/** \brief Da de alta una persona en la primera posición del vector con estado LIBRE que haya disponible.
 *         Si no hay disponible utiliza la primera posición del vector con una persona dada de BAJA.
 *         Si tampoco hay disponibilidad muestra un mensaje de error informando que no hay lugar disponible.
 *         Para el alta se pide el ingreso al usuario por teclado de los tres campos editables de la estructura:
 *         dni -> valida que sea un numero mayor a cero.
 *         nombre -> valida que no se ingrese una cadena vacía.
 *         edad -> valida un entero entre 1 y 120.
 *         El estado lo setea la función a OCUPADO.
 * \param lista[] EPersona -> Vector de personas donde se ingresará el nuevo dato.
 * \return int  0 -> Alta OK.
 *             -1 -> No hay espacio suficiente para agregar personas.
 *             -3 -> Acción cancelada por el usuario.
 */
int EPersona_alta(EPersona lista[]);

/** \brief Da de baja lógica una persona, para ello se le muestra al usuario un listado de las personas
 *         dadas de alta actualmente invocando a la función EPersona_mostrarListadoConOcupados y se le pide al usuario
 *         que ingrese el DNI de la persona a dar de baja. Si el DNI ingresado no existe muestra el error
 *         y se pide reingreso. Una vez ingresado un DNI existente se muestra al usuario los datos de la
 *         persona a dar de baja invocando a la función EPersona_mostrarUno, y se le pide que confirme (S) o
 *         descarte (N) la baja a realizar.
 * \param lista[] EPersona -> Vector de personas desde donde el usuario elegirá el elemento a dar de baja.
 * \return int  0 -> Baja OK.
 *             -1 -> No hay personas disponibles para dar de baja.
 */
int EPersona_baja(EPersona lista[]);

/** \brief Valida si un número pasado por parámetro es entero o decimal.
 *
 * \param double Número que se va a validar.
 * \return int Resultado de la validación:
 *             0 -> El número es entero.
 *             1 -> El número es decimal.
 *
 */
int validarEnteroDecimal(double);

/** \brief Pide un número entero al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor mínimo del intervalo de validación
 * \param Valor máximo del intervalo de validación
 * \return El número ingresado por el usuario validado
 *
 */
int pedirEntero(char[], int, int);

/** \brief Pide un número entero al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor mínimo del intervalo de validación
 * \param Valor máximo del intervalo de validación
 * \return El número ingresado por el usuario validado
 *
 */
int validarEntero(int, int, int);

/** \brief Pide un número entero al usuario
 *
 * \param Mensaje a mostrar al usuario
 * \return El número ingresado por el usuario
 *
 */
int pedirEnteroSinValidar(char[]);

/** \brief Pide una cadena de caracteres al usuario validando que no supere el tamaño definido
 *         para evitar desbordamiento
 *
 * \param char[] Mensaje a mostrar al usuario
 * \param char[] La cadena ingresada por el usuario y validada
 * \param int Longitud máxima de la cadena de caracteres
 * \return void
 *
 */
void pedirString(char[], char[], int);

/** \brief Valida que una cadena de caracteres no supere el tamaño definido para evitar desbordamiento
 *
 * \param char[] La cadena ingresada por el usuario
 * \param int Longitud máxima de la cadena de caracteres
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

/** \brief Llama a la rutina de Windows que pausa la ejecución.
 *
 * \param void
 * \return void
 *
 */
void pausarEjecucion(void);

void ordenarVectorMenorMayor(EPersona[]);

#endif // FUNCIONES_H_INCLUDED
