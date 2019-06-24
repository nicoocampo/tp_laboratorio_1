#include <stdio.h>
#include <stdlib.h>
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_compareByName(Employee* empleado1, Employee* empleado2);
int employee_compareById(Employee* empleado1, Employee* empleado2);
int employee_compareBySueldo(Employee* empleado1, Employee* empleado2);
int employee_compareByHorasTrabajadas(Employee* empleado1, Employee* empleado2);
#endif // employee_H_INCLUDED
