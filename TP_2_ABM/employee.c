#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "employee.h"
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
    opcion=pedirEntero("Elija una opcion valida", 5, 1);
    return opcion;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len){
    int i, retorno=0;
    if(len<0)
        retorno=-1;
    for(i=0;i<len;i++)
        list[i].isEmpty=1;
    return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee list[], int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int retorno=-1, i;
    i=findEmpty(list,len);
    if(len>0 || i>0){
        retorno=0;
        list[i].id=id;
        strcpy(list[i].name,name);
        strcpy(list[i].lastName,lastName);
        list[i].salary=salary;
        list[i].sector=sector;
        list[i].isEmpty=0;
    }
    return retorno;
}
/** \brief encuentra una estructura vacia y retorna la posicion
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int findEmpty(Employee list[], int len){
    int i, retorno=-1;
    for(i=0;i<len;i++){
        if(list[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len, int id){
    int retorno=-1;
    system("cls");
    int aux;
    aux=findEmployeeById(list, len, id);
    if(aux!=-1){
        list[aux].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len, int id){
    int retorno=-1, i;
    if(len>0){
        for(i=0;i<len;i++){
            if(list[i].id==id){
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployee(Employee list[], Sector sectores[], int len, int ts){
    system("cls");
    int i, retorno=-1;
    if(len>0 && ts>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty==0){
                printf("Nombre: %s", list[i].name);
                printf("\nApellido: %s", list[i].lastName);
                printf("\nSueldo: %.2f", list[i].salary);
                printf("\nID: %d", list[i].id);
                printf("\nSector: %s\n\n", sectores[list[i].sector].descripcion);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployee(Employee list[],int len, int order){
    int i, j, retorno=-1;
    Employee aux;
    if(len>0){
        if(order==0){
            for(i=0; i<len-1; i++){
                for(j=i+1; j<len; j++){
                    if(stricmp(list[i].lastName,list[j].lastName)>0){
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }
        }
        else{
            for(i=0; i<len-1; i++){
                for(j=i+1; j<len; j++){
                    if(stricmp(list[i].lastName,list[j].lastName)<0){
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief muestra en pantalla los salarios total, promedio y los que cobran mas que el promedio
 *
 * \param list Employee
 * \param length int
 *
 */
void salarios(Employee list[], int len){
    int i, flag=0;
    float total=0, promedio=0;
    for(i=0;i<len;i++){
        if(list[i].isEmpty==0){
            total=total+list[i].salary;
            flag++;
        }
    }
    system("cls");
    promedio=total/flag;
    printf("Total salarios: %.2f", total);
    printf("\n\nPromedio de los salarios: %.2f", promedio);
    printf("\n\nEmpleados que superan el promedio: \n");
    for(i=0;i<len;i++){
        if(list[i].isEmpty==0){
            if(list[i].salary>promedio){
                printf("Nombre: %s", list[i].name);
                printf("\nApellido: %s", list[i].lastName);
                printf("\nSueldo: %.2f", list[i].salary);
                printf("\nID: %d\n\n", list[i].id);
            }
        }
    }
    system("pause");
}

/** \brief muestra en pantalla el contenido de la estructura de empleados y sectores
 *
 * \param lista Employee
 * \param sectores Sector
 * \param tam int
 * \param id int
 * \param ts int
 *
 */
void mostrarEmpleado(Employee lista[], Sector sectores[], int tam, int id, int ts){
    printf("Nombre: %s", lista[id].name);
    printf("\nApellido: %s", lista[id].lastName);
    printf("\nSueldo: %.2f", lista[id].salary);
    printf("\nID: %d", lista[id].id);
    printf("\nSector: %s\n\n", sectores[lista[id].sector].descripcion);
}
/** \brief modifica los datos de una estructura
 *
 * \param lista Employee
 * \param sectores Sector
 * \param tam int
 * \param ts int
 *
 */
void modificarEmpleado(Employee lista[], Sector sectores[], int tam, int ts){
    int aux, aux2, i;
    system("cls");
    aux2=findEmployeeById(lista, tam, aux=pedirEntero("el ID del empleado a modificar", 9000,1));
    if(aux2==-1)
        printf("\nNo se encontro el ID solicitado\n");
    else{
        do{
            system("cls");
            i=menuModificacion(lista, sectores, tam, ts, aux2);
            switch(i){
                case 1:
                    cadenaSoloLetras("nombre a modificar",lista[aux2].name,32);
                    break;
                case 2:
                    cadenaSoloLetras("apellido a modificar",lista[aux2].lastName,32);
                    break;
                case 3:
                    lista[aux2].salary=pedirEntero("sueldo a modificar", 1000000, 1);
                    break;
                case 4:
                    lista[aux2].sector=pedirEntero("sector a modificar: 1- Contabilidad 2- Sistemas 3- RRHH", 3, 1);
                    break;
                case 5:
                    break;
            }
        }while(i!=5);
    }
}

int menuModificacion(Employee lista[],Sector sectores[], int tam, int ts, int aux){
    int opcion;
    mostrarEmpleado(lista,sectores,tam,aux, ts);
    printf("\n\n1 - Modificar Nombre\n2 - Modificar Apellido\n3 - Modificar sueldo\n4 - Modificar sector\n5 - Salir\n\nOpcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int hardcodearDatosEmpleados(Employee list[], int len){
    int i;
    int id[]={1,8,9,7,2,4};
    int sector[]={2,1,3,1,2,3};
    float salary[]={100,10000,30,2,3000,99900};
    int isEmpty[]={0,0,0,0,0,0};
    char name[][50]={"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char lastName[][50]={"aaaaa","lllll","cccccc","zzzzzzz","ffffff","yyyyyy"};
    for(i=0; i<len; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].salary= salary[i];
        list[i].isEmpty = isEmpty[i];
        list[i].sector = sector[i];

    }
    return 1;
}
