//SEM MUTEX

#include <windows.h>
#include <stdio.h>

#define NUM_THREADS 100

int global = 0;

DWORD WINAPI incrementa(void *args){
	int a;
	a = global;
	a++;
	Sleep(100);
	global = a;
	printf("global = %d\n", global);
}

DWORD WINAPI decrementa(void *args){
	int a;
	a = global;
	a--;
	Sleep(100);
	global = a;
	printf("global = %d\n", global);
}

int main(){
	
	//disparada de 200 threads
	for (int i = 0; i < NUM_THREADS; i++){
		//dispara 100 threads do incrementa
		CreateThread(NULL, 0, incrementa, NULL, 0, NULL);
		//dispara 100 threads do decrementa
		CreateThread(NULL, 0, decrementa, NULL, 0, NULL);
	}
	SuspendThread(GetCurrentThread());

	return 0;
}