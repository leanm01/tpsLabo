/*
 * UTN.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Leandro
 */

#ifndef UTN_H_
#define UTN_H_

#define LIMITE_BUFFER_STRING 4096
int esNumerico (char str[]);
int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int utn_getFloat(char* mensaje,char* mensajeError,float* pResultado,float minimo,float maximo,int reintentos);
int esUnNombreValido(char* cadena,int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int esFlotante(char* array,int limite);
int getFloat(float* pFloat);
int utn_getCuit(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int isCuit(char* cadena,int limite);
int utn_getAviso(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);

int utn_getChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos);
int utn_getSexo(char* mensaje, char* mensajeError, char* pResultado,int reintentos);

int menu();
int otroMenu();
int informes();
int modificar();

#endif /* UTN_H_ */
