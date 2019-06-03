#include "Employee.h"
#include "func.h"

Employee* employee_new(){
    char nombre[256];
    Employee* employee=(Employee*)malloc(sizeof(Employee));
    employee->id=pedirEntero("ID");
    employee->sueldo=pedirEntero("sueldo");
    employee->horasTrabajadas=pedirEntero("horas trabajadas");
    pedirCadena(employee->nombre, 256,"Nombre");

    return employee;
}

int employee_setId(Employee* this,int id){

    return 0;
}
int employee_getId(Employee* this,int* id){


    return 0;
}

int employee_setNombre(Employee* this,char* nombre){


    return 0;
}

int employee_getNombre(Employee* this,char* nombre){


    return 0;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){


    return 0;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){


    return 0;
}

int employee_setSueldo(Employee* this,int sueldo){


    return 0;
}

int employee_getSueldo(Employee* this,int* sueldo){


    return 0;
}
