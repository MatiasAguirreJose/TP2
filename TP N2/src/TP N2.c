/*
 ============================================================================
 Name        : TP.c
 Author      : matias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Matias Aguirre 43921121
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ArrayEmployees.h"
#define tam 1000
#define TRUE 0
#define FALSE 1

int main(void) {
	setbuf(stdout, NULL);
	int id = 0;
	char  name[51];
	char lastName[51];
	float salary;
	int sector;
	int verificador;


	Employee Lista[tam];
	InicializarClientes(Lista,  tam);

 int Opcion;
 ElijaOpcion();
do{

scanf("%d",&Opcion);

switch (Opcion) {


	case 1:
		id++;
		do{
			verificador = GetString("Ingrese su Nombre", "Escribalo Bien", name, 51);
		}while(verificador==-1);

		do{
			verificador = GetString("Ingrese su Apellido","Escribalo Bien", lastName, 51);
		}while(verificador==-1);

		getNumeroFloat(&salary, "Ingrese su Salario");
		getNumero(&sector, "Ingrese su Sector");


		if(addEmployee(Lista, tam, id,  name, lastName, salary, sector) == TRUE ){
			puts(" \n *se agrego correctamente* \n ");
		}else{
			puts("¡¡NOO se agrego correctamente");
		}
		 ElijaOpcion();
		break;

	case 2:


		findEmployeeById(Lista,tam, id);


		 ElijaOpcion();
		break;

	case 3:


		removeEmployee(Lista,tam, id);
		 ElijaOpcion();


		break;
	case 4:

		puts("ID           NOMBRE        APELLIDO           SALARIO         SECTOR");
		sortEmployees(Lista,tam, 1);
		printEmployees(Lista, tam);

		 Promedio(Lista,tam, id);
		break;




}
if(Opcion < 1 || Opcion > 5){
puts("ERROR INGRESE CORRECTAMENTE");
}

}while(id<tam);

printf("Usted Ya relleno los %d tamaños",tam);
	return EXIT_SUCCESS;
}
