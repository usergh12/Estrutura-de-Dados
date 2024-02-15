#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DECLARANDO ESTRUTURA DOS ELEMENOS A SEREM ORDENADOS NO VETOR
struct Vetor
{
    int chave;
    float real;
};
typedef struct Vetor estrutura_vetor;

void shellsort(estrutura_vetor* vetor,int tamanho){
    int i, j, h;
    estrutura_vetor aux;
    for(h = 1; h < tamanho; h = 3 *h+1);
    while(h>0){
      h = (h-1)/3;
      for( i = h; i< tamanho;i++){
        aux = vetor[i];
        j = i;
        while(vetor[j-h].chave < aux.chave){
            vetor[j] = vetor[j-h];
            j -= h;
            if( j < h) break;
        }
        vetor[j]=aux;
      }
    }
}

void merge(estrutura_vetor* vetor, int ini, int meio,int fim,int tamanho){
    int i,j,k;
    estrutura_vetor * aux = (estrutura_vetor*)malloc(tamanho*sizeof(estrutura_vetor));
    i = ini;
    j = meio+1;
    k = ini;

    while(i<=meio && j<=fim){
        if(vetor[i].chave > vetor[j].chave){
            aux[k]=vetor[i];
            i++;
        }
        else{
            aux[k] = vetor [j];
            j++;
        }
        k++;
    }
    while(i<=meio){
        aux[k] = vetor[i];
        i++;
        k++;
    }

    while(j<=fim){
        aux[k]=vetor[j];
        j++;
        k++;
    }

    for(i=ini; i<=fim;i++){
        vetor[i]=aux[i];
    }

    free(aux);
}

void merge_sort(estrutura_vetor* vetor, int ini, int fim, int tamanho){
    int meio;
    if(ini < fim){
    meio = (ini+fim)/2 ;
    merge_sort(vetor,ini,meio,tamanho);
    merge_sort(vetor,meio+1,fim,tamanho);
    merge(vetor,ini,meio,fim,tamanho);
    
    }
}

//FUN��O TESTE
void imprime_teste (estrutura_vetor *v,int tamanho)
{
    for (int i=0;i<tamanho;i++)
    {
        printf ("\nChave [%d] = %d",tamanho,v[i].chave);
        printf ("\nReal [%d] = %f",tamanho,v[i].real);
    }
}
// FUN��O QUICK PARTE 2
int particao(estrutura_vetor *v,int LI, int LS)
{
    int aux;
    int e = LI;
    int d = LS;
    int pivo = v[LI].chave;

    while (e < d)
    {
        while((v[e].chave >= pivo) && (e < LS))
        {
            e++;
        }

        while((v[d].chave < pivo) && (d > LI))
        {
            d--;
        }

        if(e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave = aux;
        }
    }
        aux = v[LI].chave;
        v[LI].chave = v[d].chave;
        v[d].chave = aux;

    return d;
}

// FUN��O QUICK PARTE 1
void quicksort(estrutura_vetor *v, int LI, int LS)
{
    if(LI < LS)
    {
        int p,i;

        p = particao(v,LI,LS);

        quicksort(v,LI,p-1);
        quicksort(v,p+1,LS);
    }
}

// FUN��O PARA CRIAR O VETOR
void cria_vetor(estrutura_vetor *vetor, int seed, int tamanho)
{
    clock_t start_time, end_time; // Cronometro
    double elapsed_time;          // Cronometro
    int opcao;

    // Gerando Conjunto de Numeros aleat�rios de acordo com a seed (raz�o = 10) - FORMA 1s
    for(seed = 10; seed <= 100; seed += 10)
    {
        // Gernando valores aleat�rios
        srand(seed);

        // Preenchendo o vetor - Forma 1
        for (int i = 0; i < tamanho; i++)
        {
            vetor[i].chave = rand()% 101;
            vetor[i].real = 100.0 + (float)rand() / RAND_MAX * (1000.0 - 100.0);
        }

        printf ("FORMA 1\n\nVetor de Tamanho = %d \nSemente = %d \nEscolha o metodo de ordenacao: ",tamanho,seed);
        printf ("\n\n[1]. QuickSort",tamanho);

        do
        {
            printf ("\n\nOpcao: ");
            opcao = 0;
            scanf  ("%d",&opcao);
        }while(opcao<1 || opcao>1);

        switch(opcao)
        {
            case 1:
                printf ("\n--------------- STATUS ---------------");
                start_time = clock();
                quicksort(vetor,0,tamanho-1);
                end_time = clock();
                elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                printf("\nTEMPO DE EXECUCAO EM MILISEGUNDOS:%0.2f", elapsed_time*1000000);
                printf("\nTEMPO DE EXECUCAO EM SEGUNDOS:%f \n--------------------------------------\n\n", elapsed_time);
            break;
        }

    }

    // FORMA 2
    for(seed = 10; seed <= 100; seed += 10)
    {
        // Gernando valores aleat�rios
        srand(seed);

        // Preenchendo o vetor - Forma 1
        for (int i = 0; i < tamanho; i++)
        {
            if(i!=0)
                vetor[i].chave = vetor[i-1].chave + (rand()% 101);
            else
                vetor[i].chave = rand()% 101;
            vetor[i].real = 100.0 + (float)rand() / RAND_MAX * (1000.0 - 100.0);
        }

        printf ("FORMA 2\n\nVetor de Tamanho = %d \nSemente = %d \nEscolha o metodo de ordenacao: ",tamanho,seed);
        printf ("\n\n[1]. QuickSort",tamanho);

        do
        {
            printf ("\n\nOpcao: ");
            opcao = 0;
            scanf  ("%d",&opcao);
        }while(opcao<1 || opcao>1);

        switch(opcao)
        {
            case 1:
                printf ("\n--------------- STATUS ---------------");
                start_time = clock();
                quicksort(vetor,0,tamanho-1);
                end_time = clock();
                elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                printf("\nTEMPO DE EXECUCAO EM MILISEGUNDOS:%0.2f", elapsed_time*1000);
                printf("\nTEMPO DE EXECUCAO EM SEGUNDOS:%f \n--------------------------------------\n\n", elapsed_time);
            break;
        }

    }

}

// FUN��O PRINCIPAL
int main()
{
    // Declarando vari�veis
    clock_t start_time, end_time; // Cronometro
    double elapsed_time;          // Cronometro
    unsigned int seed;            // Semente
    estrutura_vetor *vetor_1;     // Vetor de tamanho 10 000

    // Alocando Dinamicamente
    vetor_1 = (estrutura_vetor *)malloc(10000 * sizeof(estrutura_vetor));

    // Chamando a fun��o para criar o vetor
    cria_vetor(vetor_1,seed,10000);

    return 0;
}
