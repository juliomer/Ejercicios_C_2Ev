/* 2º Realizar un programa que dado un array de 15 elementos enteros, resuelva mediante funciones los siguientes apartados:
*  - Generar. Me permite generar aleatoriamente todos los elementos del array: (1-50)
*  - Media. Me permite calcular la media
*  - Menor. Me dirá cual es el menor número del array.
*  - Sumatorio. Me dará la suma de todos los elementos del array.
*  char menu();
*  void Generar(int array[TAM]);
*  void Ver(int array[TAM]);
*  float Media(int array[TAM]);
*  int Menor(int array[TAM]);
*  long Sumatorio(int array[TAM]);
*  void parar();
*/

#include <stdio.h>
#include <time.h>
#include <ctype.h>

#define TAM 15

/* Prototipos */
char Menu(void);
void Generar(int array[TAM]);
void Ver(int array[TAM]);
float Media(int array[TAM]);
int Menor(int array[TAM]);
long Sumatorio(int array[TAM]);
//void Parar();


/* Programa Principal */
void main(){
	//Variables
	int vector[TAM];
	char opcion;
	
	Generar(vector); // Inicializamos array
	//Ver(vector);
	
	do{	
		opcion=Menu();
		fflush(stdin);
		
		switch(opcion){
		case 'a':
			Generar(vector);
			printf("\nArray generado\n");
			break;
		case 'b':
			Ver(vector);
			break;
		case 'c':
			printf("\nMedia = %0.2f\n", Media(vector));
			break;
		case 'd':
			printf("\nMenor = %d\n", Menor(vector));
			break;
		case 'e':
			printf("\nSumatorio = %d\n", Sumatorio(vector));
			break;
		case 's':
			printf("\nFIN");
			break;
		default:
			printf("\nOpcion incorrecta.");
			break;
		}	
	}while (opcion!='s');	
		
}


/* Funciones */
char Menu(void){
	char op;
	fflush(stdin);
	
	printf("\nArrays: Media, Menor, Sumatorio\n"); 
	printf("A. Generar Array\n");
	printf("B. Ver Array\n");
	printf("C. Media de los elementos del array\n");
	printf("D. Menor elemento del array\n");
	printf("E. Sumatorio de los elementos del array\n");
	printf("S. Salir\n");
	printf("Introduce una opcion: ");
	scanf("%c", &op);
	
	return tolower(op);
}


void Generar(int array[TAM]){
	srand((unsigned) time(NULL));
	int i=0;
	for(i=0;i<TAM;i++){
		array[i]=(rand()%50)+1;
	}		
}


void Ver(int array[]){
	int i;
	printf("\nVector = ");
	for(i=0;i<TAM;i++){
		printf("[%d] ", array[i]);
	}
}


float Media (int array[]){	
	return (float)(Sumatorio(array)/(float)TAM);
}


int Menor(int array[]){
	int i=0, aux=0;
	aux=array[0];
	for(i=0;i<TAM;i++){		
		if(array[i]<aux){
			aux=array[i];
		}
	}
	return aux;
}


long Sumatorio(int array[]){
	int i=0, sum=0;
	for(i=0;i<TAM;i++){
		sum+=array[i];
	}
	return sum;
}
