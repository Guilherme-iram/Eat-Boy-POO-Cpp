#include "Heroi.hpp"
#include "Personagem.hpp"
#include <conio.h>

Heroi::Heroi(char simb, int pos_x, int pos_y, Mapa_jogo *labirinto) : 
    Personagem(simb, pos_x, pos_y, labirinto) {
}

void Heroi::poder(){

    if (move_status == 0){
        system("color 06");
        status = 0;
    }
        
    if(status == 1) { 
        system("color 04");
        simbolo = '@';
        move_status--;

    } else if (status == 2) {
        system("color 03");
        simbolo = '*';
        move_status--;

    } else {
        simbolo = 'c';
    }
}

void Heroi::move(char comando) {
     if(estou_vivo()) {
        char proxima_posicao;

        switch (comando) {
            
        case 'W':
        case 'w':
            proxima_posicao = mapa->matriz[posicao_x - 1][posicao_y]; 
            if (proxima_posicao == '-' || proxima_posicao == '|'){
                break;
            }
            if(tem_fantasma(proxima_posicao, status)){ // Verificar colis�o com fantasma
                break;
            }
            tem_pilula(proxima_posicao); // Verificar se tem uma pilula
            poder();

            mapa->matriz[posicao_x - 1][posicao_y] = simbolo;
            mapa->matriz[posicao_x][posicao_y] = '.';
            posicao_x = posicao_x - 1;
            posicao_y = posicao_y;
            break;

        case 'A':
        case 'a':
            proxima_posicao = mapa->matriz[posicao_x][posicao_y - 1];
            if (proxima_posicao == '-' || proxima_posicao == '|'){
                break;
            }

            if(tem_fantasma(proxima_posicao, status)){ // Verificar colis�o com fantasma
                break;
            }
            tem_pilula(proxima_posicao); // Verificar se tem uma pilula
            poder();

            mapa->matriz[posicao_x][posicao_y - 1] = simbolo;
            mapa->matriz[posicao_x][posicao_y] = '.';

            posicao_x = posicao_x;
            posicao_y = posicao_y - 1;
            break;

        case 'S':
        case 's':
            proxima_posicao = mapa->matriz[posicao_x + 1][posicao_y];

            if (proxima_posicao == '-' || proxima_posicao == '|'){
                break;
            }
            
            if(tem_fantasma(proxima_posicao, status)){ // Verificar colis�o com fantasma
                break;
            }
            tem_pilula(proxima_posicao); // Verificar se tem uma pilula
            poder();

            mapa->matriz[posicao_x + 1][posicao_y] = simbolo;
            mapa->matriz[posicao_x][posicao_y] = '.';

            posicao_x = posicao_x + 1;
            posicao_y = posicao_y;
            break;

        case 'D':
        case 'd':
            proxima_posicao = mapa->matriz[posicao_x][posicao_y + 1];

            if (proxima_posicao == '-' || proxima_posicao == '|'){
                break;
            }
               
            if(tem_fantasma(proxima_posicao, status)){ // Verificar colis�o com fantasma
                break;
            }
            tem_pilula(proxima_posicao); // Verificar se tem uma pilula
            poder();

            mapa->matriz[posicao_x][posicao_y + 1] = simbolo;
            mapa->matriz[posicao_x][posicao_y] = '.';

            posicao_x = posicao_x;
            posicao_y = posicao_y + 1;
            break;
        
        default: break;
        }   
    }
}


void Heroi::tem_pilula(char objeto){
    if (objeto == 'o'){
        status = 1;
        move_status = 20;
    }
        
    if (objeto == 'O'){
        status = 2;
        move_status = 20;
    }
        
}

int Heroi::tem_fantasma(char objeto, int status) {
    if(objeto == '#' && status != 1){             // Na colis�o com fantasma
        mapa->matriz[posicao_x][posicao_y] = '.'; // Ocorre a substitui��o do caracter do personagem para um .
        return 1;
    }
    return 0; 
}                                