#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/**
 * @brief Menu de opciones de la calculadora
 *
 * @param operandos[] array donde se alojan los operandos
 * @param banderas[] array de banderas que notifican que el usuario ingresa los operandos
 *
 * @return la opcion elegida por el usuario
 *
 */
int menu(float operandos[], int banderas[]){
    int opcion;
    system("cls");
    do{
    if(banderas[0]==0)
        printf("1 - Ingresar 1er operando (A=x)");
    else
        printf("1 - Ingresar 1er operando (A=%.2f)", operandos[0]);
    if(banderas[1]==0)
        printf("\n2 - Ingresar 2do operando (B=y)");
    else
        printf("\n2 - Ingresar 2do operando (B=%.2f)", operandos[1]);
    printf("\n3 - Calcular todas las operaciones");
    printf("\n4 - Informar resultados");
    printf("\n\n5 - Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);
    }while (opcion<0 || opcion>5);
    return opcion;
}

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
void calcularOperaciones(float operandos[], float resultados[], float operandosAux[], int banderas[], int banderasError[]){
    if(banderas[0]==0 || banderas[1]==0)
        printf("\n\nNO SE PUDIERON REALIZAR LAS OPERACIONES POR FALTA DE OPERANDOS\n");
    else{
        resultados[0]=suma(operandos, 2);
        resultados[1]=diferencia(operandos, 2);
        resultados[2]=producto(operandos, 2);
        resultados[3]=cociente(operandos, banderasError);
        resultados[4]=factorial(operandos, banderasError, 0);
        resultados[5]=factorial(operandos, banderasError, 1);
        operandosAux[0]=operandos[0];
        operandosAux[1]=operandos[1];
        banderas[2]=1;
        printf("\n\nSE REALIZARON LAS OPERACIONES CON EXITO!\n");
    }
    system("pause");
}

/**
 * @brief Muestra en pantalla los valores del array resultados
 *
 * @param resultados[] array donde se alojan los resultados de las operaciones matematicas para mostrar en pantalla
 * @param operandosAux[] array donde se alojan los operandos
 * @param banderasError[] array de banderas para notificar errores en las operaciones matematicas
 *
 */
void mostrarResultados(float resultados[], int banderas[], float operandosAux[], int banderasError[]){
    if(banderas[2]==0)
        printf("\n\nERROR: EJECUTE PRIMERO LAS OPERACIONES MATEMATICAS\n\n");
    else{
        printf("\n\nLa suma entre %.2f y %.2f es: %.2f", operandosAux[0], operandosAux[1], resultados[0]);
        printf("\nLa diferencia entre %.2f y %.2f es: %.2f", operandosAux[0], operandosAux[1], resultados[1]);
        printf("\nEl producto entre %.2f y %.2f es: %.2f", operandosAux[0], operandosAux[1], resultados[2]);
        if(banderasError[0]==1)
            printf("\nERROR: NO SE PUEDE CALCULAR LA DIVISION ENTRE CEROS");
        else
            printf("\nEl cociente entre %.2f y %.2f es: %.2f", operandosAux[0], operandosAux[1], resultados[3]);
        if(banderasError[1]==1)
            printf("\nERROR: NO SE PUEDE CALCULAR EL FACTORIAL DE UN NUMERO NEGATIVO");
        else
            printf("\nEl factorial de %.2f es: %.2f", operandosAux[0], resultados[4]);
        if(banderasError[2]==1)
            printf("\nERROR: NO SE PUEDE CALCULAR EL FACTORIAL DE UN NUMERO NEGATIVO\n\n");
        else
            printf("\nEl factorial de %.2f es: %.2f\n\n", operandosAux[1], resultados[5]);
        }
    system("pause");
}

/**
 * @brief Ingresa operandos
 *
 * @param opcion Variable que sirve para decidir donde guardar el operando
 *
 * @return Devuelve el operando ingresado
 *
 */
float ingresoOperando(int opcion){
    float operando;
    if(opcion==1){
        printf("\nIngrese el 1er operando A: ");
        scanf("%f", &operando);
    }
    else{
        printf("\nIngrese el 2do operando B: ");
        scanf("%f", &operando);
    }
    return operando;
}

/**
 * @brief Suma operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a sumar
 * @param len Cantidad de numeros del array a sumar
 *
 * @return El resultado de la suma
 */
float suma(float operandos[], int len){
    float total=0;
    int i;
    for(i=0; i<len;i++){
        total=total+operandos[i];
    }
    return total;
}

/**
 * @brief Resta operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a restar
 * @param len Cantidad de numeros del array a restar
 *
 * @return El resultado de la diferencia
 */
float diferencia(float operandos[], int len){
    float total=operandos[0];
    int i;
    for(i=1; i<len;i++){
        total=total-operandos[i];
    }
    return total;
}

/**
 * @brief Multiplica operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a multiplicar
 * @param len Cantidad de numeros del array a multiplicar
 *
 * @return El resultado del producto
 */
float producto(float operandos[], int len){
    float total=operandos[0];
    int i;
    for(i=1; i<len;i++){
        total=total*operandos[i];
    }
    return total;
}
/**
 * @brief Divide operandos y devuelve el resultado
 *
 * @param operandos[] El array de numeros a dividir
 * @param banderasError[] array de banderas para notificar errores
 en las operaciones matematicas, en este caso, la division entre ceros
 *
 * @return El resultado de la division
 */
float cociente(float operandos[], int banderasError[]){
    float total;
    if(operandos[1]==0)
        banderasError[0]=1;
    else
        total=operandos[0]/operandos[1];
    return total;
}
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
float factorial(float operandos[], int banderasError[], int i){
    float operando=operandos[i];
    float total;
    if(operando<0){
        banderasError[1+i]=1;
    }
    else if(operando==1 || operando==0){
        total=1;
    }
    else{
        total=operando;
        while(operando>1){
            operando--;
            total=total*operando;
        }
    }
    return total;
}
