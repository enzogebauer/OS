#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg){
    for(int i = 0; i < 10; i++) printf("Oi\n");
    return NULL;
}

void *thread_func2(void *arg){
	int vet[100],ehprimo,i,d;
    //flag de num primo, 0 -> falso e 1 -> verdadeiro
	ehprimo = 1;
	
    //inicializando vetor com int de 0 a 99
	for(i = 0; i <100; i++){
		vet[i] = i;
	}
	
	for(i = 0; i <100; i++){
        
        //0 e 1 nao sao primos e nem divisiveis por 2
        if (vet[i] <= 1 || vet[i] != 2 && vet[i] % 2 == 0) ehprimo = 0;

		d = 3;
        //mmc
		while(ehprimo == 1 && d <= (vet[i])/2){
            //se entrar, nn eh primo
            if((vet[i]) % d == 0) ehprimo=0;
            d = d + 2; 
        }

        if (ehprimo == 1) printf("%d eh primo\n", vet[i]);
        else printf("%d nao eh primo\n", vet[i]);
        
        ehprimo=1;
	}
	return NULL;
}

int main(int argc, char **argv){

    pthread_t threads[10];
    sched_param param1,param2;

    param1.sched_priority = 50;
    pthread_create(&(threads[0]),NULL,thread_func,NULL);
    pthread_setschedparam(threads[0],SCHED_RR,&param1);
    
    param2.sched_priority = 1;
    pthread_create(&(threads[1]),NULL,thread_func2,NULL);
    pthread_setschedparam(threads[1],SCHED_RR,&param2);
    
    //printf("Thread principal a esperar a terminação das threads criadas \n");

    //aguardar todas threads 
    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);
    
    return 0;
}


/*
Quando se cria 2 ou + threads (ou rotinas), eles serao executados de forma paralela.
Ou seja, se vc criou 2 threads que executara um loop de 0 a 5. A execucao sera:
0,0,1,1
Sem as threads:
0,1,2,3,4,5,0,1,2,3,4,5

Guarda informacaoo sobre a thread criada. 
Especifica algumas propriedades da thread a criar. 
A funcao que a nova thread vai executar. 
Representar argumentos a esta funcao.

pthread_create(&thread,NULL,thread_func,NULL);

Aguardar a execucao de todas as threads;
pthread_join(threads[0],NULL);
*/

