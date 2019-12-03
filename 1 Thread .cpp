#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <conio.h>
#include <time.h>
 
 
  
void matriz(int num){  
//Declara variáveis
int matriz[num][num], li ,co, cont=0;
	
	//Dá valor cada posição da matriz
	for(li = 0; li < num; li ++){
		for(co = 0; co < num; co ++){
			matriz[li][co] = 10;
			//soma da diagonal principal
			if(co == li){
				cont += matriz[li][co];
			}
		}
	}	

	//Exibe na tela valor de cada posição
	for(li = 0; li < num; li ++){
		for(co = 0; co < num; co ++){
			printf("Matriz [%d][%d] = %d \n ", li, co, matriz[li][co]);
		}
		printf("\n");
	}
	
	//Exibe na tela 
	printf("Soma da diagonal principal: %d",cont);
}
 
  
void par_impar(int n) 
{ 
	//Delcara Variáveis
    int  i, j, soma = 0, q=0;
	
	//função para exibir se o número é par ou impar e a quantidade de divisores do número
	for (i = n ; i > 0 ; i --) {
        q=0;	
		if(i%2==0)//operador %
		{
		printf("\n O numero %d eh par\n", i);
		soma+= i;
		}
		else
		printf("\n O numero %d eh impar\n", i);
		
		for(j = 1; j <= i; j ++){
			if(i % j ==0){
				q++;	
			}
		}
		//Exibe na tela a quantidade de divisores do número
		printf("\n quantidade de divisores do numero %d : %d\n", i,q);
	}
	
	//Exibe na tela a soma de todos os números pares
	printf("\n Soma de todos os pares: %d\n", soma);
} 


//define máximo para a fatoração
#define MAX 500000 
  
//declara variáveis 
int mult(int x, int res[], int resp); 
  
void fatorial(int n) 
{ 
	
    int res[MAX]; 
  
    res[0] = 1; 
    int resp = 1; 
  	int x;
  	//Aplica a fórmula de Fatoração
    for (x=2; x<=n; x++) 
        resp = mult(x, res, resp); 
  
  	int i;
    
    for (i=resp-1; i>=0; i--) 
        printf("%d\n", res[i]); 
} 
   
int mult(int x, int res[], int resp) 
{ 
	//Declara variáveis
    int tranp = 0, i;
    
    //multiplica o X pelo número
    for (i=0; i<resp; i++) 
    { 
        int prod = res[i] * x + tranp; 
        //armazena o último digiro em res[i]
        res[i] = prod % 10;   
        //coloca o resto na transp
        tranp  = prod/10;     
    } 
  	//Aumenta o tamanho do resultado
    while (tranp) 
    { 
        res[resp] = tranp%10; 
        tranp = tranp/10; 
        resp++; 
    } 
    return resp; 
} 

//Inicia rotinas
void * routine(void *arg);

int main (int argc, char *argv[])
{
	pthread_t thread_idA;
 	
	void * thread_res;
 	int rstatus;
 
 	//inicia contagem do tempo
 	clock_t Tempo[2];
	double Calculo_Tempo;
    Tempo[0] = clock();
 
 	//Inicia thread e indica a função 
 	rstatus = pthread_create (&thread_idA, NULL, routine, (void*)("Thread A"));
 	//Finaliza Thread
	rstatus = pthread_join (thread_idA, &thread_res);
	
	//Fim do calculo do tempo e exibe na tela o tempo de execução
	Tempo[1] = clock();
    Calculo_Tempo = (Tempo[1] - Tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\n");
	printf("Tempo de execucao: %g ms.", Calculo_Tempo);
 
 return 0;
}
 
void * routine(void *arg)
{	
	//Chama rotinas
	matriz(500);
	par_impar(2500);
	fatorial(25000);
	fatorial(50000);
 	pthread_exit(arg);
}

