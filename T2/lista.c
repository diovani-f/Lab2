#include "lista.h"

struct aluno{
    int matricula;
    char nome[50];
    int telefone;
    struct aluno *proximo;
};

struct professor{
    int codigo;
    char nome[50];
    char departamento[50];
    struct professor *proximo;
};

struct projeto{
    int codigo; //
    char descricao[200]; //
    char tipo[50]; //
    float orcamentoAprovado; //
    float orcamentoAtual; //
    Professor *coordenador; //
    struct projeto *proximo;
};

struct vinculo{
    float valorMensal;
    Aluno *vinculadoA;
    Projeto *vinculadoP;
    struct vinculo *proximo;
};


void cadastrar_projeto(Projeto **listaProj, Professor *listaP){

    Projeto *novo = malloc(sizeof(Projeto));

    if(listaP == NULL){
        printf("Lista de professores nao pode ser nulo para criar um projeto!\n");
        return;
    }
    
    int codigo, prof, cont=0;
    float orcamentoAtual, orcamentoAprovado;
    char tipo[50], descricao[200];
    printf("\n----------CADASTRO DE PROJETO----------\n");

    printf("Digite o codigo do projeto:\n");
    scanf("%i", &codigo);

    if((*listaProj) != NULL){
        while((*listaProj) != NULL){
            if((*listaProj)->codigo == codigo){
                printf("\nJa tem um projeto com esse codigo!\n");
                return;
            }
           (*listaProj) = (*listaProj)->proximo;
        }
    }
    

    printf("Digite o orcamento atual do projeto:\n");
    scanf("%f", &orcamentoAtual);

    printf("Digite o orcamento aprovado do projeto:\n");
    scanf("%f", &orcamentoAprovado);

    printf("Digite o tipo de projeto:\n");
    scanf("%s", tipo);

    printf("Digite a descricao do projeto:\n");
    scanf("%s", descricao);

    

    listar_professor(listaP);
    printf("Digite o codigo do professor que deseja coordenar o projeto:\n");
    scanf("%i", &prof);


    if(novo){
        while(listaP != NULL){
            if(listaP->codigo == codigo){
                novo->coordenador = listaP;
            }
            listaP = listaP->proximo;
        }
        novo->codigo = codigo;
        novo->orcamentoAtual = orcamentoAtual;
        novo->orcamentoAprovado = orcamentoAprovado;
        strcpy(novo->tipo, tipo);
        strcpy(novo->descricao, descricao);
        novo->proximo = *listaProj;
        *listaProj = novo;
        printf("\nCADASTRO FEITO COM SUCESSO.\n");
    }
    else{
        printf("error 404");
        exit;
    }
}
void listar_projeto(Projeto *listaProj){
    printf("Lista de projetos(s)\n");
     
    while(listaProj != NULL){
        printf("-----------------------\n");
        printf("Codigo:%i\n", listaProj->codigo);
        printf("Descricao:%s\n", listaProj->descricao);
        printf("Orcamento aprovado:%2.f\n", listaProj->orcamentoAprovado);
        printf("Orcamento Atual:%2.f\n", listaProj->orcamentoAtual);
        printf("Tipo:%s\n", listaProj->tipo);
        printf("Nome do coordenador:%s\n", listaProj->coordenador->nome);
        listaProj = listaProj->proximo;
        printf("-----------------------\n");
    }
    printf("\n");
}


void cadastrar_aluno(Aluno **listaA){

    Aluno *novo = malloc(sizeof(Aluno));
    
    int matricula, telefone;
    char nome[50];

    printf("\n----------CADASTRO DE ALUNO----------\n");

    printf("Digite o nome do aluno que deseja cadastrar:\n");
    scanf("%s", nome);

    printf("Digite o numero da matricula do aluno:\n");
    scanf("%i", &matricula);

    if((*listaA) != NULL){
        while((*listaA) != NULL){
            if((*listaA)->matricula == matricula){
                printf("\nJa tem um aluno com essa matricula\n");
                return;
            }
           (*listaA) = (*listaA)->proximo;
        }
    }

    printf("Digite o telefone do aluno:\n");
    scanf("%i", &telefone);

    if(novo){
        novo->matricula = matricula;
        novo->telefone = telefone;
        strcpy(novo->nome, nome);
        novo->proximo = *listaA;
        *listaA = novo;
        printf("\nALUNO INSERIDO COM SUCESSO.\n\n");
    }
    else{
        printf("error 404");
        exit;
    }
}
void listar_aluno(Aluno *listaA){
    
    printf("Lista de Aluno(s)\n");

    while(listaA != NULL){
        printf("-----------------------\n");
        printf("Nome:%s\n", listaA->nome);
        printf("Telefone:%i\n", listaA->telefone);
        printf("Matricula:%d\n", listaA->matricula);
        listaA = listaA->proximo;
        printf("-----------------------\n");
    }
    printf("\n");
}


void cadastrar_professor(Professor **listaP){

    Professor *novo = malloc(sizeof(Professor));
    
    int codigo;
    char nome[50], departamento[50];

    printf("\n----------CADASTRO DE PROFESSORES----------\n");
    printf("Digite o nome do professor:\n");
    scanf("%s", nome);

    printf("Digite o codigo do professor\n");
    scanf("%i", &codigo);

    if((*listaP) != NULL){
        while((*listaP) != NULL){
            if((*listaP)->codigo == codigo){
                printf("\nJa tem um professor com essa matricula\n");
                return;
            }
           (*listaP) = (*listaP)->proximo;
        }
    }
    

    printf("Digite o departamento em que o professor trabalha\n");
    scanf("%s", departamento);


    if(novo){
        novo->codigo = codigo;
        strcpy(novo->departamento, departamento);
        strcpy(novo->nome, nome);
        novo->proximo = *listaP;
        *listaP = novo;
        printf("\nPROFESSOR INSERIDO COM SUCESSO.\n\n");
    }
    else{
        printf("error 404");
        exit;
    }
}
void listar_professor(Professor *listaP){
    printf("Lista de Professores(s)\n");

    while(listaP != NULL){
        printf("-----------------------\n");
        printf("Nome:%s\n", listaP->nome);
        printf("Codigo:%d\n", listaP->codigo);
        printf("Departamento:%s\n", listaP->departamento);
        listaP = listaP->proximo;
        printf("-----------------------\n");
    }
    printf("\n");

}


void cadastrar_vinculo(Vinculo **listaV, Projeto *listaProj, Aluno *listaA){
    Vinculo *novo = malloc(sizeof(Vinculo));
    int matr, cod, cont=0;
    float valorMensal;


    if(listaProj == NULL || listaA == NULL){
        printf("\nLista de Projetos ou Alunos não podem ser nulos para criar um vinculo!\n");
        return;
    }
    

    printf("\n----------CADASTRO DE VINCULOS----------\n");

    listar_aluno(listaA);
    printf("Digite a matricula do aluno que deseja participar do projeto:\n");
    scanf("%i", &matr);

    listar_projeto(listaProj);
    printf("Digite o codigo do projeto que deseja vincular:\n");
    scanf("%i", &cod);
   

    printf("Digite o valor mensal que sera pago para o aluno:\n");
    scanf("%f", &valorMensal);


    if(novo){
        novo->valorMensal = valorMensal;
        while(listaProj != NULL){
            if(listaProj->codigo == cod){
                
                novo->vinculadoP = listaProj;
            }
            listaProj = listaProj->proximo;
        }
        
        while(listaA != NULL){
            if(listaA->matricula == matr){
                if(valorMensal * 12 < novo->vinculadoP->orcamentoAtual){
                    novo->vinculadoP->orcamentoAtual = novo->vinculadoP->orcamentoAtual - valorMensal * 12;
                    novo->vinculadoA = listaA;
                }
                else{
                    printf("Nao ha dinherio suficiente para adicionar o aluno nesse projeto\n");
                    return;
                }
            }
            listaA = listaA->proximo;
        }
        novo->proximo = *listaV;
        *listaV = novo;
        printf("\nCADASTRO FEITO COM SUCESSO.\n\n");

    }
    else{
        printf("error 404");
        exit;
    }
}
void listar_vinculo(Vinculo *listaV){

    printf("Lista de Vinculos(s)\n");

    while(listaV != NULL){
        printf("-----------------------\n");
        printf("Professor Cordenador:%s\n", listaV->vinculadoP->coordenador->nome);
        printf("Codigo do projeto:%i\n", listaV->vinculadoP->codigo);
        printf("Nome do Aluno:%s\n", listaV->vinculadoA->nome);
        printf("Matricula do Aluno:%i\n", listaV->vinculadoA->matricula);
        printf("Valor mensal pago para o aluno:%2.f\n", listaV->valorMensal);
        listaV = listaV->proximo;
        printf("-----------------------\n");
    }
    printf("\n");

}
void remover_vinculo(Vinculo **listaV, Projeto **listaProj){

    if(listaV == NULL){
        printf("Lista de VINCULOS nao pode ser nulo para remover um vinculo!\n");
        return;
    }

    Vinculo *aux, *remover = NULL;
    Projeto *novo = NULL;
    novo = *listaProj;


    float valorMen;
    int matricula, restanteFinal, codigoProj, cont=0;
    

    printf("\n----------CADASTRO DE VINCULOS----------.\n\n");

    listar_vinculo(*listaV);


    printf("Digite a matricula do aluno que deseja remover:\n");
    scanf("%i", &matricula);

    printf("Digite o codigo do projeto que deseja remover:\n");
    scanf("%i", &codigoProj);
    
    printf("Digite quantos meses restam para o final do projeto:\n");
    scanf("%i", &restanteFinal);


    
    if(*listaV){
        if((*listaV)->vinculadoA->matricula == matricula && (*listaV)->vinculadoP->codigo == codigoProj){
            remover = *listaV;
            
            while(novo->codigo != remover->vinculadoP->codigo){
                novo = novo->proximo;
            }
            remover->vinculadoP->orcamentoAtual = remover->vinculadoP->orcamentoAtual + (remover->valorMensal * restanteFinal);
            *listaV = remover->proximo;
        }
        else{
            aux = *listaV;
            while (aux->proximo && aux->proximo->valorMensal != valorMen)
                aux = aux->proximo;
            if(aux->proximo){

                while(novo->codigo != aux->vinculadoP->codigo){
                novo = novo->proximo;
                }
                aux->vinculadoP->orcamentoAtual = aux->vinculadoP->orcamentoAtual + (aux->valorMensal * restanteFinal);
                remover = aux->proximo;
                aux->proximo = remover->proximo;                
            }
        }
    }

    free(remover);
    printf("Vinculo removido com sucesso\n");
}


void apresentar_final(Projeto *listaProj, Vinculo *listaV, int *aux){
    int cont = 0;

    while(listaProj != NULL){
        printf("-----------------------\n");
        printf("Codigo:%i\n", listaProj->codigo);
        printf("Descricao:%s\n", listaProj->descricao);
        printf("Orcamento Atual:%2.f\n", listaProj->orcamentoAtual);
        printf("Tipo:%s\n", listaProj->tipo);
        printf("Nome do coordenador:%s\n", listaProj->coordenador->nome);
        while (listaV != NULL)
        {
            if(listaV->vinculadoP->codigo == listaProj->codigo){
                cont = 1;
                printf("Aluno vinculado ao projeto:%s\n", listaV->vinculadoA->nome);
            }
            listaV = listaV->proximo;
        }
        if(cont == 0)
            printf("Nao ha aluno vinculado");
        
        listaProj = listaProj->proximo;
        printf("\n-----------------------\n");
    }
    *aux = 0;
    return;
}


void libera_memoria(Projeto *listaProj, Aluno *listaA, Vinculo *listaV, Professor *listaP){
    free(listaProj);
    free(listaA);
    free(listaV);
    free(listaP);
}