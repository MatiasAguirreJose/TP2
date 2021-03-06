#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#endif /* ARRAYEMPLOYEES_H_ */


struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

//-----------------------------------------------------------------------------------------
/// \brief Se pide un char , se lo ingresa y valida si es un strig
/// \param mensaje[] char
/// \param entidad
/// \return int Retorna si es false o true enm caso de false se repite
int GetString(char mensaje[],char mensajeError[], char cadena[], int tam);


/// \brief valida si es un entero
/// \param int* pResultado
/// \return retorna false o true
int getInt(int* pResultado);

/// \brief valida si es un string
/// \param int* pResultad
/// \return int Retorna si es false o true
int esNumerica(char* cadena);

/// \brief Se pide un numero flotante, se lo ingresa y valida
/// \param har mensaje[]
/// \param float* pResultado
/// \return int Retorna un flotante
float getNumeroFloat(float* pResultado, char mensaje[]);

/// \brief verifica si no e sun string
/// \param float* pResultado)
/// \return int Retorna un entero
int getFloat(float* pResultado);

/// \brief Se pide un numero flotante, se lo ingresa y valida
/// \param har mensaje[]
/// \param float* pResultado
/// \return int Retorna un flotante
int esNumericaFloat(char* cadena);

/// \brief valida si es un string
/// \param char* cadena
/// \return int Retorna si es false o true
int esString(char* cadena);

/// \brief ingresa un numero y lo guarda
/// \param int* pResultado
/// \param char mensaje[]
/// \return retorna un entero
int getNumero(int* pResultado, char mensaje[]);


//-----------------------------------------------------------------------------------------


/// \brief muestra el menu
/// \param --
/// \param ---
/// \return ----
void ElijaOpcion(void);

/// \brief inicializa el cliente
/// \param Employee* lis
/// \param int tam
/// \return returna un entero
int InicializarClientes(Employee* list,  int tam);

/// \brief agrega a una persona
/// \param Employee* list
/// \param int len
/// \param int id
/// \param char name[]
/// \paramchar lastName[]
/// \param float salary
/// \param int sector
/// \return returna un entero

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/// \brief muestra los clientes
/// \param Employee* lis
/// \param int len
/// \return returna un entero
int  printEmployees(Employee* list, int len);

/// \brief muestra un mensaje de lo qeu desea modificar
/// \param -
/// \param -
/// \return -
void Modificar(void);

/// \brief ingresa lo que quiera modificar del cliente y lo guarda
/// \param Employee* list
/// \param int len
/// \param int id
/// \param int verificador
/// \return entero

int findEmployeeById(Employee* list, int len,int id);


/// \brief elimina un cliente
/// \param Employee* list
/// \param int len
/// \param int id
/// \return entero

int removeEmployee(Employee* list, int len, int id);

/// \brief ordena alfabeticamente o por sector
/// \param Employee* list
/// \param int len
/// \param int order
/// \return entero

int sortEmployees(Employee* list, int len, int order);

/// \brief hace el promedio
/// \param Employee* list
/// \param int len
/// \param int id
/// \return -

void Promedio(Employee* list, int len, int id);



