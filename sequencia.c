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
    if(faltando == 1<<31)
    {
        printf("A sequencia inserida nao possui um numero omisso\n");
        exit(0);
    }
    printf("\n\nO numero faltando é: %i\n, o programa demorou %0.4lfms para encontrar\n\n", faltando, tempoExecEmMs);
    return 0;
}

int * EntradaSequencia(int * tamRef){
    int tam;
    // printf("Qual o tamanho da sequencia? (Tamanho minimo é 2)\n");
    scanf("%i", &tam);
    if(tam < 2){
        printf("O tamanho da sequencia precisa ser de no minimo 2 digitos\n");
        exit(1);
    }

    int * ptr = malloc(sizeof(int) * tam);
    // printf("Digite a sequencia de digitos onde falta um digito\n");
    for(int i = 0; i<tam; i++){
        scanf("%i,", &ptr[i]);
    }
    *tamRef = tam;
    return ptr;
}

// int * EntradaSequenciaFile(int *tamRef){
//     FILE * 
// }

int ProcuraFaltante(int * arr, int ini, int fim){
    if(ini > fim) return 1 << 31;
    int meio = ini + (fim - ini)/2;
    if(arr[meio] == arr[0] + meio)
    {
        return ProcuraFaltante(arr, meio + 1, fim);
    }
    else
    {
        if(arr[meio - 1] == arr[0] + (meio - 1)) return arr[0] + meio;
        else return ProcuraFaltante(arr,  ini, meio);

    }
}

