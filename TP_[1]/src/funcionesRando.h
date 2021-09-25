/*
 * funcionesRando.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Gaston
 */

#ifndef FUNCIONESRANDO_H_
#define FUNCIONESRANDO_H_

/**
 *
 * @param mensaje mensaje asignado en el main e impreso en el printf de la funcion
 * @brief se lee el valor int ingresado por el usuario y lo graba en una variable
 * @return devuelve al main el numero ingresado por el usuario
 */
int ingresarEntero( char mensaje[]);

/**
 *
 * @param flagNum1 bandera que controla el ingreso del primer operador
 * @param flagNum2 bandera que controla el ingreso del segundo operador
 * @param num1 trae el operador 1 de la funcion main
 * @param num2 trae el operador 2 de la funcion main
 * @brief la funcion imprime el menu y controla que se hayan ingresado los operadores para mostrarlos tambien en el menu,
 * luego devuelve al main la opcion seleccionada como un int
 * @return
 */
int menu(int flagNum1, int flagNum2,int num1,int num2);

/**
 *
 * @param num1 trae del main el primer operador
 * @param num2 trae del main el segundo operador
 * @brief se suman los operadores num1, num2
 * @return devuelve la suma
 */
int sumaNumeros(int num1, int num2);

/**
 *
 * @param num1 trae el operador 1 de la funcion main
 * @param num2 trae el operador 2 de la funcion main
 * @brief se restan los operadores num1, num2
 * @return devuelve el resultado de la resta
 */
int restaNumeros(int num1, int num2);

/**
 *
 * @param num1 trae el operador 1 de la funcion main
 * @param num2 trae el operador 2 de la funcion main
 * @param pResultadoDivision se guarda el valor del puntero en una direccion de memoria determinada
 * @brief la funcion analisa que el segundo operador sea distinto de 0. Si es igual a 0 el error es verdadero y no es falso
 * @return devuelve el valor de error para ser analizado en el main
 */
int divisionNumeros(int num1, int num2, float* pResultadoDivision);

/**
 *
 * @param num1 trae el operador 1 de la funcion main
 * @param num2 trae el operador 2 de la funcion main
 * @brief la funcion multiplica el num1 y num2
 * @return devuelve el resultado de la aplicacion
 */
int multiplicarNumeros (int num1, int num2);

/**
 *
 * @param num recibe el valor de la variable que haya enviado desde el main
 * @brief la funcion analisa si el valor que trae es negativo (no posee factorial), 0 y 1 factorial =1 y
 * si es mayor a 1 itera el factorial en la misma funcion hasta que cumpla que sea igual a 1
 * @return devuelve el resultado del factorial
 */
long long int factorial (int num);


#endif /* FUNCIONESRANDO_H_ */
