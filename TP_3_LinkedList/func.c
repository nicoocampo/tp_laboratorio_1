#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

/** \brief muestra en pantalla un menu de opciones
 *
 * \param mensaje char[]
 *
 * \return opcion int
 *
 */
int menu(char mensaje[]){
    int opcion;
    system("cls");
    printf("%s", mensaje);
    opcion=pedirEntero("\n\nElija una opcion valida");
    return opcion;
}

int pedirEntero(char mensaje[]){
    int retorno, flag=1, i;
    char str[40];
    do{
        flag=1;
        printf("%s: ", mensaje);
        fflush(stdin);
        scanf("%s", str);
        for(i=0;i<40;i++){
            if(str[i]=='\0')
                break;
            if(str[i]<'0' || str[i]>'9'){
                flag=0;
                break;
            }
        }
    retorno=atoi(str);
    }while(flag==0);
    return retorno;
}

int pedirCadena(char* pCadena,int len, char mensaje[]){
    char auxCadena[256];
    int retorno=-1;
    if(pCadena!=NULL && len>0){
        do{
            retorno=1;
            fflush(stdin);
            printf("Ingrese %s: ", mensaje);
            gets(auxCadena);
            if(strlen(auxCadena)>len){
                printf("ERROR: DEMASIADOS CARACTERES INGRESADOS\n");
                retorno=0;
            }
        }while(retorno==0);
        strcpy(pCadena, auxCadena);
    }
    return retorno;
}
