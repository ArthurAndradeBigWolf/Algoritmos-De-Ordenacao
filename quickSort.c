#include<stdlib.h>
#include<stdio.h>

//Assinaturas da função
int partition(int *vetor, int p, int u, FILE*arquivo);
void troca(int *a, int *b);
void quicksort(int *vetor, int p, int u, FILE*arquivo);

int main(int argc, char const *argv[])
{
    int vetor[] = {2,8,7,1,3,5,6,4};
    int n = sizeof(vetor)/4;
    FILE *arquivo;

    arquivo = fopen("dadosQuick.csv", "w");

    fputs("Vetor que vai ser ordenado >> ",arquivo);

    for(int i = 0; i< n ; i++){
     fprintf(arquivo,"%d, ", vetor[i]);   
    }

    fputs("\n", arquivo);


    //ORDENANDO
    quicksort(vetor,0, n - 1,arquivo);

    
    fputs("Vetor ordenado >>> ",arquivo);
    for(int t = 0; t<n ; t++){
        fprintf(arquivo,"%d, ", vetor[t]);
    }
    fputs("\n",arquivo);

    fclose(arquivo);
    return 0;
}


void quicksort(int *vetor, int p, int u, FILE*arquivo){
    
    //CASO BASE DA RECURSÃO
    if(p<u){
        fputs("Realizando partition....\n",arquivo);
        int q = partition(vetor,p,u,arquivo);
        quicksort(vetor,p,q-1,arquivo);
        quicksort(vetor,q+1,u,arquivo);        
    }

}

//FUNÇÃO DE PARTITION
int partition(int *vetor, int p, int u, FILE*arquivo){
    int pivo, i;
    pivo = vetor[u];
    i = p - 1;

    fprintf(arquivo," PIVO >> | %d |\n",pivo);

    for(int j = p; j <= u - 1; j++){

            if(vetor[j] <= pivo){
                i++;
                fprintf(arquivo,"Troca %d com %d...\n",vetor[i],vetor[j]);
                //TROCA
                troca(&vetor[i], &vetor[j]);
            }
            
            for(int k = 0; k<8; k++){
                fprintf(arquivo,"%d, ", vetor[k]);
            }

            fputs("\n",arquivo);

        }

        //MOVIMENTANDO O PIVO
        fputs("TROCANDO PISO COM O DA FRENTE DO MENOR...",arquivo);
        fprintf(arquivo,"PIVO INDO PRO INDEX %d",i);
        fputs("\n",arquivo);

        troca(&vetor[i+1],&vetor[u]);
        return (i + 1);
    }
  

//TROCA AS POSIÇÕES
void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


