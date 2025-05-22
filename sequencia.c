#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ProcuraFaltante(int * arr, int ini, int fim);
int * EntradaSequencia(int * tamRef);
clock_t inicio;
clock_t fim;

int main(){
    int tam = 0;
    printf("Entrando com dados...\n");
    int * Sequencia = EntradaSequencia(&tam);
    printf("Terminada a entrada, procurando o faltante...\n");
    inicio = clock();
    int faltando = ProcuraFaltante(Sequencia, 0, tam -1);
    fim = clock();
    free(Sequencia);

    double tempoExecEmMs = (((double)(fim - inicio))/CLOCKS_PER_SEC) * 1000;
    if(faltando == -1)
    {
        printf("A sequencia inserida nao possui um numero omisso\n");
        exit(0);
    }
    printf("\n\nO numero faltando é: %i\n, o programa demorou %0.4lfms para encontrar\n\n", faltando, tempoExecEmMs);
    return 0;
}

int * EntradaSequencia(int * tamRef){
    int tam;
    scanf("%i", &tam);
    if(tam < 1){
        printf("O tamanho da sequencia precisa ser de no minimo 1 digito\n");
        exit(1);
    }

    int * ptr = malloc(sizeof(int) * tam);
    for(int i = 0; i<tam; i++){
        scanf("%i,", &ptr[i]);
    }
    *tamRef = tam;
    return ptr;
}

int ProcuraFaltante(int * arr, int ini, int fim){
    if(ini > fim) return -1;
    int meio = ini + (fim - ini)/2;
    if(arr[meio] == 1 + meio)
    {
        return ProcuraFaltante(arr, meio + 1, fim);
    }
    else
    {
        if(meio == 0 || arr[meio - 1] == 1 + (meio - 1)) return 1 + meio;
        return ProcuraFaltante(arr,  ini, meio);
    }
}

