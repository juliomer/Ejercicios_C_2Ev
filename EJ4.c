/* 4º Realizar un  programa que dado un array de 30 elementos de tipo char, resuelva mediante funciones los siguientes apartados:
*  - Copiar: Copiará el array origen en otro llamado destino.
*  - Comparar. Comparará el array origen con otro destino recogido por el usuario y me dirá si son exactamente iguales o no.
*  - Longitud. Me dirá el número de caracteres que tiene el array origen.
*  - Nveces. Me dirá el número de veces que aparece el carácter  en el array origen
*
* char menu();
* void Generar(char array[TAM]);
* void Ver(char array[TAM]);
* void Copiar(char array[TAM],char destino[TAM]);
* int Comparar(char array[TAM],char destino[TAM]);
* int Longitud(char array[TAM]);
* int Nveces(char c,char array[TAM]);
* void parar();
*/

#include <stdio.h>
#include <time.h>

#define TAM 30

/* Prototipos */
char Menu();
void Generar(char array[TAM]);
void Ver(char array[TAM]);
void Copiar(char array[TAM],char destino[TAM]);
int Comparar(char array[TAM],char destino[TAM]);
int Longitud(char array[TAM]);
int Nveces(char c,char array[TAM]);
//void parar();


/* Programa Principal*/
void main(){
	char cadena1[TAM], cadena2[TAM];
	char opcion, buscado;
	
	//Inicializamos
	Generar(cadena1);
	Generar(cadena2);
	
	do{	
		opcion=Menu();		
		switch(opcion){
		case 'a':
			Generar(cadena1);
			printf("\nCadena generada\n");
			Ver(cadena1);
			printf("\n");
			break;
		case 'b':
			Ver(cadena1);
			printf("\n");
			Ver(cadena2);
			printf("\n");
			break;
		case 'c':
			Copiar(cadena1, cadena2);
			Ver(cadena1);
			printf("\n");
			Ver(cadena2);
			printf("\n");
			break;
		case 'd':
			Comparar(cadena1, cadena2)==TAM?printf("\nSon iguales.\n"):printf("\nNo son iguales.\n");
			break;
		case 'e':
			printf("\nLa cadena tiene una longitud de %d caracteres.\n", Longitud(cadena1));
			break;
		case 'f':
			Ver(cadena1);
			printf("\nIntroduce caracter a buscar: ");
			fflush(stdin);
			scanf("%c", &buscado);		
			printf("\nEl caracter %c aparece %d veces en la cadena.\n", buscado, Nveces(buscado, cadena1));
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
	
	printf("\nArrays: Cadenas de Caracteres\n"); 
	printf("A. Generar Cadena de caracteres\n");
	printf("B. Ver Cadenas\n");
	printf("C. Copiar Cadena\n");
	printf("D. Comparar Cadenas\n");
	printf("E. Longitud Cadena\n");
	printf("F. NVeces que se repite caracter en la Cadena\n");
	printf("S. Salir\n");
	printf("Introduce una opcion: ");
	scanf("%c", &op);
	
	return tolower(op);
}


void Generar(char array[]){
	srand((unsigned) time(NULL));
	int i=0;
	for(i=0;i<TAM;i++){
		array[i]=(char)((rand()%26)+65);
	}		
}


void Ver(char array[]){
	int i;
	printf("\nCadena = ");
	for(i=0;i<TAM;i++){
		printf("[%c] ", array[i]);
	}
}


void Copiar(char array[], char destino[]){
	int i=0;
	for(i=0;i<TAM;i++){
		destino[i]=array[i];
	}
	
}


int Comparar(char array[], char destino[]){
	int i=0, cont=0;
	for(i=0;i<TAM;i++){
		if (destino[i]==array[i]){
			cont++;
		}
	}
	return cont;
}


int Longitud(char array[]){
	int i=0, cont=0;
	for(i=0;i<TAM;i++){
		if (array[i]!='\0'){
			cont++;
		}
	}
	return cont;
}


int Nveces(char c, char array[]){
	int i=0, aux=0;
	for(i=0;i<TAM;i++){
		if (c==array[i]) 
			aux++;
	}
	return aux;	
}

