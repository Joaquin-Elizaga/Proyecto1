#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define LIMITE 6

//Estructura de la cache

typedef struct T_LINEA_CACHE{
	short int etq;
	short int datos[8];
}T_LINEA_CACHE;


//Inicio las funciones que voy a utilizar

void ComienzoCache(T_LINEA_CACHE* T_LINEA_CACHE);
void abrirRamFile(T_LINEA_CACHE* T_LINEA_CACHE);
int LecturaAccesoMemorias(int direccionBin);
void asignar();

int main(int argc, char* argv[]){
	
	//Inicializamos las variables	
		T_LINEA_CACHE T_LINEA_CACHE[4];
		int tiempoglobal = 0, numfallos = 0;
		int direccion, palabra, linea, etiqueta, bloque, dato, direccionBin;
	
	
	//Funcion para el comienzo de la cache
		ComienzoCache(T_LINEA_CACHE);
	

	//Funcion para Abrir y leer el archivo 'RAM.bin'
		abrirRamFile(T_LINEA_CACHE);
	
	
	//Abrimos el fichero 'accesos_memoria.txt'
		FILE *fichero_direcciones = fopen("accesos_memoria.txt", "r");  
		printf( "\n\nLeyendo el fichero 'accesos_memoria.txt'...\n" );
		sleep(2);
	
	//Comprobamos si se puede acceder al fichero
		if (fichero_direcciones == NULL) { 		
			//Si el fichero no existe, printea...						 
				printf( "\n\tNo se puede acceder al fichero 'accesos_memoria.txt'. \n Saliendo...\n" );
				exit( -1 );
		}
	
	//Le Pasamos la variable "direccionBin" a la funcion "LecturaAccesoMemoria"
		LecturaAccesoMemorias(direccionBin);
	
	//Cerramos el fichero
		if (fclose(fichero_direcciones)!= 0){ 							 
			//Si el valor es distinto de 0, printea...
				printf("\n\n\tHa habido un error al fichero 'accesos_memoria.txt'. \n Saliendo...\n");
				exit( -1 );
		}
		//Si el valor es 0 entonces se lee correctamente
		else{
			printf("\tFichero 'accesos_memoria.txt' leido correctamente.\n");
			sleep(2);
		}

	//Direccion es igual a al valor de la funcion "lecturaAccesoMemoria" cuando le pasas "direccionBin"
		direccion = LecturaAccesoMemorias(direccionBin); 

	//Funcion que asigna la palabra, linea y etiqueta
		asignar();
	
	
	//Menu de acierto y de fallo
		printf("\n\n Comparando la etiqueta de la cache y la etiqueta de la direccion de memoria...\n");
		sleep(2);
	
	
		if(T_LINEA_CACHE[0].etq == etiqueta){
			printf("\tT: %d  Acierto de CACHE  ADDR %04X  ETQ %X  Linea %02X  Palabra %02X  DATO %02X\n", tiempoglobal, direccion, etiqueta, linea, palabra, dato);
		}
		else{
			tiempoglobal =+ 10;
			numfallos++;
			printf("\tT: %d  Fallo de CACHE %d  ADDR %04X  ETQ %X  Linea %02X  Palabra %02X  bloque %02X\n", tiempoglobal, numfallos, direccion, etiqueta, linea, palabra, bloque);
		}
		
		return 0;
		
}


	//Funcion que asigna la palabra, linea y etiqueta a cada direccion de memoria del fichero 'accesos_memoria.txt'
		void asignar(){	

		int direccion, palabra, linea, etiqueta, bloque;
	
	
	//Lo que ocupa cada mascara(campo)
		palabra = direccion & 0b111;
		linea = (direccion & 0b11)>>3;
		etiqueta = (direccion & 0b11111)>>5;
	
		bloque = etiqueta + linea;
}


	//Funcion para inicializar la cache (ETQ y Datos iguales a FF y 0)
		void ComienzoCache(T_LINEA_CACHE* T_LINEA_CACHE){
	
		int x, i;
		printf("Comienzo de la cache:");
		sleep(2);
		
			for(x=4; x>0; x--){
			T_LINEA_CACHE[x].etq = 0XFF;
			printf("\nETQ: %X  Data", T_LINEA_CACHE[x].etq);
		
			for(i=8; i>0; i--){
				T_LINEA_CACHE[x].datos[i] = 0;
				printf(" %02X", T_LINEA_CACHE[x].datos[i]);		
			}
		}	
}


	//Funcion que abre y lee el fichero 'RAM.bin'
		void abrirRamFile(T_LINEA_CACHE* T_LINEA_CACHE){
	
	//Apertura del fichero para lectura
		FILE *fichero_ram = fopen("RAM.bin", "r"); 		
		printf("\n\nLeyendo el fichero 'RAM.bin'...\n");
		sleep(2);	
	
	//Comprobacion del fichero abierto 
		if (fichero_ram == NULL) { 					
			printf( "\n\tNo se puede abrir el fichero 'RAM.bin'. Saliendo...\n" );
			exit( -1 );
		}
	
	//Declaro el array en el que guardaré el contenido del fichero RAM.bin
		unsigned char ram[1024]; 						
		ram[1024] = getc(fichero_ram);	
		
	//Comprobación de fin de fichero. Si esta en 0 (no ha acabado), sigue leyendo
		while (feof(fichero_ram) == 0) { 	 
		//ram = contenido del documento
			ram[1024] = getc(fichero_ram); 		
	
	//cierre de fichero	
		if (fclose(fichero_ram)!= 0){ 				
			printf( "\n\n\tProblemas al cerrar el fichero 'RAM.bin'. Saliendo...\n" );
			exit( -1 );
		}
		
		else{
			printf("\tFichero 'RAM.bin' leido correctamente.\n");
			sleep(2);
		}	
	}


	//Funcion que lee el fichero 'accesos_memira.txt' 
		int LecturaAccesoMemorias(int direccionBin){
	
		FILE *fichero_direcciones = fopen("accesos_memoria.txt", "r");
		char direccion_memoria[4];
		
		while(fgets(direccion_memoria, 6, (FILE*) fichero_direcciones)){
		//printf("%s --> Binario: ", direccion_memoria);
		direccionBin = strtol(direccion_memoria, NULL, 16);
		//printf ("%d\n", direccionBin);
		}
}





