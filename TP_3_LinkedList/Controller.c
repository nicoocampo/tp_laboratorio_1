#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "func.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArch;
    pArch=fopen("data.csv","r");
    parser_EmployeeFromText(pArch,pArrayListEmployee);
    fclose(pArch);
    system("cls");
    printf("Cargado exitosamente!\n\n");
    system("pause");
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArch;
    pArch=fopen("data.csv","rb");
    parser_EmployeeFromBinary(pArch,pArrayListEmployee);
    fclose(pArch);
    system("cls");
    printf("Cargado exitosamente!\n\n");
    system("pause");
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=1;
    if(pArrayListEmployee!=NULL){
        ll_add(pArrayListEmployee,employee_new());
        retorno=1;
    }
    return retorno;;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee==NULL)
        return 0;
    Employee* aux;
    int i, id, opcion;
    id=pedirEntero("ID del trabajador a modificar");
    for (i=0;i<ll_len(pArrayListEmployee);i++){
        aux=ll_get(pArrayListEmployee, i);
        if(aux->id==id){
            do{
                system("cls");
                printf("Nombre: %s\nID: %d\nHoras trabajadas: %d\nSueldo: %d\n", aux->nombre, aux->id, aux->horasTrabajadas, aux->sueldo);
                opcion=menu("\n\nMenu de opciones:\n1-Cambiar nombre\n2-Cambiar ID\n3- Cambiar horas trabajadas \n4- Cambiar sueldo\n5-Salir");
                switch(opcion){
                    case 1:
                        pedirCadena(aux->nombre,256,"el nuevo nombre del empleado");
                        break;
                    case 2:
                        aux->id=pedirEntero("el nuevo ID");
                        break;
                    case 3:
                        aux->horasTrabajadas=pedirEntero("las nuevas horas trabajadas");
                        break;
                    case 4:
                        aux->sueldo=pedirEntero("el nuevo sueldo");
                        break;
                    case 5:
                        break;
                    default:
                        system("cls");
                        printf("Ingrese una opcion valida\n\n");
                        system("pause");
                        break;
                }
            }while(opcion!=5);
        }
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int opcion=0;
    if(pArrayListEmployee==NULL)
        return 0;
    Employee* aux;
    int i, id;
    id=pedirEntero("ID del trabajador a dar de baja");
    for (i=0;i<ll_len(pArrayListEmployee);i++){
        aux=ll_get(pArrayListEmployee, i);
        if(aux->id==id){
            do{
                system("cls");
                printf("ID: %d\nNombre: %s\nSueldo: %d\nHoras trabajadas: %d\n\n", aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
                opcion=menu("1-. Borrar empleado\n2-. Cancelar");
            }while(opcion<1 || opcion>2);
            if(opcion==1){
                ll_remove(pArrayListEmployee, i);
                printf("\n\nEliminado exitosamente!\n\n");
                break;
            }
            else{
                printf("\n\nCancelado!\n");
                break;
            }
        }
    }
    system("pause");
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee==NULL)
        return 0;
    Employee* aux;
    int i;
    for (i=0;i<ll_len(pArrayListEmployee);i++){
        aux=ll_get(pArrayListEmployee, i);
        printf("\nNombre: %s\nID: %d\nHoras trabajadas: %d\nSueldo: %d\n", aux->nombre, aux->id, aux->horasTrabajadas, aux->sueldo);
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    int opcion;
    if(pArrayListEmployee != NULL){
            switch(opcion=menu("1-. Ordenar por ID\n2-. Ordenar por nombre\n3-. Ordenar por sueldo\n4-. Ordenar por horas trabajadas\n")){
                case 1:
                    ll_sort(pArrayListEmployee, employee_compareById, 1);
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, employee_compareByName, 1);
                    break;
                case 3:
                    ll_sort(pArrayListEmployee, employee_compareBySueldo, 1 );
                    break;
                case 4:
                    ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 1 );
            }
            printf("\n\nOrdenado exitosamente!");
            system("pause");
            estado= 0;
    }
    return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

