/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Rando Gaston
 Version     : 1.0.0
 Copyright   : Pendiente
 Description : Calculadora 2 variables
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesRando.h"

int main(){


	setbuf(stdout, NULL);
	puts("!!!Calculadora!!!\n"); /* prints !!!Calculadora!!! */
    int opcion, num1, num2, flagNum1=0,flagNum2=0, flagEcuaciones=0;
    int resultadoSuma, resultadoResta, errorDivision, resultadoMultiplicar;
    long long int factorialX, factorialY;
    float resultadoDivision;


    do {
        switch(menu(flagNum1,flagNum2,num1,num2)){

            case 1:
                flagNum1=1;
                num1=ingresarEntero("Ingrese el primer operador: \n");
            break;

            case 2:
                flagNum2=1;
                num2=ingresarEntero("Ingrese el segundo operador: \n");
            break;

            case 3:
                if(flagNum1==1 && flagNum2==1){
                    flagEcuaciones=1;
                    resultadoSuma = sumaNumeros(num1,num2);
                    resultadoResta = restaNumeros(num1,num2);
                    errorDivision = divisionNumeros(num1,num2, &resultadoDivision);
                    resultadoMultiplicar = multiplicarNumeros(num1,num2);
                    factorialX=factorial(num1);
                    factorialY=factorial(num2);
                }

                else{
                    printf("No ingreso todos los operadores\n");

                }
            break;

            case 4:

                if(flagNum1==1 && flagNum2==1){
                    if(flagEcuaciones==1){
                        printf("El resultado de %d + %d es: %d\n", num1, num2, resultadoSuma);
                        printf("El resultado de %d - %d es: %d\n", num1, num2, resultadoResta);

                        if(errorDivision){
							printf("No es posible dividir por cero\n");
						}
						else{
							printf("El resultado de %d / %d es: %.2f\n", num1, num2, resultadoDivision);
						}

                        printf("El resultado de %d * %d es: %d\n", num1, num2, resultadoMultiplicar);

                        if (factorialX){
							printf("El factorial de %d es: %lld, " ,num1 ,factorialX);
						}
                        else{
							printf("El operador %d no tiene factorial, ", num1);
						}
						if (factorialY){
							printf("El factorial de %d es: %lld\n" ,num2,factorialY);
						}
						else{
							printf("El operador %d no tiene factorial\n", num2);
						}


                    }
                    else{
                        printf("No realizo las operaciones matematicas!\n");

                    }
                }

				else{
					printf("No ingreso todos los operadores\n");
				}
            break;

            case 5:
                opcion=5;
            break;

            default:
                printf("Opcion Invalida\n");
            break;

        }

    system("pause");

    } while(opcion!=5);

    system("cls");
    printf("\n\n Hasta luego! :D\n\n");

	return EXIT_SUCCESS;
}
