/*
 * funcionesRando.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Gaston
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesRando.h"

/// @param mensaje mensaje asignado en el main e impreso en el printf de la funcion
///se lee el valor int ingresado por el usuario
/// @return devuelve al main el numero ingresado por el usuario
int ingresarEntero( char mensaje[]){
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}


/// @param flagNum1 trae del main la bandera de la carga del primer operador
/// @param flagNum2 trae del main la bandera de la carga del segundo operador
/// @param num1 trae el operador para exponer como x
/// @param num2 trae el operador para exponer como y
/// imprime las opciones que el usuario puede ingresar
/// el usuario no puede ingresar la opcion 3 sin haber ingresado la 1 y la 2
/// tampoco puede ingresar la 4 sin haber realizado la 3 y/o 1 y 2
/// @return devuelve la opcion seleccionada
int menu(int flagNum1, int flagNum2,int num1, int num2){

    int opcion;

    system("cls");


    printf("Menu de opciones\n\n");
    printf("1. Ingresar 1er operador: ");
    if(flagNum1==1){
        printf("X = %d\n",num1);
    }
    else{
        printf("\n");
    }
    printf("2. Ingresar 2do operador: ");
    if(flagNum2==1){
        printf("Y = %d\n",num2);
    }
    else{
        printf("\n");
    }
    printf("3. Calcular todas las operaciones: \n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    printf("\nIndique opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

   return opcion;
}


/*int ingresoNum(){
    int num;

    printf("Ingrese un operador \n");
    scanf("%d", &num);

    return num;
}*/

/// @param num1 trae del main el primer operador
/// @param num2 trae del main el segundo operador
/// se suman los operadores
/// @return devuelve la suma
int sumaNumeros(int num1, int num2){

	int resultadoSuma;

    resultadoSuma=num1+num2;

    return resultadoSuma;
}

/// @param num1 trae del main el primer operador
/// @param num2 trae del main el segundo operador
/// realiza la resta
/// @return devuelve el resultado
int restaNumeros(int num1, int num2){

	int resultadoResta;

	resultadoResta=num1-num2;

	return resultadoResta;
}

/// @param num1 trae del main el primer operador
/// @param num2 trae del main el segundo operador
/// si el segundo operador es = 0 se registra que existe error = 1
/// caso contrario no hay error y se calcula la division
/// @param pResultadoDivision se guarda el valor de la variable puntero la cual tendra el resultado
/// @return se devuelve si hay error, si es posible realizar la division
int divisionNumeros(int num1, int num2, float* pResultadoDivision){

    int error;

    if(num2==0){
        error=1;
    }
    else{
        error=0;
        *pResultadoDivision =(float) num1 / num2;
    }
    return error;
}

/// @param num1 trae del main el primer operador
/// @param num2 trae del main el segundo operador
/// se realiza la multiplicacion
/// @return devuelve el resultado de la multiplicacion
int multiplicarNumeros (int num1, int num2){

	int resultadoMultiplicar;

    resultadoMultiplicar=num1*num2;

    return resultadoMultiplicar;

}

/// @param num trae el operador sobre el cual se calculara el factorial
/// la funcion es iterativa, si num es 1 o 0 devolvera 1, si es negativo devolvera 0 implicando falsedad y que no tiene factorial
/// si es mayor a 1 la funcion iterara hasta que el numero sea igual a 1 y terminara la iteracion
/// @return
long long int factorial (int num){

    int retorno;
    retorno=1;

    if(num<0){
        retorno = 0;
    }
    else{
        if (num>1){
            retorno = num*factorial(num-1);
        }
        else{
            retorno = 1;
        }
    }
    return retorno;
}



