#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float operandos[2], operandosAux[2], resultados[6];
    int banderas[3]={0}, banderasError[3]={0};
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
                mostrarResultados(resultados, banderas, operandosAux, banderasError);
                break;
            case 5:
                seguir='n';
                break;
        }

    }while (seguir!='n');
    return 0;
}


