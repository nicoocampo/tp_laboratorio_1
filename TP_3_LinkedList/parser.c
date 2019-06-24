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
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    char name[120], id[120], salary[120],hour[120];
    if(pFile == NULL){
        return -1;
    }
        system("cls");
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id ,name ,hour, salary);
        while(!feof(pFile))
        {
            empleado=(Employee*)malloc(sizeof(Employee));
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id ,name ,hour, salary);
            employee_setId(empleado,atoi(id));
            employee_setNombre(empleado,name);
            employee_setHorasTrabajadas(empleado,atoi(hour));
            employee_setSueldo(empleado, atoi(salary));
            ll_add(pArrayListEmployee, empleado);

        }
        return 1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    Employee* empleado;
    int verificacion = -1;
    if(pFile != NULL && pArrayListEmployee != NULL){
        verificacion = 0;
        while(!(feof(pFile))){
            empleado=(Employee*)malloc(sizeof(Employee));
            if(fread(empleado, sizeof(Employee), 1, pFile)==1)
                ll_add(pArrayListEmployee, empleado);
            else
                break;
        }
    }
    return verificacion;
}
