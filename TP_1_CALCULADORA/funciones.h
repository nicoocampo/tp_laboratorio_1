/**
 * @brief Menu de opciones de la calculadora
 *
 * @param operandos[] array donde se alojan los operandos
 * @param banderas[] array de banderas que notifican que el usuario ingresa los operandos
 *
 * @return la opcion elegida por el usuario
 *
 */
int menu(float operandos[], int banderas[]);

/**
 * @brief Calcula todas las operaciones matematicas solicitadas
 *
 * @param operandos[] array donde se alojan los operandos
 * @param resultados[] array donde se alojan los resultados de las operaciones matematicas
 * @param operandosAux[] array donde se alojan los operandos
 * @param banderas[] array de banderas que notifican que el usuario ingresa los operandos
 * @param banderasError[] array de banderas para notificar errores en las operaciones matematicas
 *
 */
void calcularOperaciones(float operandos[], float resultados[], float operandosAux[], int banderas[], int banderasError[]);

/**
 * @brief Muestra en pantalla los valores del array resultados
 *
 * @param resultados[] array donde se alojan los resultados de las operaciones matematicas para mostrar en pantalla
 * @param operandosAux[] array donde se alojan los operandos
 * @param banderasError[] array de banderas para notificar errores en las operaciones matematicas
 *
 */
void mostrarResultados(float resultados[], int banderas[], float operandosAux[], int banderasError[]);

/**
 * @brief Ingresa operandos
 *
 * @param opcion Variable que sirve para decidir donde guardar el operando
 *
 * @return Devuelve el operando ingresado
 *
 */
float ingresoOperando(int opcion);

/**
 * @brief Suma operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a sumar
 * @param len Cantidad de numeros del array a sumar
 *
 * @return El resultado de la suma
 */
float suma(float operandos[], int len);


/**
 * @brief Resta operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a restar
 * @param len Cantidad de numeros del array a restar
 *
 * @return El resultado de la diferencia
 */
float diferencia(float operandos[], int len);

/**
 * @brief Multiplica operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a multiplicar
 * @param len Cantidad de numeros del array a multiplicar
 *
 * @return El resultado del producto
 */
float producto(float operandos[], int len);

/**
 * @brief Divide operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a dividir
 * @param banderasError[] array de banderas para notificar errores
 en las operaciones matematicas, en este caso, la division entre ceros
 *
 * @return El resultado de la division
 */
float cociente(float operandos[], int banderasError[]);

/**
 * @brief Calcula el factorial de un numero
 *
 * @param operando[] El numero a calcular el factorial
 * @param banderasError[] array de banderas para notificar errores
 en las operaciones matematicas, en este caso, el factorial de numeros negativos
 * @param i La posicion del array donde se aloja el numero a calcular el factorial
 *
 * @return El resultado del factorial
 */
float factorial(float operandos[], int banderasError[], int i);

