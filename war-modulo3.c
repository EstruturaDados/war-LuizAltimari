#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constantes

#define TAM_NOME 30
#define TAM_COR 10


// Definição das estruturas

struct Territorio {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
};

// Protótipo das funções

void atacar(struct Territorio *atacante, struct Territorio *defensor);
void liberarMemoria(struct Territorio *atacante, struct Territorio *defensor, struct Territorio *mapa);
void limparBufferEntrada();
void pressioneEnter();
void cadastrarTerritorio(struct Territorio* mapa);
void listarTerritorios(struct Territorio* mapa);
void exibirCabecalho();
void atribuirMissao(char* destino, char* missoes[], int totalMissoes);



int main()
{
    exibirCabecalho();
    return 0;
}

//Definição das funções
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Utilidades
void pressioneEnter(){
    printf("\nPressione Enter para continuar...");
    getchar();
}

void exibirCabecalho(){
    printf("\n===================================\n");
    printf("  WAR ESTRUTURADO   \n");
    printf("===================================\n");
}

void liberarMemoria(struct Territorio *atacante, struct Territorio *defensor, struct Territorio *mapa){
    free(atacante);
    free(defensor);
    free(mapa);
    printf("Memória liberada.");
    pressioneEnter();
}

//Função para cadastrar territórios - territórios hard coded
void cadastrarTerritorio(struct Territorio* mapa) {

    *mapa[0].nome = "América";
    *mapa[0].cor = "Verde";
    mapa[0].tropas = 2;
      
    *mapa[1].nome = "Europa";
    *mapa[1].cor = "Azul";
    mapa[1].tropas = 2;

    *mapa[2].nome = "Ásia";
    *mapa[2].cor = "Amarelo";
    mapa[2].tropas = 2;

    *mapa[3].nome = "Oceania";
    *mapa[3].cor = "Lilás";
    mapa[3].tropas = 2;

    *mapa[4].nome = "Africa";
    *mapa[4].cor = "Magenta";
    mapa[4].tropas = 2;


    for(int i = 0; i < 5; i++){
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';
        limparBufferEntrada();
    }
}

//Função para o cadastro dos territórios
void listarTerritorios(struct Territorio *mapa){
    printf("\n===================================\n");
    printf("  MAPA DO MUNDO - ESTADO ATUAL   \n");
    printf("===================================\n");
    
    for(int i = 0; i < 5; i++){

        printf("%d. %s (Exército %s, Tropas: %d)\n", i +1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

void atacar(struct Territorio *atacante, struct Territorio *defensor){

    //Garantindo a aleatoriedade do dado
    srand(time(NULL));

    int dadoAtaque = 1 + (rand() % 5);
    int dadoDefesa = 1 + (rand() % 5);

    printf("\n----- RESULTADO DA BATALHA ------");

    printf("\nO atacante %s rolou o dado e tirou %d\n", atacante->nome, dadoAtaque);
    printf("\nO defensor %s rolou o dado e tirou %d\n", defensor->nome, dadoDefesa);

    if(dadoAtaque > dadoDefesa){

        int tropaTransferida = (defensor->tropas)/2;
        defensor->tropas = tropaTransferida;
        atacante->tropas =  atacante->tropas + tropaTransferida;
        printf("\nVitória do Ataque! O defensor perdeu %d tropas.", tropaTransferida);
    } else if(dadoAtaque < dadoDefesa){
        atacante->tropas =  atacante->tropas - 1;
        printf("\nVitória do Defensor! O Defensor perdeu 1 tropas.");
    } else {
        printf("Empate\n");
    }

    printf("\nPressione Enter para o próximo turno...");
    getchar();

}