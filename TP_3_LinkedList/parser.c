#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee){
/*    int id, salary, hour, r, i;
    char name[120];
    if(pFile == NULL){
        return -1;
    }
    r = fscanf(pFile,"%d,%[^,],%d,%d\n",id ,name ,hour, salary);
    do{
        r = fscanf(pFile,"%d,%[^,],%d,%d\n",id ,name ,hour, salary);
        if(r==4){
            pArrayListEmployee->pFirstNode->pElement->id= id;
            strncpy(pArrayListEmployee[i].nombre,name);
            pArrayListEmployee[i].horasTrabajadas = hour;
            pArrayListEmployee[i].sueldo = salary;
            i++;
        }
        else
            break;
    }
    while(!feof(pFile) && i<len);*/
    return 1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    fread(pArrayListEmployee, sizeof(Employee),1,pFile);
    return 1;
}
