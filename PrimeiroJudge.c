#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_PILHA 50
#define MAX_FILA 50

/// PILHA
typedef struct{
    int ID[MAX_PILHA];
    int topo;
}TPilha;

TPilha *Inicia_TPilha(){
    TPilha* MinhaPilha=(TPilha*)malloc(sizeof(TPilha));
    MinhaPilha->topo = -1;
    return MinhaPilha;
}


int Verifica_Cheia(TPilha*MinhaPilha){
    return (MinhaPilha->topo >= MAX_PILHA-1);
}

int Push(TPilha *MinhaPilha, int x){
    if( Verifica_Cheia(MinhaPilha) ){
        printf("Pilha Cheia.");
        return -1;
    }
        MinhaPilha->topo++;
        MinhaPilha->ID[MinhaPilha->topo]=x;
        return 0;
}

int Verifica_Vazio(TPilha *MinhaPilha){
    return (MinhaPilha->topo < 0);
}

int Pop(TPilha *MinhaPilha,int *aux){
    if( Verifica_Vazio(MinhaPilha) ){
        printf("Pilha Vazia.");
        return -1;
    }
        *aux = MinhaPilha->ID[MinhaPilha->topo];
        MinhaPilha->topo--;
        return 0;
}

int Desaloca(TPilha *MinhaPilha){
    free(MinhaPilha);
    return 0;
}

/// FILA
typedef struct{
    int RA;
    char Nome[20];
}Info;

typedef struct{
    Info Itens[MAX_FILA];
    int n;
    int ini;
}TFILA;

TFILA *Cria_Fila(){
    TFILA *MinhaFila = (TFILA*)malloc(sizeof(TFILA));
    MinhaFila->ini = 0;
    MinhaFila->n=0;
    return MinhaFila;
}

int Insere_Fila(TFILA *MinhaFila,char nome[],int ra){
    int fim;
    if(MinhaFila == NULL){
        printf("Fila nao inicializada.");
        return -1;
    }
    if(MinhaFila->n == MAX_FILA){
        printf("Fila Cheia.");
        return -1;
    }
    fim = (MinhaFila->n+MinhaFila->ini)%MAX_FILA;
    MinhaFila->Itens[fim].RA = ra;
    strcpy(MinhaFila->Itens[fim].Nome,nome);
    MinhaFila->n++;

    return 0;
}

int retira(TFILA *MinhaFila,Info aux){
    if(MinhaFila == NULL){
        printf("Nao alocada.");
        return -1;
    }
    if(MinhaFila->n==0){
        printf("Fila Vazia.");
        return -1;
    }
    aux = MinhaFila -> Itens[MinhaFila->ini];
    MinhaFila->ini = (MinhaFila->ini+1)%MAX_FILA;
    MinhaFila->n--;
    return 0;
}

void ListarElemento(TFILA *MinhaFila, int i){
    printf("%d ",MinhaFila->Itens[i].RA);
    printf("%s\n",MinhaFila->Itens[i].Nome);
}

void ListagemCompleta(TFILA *MinhaFila){
        int i;
        for(i=MinhaFila->ini ; i != (MinhaFila->n+MinhaFila->ini)%MAX_FILA ; i=(i+1)%MAX_FILA){
            ListarElemento(MinhaFila,i);
        }
}

void LiberaFila(TFILA *MinhaFila){
    free(MinhaFila);
}

int main(){
    /// Variaveis
    int N,M,P,i,j;
    //int *X;
    int RA,ID,vet[100];
    char Nome[20];

    /// TAD's
    TPilha *MinhaPilha = Inicia_TPilha();
    TFILA *PFila =  Cria_Fila();

    /// Judge
   // X=(int*)malloc(P*sizeof(int));

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d",&RA);
        gets(Nome);
        Insere_Fila(PFila,Nome,RA);
    }

    scanf("%d",&M);

    for(i=0;i<M;i++){
        scanf("%d",&ID);
        Push(MinhaPilha,ID);
    }

    scanf("%d",&P);
    for(i=0;i<P;i++){
        scanf("%d",&vet[i]);
        //*X = vet[i];
        for(j=0;j<M;j++){
            if(MinhaPilha->ID[M-(j+1)] == vet[i]){
                ListarElemento(PFila,j);
            }
        }
    }

    Desaloca(MinhaPilha);
    LiberaFila(PFila);
    //free(X);
    return 0;
}
