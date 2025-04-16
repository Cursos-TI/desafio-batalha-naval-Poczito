#include <stdio.h>

#define LIN 10
#define COL 10

int main(){

    //Criação do tabuleiro todo preenchido com 0
    int tabuleiro[LIN][COL];
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            tabuleiro[i][j] = 0;
        }
    }


    //Inicializando os verificadores das condições de posição do navio. 0 = condições não verificadas, 1 = condições verificadas. Serve para sair do loop
    int verifica = 0;
    

    ///Declarando as variáveis de posição do navio a ser registrado
    int navioi, navioj;


    //Entrada de dados e verificação das condições do navio horizontal
    while (verifica == 0){
        printf("Entre com a posição inicial do navio 1 (horizontal), linha e coluna:\n");
        scanf("%d %d", &navioi, &navioj);
        if(1 <= navioi <= LIN && 1 <= navioj <= COL && (navioj + 2) <= COL){ //Verificando se o início e final estão no tabuleiro
            verifica = 1;
        }
        verifica == 0 ? printf("Posição inválida!\n") : printf("Posição registrada!\n");
    }
    tabuleiro[navioi - 1][navioj - 1] = tabuleiro[navioi - 1][navioj] = tabuleiro[navioi - 1][navioj + 1] = 3; //Registrando o navio no tabuleiro
    printf("Coordenadas do navio 1: (%d,%d), (%d,%d) e (%d,%d)\n\n", navioi, navioj, navioi, navioj + 1, navioi, navioj + 2);
    verifica = 0; //Resetando verificador


    //Entrada de dados e verificação das condições do navio vertical
    while (verifica == 0){
        printf("Entre com a posição inicial do navio 2 (vertical), linha e coluna:\n");
        scanf("%d %d", &navioi, &navioj);
        if(1 <= navioi <= LIN && 1 <= navioj <= COL && (navioi + 2) <= LIN){ //Verificando se o início e final estão no tabuleiro
            if(tabuleiro[navioi - 1][navioj - 1] == 0 && tabuleiro[navioi - 0][navioj - 1] == 0 && tabuleiro[navioi + 1][navioj - 1] == 0){
            //Verificando se não há outro navio nas posições
                verifica = 1;
            }
        }
        verifica == 0 ? printf("Posição inválida!\n") : printf("Posição registrada!\n");
    }
    tabuleiro[navioi - 1][navioj - 1] = tabuleiro[navioi][navioj - 1] = tabuleiro[navioi + 1][navioj - 1] = 3;
    printf("Coordenadas do navio 2: (%d,%d), (%d,%d) e (%d,%d)\n\n", navioi, navioj, navioi + 1, navioj, navioi + 2, navioj);
    verifica = 0; //Resetando verificador


    //Entrada de dados e verificação das condições do navio diagonal subindo
    while (verifica == 0){
        printf("Entre com a posição inicial do navio 3 (diagonal subindo), linha e coluna:\n");
        scanf("%d %d", &navioi, &navioj);
        if(1 <= navioi <= LIN && 1 <= navioj <= COL && (navioi - 2) >= 1 && (navioj + 2 <= COL)){ //Verificando se o início e final estão no tabuleiro
            if(tabuleiro[navioi - 1][navioj - 1] == 0 && tabuleiro[navioi - 2][navioj] == 0 && tabuleiro[navioi - 3][navioj + 1] == 0){
                //Verificando se não há outro navio nas posições
                verifica = 1;
            }
        }
        verifica == 0 ? printf("Posição inválida!\n") : printf("Posição registrada!\n");
    }
    tabuleiro[navioi - 1][navioj - 1] = tabuleiro[navioi - 2][navioj] = tabuleiro[navioi - 3][navioj + 1] = 3;
    printf("Coordenadas do navio 3: (%d,%d), (%d,%d) e (%d,%d)\n\n", navioi, navioj, navioi - 1, navioj + 1, navioi - 2, navioj + 2);
    verifica = 0; //Resetando verificador

    
    //Entrada de dados e verificação das condições do navio diagonal descendo
    while (verifica == 0){
        printf("Entre com a posição inicial do navio 4 (diagonal descendo), linha e coluna:\n");
        scanf("%d %d", &navioi, &navioj);
        if(1 <= navioi <= LIN && 1 <= navioj <= COL && (navioi + 2) <= LIN && (navioj + 2 <= COL)){ //Verificando se o início e final estão no tabuleiro
            if(tabuleiro[navioi - 1][navioj - 1] == 0 && tabuleiro[navioi][navioj] == 0 && tabuleiro[navioi + 1][navioj + 1] == 0){
                //Verificando se não há outro navio nas posições
                verifica = 1;
            }
        }
        verifica == 0 ? printf("Posição inválida!\n") : printf("Posição registrada!\n");
    }
    tabuleiro[navioi - 1][navioj - 1] = tabuleiro[navioi][navioj] = tabuleiro[navioi + 1][navioj + 1] = 3;
    printf("Coordenadas do navio 4: (%d,%d), (%d,%d) e (%d,%d)\n\n", navioi, navioj, navioi + 1, navioj + 1, navioi + 2, navioj + 2);

    //Criação das habilidades

    //Exibição do tabuleiro com os navios posicionados
    printf("---- Tabuleiro ----\n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    int escolha, habi, habj; //criando variáveis para a escolha da habilidade e localização
    
    verifica = 0; //Reset do verificador

    //Escolha da habilidade
    while(verifica == 0){
        printf("\nDigite o número da habilidade que deseja usar:\n");
        printf("1 - Cone\n");
        printf("2 - Octaedro\n");
        printf("3 - Cruz\n");
        scanf("%d", &escolha);
        if(escolha >= 1 && escolha <= 3){
            verifica = 1;
        }else{
            printf("Escolha inválida!");
        }
    }

    verifica = 0; //Reset do verificador

    //Escolha da posição da habilidade
    while(verifica == 0){
        printf("Insira a posição inicial da habilidade, linha e coluna:\n");
        scanf("%d %d", &habi, &habj);

        if((habi <= (LIN - 2)) && (habj <= (COL - 4)) && (habi >= 1) && (habj >= 1)){
            verifica = 1;
            printf("Posição válida!\n\n");
        }
        else{
            printf("Posição inválida!\n\n");
        }
    }
    
    switch (escolha){
        case 1:
            tabuleiro[habi-1][habj+1]++;
            tabuleiro[habi][habj]++;
            tabuleiro[habi][habj+1]++;
            tabuleiro[habi][habj+2]++;
            tabuleiro[habi+1][habj+1]++;
            tabuleiro[habi+1][habj]++;
            tabuleiro[habi+1][habj-1]++;
            tabuleiro[habi+1][habj+2]++;
            tabuleiro[habi+1][habj+3]++;

            break;

        case 2:
            tabuleiro[habi-1][habj+1]++;
            tabuleiro[habi][habj]++;
            tabuleiro[habi][habj+1]++;
            tabuleiro[habi][habj+2]++;
            tabuleiro[habi+1][habj+1]++;
            break;

        case 3:
            tabuleiro[habi-1][habj+1]++;
            tabuleiro[habi][habj]++;
            tabuleiro[habi][habj+1]++;
            tabuleiro[habi][habj+2]++;
            tabuleiro[habi][habj-1]++;
            tabuleiro[habi][habj+3]++;
            tabuleiro[habi+1][habj+1]++;

            break;   
    }

    printf("---- Tabuleiro ----\n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("1 = Habilidade na água\n");
    printf("3 = Navio\n");
    printf("4 = Habilidade no navio\n");
    
    return 0;
}