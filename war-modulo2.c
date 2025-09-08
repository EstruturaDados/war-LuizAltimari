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
    pressioneEnter();
    getchar();

}

//Função de Ataque
void atacar(struct Territorio* atacante, struct Territorio* defensor){

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

//Função para o cadastro dos territórios
void listarTerritorios(int tamMapa, struct Territorio *mapa){
    printf("\n===================================\n");
    printf("  MAPA DO MUNDO - ESTADO ATUAL   \n");
    printf("===================================\n");
    
    for(int i = 0; i < tamMapa; i++){

        printf("%d. %s (Exército %s, Tropas: %d)\n", i +1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

int main()
{
    printf("\n===================================\n");
    printf("  WAR ESTRUTURADO   \n");
    printf("===================================\n");

    printf("Escolha qua quanntidade de territórios: ");
    int qtdTerritorios;
    scanf("%d", &qtdTerritorios);   
    limparBufferEntrada();
    struct Territorio* mapa = (struct Territorio *)calloc(qtdTerritorios, sizeof(struct Territorio));
    cadastrarTerritorio(qtdTerritorios, mapa);
    listarTerritorios(qtdTerritorios, mapa);    

    int atacante;
    int defensor;

    do{

        printf("\n------ FASE DE ATAQUE ------\n");
        printf("Escolha o território atacante (1 a %d ou 0 para sair): ", qtdTerritorios);
        scanf("%d", &atacante);
        if(atacante != 0){
            printf("Escolha o território defensor (1 a %d): ", qtdTerritorios);
            scanf("%d", &defensor);

            //Valida se o atacante é diferente do defensor
            if(atacante != defensor){
                
                struct Territorio *a = &mapa[atacante - 1];                
                struct Territorio *d = &mapa[defensor - 1];                
                atacar(a, d);  
                listarTerritorios(qtdTerritorios, mapa);               

            } else {
                printf("\nO atacante deve ser diferente do defensor.\n");
            }

        } else {

            printf("\n Saindo do Jogo...\n");
        }

    } while(atacante != 0);
    

    free(mapa);
    return 0;

}
