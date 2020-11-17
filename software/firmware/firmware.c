//#include "stdlib.h"
#include "system.h"
#include "periphs.h"
#include "iob-uart.h"

int main()
{

int i = 0;//iterador
int media = 0;
int acumulador = 0;
int valor_random = 0;//guarda valor random gerado
int n_valores_processados = 0;

  //init uart 
  uart_init(UART_BASE,FREQ/BAUD);   
  
  for(i=1; i<= 100; i++){//i=1, (...), i=100
     	valor_random = rand() % 20;//recebe 1 valor random entre 0 e 20 (pra nao ocorrer overflow)
     	//uart_printf(" %d \n", valor_random);
     	
	acumulador += valor_random;
	n_valores_processados++;
		
     }
     media = acumulador / n_valores_processados;
     
  uart_printf("Media truncada: %d\n", media);
  //char *a = malloc(10);
  //free(a);
}
