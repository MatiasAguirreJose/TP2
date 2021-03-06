
#ifndef ARRAYEMPLOYEES_C_
#define ARRAYEMPLOYEES_C_
#endif /* ARRAYEMPLOYEES_C_ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "ArrayEmployees.h"

#define TRUE 0
#define FALSE 1
void Modificar(void){

		puts(" Que desea Modificar? \n");
		puts(" 1-Nombre");
		puts(" 2-Apellido ");
		puts(" 3-Salario");
		puts(" 4-Sector");

}


void ElijaOpcion(void){
	setbuf(stdout, NULL);

	puts("Elija una Opcion \n");
	puts(" 1- Dar de alta");;
	puts(" 2- Modificar Cliente");
	puts(" 3- Eliminar Cliente");
	puts(" 4- Ordenar Alfabeticamente");



}




int InicializarClientes(Employee* list,  int tam){


	int retorno;
	retorno = -1;

	if(list != NULL && tam>=0 ){
		for (int i = 0; i < tam; i++) {
			list[i].isEmpty = TRUE;



		}
		retorno = 0;
	}


	return retorno;

}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	setbuf(stdout, NULL);


	int retorno = -1;
	int i;

	for (i = 0; i < len; ++i) {
		if (list[i].isEmpty == TRUE){
		list[i].id=id;
		strcpy(list[i].name, name);
		strcpy(list[i].lastName, lastName);
		list[i].salary = salary;
		list[i].sector = sector;
		list[i].isEmpty = FALSE;
		retorno = TRUE;
		break;
		}

	}
 return retorno;
}

int printEmployees(Employee* list, int len){

	setbuf(stdout, NULL);
	int i;
	for (i = 0; i < len; ++i) {
		if(list[i].isEmpty==FALSE){

			printf(" %d ",list[i].id);
			printf(" %15s ",list[i].name);
			printf("%15s ",list[i].lastName);
			printf(" %15.2f ",list[i].salary);
			printf(" %10d \n",list[i].sector);



		}

	}
	return 0;
}

int findEmployeeById(Employee* list, int len,int id){
	setbuf(stdout, NULL);
	char name [51];
	char apellido[51];
	float salario;
	int sector;
	int verificador;
	int Opcion;
	if(list != NULL && len>=0){
	for (int i = 0; i < len; ++i) {

		getNumero(&id, "Ingrese el Id \n");
		if(list[i].id==id){

			printf("Usted Elijio el ID %d \n",list[i].id);
			Modificar();
			scanf("%d",&Opcion);

			switch (Opcion) {
				case 1:
					do{
					verificador = GetString("Ingrese el Nuevo Nombre","Escribalo Bien", name, 51);
					strcpy(list[i].name, name);
					}while(verificador==-1);
					break;
				case 2:
					do{
					verificador = GetString("Ingrese el Nuevo Apellido","Escribalo Bien", apellido, 51);
					strcpy(list[i].lastName, apellido);
					}while(verificador==-1);
					break;
				case 3:
					getNumeroFloat(&salario, "Ingrese El nuevo Salario");
					list[i].salary= salario;

					break;
				case 4:
					getNumero(&sector, "Ingrese El nuevo Sector");
					list[i].sector = sector;
					break;
				}
			break;
			puts("\n modificado con exito");

			}	else{

				puts("no existe ese id"); }





	}

}

 return 0;
}

int removeEmployee(Employee* list, int len, int id){
	setbuf(stdout, NULL);
	int Opcion;
	if(list != NULL && len>=0){
		for (int i = 0; i < len; ++i) {
		getNumero(&id, "Ingrese el Id \n");
		if(list[i].id==id){
		printf("Usted Elijio el ID %d \n",list[i].id);
		puts("Desea Elimiarlo 1-Si 2-No ?  \n");
		scanf("%d",&Opcion);

		switch (Opcion) {
			case 1:
				list[i].isEmpty = TRUE;

				puts("Se a removido el id ");

				break;

			case 2:
				puts("Saliendo.... ");
				break;
		}

		}
		break;

	}

	}

	return 0;

}

int sortEmployees(Employee* list, int len, int order)
{

	Employee aux;
	setbuf(stdout, NULL);
	if(list != NULL && len>=0){
		for (int i = 0; i < len-1; ++i) {
			for(int j=i+1; j<len; j++){
			if(list[i].isEmpty==FALSE && order==1){


			if(strcmp(list[i].lastName, list[j].lastName)==0 )
				{
				if( list[i].sector > list[j].sector){
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}

					}else{
						if(strcmp(list[i].lastName, list[j].lastName)>0 ){
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}

						}
					}
				}
			}



			}



 return 0;
}

void Promedio(Employee* list, int len, int id){
	setbuf(stdout, NULL);
	int promedio;
	int contador =0;
	float salario;
	int i;
	if(list != NULL && len>=0){
		for ( i = 0;  i < len; ++ i) {
			if(list[i].isEmpty==FALSE){

			 salario += list[i].salary;
			}
		}
		promedio = salario/id;


	for ( i = 0;  i < len; ++ i) {
	if(list[i].salary > promedio){
			contador++;
	} }

	puts("\n\n-----------------------------------------------------");
	printf("La cantidad de salario es %.2f  \n",salario);
	printf("El Promedio es de %d \n",promedio);
	printf("La cantidad que supera el salario promedio es de %d \n",contador);
	puts("------------------------------------------------------");
	}
}
