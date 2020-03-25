/* 3º Realizar un programa que dado un array de 20 elementos enteros, resuelva mediante funciones los siguientes apartados:
*  - Generar. Me permite generar aleatoriamente todos los elementos del array: (1-10)
*  - Buscar. Me dice el número de veces que aparece el número a buscar.
*  - Ordenar el array de mayor a menor
*  - MayoresyMenores: Me debe decir cuantos elementos son mayores y cuantos elementos son menores a la media.
*
* char menu();
* void Generar(int array[TAM]);
* void Ver(int array[TAM]);
* int Buscar(int n,int array[TAM]);
* void Ordenar(int array[TAM]);
* void MayoresyMenores(int array[TAM]);
* void parar();
*/

#include <stdio.h>
#include <time.h>

#define TAM 20

/* Prototipos */
char Menu();
void Generar(int array[TAM]);
void Ver(int array[TAM]);
int Buscar(int n,int array[TAM]);
void Ordenar(int array[TAM]);
void MayoresyMenores(int array[TAM], int *mayor, int *menor);
float Media();
//void parar();


/* Programa Principal */
void main(){
	int vector[TAM];
	int mayores=0, menores=0, buscado=0, find=0;
	char opcion;
		
	Generar(vector); // Inicializamos array
	//Ver(vector);
	
	do{	
		opcion=Menu();
		//fflush(stdin);
		
		switch(opcion){
		case 'a':
			Generar(vector);
			printf("\nArray generado\n");
			Ver(vector);
			break;
		case 'b':
			Ver(vector);
			break;
		case 'c':
			printf("\nIntroduce valor a buscar: ");
			scanf("%d", &buscado);
			find=Buscar(buscado, vector);
			find==0?printf("Valor no encontrado.\n"):printf("Encontradas %d coincidencias del nº %d.\n", find, buscado);
			break;
		case 'd':
			Ordenar(vector);
			printf("\nArray Ordenado\n");
			Ver(vector);
			break;
		case 'e':
			MayoresyMenores(vector, &mayores, &menores);			
			printf("\n\nMedia = %0.2f \tMayores = %d \tMenores = %d \n", Media(vector), mayores, menores);
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
	
	printf("\nArrays: Buscar, Ordenar, MayoresyMenores\n"); 
	printf("A. Generar Array\n");
	printf("B. Ver Array\n");
	printf("C. Buscar elemento del array\n");
	printf("D. Ordenar elementos del array\n");
	printf("E. Mayores y menores de la media del array\n");
	printf("S. Salir\n");
	printf("Introduce una opcion: ");
	scanf("%c", &op);
	
	return tolower(op);
}


void Generar(int array[]){
	srand((unsigned) time(NULL));
	int i=0;
	for(i=0;i<TAM;i++){
		array[i]=(rand()%10)+1;
	}		
}


void Ver(int array[]){
	int i;
	printf("\nVector = ");
	for(i=0;i<TAM;i++){
		printf("[%d] ", array[i]);
	}
}


int Buscar(int n, int array[]){
	int i=0, aux=0;
	for(i=0;i<TAM;i++){
		if (n==array[i]) 
			aux++;
	}
	return aux;
}


float Media (int array[]){
	int i=0, aux=0;
	for(i=0;i<TAM;i++){
		aux+=array[i];
	}
	return aux/(float)TAM;
}


void MayoresyMenores(int array[], int *mayor, int *menor){
	int i=0, aux=0, med=0;
	med=Media(array);
	
	for(i=0;i<TAM;i++){		
		if(array[i]>med)
			aux++;
	}
	*mayor=aux;
	*menor=TAM-aux;
}


void Ordenar(int array[]){
	int i=0, j=0, temp=0;	
	// Ordenación por algoritmo burbuja
	for (i=1; i<TAM; i++){
       for (j=0; j<TAM-i; j++){
          if (array[j] < array[j+1]){
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
          }
       }
	}
}
