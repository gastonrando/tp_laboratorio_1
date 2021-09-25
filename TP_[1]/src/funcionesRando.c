/*
 * funcionesRando.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Gaston
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesRando.h"

int ingresarEntero( char mensaje[]){
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

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

int sumaNumeros(int num1, int num2){

	int resultadoSuma;

    resultadoSuma=num1+num2;

    return resultadoSuma;
}

int restaNumeros(int num1, int num2){

	int resultadoResta;

	resultadoResta=num1-num2;

	return resultadoResta;
}

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

int multiplicarNumeros (int num1, int num2){

	int resultadoMultiplicar;

    resultadoMultiplicar=num1*num2;

    return resultadoMultiplicar;

}

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



