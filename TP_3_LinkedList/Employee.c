#include "Employee.h"
#include "func.h"
#include <string.h>

Employee* employee_new(){
    Employee* employee=(Employee*)malloc(sizeof(Employee));
    pedirCadena(employee->nombre, 256,"Nombre");
    employee->id=pedirEntero("ID");
    employee->sueldo=pedirEntero("sueldo");
    employee->horasTrabajadas=pedirEntero("horas trabajadas");
    return employee;
}

int employee_setId(Employee* this,int id){
    int retorno=-1;
    if(this!=NULL && id>0){
        this->id=id;
        retorno=1;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id){
    int retorno=-1;
    if(this!=NULL && id>0){
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
    int retorno=-1;
    if(this!=NULL && nombre!=NULL){
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
    int retorno=-1;
    if(this!=NULL && nombre!=NULL){
        nombre=this->nombre;
        retorno=1;
    }
    return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>0){
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
    int retorno=-1;
    if(this!=NULL && sueldo>0){
        this->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int retorno=-1;
    if(this!=NULL && sueldo>0){
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_compareByName(Employee* empleado1, Employee* empleado2){
    return stricmp(empleado1->nombre,empleado2->nombre);
}

int employee_compareById(Employee* empleado1, Employee* empleado2){
    int retorno;
    if(empleado1->id>empleado2->id){
        retorno= 1;
    }
    else if(empleado1->id<empleado2->id){
        retorno= -1;
    }
    else{
        retorno= 0;
    }
    return retorno;
}

int employee_compareBySueldo(Employee* empleado1, Employee* empleado2){
    int retorno;
    if( empleado1->sueldo>empleado2->sueldo){
        retorno= 1;
    }
    else if(empleado1->sueldo<empleado2->sueldo){
        retorno= -1;
    }
    else{
        retorno= 0;
    }
    return retorno;
}

int employee_compareByHorasTrabajadas(Employee* empleado1, Employee* empleado2){
    int retorno;
    if(empleado1->horasTrabajadas>empleado2->horasTrabajadas){
        retorno= 1;
    }
    else if(empleado1->horasTrabajadas<empleado2->horasTrabajadas ){
        retorno= -1;
    }
    else{
        retorno= 0;
    }
    return retorno;
}
