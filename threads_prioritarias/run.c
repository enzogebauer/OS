#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg){
    printf("Oi\n");
    return NULL;
}

void *thread_func2(void *arg){
	int vet[100],ehprimo,i,d;
    //flag de num primo
	ehprimo = 1;
    i = 0;
    d = 2;
	
    //inicializando vetor com int de 0 a 99
	for(int i = 0; i <100; i++){
		vet[i] = i;
	}
	
	for(i = 0; i <100; i++){
        
        //0 e 1 nao sao primos
        if (vet[i] <= 1) ehprimo = 0;

        //mmc
		while(ehprimo == 1 && d <= vet[i]/2){
            //se entrar, nn eh primo
            if(vet[i] % d == 0) {
                ehprimo=0;
            }
            d = d+1; 
        }

        if (ehprimo == 1) printf("%d eh primo\n", vet[i]);
        else printf("%d nao eh primo\n", vet[i]);

        ehprimo=1;
	}
	return NULL;
}

int main(int argc, char **argv){

    pthread_t thread1,thread2,thread3,thread4,thread5;

    const int policy = SCHED_RR;
    struct sched_param param;

    param.sched_priority = 20;
    pthread_create(&thread1,pthread_setschedparam(thread1,policy,&param),thread_func,NULL);
    param.sched_priority = 10;
    pthread_create(&thread2,pthread_setschedparam(thread2,policy,&param),thread_func2,NULL);
    
    printf("Thread principal a esperar a terminação das threads criadas \n");

    //aguardar todas threads 
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    
    return 0;
}


/*
Guarda informação sobre a thread criada. 
Especifica algumas propriedades da thread a criar. 
A função que a nova thread vai executar. 
Representar argumentos a esta função.

pthread_create(&thread,NULL,thread_func,NULL);
*/

