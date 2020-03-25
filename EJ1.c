/* EJ1º Realizar un programa que me cambie el contenido de dos variables pasadas desde el programa principal. 
*  La función se llama cambiar y se le pasan dos variables de tipo entero a y b.
*/

#include <stdio.h>

/* Prototipos */
void cambiar(int *r, int *s);

/* Programa Principal */
void main(){
	// Variables
	int a=0, b=0;
	
	printf("\nIntroduce dos enteros (separados por espacio): ");
	scanf("%d %d", &a, &b);	
	
	printf ("\nValores Iniciales: a = %d y b= %d", a, b);
	
	cambiar(&a, &b);
	
	printf ("\nValores Intercambiados: a = %d y b= %d", a, b);
}


/* Funciones */
void cambiar(int *r, int *s){
	int aux=0;
	aux=*r;
	*r=*s;
	*s=aux;
}

