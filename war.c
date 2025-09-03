// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//Bibliotecas
#include <stdio.h>
#include <string.h>

// Estrutura de território contendo nome, cor e tropas
// Definido globalmente para facilitar a modulatização
struct Territorio {
  char nome[30];
  char cor[30];
  int tropas;
};

//Vetor para armazenar 5 territórios
struct Territorio territorios[5];

void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//Função para o cadastro dos territórios
void cadastrarTerritorio(){
    
    for(int i = 0; i < 5; i++){
        printf("--- Cadastrando Território %d ---\n", i+1);
        printf("Nome do Território: ");
        scanf("%s", territorios[i].nome);
        printf("Cor do Exército: ");
        scanf("%s", territorios[i].cor);
        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        printf("\n");
    }
    
    printf("Cadastro inicial concluído com sucesso!\n\n");
    limparBufferEntrada();
}

//Função para o cadastro dos territórios
void listarTerritorios(){
    printf("===================================\n");
    printf("  MAPA DO MUNDO - ESTADO ATUAL   \n");
    printf("===================================\n");
    
    for(int i = 0; i < 5; i++){
        printf("-----------------------\n");
        printf("TERRITÓRIO %d\n", i+1);
        printf(" - Nome: %s\n", territorios[i].nome);
        printf(" - Dominado por: Exército: %s\n", territorios[i].cor);
        printf(" - Tropas: %d\n\n", territorios[i].tropas);
    }

    limparBufferEntrada();
}


int main() {
    
    //Chamada da função de cadastro
    cadastrarTerritorio();
    
    //Chamada da função de listagem
    listarTerritorios();

    return 0;
}