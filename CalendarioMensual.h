/******************************************
* NOMBRE: #Fernando#
* PRIMER APELLIDO: #Garcia-Mascaraque#
* SEGUNDO APELLIDO: #Santillana#
* DNI: #50878079#
* EMAIL: #fergms1988@gmail.com#
*******************************************/

#pragma once


#include "Farmadron.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef int vector[31];

int CalcularDiaMes(int anio, int newMes);
int Zeller(int anio, int mes);
void calendario(int mes, int anio, char & continua,  vector X );
