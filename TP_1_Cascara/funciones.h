
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide el ingreso por teclado de un n�mero al usuario, mostrandole un mensaje personalizado.
 *
 * \param char[] Mensaje a mostrar al usuario.
 * \return float El n�mero ingresado por el usuario.
 *
 */
float pedirFlotante(char[]);

/** \brief Calcula la suma de dos n�meros.
 *
 * \param float Primer t�rmino de la suma.
 * \param float Segundo t�rmino de la suma.
 * \return float Resultado de la suma de ambos t�rminos.
 *
 */
float calcularSuma(float, float);

/** \brief Calcula la resta de dos n�meros.
 *
 * \param float Primer t�rmino de la resta.
 * \param float Segundo t�rmino de la resta.
 * \return float Resultado de la resta de ambos t�rminos.
 *
 */
float calcularResta(float, float);

/** \brief Calcula la divisi�n de dos n�meros.
 *
 * \param float Primer t�rmino de la divisi�n.
 * \param float Segundo t�rmino de la divisi�n.
 * \return float Resultado de la divisi�n de ambos t�rminos.
 *
 */
float calcularCociente(float, float);

/** \brief Valida los dos t�rminos de una divisi�n.
 *         Devuelve error si el segundo t�rmino de la divisi�n (o divisor) es cero.
 *         Si el primer t�rmino (o dividendo) tambi�n es cero especifica en el error que se trata de una indeterminaci�n.
 *
 * \param float Primer t�rmino de la divisi�n.
 * \param float Segundo t�rmino de la divisi�n.
 * \return int Resultado de la validaci�n:
 *             0 -> Validaci�n OK.
 *             1 -> ERROR. Divisi�n por cero sin indeterminaci�n.
 *             2 -> ERROR. Divisi�n por cero con indeterminaci�n.
 *
 */
int validarCociente(float, float);

/** \brief Calcula la multiplicaci�n de dos n�meros.
 *
 * \param float Primer t�rmino de la multiplicaci�n.
 * \param float Segundo t�rmino de la multiplicaci�n.
 * \return float Resultado de la multiplicaci�n de ambos t�rminos.
 *
 */
float calcularProducto(float, float);

/** \brief Calcula el factorial de un n�mero.
 *
 * \param float N�mero al cual se le va a calcular el factorial.
 * \return int Factorial del n�mero ingresado por par�metro.
 *
 */
int calcularFactorial(float);

/** \brief Valida si es posible calcular el factorial de un n�mero.
 *         Devuelve error para los casos en que el n�mero es negativo o no es entero.
 *
 * \param float N�mero que se va a validar para la operaci�n factorial.
 * \return int Resultado de la validaci�n:
 *             0 -> Validaci�n OK.
 *             1 -> ERROR. Factorial de n�mero decimal.
 *             2 -> ERROR. Factorial de n�mero negativo.
 *
 */
int validarFactorial(float);

/** \brief Llama a la rutina de Windows que limpia la pantalla de la consola.
 *
 * \param void
 * \return void
 *
 */
void limpiarPantalla(void);

/** \brief Valida si un n�mero pasado por par�metro es entero.
 *
 * \param float N�mero que se va a validar.
 * \return int Resultado de la validaci�n:
 *             0 -> El n�mero es entero.
 *             1 -> El n�mero no es entero.
 *
 */
int validarEntero(float);

#endif // FUNCIONES_H_INCLUDED
