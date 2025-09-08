#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definição de Constantes
#define TAM_NOME 30
#define TAM_COR 10

//Definição de estruturas

struct Territorio {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
};


//Definição das funções
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Utilidades
void pressioneEnter(){
    printf("\nPressione Enter para continuar...");
}

void cadastrarTerritorio(int numTerritorios, struct Territorio* mapa){

    printf("===================================\n");
    printf("  CADASTRO DE %d TERRITÓRIOS   \n", numTerritorios);
    printf("===================================\n");
      

    for(int i = 0; i < numTerritorios; i++){
        printf("-----------------------\n");
        printf("TERRITÓRIO %d\n", i+1 );
        printf(" - Nome: ");
        fgets(mapa[i].nome, TAM_NOME,stdin);
        printf(" - Cor: ");
        fgets(mapa[i].cor, TAM_COR,stdin);

        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';
        
        printf(" - Tropas: ");
        scanf("%d", &mapa[i].tropas);

        limparBufferEntrada();
    }

    printf("Territórios cadastrados com sucesso!\n");
    limparBufferEntrada();
    pressioneEnter();
    getchar();

}

void atualizarCampos(){

}

void atacar(struct Territorio* atacante, struct Territorio* defensor){


}

//Função para o cadastro dos territórios
void listarTerritorios(int tamMapa, struct Territorio *mapa){
    printf("===================================\n");
    printf("  MAPA DO MUNDO - ESTADO ATUAL   \n");
    printf("===================================\n");
    
    for(int i = 0; i < tamMapa; i++){
        printf("-----------------------\n");
        printf("TERRITÓRIO %d\n", i+1);
        printf(" - Nome: %s\n", mapa[i].nome);
        printf(" - Cor: %s\n", mapa[i].cor);
        printf(" - Tropas: %d\n\n", mapa[i].tropas);
    }

    limparBufferEntrada();
}

int main()
{
    struct Territorio* mapa = (struct Territorio *)calloc(2, sizeof(struct Territorio));
    cadastrarTerritorio(2, mapa);
    listarTerritorios(2, mapa);
    free(mapa);
    return 0;

}