#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/** \brief Pide que el usuario ingrese un entero y lo valida
 *
 * \param mensaje[] mensaje a mostrar en pantalla al pedir el entero
 * \return El entero validado
 *
 */
int pedirEntero(char mensaje[], int max, int min);

/** \brief Pide que el usuario ingrese un flotante y lo valida
 *
 * \param mensaje[] mensaje a mostrar en pantalla al pedir el flotante
 * \return el flotante ya validado
 *
 */
float pedirFlotante(char mensaje[]);

/** \brief Pide que el usuario ingrese un caracter
 *
 * \param mensaje[] mensaje a mostrar en pantalla al pedir el caracter
 * \return El caracter solicitado
 *
 */
char pedirCaracter(char mensaje[]);

/** \brief Pide que el usuario ingrese una cadena y la valida
 *
 * \param mensaje[] mensaje a mostrar en pantalla al pedir el cadena
 *
 */
void pedirCadena(char mensaje[],char cadena[],int len);

/** \brief Pide que el usuario que ingrese un caracter 'M' o 'F' y lo valida
 *
 * \param mensaje[] mensaje a mostrar en pantalla al pedir el cadena
 * \return El caracter solicitado
 *
 */
char pedirSexo(char mensaje[]);

void cadenaSoloLetras(char mensaje[], char cadena[], int len);

