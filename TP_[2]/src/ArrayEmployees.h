/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Gaston
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define QTY_EMPLOYEES 1000
#define CHAR_LEN 51


typedef struct{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

} Employee;

int menu();
int initEmployees(Employee* list, int len); //inicializa los espacion en memoria
int searchFree(Employee lista[], int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len,int id);
int modifyEmployee(Employee list[], int len);
int menuModifyEmployee();
int removeEmployee(Employee* list, int len, int id);
int showEmployees(Employee list[], int len);
void showEmployee (Employee x);
int sortEmployees(Employee* list, int len, int order);
int inform(Employee* list, int len);
int sortEmployeesTwo(Employee* list, int len);
int menuSortEmployees();
int resetFlag(Employee* list, int len, int* flag);


#endif /* ARRAYEMPLOYEES_H_ */
