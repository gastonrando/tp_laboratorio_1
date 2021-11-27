/*
 * ArrayEmployees.c
 *
 *
 *      Author: Gaston
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <ctype.h>
#include <string.h>
#include "miBiblioteca.h"
#define QTY_EMPLOYEES 1000
#define CHAR_LEN 51

int menu(){

	int option;

	system("cls");
	printf("---------------------------------------------\n");
	printf("                  ABM PERSONA      \n");
	printf("---------------------------------------------\n");

	printf(" 1. ALTA\n");
	printf(" 2. MODIFICAR\n");
	printf(" 3. BAJA\n");
	printf(" 4. INFORMAR\n");
	printf(" 5. SALIR\n\n");

	printf("INGRESE UNA OPCION: ");
	scanf("%d", &option);


	return option;
}


int initEmployees(Employee* list, int len)
{
	int todoOk = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			list[i].isEmpty = 1;
		}
		todoOk= 0;
	}


	return todoOk;
}

int searchFree(Employee list[], int len){
	int index = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){

		   if(list[i].isEmpty){
			   index = i;
				break;
			}
		}
	}
	return index;
}

int addEmployee(Employee* list, int len, int* id){

	    int todoOk = -1;
	    int index;

	    char name[51];
	    char lastName[51];
	    float salary;
	    int sector;


	    //Employee auxEmployee;


	    if (list != NULL && len > 0)
	    {

	        system("cls");
	        puts("**ALTA EMPLEADO**\n\n");
	        index = searchFree(list, len);


	        if(index == -1)
	        {
	            printf("No hay mas lugar \n");
	        }
	        else
	        {


	        	list[index].id= *id;
	        	(*id)++;

	        	do{

	        	printf("Ingrese nombre: ");
	            fflush(stdin);
	            gets(name);
	        	} while(validarCadena(name));
	        	puts("---------------------------------------");
	        	strcpy(list[index].name,name);

	        	do{
	        	printf("Ingrese apellido: ");
	            fflush(stdin);
	            gets(lastName);
	        	}while(validarCadena(lastName));
	            strcpy(list[index].lastName,lastName);
	            puts("---------------------------------------");


	            do{
	            printf("Ingrese Salario: ");

	            }while(getFloat(&salary)==-1);
	        	list[index].salary = salary;
	            puts("---------------------------------------");


	            utn_getInt(&sector, "Ingrese el sector: ", "Error, ");
	            list[index].sector = sector;
	            puts("---------------------------------------");

	            list[index].isEmpty = 0;


	        }
	        todoOk = 0;
	    }
	    return todoOk;
	}

int findEmployeeById(Employee* list, int len,int id){

	int idFound = -1;
	if(list != NULL && len > 0){
		for(int i=0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].id == id){
				idFound = i;
			}
		}
	}
	return idFound;
}

int modifyEmployee(Employee list[], int len){

	int todoOk = -1;
	int id;
	int index;
	char confirm;
	char subConfirm ='s';
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;

	if(list != NULL && len > 0){

		printf("--------------------------------------------------------------\n");
		printf("                        MODIFICAR EMPLEADO                       \n");
		printf("--------------------------------------------------------------\n\n");

		showEmployees(list, len);
		utn_getInt(&id, "Ingrese ID numerico: ", "Error, ");
		index = findEmployeeById(list, len, id);

		if(index == -1){

			printf("\n no existe una persona con id %d ", id);

		}
		else{
			showEmployee(list[index]);
			printf("Desdea modificar al empleado? s/n: ");
			fflush(stdin);
			scanf("%c", &confirm);

			while(validateChar(confirm, 's', 'n')==-1){

					printf("Opcion incorrecta...Reintentelo nuevamente: ");
					fflush(stdin);
					scanf("%c", &confirm);
				}



			if(confirm == 's'){
				do{
				switch(menuModifyEmployee()){

					 case 1:

						 do{
							 printf("ingrese nuevo nombre: ");
						 	 fflush(stdin);
						 	 gets(auxName);
						 	 } while(validarCadena(auxName));
						 	 puts("---------------------------------------");
						 	 strcpy(list[index].name,auxName);
						 break;
					 case 2:
						 do{
							 printf("ingrese nuevo apellido: ");
						 	 fflush(stdin);
						 	 gets(auxLastName);
						 }while(validarCadena(auxLastName));
						 strcpy(list[index].lastName, auxLastName);
						 break;
					 case 3:
						 do{
							 printf("ingrese nuevo salario: ");
						 }while(getFloat(&auxSalary)==-1);
						 list[index].salary = auxSalary;
						 break;
					 case 4:
						 utn_getInt(&auxSector, "ingrese nuevo sector: ", "Error, ");
						 list[index].sector = auxSector;
						 //fflush(stdin);
						 list[index].sector = auxSector;
						 break;
					 case 5:
						 subConfirm = 'n';
						 break;


					 default:
						 printf("opcion invalida\n");
						 break;
					}
				}while(subConfirm == 's');
			}

		else{
			printf("se ha cancelado la modificacion\n");
		}
			todoOk = 0;
		}
	}
	return todoOk;
}

int removeEmployee(Employee* list, int len){
	int todoOk = -1;
	int index;
	int id;
	char confirm;

	if(list != NULL && len > 0){

		printf("--------------------------------------------------------------\n");
		printf("                        BAJA EMPLEADOS                       \n");
		printf("--------------------------------------------------------------\n\n");

		showEmployees(list, len);
		utn_getInt(&id, "Ingrese el ID del empleado que desea dar de baja: \n, ", "Error, ");
		index = findEmployeeById(list, len, id);

		if(index == -1){
			printf("No se encontro empleado con ID: %d... Reintentelo nuevamente.\n", id);
		}
		else
		{

			printf("¿Desea confirmar la baja de empleado? (s/n)");
			fflush(stdin);
			scanf("%c", &confirm);
			while(validateChar(confirm, 's', 'n')==-1){
				printf("Opcion incorrecta...Reintentelo nuevamente (s/n): ");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			//printf("¿Desea confirmar la baja de empleado? (s/n)");
			//fflush(stdin);
			//scanf("%c", &confirm);

			if(confirm == 's'){
				list[index].isEmpty = 1;
				todoOk = 0;
			}
			else
			{
				printf("\nSe ha cancela la baja de empleado...\n");
			}
		}

	}

	return todoOk;
}

int menuModifyEmployee(){

	int option;


	system("cls");

	printf("---------------------------------------------------\n");
	printf("                Menu modificacion    \n");
	printf("---------------------------------------------------\n");

	printf("   1. NOMBRE\n");
	printf("   2. APELLIDO\n");
	printf("   3. SALARIO\n");
	printf("   4. SECTOR\n");
	printf("   5. SALIR\n");

	printf("ingrese opcion:  ");
	scanf("%d", &option);


	return option;
}

int inform(Employee* list, int len){
	int todoOk = -1;
	int orden;

	if(list != NULL && len > 0)
	{
		switch(menuSortEmployees()){
		case 1:
			printf("\nQuiere ordenar de forma ascendente(1) o descendente(0)?: ");
			scanf("%d", &orden);
			while(orden != 0 && orden != 1)
			{
				printf("Opcion no valida ingrese si quiere ordenar de forma ascendente(1) o descendente(0)? : ");
				scanf("%d", &orden);
			}
			sortEmployees(list, len, orden);
			showEmployees(list, QTY_EMPLOYEES);
			break;

		case 2:
			sortEmployeesTwo(list, len);
			break;
		case 3:
			break;

		default:
			printf("Opcion invalida... Reintentelo nuevamente. ");
			break;
		}

		todoOk = 0;
	}

	return todoOk;
}

int menuSortEmployees()
{
	int option;

	printf("---------------------------------------------------------------\n");
	printf("                       MENU INFORMAR                    \n");
	printf("-----------------------------------------------------------------\n");

	printf("1. Ordenar alfabeticamente por apelliodo y sector. \n");
	printf("2. Ver total de salarios, promedio y cuantos empleados poseen un salario por encima del la media.\n");
	printf("3. Volver al menu principal\n\n");



	printf("Elija una opcion: ");
	scanf("%d", &option);


	return option;
}


int sortEmployeesTwo(Employee* list, int len){
	int todoOk = -1;
	float total = 0;
	int amount = 0;
	float average;
	int employeeAboveAvarage = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
			{
				total += list[i].salary;
				amount++;
			}
		}


		if(amount != 0)
		{
			average = total / amount;
		}

		for(int i = 0; i < len; i++)
		{
			if(list[i].salary > average && list[i].isEmpty == 0){
				employeeAboveAvarage++;
			}
		}

		printf("\n------------------------------------------------\n");
		printf("- Total de los salarios: $ %.2f \n", total);
		printf("- Promedio de los salarios: %.2f\n", average);
		printf("- Empleados que superan el salario promedio: %d \n", employeeAboveAvarage);
		printf("-------------------------------------------------\n\n");


		todoOk  = 0;
  }
	return todoOk;
}


int showEmployees(Employee list[], int len) {

    int todoOk=0;
    if(list !=NULL && len > 0){
        system("cls");
        printf("%36s\n", "** Lista de empleados **");
        printf("------------------------------------------------\n");
        printf(" ID    Nombre     Apellido   Sueldo     Sector \n");
        printf("------------------------------------------------\n");

        for(int i=0; i<len; i++){
        	if(list[i].isEmpty == 0){
        		showEmployee(list[i]);

        	}
        }
        todoOk=1;
    }
    return todoOk;
}

void showEmployee (Employee x){

printf("%.d   %-10s %-10s %-10.2f %d\n",
       x.id,
       x.name,
       x.lastName,
       x.salary,
       x.sector);
}


int sortEmployees(Employee* list, int len, int order){

	int todoOk=-1;
    Employee auxEmpleado;

    if(list !=NULL && len > 0)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j=i+1; j < len; j++)
            {
                if(order == 1){
                    if((strcmp(list[i].lastName, list[j].lastName)>0) ||
                       (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector)){
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
                else{
                    if((strcmp(list[i].lastName, list[j].lastName)<0) ||
                       (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector))   //condicion para ordenar de manera descendente
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
            }
        }


        todoOk=0;
    }
    return todoOk;
}

int resetFlag(Employee* list, int len, int* flag){
	int todoOk = -1;
	if(list != NULL && len > 0)	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				*flag = 0;
			}
			else
			{
				*flag = 1;
				break;
			}
		}
		todoOk = 0;
	}
	return todoOk;
}

