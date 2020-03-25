/* 6º Realizar un programa que dado un array de 20 elementos enteros, resuelva mediante funciones los siguientes apartados:
*  - Generar. Me permite generar aleatoriamente todos los elementos del array: (1-10)
*  - Ver. Me permite visualizar el contenido del array
*  - Moda. Me dice el número que más veces se repite. (si hay varios uno de ellos)
*  - Ordenar el array de menor a mayor
*  - Paresimpares: Me debe decir cuantos elementos son pares y cuantos elementos son impares.
*
* char menu();
* void Generar(int array[TAM]);
* void Ver(int array[TAM]);
* int Moda(int array[TAM]);
* void Ordenar(int array[TAM]);
* int ParesImpares(int array[TAM]);
* void parar();
*/

#include <stdio.h>
#include <time.h>

#define TAM 20

/* Prototipos */
char Menu();
void Generar(int array[TAM]);
void Ver(int array[TAM]);
void Moda(int array[TAM], int *pos, int *rep);
void Ordenar(int array[TAM]);
void ParesImpares(int array[TAM], int *par, int *impar);
//void parar();


/* Programa Principal */
void main(){
	int vector[TAM];
	int posicion=0, repetidos=0, pares=0, impares=0;
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
			printf("\n");
			break;
		case 'b':
			Ver(vector);
			printf("\n");
			break;
		case 'c':
			Moda(vector, &posicion, &repetidos);
			printf("\nLa Moda es %d con %d repeticiones\n", vector[posicion], repetidos+1);
			break;
		case 'd':
			Ordenar(vector);
			printf("\nArray Ordenado\n");
			Ver(vector);
			printf("\n");
			break;
		case 'e':
			ParesImpares(vector, &pares, &impares);			
			printf("\nPares = %d \tImpares = %d \n", pares, impares);
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
	
	printf("\nArrays: Moda, Ordenar, Pares\n"); 
	printf("A. Generar Array\n");
	printf("B. Ver Array\n");
	printf("C. Moda de los elementos del array\n");
	printf("D. Ordenar elementos del array\n");
	printf("E. Elementos Pares e Impares del array\n");
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


void Moda (int array[], int *pos, int *rep){
	int i, j, s;
	*rep=0;
	for(i=0;i<TAM;i++){
        s=0;
        for(j=0;j<TAM;j++){
            if(array[i]==array[j] && i!=j){
                s=s+1;
            }               
        }
        if(s>=*rep){
	        *rep=s; //repeticiones (guardamos el mayor por el momento)
	        *pos=i; //posicion
        }
    }
    
}


void ParesImpares(int array[], int *par, int *impar){
	int i=0, aux=0;	
	for(i=0;i<TAM;i++){		
		if(array[i]%2==0){
			aux++;
		}
	}
	*par=aux;
	*impar=TAM-aux;
}


void Ordenar(int array[]){
	int i=0, j=0, temp=0;	
	// Ordenación por algoritmo burbuja
	for (i=1; i<TAM; i++){
       for (j=0; j<TAM-i; j++){
          if (array[j] > array[j+1]){
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
          }
       }
	}
}
