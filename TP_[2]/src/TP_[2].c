/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"


#define QTY_EMPLOYEES 1000
#define CHAR_LEN 51


int main(){

	setbuf(stdout, NULL);


	Employee list [QTY_EMPLOYEES];
	Employee unEmployee;
	initEmployees(list, QTY_EMPLOYEES);
	int nextId = 1;
	int flag = 0;
	char seguir = 's';
	system("cls");
	do{

		switch(menu()){ //opciones del tp

		case 1:
			if(addEmployee(list, QTY_EMPLOYEES, &nextId) == 0){
				printf("Alta exitosa\n");
				flag=1;

			}
			else
			{
				printf("hubo un problema al hacer el alta\n"); //SI DEVUELVE EL 0, HUBO ERROR
			}
			break;

		case 2:
			if	(flag == 0){
				printf("Debe tener un empleado de alta primero\n");
			}
			else{
				if(modifyEmployee(list, QTY_EMPLOYEES) == 0){
					printf("Listado actualizado!!! \n");
						}
						else
						{
							printf("hubo un problema la modificacion\n");
						}
			}
			break;
		case 3:
			if	(flag == 0){
							printf("Debe tener un empleado de alta primero\n");
						}
			else{
				if(removeEmployee(list, QTY_EMPLOYEES) == 0){
							printf("\nLa baja se ha realizado con exito!\n");

						}
						else
						{
							printf("Ocurrio un problema al realizar la baja....Reintentelo nuevamente.\n");
						}
			resetFlag(list, QTY_EMPLOYEES, &flag);
			}
				break;
		case 4:
			if	(flag == 0){
				printf("Debe tener un empleado de alta primero\n");
			}
			else{
			inform(list, QTY_EMPLOYEES);
			}
			break;

		case 5:
			seguir = 'n';
			break;
		default:
			printf("opcion invalida");
			break;

		}
		system("pause");
	}while(seguir == 's');
//addEmployees(&list); //funcion para agregar empleados

	return EXIT_SUCCESS;
}

