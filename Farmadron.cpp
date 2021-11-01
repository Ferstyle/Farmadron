/******************************************
* NOMBRE: #Fernando#
* PRIMER APELLIDO: #Garcia-Mascaraque#
* SEGUNDO APELLIDO: #Santillana#
* DNI: 
* EMAIL: #fergms1988@gmail.com#
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Farmadron.h"
#include "CalendarioMensual.h"

typedef int TipoDiasConPedidos[31];

TipoDiasConPedidos DiasConPedidos;

/* Busca el último registro paciente */

int TipoPaciente::BuscarRegistro( int & numReg) {
  int indice = 0 ;

/* recorremos toda el vector hasta encontrar el último número de paciente asignado*/

  while ( indice <= 20) {

    if (datoPaciente[indice].id == (indice +1)) {
      indice++;
      numReg = indice ;
    } else {
      numReg= numReg + 1 ;
      indice = 21 ;
    };
  };
  return ( numReg );
}

/*  Busca el ultimo registro pedido del vector para la numeración   */

int TipoPaciente::BuscarPedido( int & findReg) {
  int ind0 = 0 ;

  while ( ind0 <= 100) {   /* recorremos toda el vector hasta encontrar el último número de pedido asignado*/


    if (datoPedido[ind0].registroPedido == (ind0 + 1)) {
      ind0++;

      findReg = ind0 ;
    } else {
      findReg = findReg + 1 ;
      ind0 = 200;
    };
  };

  return( findReg ) ;
}

/*  Busca el ultimo numero de pedido del vector para la numneracion    */

int TipoPaciente::NumPedido( int & numpedido) {
  int ind0 = 0 ;

  while ( ind0 <= 200) { // recorremos toda el array hasta encontrar el ultimo numero de pedido asigando

    if (datoPedido[ind0].registroPedido == (ind0 + 1 )) {
      numpedido = datoPedido[ind0].idPedido ;
      ind0 --;
    } else {
      numpedido = datoPedido[ind0-1].idPedido + 1;
      ind0 = 250;
    };
  };
  return( numpedido ) ;
}

/*  Funcion para detectar si la fecha es correcta de acuerdo con los formatos y dia/mes/año  */

int TipoPaciente::FechaAcertada(int & newDia, int newMes, int newAnio) {

  /* Función para calcular el número de días de cada mes y  en función del año bisiesto */

  switch (newMes) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    newDia = 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    newDia = 30;
    break;
  case 2:
    if (newAnio%4 == 0  && newAnio%100 != 0 || newAnio%400 == 0) {
      newDia = 29 ;
    } else {
      newDia = 28 ;
    };
    break;
  default:
    newDia = 30 ;
  };
  return newDia;

}

/*  Procedimiento para detectar los campos de la fecha y cargar los vectores  */

void TipoPaciente::FechasEnvio( int contEnvios ) {

  /* Función para introducir analizar los errores de tecla del usuario y que las fechas tengan los formatos correctos */

  int dia2, mes2, anio2, newDia, newMes, newAnio, frecuencia, ind0, ind1, ind2;
  bool pruebaFecha = true;
  dia2 = 1 ;
  while (pruebaFecha) {

    if (contEnvios > 1 ) {

      do {
        printf("Numero de dias entre cada env\xa1o? (entre 1 y 15 dias)? ");
        scanf( " %d" , &frecuencia ) ;
        if (frecuencia < 0 || frecuencia > 15) {
          printf( "\n Valor no permitido debe ser entre 1 y 15 \n" );
        }
      } while (frecuencia < 0 || frecuencia > 15);
      fflush(stdin);
      printf("Dia del primer env\xa1o? ");
      scanf( " %d" , &dia2 ) ;
      printf("Mes del primer env\xa1o? ");
      scanf( " %d" , &newMes ) ;
      printf("A\xa4o del primer env\xa1o? ");
      scanf( " %d" , &newAnio ) ;
    } else if (contEnvios == 0) {
      system("cls");
      fflush(stdin);
      printf( "%s", "Calendario Mensual de Pedidos\n" );
      printf( "Selecci\xa2n Mes ? " );
      scanf( "%2d", &newMes);
      printf( "Selecci\xa2n Ano ? " ) ;
      scanf( "%4d", &newAnio);
    } else {
      fflush(stdin);
      printf("Dia del env\xa1o? ");
      scanf( " %d" , &dia2 ) ;
      printf("Mes del env\xa1o? ");
      scanf( " %d" , &newMes ) ;
      printf("A\xa4o del env\xa1o? ");
      scanf( " %d" , &newAnio ) ;
    };

    FechaAcertada(newDia, newMes, newAnio);

    if (dia2 <= 0 || dia2 > newDia || newMes <= 0 || newMes > 12 || newAnio < 2020) {
      printf("\n La fecha es incorrecta\n");
      system("pause");
    } else {
      pruebaFecha = false;

      filtraFecha[0].dia = dia2;
      filtraFecha[0].mes = newMes;
      filtraFecha[0].anio = newAnio;
    };
  };
  if (contEnvios > 1) {
    for (int j = 0 ; j <= contEnvios-2 ; j++) {
      mes2 = newMes ;
      anio2 = newAnio ;
      dia2 = dia2 + frecuencia;
      if (dia2 > FechaAcertada(newDia, newMes, newAnio)) {
        if (newMes == 12) {
          newMes = 1 ;
          newAnio++ ;
        } else {
          newMes++;
        };
        newDia = dia2- newDia;
      } else {
        newDia =  dia2;
      };

      filtraFecha[j+1].dia = newDia;
      filtraFecha[j+1].mes = newMes;
      filtraFecha[j+1].anio = newAnio;

      dia2 = newDia ;
      mes2 = newMes ;
      anio2 = newAnio ;
    };
  };
  ind0 = 0 ;
  ind1 = 0 ;
  ind2 = 0 ;

  while (ind0 < 100 ) {

    if ( datoPedido[ind0].mes == filtraFecha[0].mes &&
         datoPedido[ind0].anio == filtraFecha[0].anio ) {

      DiasConPedidos[ind2] = datoPedido[ind0].dia ;
    } else {
      DiasConPedidos[ind2] = 0;
    };
    ind2++;

    if ( datoPedido[ind0].dia == filtraFecha[0].dia &&
         datoPedido[ind0].mes == filtraFecha[0].mes &&
         datoPedido[ind0].anio == filtraFecha[0].anio ) {

      comunicaFecha[ind1].dia = filtraFecha[0].dia ;
      comunicaFecha[ind1].mes = filtraFecha[0].mes;
      comunicaFecha[ind1].anio = filtraFecha[0].anio;
      comunicaFecha[ind1].registro = datoPedido[ind0].registroPedido;
      comunicaFecha[ind1].pedido = datoPedido[ind0].idPedido;
      comunicaFecha[ind1].paciente = datoPedido[ind0].idPaciente;
      ind1++;
    } else {

      comunicaFecha[ind1].dia = 0 ;
      comunicaFecha[ind1].mes = 0;
      comunicaFecha[ind1].anio = 0;
      comunicaFecha[ind1].registro = 0;
      comunicaFecha[ind1].pedido = 0;
    };
    ind0++;
  }
}

/*  Procedimiento para registrar un nuevo pedido  */

void TipoPaciente::NewPedido() {
  int numberPedido = 0;
  int findReg = 0;
  char otroPedido = 'X';

  system("cls");

  while (toupper(otroPedido) != 'N') {

    BuscarPedido(findReg);
    NumPedido(numberPedido);

    if (numberPedido > 100) {
      printf("\n Supera el limite m\xa0ximo de pedidos..\n");
      system("pause");
      return;
    } else {
    } ;

    printf("\n");
    printf("Nuevo Pedido: \n" );
    printf("Ref Paciente (entre 1 y 20) ? ");
    scanf( " %d" , &datoPedido[findReg-1].idPaciente ) ;

    if (datoPaciente[(datoPedido[findReg-1].idPaciente)-1].id != datoPedido[findReg-1].idPaciente) {
      printf( "\n Esta referencia no exite.. \n");
      system("pause");
      return;
    } else {
      printf( " =========================>  Paciente.: %s \n" , datoPaciente[datoPedido[findReg-1].idPaciente-1].cadena );
    };

    printf("Numero de env\xa1os? ");
    scanf( " %d" , &datoPedido[findReg-1].infPedidos ) ;

    FechasEnvio(datoPedido[findReg-1].infPedidos);

    Farmacos(datoPedido[findReg-1].infPedidos, findReg, numberPedido );

    printf("\n Otro Pedido (S/N)? ");
    scanf( " %c" , &otroPedido );
    system("cls");
  }
}

/*  Procedimiento teclear los detalles de los medicamentos  */

void TipoPaciente::Farmacos(int numberEnv, int pacReg, int numberPedido) {
  char otroFarmaco = 'X';
  int ind1 = 0;
  int auxPedido = 0;
  int auxFecha = 0;
  int auxTotal = 0;
  int auxPaciente = datoPedido[pacReg-1].idPaciente ;
  int pesoEnvio = 0;
  int maxFarmaco = 1;
  int pesoTotal = 0;

  while (toupper(otroFarmaco) != 'N' ) {

    while (toupper(otroFarmaco) != 'N' && pesoEnvio < 3000  && pesoTotal < 3000 && maxFarmaco < 6) {
      printf(" (N: %d) Nombre f\xa0rmaco (entre 1 y 20 caracteres) ? ", maxFarmaco );
      scanf( " %[^\n]s" , &datoPedido[pacReg-1].farmaco ) ;

      do {
        pesoTotal = 0;
        do {
          fflush(stdin);
          printf("Peso f\xa0rmaco (menos de 3000 gramos ) ? ");
          scanf( " %d" , &datoPedido[pacReg-1].peso ) ;
          if (datoPedido[pacReg-1].peso < 1 || datoPedido[pacReg-1].peso > 3000 ) {
            printf( "\n Excede el peso permitido o datos incorrectos \n");
          };
        } while ( datoPedido[pacReg-1].peso < 1 || datoPedido[pacReg-1].peso > 3000 ) ;

        fflush(stdin);
        printf("Unidades de f\xa0rmaco ? ");
        scanf( " %d" , &datoPedido[pacReg-1].units ) ;
        pesoTotal =  datoPedido[pacReg-1].peso*datoPedido[pacReg-1].units ;
        if (datoPedido[pacReg-1].units < 1 || datoPedido[pacReg-1].units > 100 ) {
          printf( "\n Sobrepasada la cantidad permitida o datos incorrectos \n");
        };
        if (pesoTotal > 3000) {
          printf( "\n Sobrepasado el peso permitido de env\xa1o \n");
        };
      } while ( datoPedido[pacReg-1].units < 1 || datoPedido[pacReg-1].units > 100 || pesoTotal > 3000) ;

      pesoEnvio = pesoEnvio + pesoTotal;

      if (pesoEnvio > 3000 || pesoTotal > 3000) {

        printf( "\n El pedido excede el peso maximo permitido de 3000 gramos \n");
        printf( "\n Este ultimo f\xa0rmaco se borrara del pedido !!!! \n");

        datoPedido[pacReg-1].registroPedido = 0 ;
        datoPedido[pacReg-1].idPedido = 0 ;
        datoPedido[pacReg-1].idPaciente = 0;
        datoPedido[pacReg-1].dia = 0 ;
        datoPedido[pacReg-1].mes = 0 ;
        datoPedido[pacReg-1].anio = 0 ;
        strcpy(datoPedido[pacReg-1].farmaco, " ");
        datoPedido[pacReg-1].peso = 0 ;
        datoPedido[pacReg-1].units = 0 ;

        return ;
      };

      ind1 = pacReg;
      auxPedido = numberPedido;
      auxTotal = ( pacReg-1) + numberEnv ;
      auxFecha = 0 ;
      for (int j = pacReg-1 ; j < auxTotal  ; j++) {

        datoPedido[j].registroPedido = pacReg ;
        datoPedido[j].idPedido = auxPedido ;
        datoPedido[j].idPaciente = auxPaciente;
        datoPedido[j].dia = filtraFecha[auxFecha].dia ;
        datoPedido[j].mes = filtraFecha[auxFecha].mes ;
        datoPedido[j].anio = filtraFecha[auxFecha].anio ;
        strcpy(datoPedido[j].farmaco, datoPedido[ind1-1].farmaco);
        datoPedido[j].peso = datoPedido[ind1-1].peso ;
        datoPedido[j].units = datoPedido[ind1-1].units ;

        pacReg++;
        auxPedido++;
        auxFecha++;
      }
      fflush(stdin);
      printf("\n Otro f\xa0rmaco (S/N)? ");
      scanf( " %c" , &otroFarmaco );
      maxFarmaco = maxFarmaco + 1 ;


    };
    if (maxFarmaco > 5) {
      printf( "\n No se puede mas de 5 f\xa0rmacos por pedido \n");
      otroFarmaco = 'N';
      system("pause");
    };
  }
}

/*  Procedimiento dar de alta nuevos pacientes  */

void TipoPaciente::AltaNuevoPaciente() {
  int numReg = 0 ;
  char paciOp = 'X';
  char datosBien = 'X';
  int longitudMax = 20 ;
  int distanciaMax = 0 ;
  int anguloMax =0 ;


  while (toupper(paciOp) != 'N') {
    paciOp = 'X';
    datosBien = 'X';
    BuscarRegistro(numReg);

    if ( numReg > 20) {
      printf("Ha Superado el limite maximo de registros");
      datosBien = 'S';
    };

    while ( toupper(datosBien) != 'S') {
      longitudMax = 20 ;
      distanciaMax = 0 ;
      system("cls");
      printf("\n");
      printf("Alta nuevo paciente: \n" );

      while (longitudMax > 19) {
        fflush(stdin);
        datoPaciente[numReg-1].id = numReg ;
        printf("Identificador (entre 1 y 20 caracteres) ? ");
        scanf( " %[^\n]s" , &datoPaciente[numReg-1].cadena ) ;
        longitudMax = strlen(datoPaciente[numReg-1].cadena);
        if (longitudMax > 19) {
          printf( "\n Ha sobrepasado el maximo de caracteres permitido\n");
        }
      }

      do {
        fflush(stdin);
        printf( "Distancia (hasta 10000 metros a plena carga) ? ");
        scanf( " %d", &datoPaciente[numReg-1].distancia ) ;
        distanciaMax=datoPaciente[numReg-1].distancia;
        if (distanciaMax < 1 || distanciaMax > 10000 ) {
          printf( "\n Valor de la distancia fuera de rango\n");
        };
      } while (  distanciaMax < 1 || distanciaMax > 10000 ) ;

      do {
        fflush(stdin);
        printf("\xb5ngulo (entre 0 y 2000 pi /1000 radianes) ? ");
        scanf( " %d" , &datoPaciente[numReg-1].angulo ) ;
        anguloMax=datoPaciente[numReg-1].angulo;
        if (anguloMax < 1 || anguloMax > 2000 ) {
          printf( "\n Valor del angulo fuera de rango\n");
        };

      } while (  anguloMax < 1 || anguloMax > 2000 ) ;


      printf("\n Datos correctos S/N? ");
      scanf( " %c" , &datosBien );
    }
    printf("\n Otro Paciente mas S/N? ");
    scanf( " %c" , &paciOp );
  }
}

/*  Procedimiento lista de pacientes   */

void TipoPaciente::ListaPacientes() {
  int indice = 0 ;
  system("cls");
  printf( "|======================================================|\n");
  printf( "|       Lista de pacientes y su ubicaci\xa2n              |\n");
  printf( "|======================================================|\n");
  printf( "|  Ref.     Identificador       Distancia     \xb5ngulo   |\n"  );
  printf( "|======================================================|\n");

  while (datoPaciente[indice].id == (indice +1)) {

    printf( "    %d", datoPaciente[indice].id);
    printf( "      %-20s ", datoPaciente[indice].cadena);
    printf(" %4d ", datoPaciente[indice].distancia);
    printf("      %6d \n", datoPaciente[indice].angulo);
    indice++;
  }
  printf("\n\n");
  system("pause");

}

/*  Procedimiento listado de pedidos   */

void TipoPaciente::ListaPedidos() {
  int fechaIndice = 0 ;
  int newDia, newMes, newAnio ;
  int pesoTotal = 0;
  int auxPedido;

  system("cls");
  printf( "|=================================|\n");
  printf( "|    Lista diaria de pedidos :    |\n");
  printf( "|=================================|\n");
  FechasEnvio(1);

  newDia = comunicaFecha[0].dia ;
  newMes = comunicaFecha[0].mes ;
  newAnio = comunicaFecha[0].anio ;

  if (newDia > 31 || newMes > 12 ||comunicaFecha[fechaIndice].registro == 0 ) {

    printf("\n No hay Pedidos para listar \n");
    system("pause");
    return;

  };

  while (comunicaFecha[fechaIndice].registro > 0  && newDia == comunicaFecha[fechaIndice].dia &&
         newMes == comunicaFecha[fechaIndice].mes &&
         newAnio == comunicaFecha[fechaIndice].anio ) {

    printf("Pedido : %d  ( paciente: %s )\n ", datoPedido[comunicaFecha[fechaIndice].registro-1].idPedido, datoPaciente[comunicaFecha[fechaIndice].paciente-1].cadena );
    printf( "Ubicaci\xa2n destino:\n Distancia: %6d y Angulo: %5d \n",  datoPaciente[comunicaFecha[fechaIndice].paciente-1].distancia , datoPaciente[comunicaFecha[fechaIndice].paciente-1].angulo );
    auxPedido = comunicaFecha[fechaIndice].pedido;
    pesoTotal = 0 ;

    while ( auxPedido == comunicaFecha[fechaIndice].pedido) {

      printf("%2d  Unidades ",  datoPedido[comunicaFecha[fechaIndice].registro-1].units);
      printf("%-20s",  datoPedido[comunicaFecha[fechaIndice].registro-1].farmaco);
      printf("Peso: %4d gramos\n",  datoPedido[comunicaFecha[fechaIndice].registro-1].units * datoPedido[comunicaFecha[fechaIndice].registro-1].peso);

      pesoTotal =  pesoTotal + (datoPedido[comunicaFecha[fechaIndice].registro-1].peso * datoPedido[comunicaFecha[fechaIndice].registro-1].units) ;
      fechaIndice++;
    }
    printf("Peso Total del Envio ..:     %4d gramos \n" , pesoTotal );

  };
  printf("\n");
  system("pause");

}

/*  Menú Principal  */

int TipoPaciente::MenuPrincipal() {
  char tecla = 'X';
  char masPedidos = 'X';

  while (toupper(tecla) != 'S' ) {
    system("cls");
    fflush(stdin);
    printf( " \n |==================================================|\n" );
    printf( " |  FarmaDron: Distribuci\xa2n de f\xa0rmacos con Dron    | \n" );
    printf( " |==================================================|\n" );
    printf( " |  Alta Nuevo paciente                 (Pulsar A)  |\n" );
    printf( " |  Ubicar pacientes                    (Pulsar U)  |\n" );
    printf( " |  Nuevo pedido                        (Pulsar N)  |\n" );
    printf( " |  Lista diaria de pedidos             (Pulsar L)  |\n" );
    printf( " |  Calendario mensual de pedidos       (Pulsar C)  |\n" );
    printf( " |  Salir                               (Pulsar S)  |\n" );
    printf( " |==================================================|\n" );
    printf( " |   Teclear una opci\xa2n valida  A|U|N|L|C|S ?       |\n");
    printf( " |==================================================|\n" );
    scanf( " %c" , &tecla );
    switch (toupper(tecla)) {
    case 'A':
      AltaNuevoPaciente();
      break;
    case 'U':
      ListaPacientes();
      break;
    case 'N':
      NewPedido();
      break;
    case 'L':
      ListaPedidos();
      break;
    case 'C':
      do {
        FechasEnvio( 0);
        calendario( filtraFecha[0].mes, filtraFecha[0].anio, masPedidos, DiasConPedidos);
      } while (toupper(masPedidos) != 'N');
      break;
    default:
      printf(" Salir de la aplicacion ");
      system("cls");
    }
  }
}
