//COM MUTEX

#include <windows.h>
#include <stdio.h>

#define NUM_THREADS 10

int global = 0;
HANDLE mutex;

DWORD WINAPI  incrementa(void *args){
	WaitForSingleObject(mutex, INFINITE);
	int a;
	a = global;
	a++;
	Sleep(100);
	global = a;
	printf("a = %d\n", a);
	ReleaseSemaphore(mutex, 1, NULL);
}

DWORD WINAPI decrementa(void *args){
	WaitForSingleObject(mutex, INFINITE);
	int a;
	a = global;
	a--;
	Sleep(100);
	global = a;
	printf("a = %d\n", a);
	ReleaseSemaphore(mutex, 1, NULL);
}

int main(){
	mutex = CreateSemaphore(NULL, 1, 1, NULL);
	
	if (mutex == NULL){
		printf("Erro ao criar o semaforo: %d\n", GetLastError());
		return 1;
	}
	
	for (int i = 0; i < NUM_THREADS; i++){
		CreateThread(NULL, 0, incrementa, NULL, 0, NULL);
		CreateThread(NULL, 0, decrementa, NULL, 0, NULL);
	}
	
	SuspendThread(GetCurrentThread());
	CloseHandle(mutex);
	return 0;
}