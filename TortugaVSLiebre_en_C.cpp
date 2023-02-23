/*	programa para simular la carrera entre
	una tortuga y una liebre */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define  CAMINO 70

/* prototypes of funtions */
void reloj( int *t , int *l );
void establecerDirecciones( int timeT , int timeL );
int verificarDireccion( void );
void imprimirPistaAux( const int pista[] , const int tamanio );
void imprimirPista( const int pista[] , const int tamanio );

int pista[ CAMINO ]; /* declara un arreglo de 70 elementos */

/* declara dos apuntadores inicializados */
int *tortuga = &pista[0];
int *liebre = &pista[0];

/* la funcion main inicia la ejecucion */
int main(){
	
	/* inicializa el arreglo pista con 0s */
	memset( pista , 0 , sizeof( pista ) );
	
	/* semilla */
	srand( time ( NULL ) );
	
	/* tic del reloj para cada participante */
	int timeT = 0;
	int timeL = 0;
	
	printf("\n\n BANG !!!!!\n"
		" Y ARRANCAN !!!!!\n\n");
	
	system("cls");
	
	/* inicio de la simulacion */
	while( ( tortuga < &pista[ CAMINO - 1 ] ) && ( liebre < &pista[ CAMINO - 1 ] ) ){
	
		reloj( &timeT , &timeL ); /* reloj */
		
		establecerDirecciones( timeT , timeL ); /* ubica a los competidores en su posicion actual */
		
		verificarDireccion(); /* verifica si cumplen las reglas de posicionado */
		
		/* si ambos se consigen en el camino */
		if( tortuga == liebre )
			imprimirPistaAux( pista , CAMINO );
		else /* De lo contrario */
			imprimirPista( pista , CAMINO );
		
		system("cls");
		
	}// fin while
	
	/* es un empate si ambos cruzan la meta */
	if( tortuga >= &pista[ CAMINO - 1 ] && liebre >= &pista[ CAMINO - 1 ] )
		printf("\n\n !!! ESTO ES UN EMPATE !!! \n\n");
	
	/* gana la tortuga */	
	if( tortuga >= &pista[ CAMINO - 1 ] )
		printf("\n\n  !!!! GANO LA TORTUGA !!!! VIVA !!!!\n\n");
	
	/* gana la liebre */
	if( liebre >= &pista[ CAMINO - 1 ] )
		printf("\n\n !!!! GANO LA LIEBRE, YUPI!! \n\n");
	
	system("pause");
	
	return 0; /* indica terminacion exitosa */
	
}// fin de la funcion main

/* define el tipo de desplazamiento */
void reloj( int *t , int *l ){
	
	*t = 1 + rand() % 10;
	*l = 1 + rand() % 10;
}// fin de la funcion relof

/* establece las direcciones */
void establecerDirecciones( int timeT , int timeL ){
	
	/* prototypes privates */
	void porcentajeTortuga( int t );
	void porcentajeLiebre( int l );
	
	porcentajeTortuga( timeT );
	porcentajeLiebre( timeL );
	
}// fin de establecerDirecciones

/* realiza el desplazaiento de la posicion de la tortuga */
void porcentajeTortuga( int t ){
	
	switch( t ){
		
		/* paso rapido */
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			tortuga += 3;
			break;
		
		/* deslizamiento */	
		case 6:
		case 7:
			tortuga -= 6;
			break;
			
		/* paso lento */	
		case 8:
		case 9:
		case 10:
			tortuga += 1;
			break;
	}// fin switch
	
}// fin porcentajeTortuga

/* realiza el desplazamiento de la posicion de la Liebre */
void porcentajeLiebre( int l ){
	
	switch( l ){
		
		/* deslizamiento grande */
		case 1:
			liebre -= 12;
			break;
			
		/* salto grande */	
		case 2:	
		case 3:
			liebre += 9;
			break;
			
		/* dormir */	
		case 4:
		case 5:
			liebre += 0;
			break;
		
		/* deslizamiento pequeño */
		case 6:	
		case 7: 
			liebre -= 2;
			break;
			
		/* salto pequeño */	
		case 8:	
		case 9:
		case 10:
			liebre += 1;
			break;
			
	}// fin switch
	
}// fin porcentajeLiebre

/* define la direccion correcta si alguno retrocede mucho*/
int verificarDireccion( void ){
	
	/* si alguno retrocede mucho */
	if( ( tortuga < &pista[0] ) || ( liebre < &pista[0] ) ){
		
		/* si ambos estan muy atras los coloca en el punto de inicio */
		if( tortuga < &pista[0] && liebre < &pista[0] ){
			tortuga = &pista[0];
			liebre = &pista[0];
			return 1;
		}
		
		/* si la tortuga esta muy atras del punto de inicio */
		if( tortuga < &pista[0] ){
			tortuga = &pista[0];
			return 1;
		}
		
		/* si la liebre esta muy atras del punto de inicio */
		if( liebre < &pista[0] ){
			liebre = &pista[0];
			return 1;
		}
	
	}
	
	return 0;
}// fin verificarDireccion

/* imprime la pista de carreras con dialogo si ambos se cruzan en el 
	recorrido */
void imprimirPistaAux( const int pista[] , const int tamanio ){
	
	printf("\n\n%23s\n\n", "MONTANIA ROCOSA" );
	
	printf("Inicio\n\n");
	for( int i = 0 ; i < tamanio ; i++ ){
		printf( &pista[i] == tortuga && &pista[i] == liebre ? "OUCH !!!!!" : " " );
	}// fin for
	printf("->Meta");
	
}// fin imprimirPistaAux

/* imprime la pista de carreras con sus Letras */
void imprimirPista( const int pista[] , const int tamanio ){
	
	printf("\n\n%23s\n\n", "MONTANIA ROCOSA" );
	
	printf("Inicio\n\n");
	for( int i = 0 ; i < tamanio ; i++ ){
		
		if( &pista[i] == tortuga )
			printf("T");
		else if( &pista[i] == liebre )
			printf("L");
		else
			printf(" ");
			
	}// fin for
	printf("->Meta");
	
}// fin imprimirPista
