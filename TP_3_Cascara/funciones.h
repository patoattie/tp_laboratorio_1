#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MODO_LECTURA_BINARIO "rb"
#define MODO_ESCRITURA_BINARIO "wb"
#define MODO_APPEND_BINARIO "ab"
#define MODO_LECTURA_TEXTO "r"
#define MODO_ESCRITURA_TEXTO "w"
#define PATH_ARCHIVO_PELICULAS "peliculas.dat"
#define PATH_ARCHIVO_TEMPORAL "peliculas.tmp"
#define PATH_HTML "template/"
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
 * \param char* Mensaje a mostrar al usuario
 * \param char* La cadena ingresada por el usuario y validada
 * \param int Longitud m�xima de la cadena de caracteres
 * \return void
 *
 */
void pedirString(char*, char*, int);

/** \brief Valida que una cadena de caracteres no supere el tama�o definido para evitar desbordamiento
 *
 * \param char* La cadena ingresada por el usuario
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

/** \brief Puebla los campos de la estructura EMovie, t�tulo con el valor del parametro tituloPelicula,
 *         el resto se le pide al usuario que los ingrese por teclado.
 * \param char* const T�tulo de la pel�cula a guardar en la estructura
 * \param EMovie* Estructura cuyos campos ser�n cargados con valores.
 * \return void
 *
 */
void cargarPelicula(const char*, EMovie*);

/** \brief Recorre secuencialmente el archivo de pel�culas, buscando por el campo tituloPelicula de la estructura EMovie.
 *         Interrumpe la b�squeda ante la primera coincidencia hallada.
 * \param char* const T�tulo a buscar
 * \param EMovie* Estructura en la cual se van volcando los registros que se van leyendo del archivo.
 * \return int Retorna 1 o 0 de acuerdo a si pudo hallar la pelicula o no
 *
 */
int buscarPelicula(const char*, EMovie*);

/** \brief Pide al usuario que ingrese un t�tulo de pel�cula por teclado
 *
 * \param char* Puntero a variable donde se guarda el t�tulo ingresado por el usuario.
 * \param char* Mensaje a mostrar al usuario por pantalla.
 * \return void
 *
 */
void pedirTituloPelicula(char*, char*);

/** \brief Si la funci�n de borrado de pel�cula concluy� exitosamente (retorna 1), la presente funci�n se encarga de
 *            borrar el archivo permanente de pel�culas (peliculas.dat) y renombrar el archivo temporal de pel�culas
 *            (peliculas.tmp), al cual no se le copi� la pel�cula eliminada, para que tome el nombre del permanente.
 *         Si la funci�n de borrado de pel�cula no pudo eliminar la misma (retorna 0), la presente funci�n se encarga de
 *            borrar el archivo temporal de pel�culas (peliculas.tmp) sin afectar el archivo permanente (peliculas.dat).
 * \param int Estado que devolvi� la funci�n de borrado de pel�cula (0 o 1).
 * \return int Retorna 1 o 0 de acuerdo a si pudo efectuar las operaciones sobre los archivos o no.
 *
 */
int restaurarArchivoPeliculas(int);

/** \brief Recorre secuencialmente el archivo de pel�culas e imprime por pantalla los valores de todos los campos de la
 *         estructura EMovie en cada uno de los registros recorridos.
 * \param EMovie* Estructura en la cual se van volcando los registros que se van leyendo del archivo.
 * \return int Retorna 1 o 0 de acuerdo a si hay datos para mostrar o no.
 *
 */
int listarPeliculas(EMovie*);

/** \brief Recorre secuencialmente el archivo permanente de pel�culas, si el t�tulo le�do es distinto al t�tulo de la estructura
 *         EMovie que se le pasa por par�metro, entonces se escribe en el archivo temporal de pel�culas. Si el t�tulo le�do es
 *         igual al t�tulo de la estructura EMovie que se le pasa por par�metro, entonces se escribe en el archivo temporal de
 *         pel�culas los datos de la estructura que viene por par�metro.
 * \param movie EMovie Estructura que tiene cargados los datos de reemplazo de la pel�cula.
 * \return int Retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no.
 *
 */
int modificarPelicula(EMovie movie);

#endif // FUNCIONES_H_INCLUDED
