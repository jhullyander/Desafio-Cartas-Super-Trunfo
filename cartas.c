#include <stdio.h>

#define NUM_CARTAS 10
#define NUM_ATRIBUTOS 3

int cartas_jogador[NUM_CARTAS / 2][NUM_ATRIBUTOS] = {
    {90, 85, 95},  // Dragao
    {75, 80, 90},  // Grifo
    {85, 75, 60},  // Minotauro
    {83, 90, 82},  // Cerbero
    {98, 65, 75}   // Golem
};

int cartas_cpu[NUM_CARTAS / 2][NUM_ATRIBUTOS] = {
    {80, 95, 70},  // Unicórnio
    {95, 70, 85},  // Fenix
    {92, 88, 91},  // Hidra
    {70, 98, 80},  // Lourus
    {87, 84, 93}   // Kraken
};

char nomes_jogador[NUM_CARTAS / 2][50] = {
    "Dragao",
    "Grifo",
    "Minotauro",
    "Cerbero",
    "Golem"
};

char nomes_cpu[NUM_CARTAS / 2][50] = {
    "Unicornio",
    "Fenix",
    "Hidra",
    "Lourus",
    "Kraken"
};

void exibir_carta(char nome[], int atributos[]) {
    printf("Nome: %s\n", nome);
    printf("1. Forca: %d\n", atributos[0]);
    printf("2. Agilidade: %d\n", atributos[1]);
    printf("3. Magia: %d\n", atributos[2]);
}

int main() {
    int cartas_jogador_restantes = NUM_CARTAS / 2;
    int cartas_cpu_restantes = NUM_CARTAS / 2;
    int rodada = 0;

    printf("--- Bem-vindo ao Super Trunfo Simples ---\n");
    printf("Seu objetivo e ganhar todas as cartas do oponente.\n\n");

    while (cartas_jogador_restantes > 0 && cartas_cpu_restantes > 0) {
        printf("--- Rodada %d ---\n", rodada + 1);
        printf("Sua carta: \n");
        exibir_carta(nomes_jogador[rodada], cartas_jogador[rodada]);

        int escolha;
        printf("\nEscolha um atributo (1-3): ");
        scanf("%d", &escolha);
        escolha--;

        printf("\nSua escolha: %d\n", cartas_jogador[rodada][escolha]);
        printf("Carta do oponente: \n");
        exibir_carta(nomes_cpu[rodada], cartas_cpu[rodada]);
        printf("Escolha do oponente: %d\n", cartas_cpu[rodada][escolha]);

        if (cartas_jogador[rodada][escolha] > cartas_cpu[rodada][escolha]) {
            printf("\nVoce venceu a rodada!\n");
            cartas_jogador_restantes++;
            cartas_cpu_restantes--;
        } else if (cartas_jogador[rodada][escolha] < cartas_cpu[rodada][escolha]) {
            printf("\nVoce perdeu a rodada.\n");
            cartas_cpu_restantes++;
            cartas_jogador_restantes--;
        } else {
            printf("\nEmpate!\n");
        }

        printf("\nCartas restantes: Voce - %d | Oponente - %d\n\n", cartas_jogador_restantes, cartas_cpu_restantes);
        
        if (cartas_jogador_restantes > 0 && cartas_cpu_restantes > 0) {
            rodada++;
            if (rodada >= NUM_CARTAS / 2) {
                printf("Fim do baralho inicial. O jogo e um empate. Tente novamente.\n");
                break;
            }
        }
    }

    if (cartas_jogador_restantes == 0) {
        printf("Voce perdeu! O oponente ficou com todas as cartas.\n");
    } else if (cartas_cpu_restantes == 0) {
        printf("Parabens! Voce venceu o jogo!\n");
    }

    return 0;
}
