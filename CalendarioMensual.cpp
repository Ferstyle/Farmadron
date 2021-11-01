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

typedef int vector[31];

int CalcularDiaDelMes(int anio, int newMes) {

  if (newMes == 1 || newMes == 3 || newMes == 5|| newMes == 7
  || newMes == 8|| newMes == 10|| newMes == 12) {

    return 31;
  }
  if (newMes == 2) {
    if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0) {
      return 29 ;
    }
    return 28 ;
  }
  return 30;
}

int Zeller(int anio, int mes) {
  int a = (14 - mes) / 12 ;
  int y = anio - a ;
  int m = mes + 12 * a - 2 ;
  int dia = 1 ;
  int DiaZeller = dia;
  DiaZeller = (dia + y + y / 4 - y / 100 + y / 400 + ( 31 * m ) / 12) % 7 ;
  return DiaZeller;
}

void calendario(int mes, int anio, char & continua, vector X) {

  int ZellerDias ;
  int DiasXMes ;
  int Resto ;
  int hayPedido = 'N';

  ZellerDias = Zeller(anio, mes);
  DiasXMes  = CalcularDiaDelMes(anio, mes);

  printf( "Pedidos del mes o vuelos del dron \n");


  switch (mes) {
  case 1:  printf( "%-20s%5d\n" , "Enero", anio );
    break ;
  case 2:   printf( "%-20s%5d\n" , "Febrero", anio );
    break ;
  case 3:   printf( "%-20s%5d\n" , "Marzo", anio );
    break ;
  case 4:   printf( "%-20s%5d\n" , "Abril", anio );
    break ;
  case 5:   printf( "%-20s%5d\n" , "Mayo", anio );
    break ;
  case 6:   printf( "%-20s%5d\n" , "Junio", anio );
    break ;
  case 7:   printf( "%-20s%5d\n" , "Julio", anio );
    break ;
  case 8:   printf( "%-20s%5d\n" , "Agosto", anio );
    break ;
  case 9:   printf( "%-20s%5d\n" , "Septiembre", anio );
    break ;
  case 10:  printf( "%-20s%5d\n" , "Octubre", anio );
    break ;
  case 11:  printf( "%-20s%5d\n" , "Noviembre", anio );
    break ;
  case 12:  printf( "%-20s%5d\n" , "Diciembre", anio );
    break ;
  default:   printf( "\%-20s%5d\n" , "ERROR DE MES", anio );
  }

  printf( "L   M   M   J   V  |" );

  printf("  S   D  \n");

  printf("\n");

  if (ZellerDias == 0) {
    ZellerDias = 6 ;
  } else {
    ZellerDias = ZellerDias - 1;
  }

  for (int indice = 1 ; indice <= ZellerDias ; indice++) {
    if (indice == 5 ) {
      printf( "%3s", "   " );
      printf( " ");
    } else {
      printf( "%4s", "    " );
    }
  };

  for (int dia = 1 ; dia <= DiasXMes ; dia++) {
    hayPedido = 'N';
    for (int k = 0 ; k <= 31; k++ ) {
      if (X[k] == dia) {
        hayPedido = 'Y';
      }
    }
    if (hayPedido == 'Y') {
      if ( (ZellerDias + dia - 5  ) % 7 == 0 ) {
        printf( "%02d " , dia );
        printf( "%c" , char (179));
        printf( " ");
      } else {
        printf( "%02d %c" , dia , ' ' );
      }
    } else {
      if ( (ZellerDias + dia - 5  ) % 7 == 0 ) {
        printf( "-- " );
        printf( "%c" , char (179));
        printf( " ");
      } else {
        printf( "--  " );
      }
    }

    if ( (ZellerDias  + dia ) % 7 == 0) {
      printf( "\n");

    }
  }

  if ((ZellerDias + DiasXMes) == 28) {
    Resto = 28 -(ZellerDias + DiasXMes);
  } else if ((ZellerDias + DiasXMes) > 35) {
    Resto = 42 -(ZellerDias + DiasXMes);
  } else {
    Resto = 35 -(ZellerDias + DiasXMes);
  }

  for (int indice = 1 ; indice <= Resto ; indice++) {
    if ( indice == Resto-2 ) {
      printf( "-- " );
      printf( "%c" , char (179));
      printf( " ");
    } else {
      printf( "%4s", "    " );
    }
  }
  printf( "\n\n");

  fflush(stdin);
  printf(" Mostrar otro mes (S/N) ?");
  scanf("%c", & continua);
}
