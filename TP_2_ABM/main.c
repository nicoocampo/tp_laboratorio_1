#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
int idAuto=0;
int main()
{
    char aux[100], aux2[100];
    Employee list[1000];
    Sector sectores[]={{},{1,"Contabilidad"},{2,"Sistemas"},{3,"RRHH"}};
    initEmployees(list, 1000);
    int flag=0;
    flag=hardcodearDatosEmpleados(list,6);
    int opcion;
    do{
        system("cls");
        switch(opcion=menu("1 - Alta\n2 - Baja\n3 - Modificacion\n4 - Informar\n5 - Salir\n\n")){
            case 1:
                idAuto++;
                cadenaSoloLetras("nombre", aux, 100);
                cadenaSoloLetras("apellido",aux2, 100);
                if(addEmployee(list,1000,idAuto,aux,aux2,pedirFlotante("Ingrese salario"),pedirEntero("Ingrese Sector: 1 - Contabilidad 2 - Sistema 3 - RRHH", 3 , 1))==-1)
                    printf("\nNo existe mas espacio en memoria\n");
                system("pause");
                flag=1;
                break;
            case 2:
                if(flag==0){
                    printf("\nIngresar algun empleado\n");
                    break;
                }
                if(removeEmployee(list, 1000, pedirEntero("Ingrese el legajo del empleado a dar de baja", 9000,1))==0)
                    printf("\nBaja confirmada con exito!\n");
                else
                    printf("\nNo se encontro el empleado solicitado\n");
                system("pause");
                break;
            case 3:
                if(flag==0){
                    printf("\nIngresar algun empleado\n");
                    break;
                }
                modificarEmpleado(list, sectores, 1000, 4);
                system("pause");
                break;
            case 4:
                if(flag==0){
                    printf("\nIngresar algun empleado\n");
                    break;
                }
                switch(opcion=menu("1- Mostrar los empleados ordenados de menor a mayor\n2- Mostrar los empleados ordenados de mayor a menor\n3- Mostrar el total de los salarios y promedio\n\n")){
                    case 1:
                        sortEmployee(list,1000,0);
                        printEmployee(list,sectores,1000,3);
                        system("pause");
                        break;
                    case 2:
                        sortEmployee(list,1000,1);
                        printEmployee(list,sectores,1000,3);
                        system("pause");
                        break;
                    case 3:
                        salarios(list, 1000);
                        break;
                }
                break;
            case 5:
                break;
            default:
                printf("\n\nOpcion invalida\n\n");
                system("pause");
            }
    }while(opcion!=5);
    return 0;
}
