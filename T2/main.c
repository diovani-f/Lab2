#include "menu.h"

int main(){

    Aluno *listaA = NULL;
    Professor *listaP = NULL;
    Projeto *listaProj = NULL;
    Vinculo *listaV = NULL;
    int aux;

    do{
        menu_principal(&aux);
        if(aux == 1) menu_aluno(&listaA);
        if(aux == 2) menu_projeto(&listaProj, listaP);
        if(aux == 3) menu_vinculo(&listaV, listaProj, listaA);
        if(aux == 4) menu_professor(&listaP);
        if(aux == 5) apresentar_final(listaProj, listaV, &aux);
        if(aux == 6) remover_vinculo(&listaV, &listaProj);
    }while(aux != 0);

    libera_memoria(listaProj, listaA, listaV, listaP);
        
    return 0;
}
 
