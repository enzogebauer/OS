#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <sched.h>

void *thread_func(void *arg)
{
    srand(time(NULL)); // Seed para a função rand()

    int vetor[5] = {5, 2, 9, 1, 5}; // Exemplo de vetor para ordenação

    // Bogo Sort
    while (!is_sorted(vetor, 5))
    {
        shuffle(vetor, 5);
    }

    printf("Vetor ordenado usando Bogo Sort: ");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return NULL;
}

// Função para verificar se o vetor está ordenado
bool is_sorted(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Função para embaralhar o vetor aleatoriamente
void shuffle(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int j = rand() % size;
        // Troca arr[i] com arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void *thread_func2(void *arg)
{
    int vet[100], ehprimo, i, d, tamanho_vet;
    // flag de num primo, 0 -> falso e 1 -> verdadeiro
    ehprimo = 1;
    tamanho_vet = 50;

    // inicializando vetor com int de 0 a 99
    for (i = 0; i < tamanho_vet; i++)
    {
        vet[i] = i;
    }

    for (i = 0; i < tamanho_vet; i++)
    {

        // 0 e 1 nao sao primos e nem divisiveis por 2
        if (vet[i] <= 1 || vet[i] != 2 && vet[i] % 2 == 0)
            ehprimo = 0;

        d = 3;
        // mmc
        while (ehprimo == 1 && d <= (vet[i]) / 2)
        {
            // se entrar, nn eh primo
            if ((vet[i]) % d == 0)
                ehprimo = 0;
            d = d + 2;
        }

        if (ehprimo == 1)
            printf("%d eh primo\n", vet[i]);
        else
            printf("%d nao eh primo\n", vet[i]);

        ehprimo = 1;
    }
    return NULL;
}
void *thread_func3(void *arg)
{
    int num = *(int *)arg;

    if (num % 2 == 0)
    {
        printf("%d eh um numero par.\n", num);
    }
    else
    {
        printf("%d eh um numero impar.\n", num);
    }

    return NULL;
}

void *thread_func4(void *arg)
{
    int num = *(int *)arg;
    int fatorial = 1;

    for (int i = 1; i <= num; ++i)
    {
        fatorial *= i;
    }

    printf("O fatorial de %d eh %d.\n", num, fatorial);

    return NULL;
}
void *thread_func5(void *arg)
{
    int num = *(int *)arg;

    if (num > 0)
    {
        printf("%d eh um numero positivo.\n", num);
    }
    else if (num < 0)
    {
        printf("%d eh um numero negativo.\n", num);
    }
    else
    {
        printf("%d eh zero.\n", num);
    }

    return NULL;
}
int main(int argc, char **argv)
{

    pthread_t threads[10];
    sched_param param1, param2, param3, param4, param5;

    // Record the start CPU time
    clock_t start_time = clock();

    param1.sched_priority = 1;
    pthread_create(&(threads[0]), NULL, thread_func, NULL);
    pthread_setschedparam(threads[0], SCHED_RR, &param1);

    param2.sched_priority = 50;
    pthread_create(&(threads[1]), NULL, thread_func2, NULL);
    pthread_setschedparam(threads[1], SCHED_RR, &param2);

    param3.sched_priority = 40;
    pthread_create(&(threads[2]), NULL, thread_func3, NULL);
    pthread_setschedparam(threads[2], SCHED_RR, &param3);

    param4.sched_priority = 30;
    pthread_create(&(threads[3]), NULL, thread_func4, NULL);
    pthread_setschedparam(threads[3], SCHED_RR, &param4);

    param5.sched_priority = 20;
    pthread_create(&(threads[4]), NULL, thread_func5, NULL);
    pthread_setschedparam(threads[4], SCHED_RR, &param5);

    // printf("Thread principal a esperar a terminação das threads criadas \n");

    // aguardar todas threads
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);
    pthread_join(threads[4], NULL);

    // Record the end CPU time
    clock_t end_time = clock();

    // Calculate and print the elapsed CPU time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

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
