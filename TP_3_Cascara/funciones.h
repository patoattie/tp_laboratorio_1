#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MODO_LECTURA_BINARIO "rb"
#define MODO_ESCRITURA_BINARIO "wb"
#define MODO_APPEND_BINARIO "ab"
#define MODO_LECTURA_TEXTO "r"
#define MODO_ESCRITURA_TEXTO "w"
#define PATH_ARCHIVO_PELICULAS "peliculas.dat"
#define PATH_ARCHIVO_TEMPORAL "peliculas.tmp"
#define TAM_TITULO 20
#define TAM_GENERO 20
#define TAM_DESCRIPCION 250
#define TAM_LINK 250
#define STR_BUFFER 400

typedef struct{
    char titulo[TAM_TITULO];
    char genero[TAM_GENERO];
    int duracion;
    char descripcion[TAM_DESCRIPCION];
    int puntaje;
    char linkImagen[TAM_LINK];
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* lista, char* nombre);

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

/** \brief Pide un n�mero entero al usuario
 *
 * \param Mensaje a mostrar al usuario
 * \return El n�mero ingresado por el usuario
 *
 */
int pedirEnteroSinValidar(char*);

/** \brief Pide una cadena de caracteres al usuario validando que no supere el tama�o definido
 *         para evitar desbordamiento
 *
 * \param char[] Mensaje a mostrar al usuario
 * \param char[] La cadena ingresada por el usuario y validada
 * \param int Longitud m�xima de la cadena de caracteres
 * \return void
 *
 */
void pedirString(char*, char*, int);

/** \brief Valida que una cadena de caracteres no supere el tama�o definido para evitar desbordamiento
 *
 * \param char[] La cadena ingresada por el usuario
 * \param int Longitud m�xima de la cadena de caracteres
 * \return void
 *
 */
void validarString(char*, int);

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
int pedirEntero(char*, int, int);

/** \brief Pide un n�mero entero al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
int validarEntero(int, int, int);
void cargarPelicula(const char*, EMovie*);
int buscarPelicula(const char*, EMovie*);
void pedirTituloPelicula(char*, char*);
int restaurarArchivoPeliculas(int);
int listarPeliculas(EMovie*);
int modificarPelicula(EMovie movie);

#endif // FUNCIONES_H_INCLUDED
