#include <stdio.h>
#include <stdlib.h>

int menu(float numeros[], int banderas[]);
float ingresoOperando(int opcion);
float suma(float operandos[], int len);
float diferencia(float operandos[], int len);
float producto(float operandos[], int len);
float cociente(float operandos[], int banderasError[]);
float factorial(float operandos[], int banderasError[], int i);
void calcularOperaciones(float operandos[], float resultados[], float operandosAux[], int banderas[], int banderasError[]);

int main()
{
    float operandos[2], operandosAux[2], resultados[6];
    int banderas[2]={0}, banderasError[3]={0};
    char seguir;
    do{
        switch(menu(operandos,banderas)){
            case 1:
                operandos[0]=ingresoOperando(1);
                banderas[0]=1;
                break;
            case 2:
                operandos[1]=ingresoOperando(2);
                banderas[1]=1;
                break;
            case 3:
                calcularOperaciones(operandos,resultados, operandosAux, banderas, banderasError);
                break;
            case 4:
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
                system("pause");
                break;
            case 5:
                seguir='n';
                break;
        }

    }while (seguir!='n');
    return 0;
}

int menu(float numeros[], int banderas[]){
    int opcion;
    system("cls");
    do{
    if(banderas[0]==0)
        printf("1 - Ingresar 1er operando (A=x)");
    else
        printf("1 - Ingresar 1er operando (A=%.2f)", numeros[0]);
    if(banderas[1]==0)
        printf("\n2 - Ingresar 2do operando (B=y)");
    else
        printf("\n2 - Ingresar 2do operando (B=%.2f)", numeros[1]);
    printf("\n3 - Calcular todas las operaciones");
    printf("\n4 - Informar resultados");
    printf("\n\n5 - Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);
    }while (opcion<0 || opcion>5);
    return opcion;
}

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
    printf("\n\nSE REALIZARON LAS OPERACIONES CON EXITO!\n");
    }
    system("pause");
}

/**
 * @brief Suma 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a sumar
 * @param segundoOperando El segundo numero a sumar
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
 * @brief Resta 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a restar
 * @param segundoOperando El segundo numero a restar
 * @return El resultado de la resta
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
 * @brief Multiplica 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a multiplicar
 * @param segundoOperando El segundo numero a multiplicar
 * @return El resultado de la suma
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
 * @brief Divide 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a sumar
 * @param segundoOperando El segundo numero a sumar
 * @param mensaje Mensaje mostrado en pantalla con el resultado
 * @param mensajeError Mensaje mostrado en pantalla al dividir por cer0
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
 * @brief Hace el factorial del numero ingresado
 * @param operando El numero a sacar el factorial
 * @param mensaje Mensaje mostrado en pantalla con el resultado
 * @param mensajeError Mensaje mostrado en pantalla al ingresar un valor negativo
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
