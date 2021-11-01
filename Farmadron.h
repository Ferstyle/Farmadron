/******************************************
* NOMBRE: #Fernando#
* PRIMER APELLIDO: #Garcia-Mascaraque#
* SEGUNDO APELLIDO: #Santillana#
* DNI: 
* EMAIL: #fergms1988@gmail.com#
*******************************************/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef int TipoDiasConPedidos[31];

/*campos y datos del pedido*/
typedef char TipoDirecionAlm[49];
typedef char TipoMunicipioAlm[49];
typedef char TipoProvinciaAlm[17];
typedef char TipoDescripcionAlm[49];
typedef struct TipoAlmacen{
  int idAlmacen ;
  TipoDirecionAlm direcionAlm;
  TipoMunicipioAlm municipio;
  TipoProvinciaAlm provincia;
  TipoDescripcionAlm nbrAlma;

  };
  typedef TipoAlmacen TipoDepot[10];
typedef char TipoFarmaco[21];



typedef struct TipoPedido {
  int regpedido;
  int idpedido;
  int idpaciente;
  int dia;
  int mes;
  int anio;
  TipoFarmaco farmaco;
  int units;
  int peso;
  int numberD;
  int infPedidos;
  int idalmacen;

};
typedef TipoPedido TipoCedula[100];

/*Datos y campos de paciente*/

typedef char TipoCadena[21];

typedef struct TipoPaciente {
  int id;
  TipoCadena cadena;
  int angulo ;
  int distancia;
  int almacen;
  int reg_paciente;
};
typedef TipoPaciente TipoTarjetas[20];

/*Vector de Fechas*/

typedef struct TipoFechas {
  int dia;
  int mes;
  int anio;
};
typedef TipoFechas TipoRegistroFecha[30];

/*Vector de Filtrado fechas*/

typedef struct TipoFiltro {
  int dia;
  int mes;
  int anio;
  int registro;
  int pedido;
  int paciente;
};
typedef TipoFiltro TipoFiltradoFecha[50];

/*Array General tipo registro*/

typedef struct TipoGestion {

  TipoTarjetas datoPaciente;
  TipoCedula datoPedido;
  TipoRegistroFecha filtraFecha;
  TipoFiltradoFecha comunicaFecha;

  /*Funciones del Programa*/

  int MenuPrincipal();
  int BuscarRegistro( int  & numReg);
  int BuscarPedido( int  & buscareg );
  int NumPedido( int  & numpedido );
  void AltaNuevoPaciente();
  void ListaPacientes();
  void NewPedido();
  void ListaPedidos();
  void FechasEnvio(int enviados);
  int FechaAcertada(int & newDia, int newMes, int newAnio);
  void Farmacos(int numEnvios, int registro2, int numPedido);

};
