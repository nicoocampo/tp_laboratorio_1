#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "func.h"


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
                printf("\nNombre: %s\nID: %d\nHoras trabajadas: %d\nSueldo: %d\n", aux->nombre, aux->id, aux->horasTrabajadas, aux->sueldo);
                opcion=menu("\nMenu de opciones:\n1-Cambiar nombre\n2-Cambiar ID\n3- Cambiar horas trabajadas \n4- Cambiar sueldo\n5-Salir");
                switch(opcion){
                    case 1:

                        break;
                    case 2:

                        break;
                    case 3:

                        break;
                    case 4:

                        break;
                    case 5:

                        break;
                    default:

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
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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

