/*
 * ArrayEmployees.h
 *
 *
 *      Author: Gaston
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define QTY_EMPLOYEES 1000
#define CHAR_LEN 51

/**
 * @struct
 * @brief define estructura del array
 *
 */
typedef struct{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

} Employee;
/**
 * @fn int menu()
 * @brief presenta menu para operar en el abm
 *
 * @return
 */
int menu();
/**
 * @fn int initEmployees(Employee*, int)
 * @brief inicializa los espacios en memoria segun la cantidad pre establecida
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de array
 * @return
 */
int initEmployees(Employee* list, int len); //inicializa los espacion en memoria
/**
 * @fn int searchFree(Employee[], int)
 * @brief busca espacio en memoria asignado pero no utilizado para guardar datos de alta
 *
 * @param lista envia tamaño del array
 * @param len envia cantidad de arrays
 * @return
 */
int searchFree(Employee list[], int len);
/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief funcion utilizada para dar de alta un empleado, solicita todos los datos al usuario.
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @param id valor autogenerado que se usara como valor unico del empleado
 * @param name nombre del empleado
 * @param lastName apellido del empleado
 * @param salary sueldo del empleado
 * @param sector sector de trabajo del empleado
 * @return
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief busca empleado por numero de id
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @param id envia numero ingresado por el usuario de id
 * @return
 */
int findEmployeeById(Employee* list, int len,int id);
/**
 * @fn int modifyEmployee(Employee[], int)
 * @brief  modifica el empleado buscado por id
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @return
 */
int modifyEmployee(Employee list[], int len);
/**
 * @fn int menuModifyEmployee()
 * @brief muestra el menu para la modifacion de empleado
 *
 * @return
 */
int menuModifyEmployee();
/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief  funcion para borrar un empleado, se le otorga valor is empty verdadero para no considerarlo mas adelante
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @param id envia la id del empleado
 * @return
 */
int removeEmployee(Employee* list, int len, int id);
/**
 * @fn int showEmployees(Employee[], int)
 * @brief hace print en pantalla de los datos de los empleados dados de alta
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @return
 */
int showEmployees(Employee list[], int len);
/**
 * @fn void showEmployee(Employee)
 * @brief  invoca a la funcion para mostrar el listado de los empleados dados de alta
 *
 * @param x
 */
void showEmployee (Employee x);
/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief ordena a los empleados segun apellido de manera descendente o ascendente
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @param order
 * @return
 */
int sortEmployees(Employee* list, int len, int order);
/**
 * @fn int inform(Employee*, int)
 * @brief  invoca menu para informar al usuario de los empleados, ya sea listado o total de sueldos, promedios y cantidad por encima de la media
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @return
 */
int inform(Employee* list, int len);
/**
 * @fn int sortEmployeesTwo(Employee*, int)
 * @brief ordena segun el apellido de manera ascendente o descendete a los empleados
 *
 * @param list envia tamaño del array
 * @param len envia cantidad de arrays
 * @return
 */
int sortEmployeesTwo(Employee* list, int len);
/**
 * @fn int menuSortEmployees()
 * @brief menu para el ordenamiento de empleados
 *
 * @return
 */
int menuSortEmployees();
/**
 * @fn int resetFlag(Employee*, int, int*)
 * @brief reinicia las banderas para que no se pueda elegir ninguna otra opcion mas alla de alta de empleados sin haber cargado 1 por lo menos.
 *
 * @param list
 * @param len
 * @param flag
 * @return
 */
int resetFlag(Employee* list, int len, int* flag);


#endif /* ARRAYEMPLOYEES_H_ */
