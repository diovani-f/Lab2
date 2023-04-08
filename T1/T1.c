#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
	char p_digitadas[100];
}palavras;

palavras p[100];

char **aloca_matriz(int* m, int* n, char** mat)
{
	int i, cont1, cont2;
	unsigned char letra;

	printf("Digite as dimensoes da matriz:\nLinhas: ");
	scanf("%d", &*m);
	printf("Colunas: ");
	scanf("%d", &*n);

	mat = (char**)malloc(*m*sizeof(char*));

	for(i = 0; i < *m; i++){
		mat[i] = (char*) malloc(*n * sizeof(char));
	}
	
	return mat;
}

void preenche_matriz(int m, int n, char** mat)
{
	char letra;
	int cont1 = 0, cont2 = 0;

	while(cont1 < m){
		while(cont2 < n){
		letra = rand() % 123;
			if(letra >= 97 && letra <= 122){
				mat[cont1][cont2] = letra;
				cont2++;
			}
		}
		cont1++;
		cont2 = 0;
	}
}

void escreve_matriz(int m, int n, char** mat)
{
	int cont1, cont2;

	for(cont1 = 0; cont1 < m; cont1++){
		for(cont2 = 0; cont2 < n; cont2++){
			printf("%c ", mat[cont1][cont2]);
		}
		printf("\n");
	}
}

bool busca_horizontal(char palavra[], int t, char** mat, int m, int n)
{
	int h_reversa = 0, h_direta = 0, k = 0, c_inicial, i, j;

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(palavra[k] == mat[i][j]){
				c_inicial = j;
				while(k < t){
					if(palavra[k] == mat[i][k + j] && h_direta != -1){
						k++;
						h_direta++;
						continue;
					}else{
						h_direta = -1;
						if(h_reversa == 0){
							k = 0;
						}
					}
					if(palavra[k] == mat[i][j - k] && h_direta == -1){
						k++;
						h_reversa++;
						continue;
					}
					break;
				}
			}
			if(h_direta == t){
				printf("Palavra '%s' ocorre na HORIZONTAL DIRETA, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, i, c_inicial , i, k + (j - 1));
				return true;
			}else{
				if(h_reversa == t){
					printf("Palavra '%s' ocorre na HORIZONTAL REVERSA, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, i, c_inicial , i, (j + 1) - k);
					return true;
				}
			}
		}
		k = 0;
		h_direta = 0;
		h_reversa = 0;
		c_inicial = 0;	
	}
	return false;
}

bool busca_vertical_direta(char palavra[], int t, char** mat, int m, int n)
{
	int v_direta = 0, k = 0, l_inicial, i, j;

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(palavra[k] == mat[i][j]){
				l_inicial = i;
				while(k < t && k + i < m){
					if(palavra[k] == mat[i + k][j]){
						k++;
						v_direta++;
						continue;
					}
					break;
				}
			}
			if(v_direta == t){
				printf("Palavra '%s' ocorre na VERTICAL DIRETA, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, l_inicial, j, k + (i - 1), j);
				return;
			}
		}
		k = 0;
		v_direta = 0;
		l_inicial = 0;		
	}
	return false;
}

bool busca_vertical_reversa(char palavra[], int t, char** mat, int m, int n)
{
	int v_reversa = 0, k = 0, l_inicial, i, j;

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(palavra[k] == mat[i][j]){
				l_inicial = i;
				while(k < t && i - k >= 0){
					if(palavra[k] == mat[i - k][j]){
						k++;
						v_reversa++;
						continue;
					}
					break;
				}
			}
			if(v_reversa == t){
				printf("Palavra '%s' ocorre na VERTICAL REVERSA, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, l_inicial, j, (i + 1) - k, j);
				return true;
			}
		}
		k = 0;
		v_reversa = 0;
		l_inicial = 0;		
	}
	return false;
}

bool busca_diagonal_principal(char palavra[], int t, char** mat, int m, int n){
    int i = 0, j = 0, k = 0, cont = 0, salvarX, salvarY, salvarX2, salvarY2, g, h;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(palavra[k] == mat[i][j]){
                g=i, h=j;
                while(g < m && h < n){
                    if(mat[g][h] == palavra[k]){
                        if(cont == 0){
                            salvarX = g;
                            salvarY = h;
                        }
                        if(cont == t - 1){
                            salvarX2 = g;
                            salvarY2 = h;
                        }
                        k++;
                        cont++;
                    }
                    else{
                        k=0;
                        cont=0;
                    }
                    g++;
                    h++;

                    if(cont == t)
                        break;
                }
            }
            if(cont == t)
                break;
        }
        if(cont == t)
            break;
    }
    if(cont == t){
		printf("Palavra '%s' ocorre na DIAGONAL PRINCIPAL, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, salvarX, salvarY, salvarX2, salvarY2);
        return true;
    }
	return false;
}

bool busca_diagonal_principal_rev(char palavra[], int t, char** mat, int m, int n){
    int i = 0, j = 0, k = 0, cont = 0, salvarX, salvarY, salvarX2, salvarY2, g, h;
    char stringInvertida[80];

    t = strlen(palavra);
    for(i = t-1; i >= 0; i--) {
        stringInvertida[j] = palavra[i];
        j += 1;
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(stringInvertida[k] == mat[i][j]){
                g=i, h=j;
                while(g < m && h < n){
                    if(mat[g][h] == stringInvertida[k]){
                        if(cont == 0){
                            salvarX = g;
                            salvarY = h;
                        }
                        if(cont == t - 1){
                            salvarX2 = g;
                            salvarY2 = h;
                        }
                        k++;
                        cont++;
                    }
                    else{
                        k=0;
                        cont=0;
                    }
                    g++;
                    h++;

                    if(cont == t)
                        break;
                }
            }
            if(cont == t)
                break;
        }
        if(cont == t)
            break;
    }
    if(cont == t){
       	printf("Palavra '%s' ocorre na DIAGONAL PRINCIPAL REVERSA, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, salvarX2, salvarY2, salvarX, salvarY);
        return true;
    }
	return false;
}

bool busca_diagonal_sec(char palavra[], int t, char** mat, int m, int n){
    int i = 0, j = 0, k = 0, cont = 0, salvarX, salvarY, salvarX2, salvarY2, g, h;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(mat[i][j] == palavra[k]){
                g=i, h=j;
                while(g < m && h > 0){
                    if(mat[g][h] == palavra[k]){
                        if(cont == 0){
                            salvarX = g;
                            salvarY = h;
                        }
                        if(cont == t - 1){
                            salvarX2 = g;
                            salvarY2 = h;
                        }
                        k++;
                        cont++;
                    }
                    else{
                        k=0;
                        cont=0;
                    }
                    g++;
                    h--;

                    if(cont == t)
                        break;
                }
            }
            if(cont == t)
                break;
        }
        if(cont == t)
            break;
    }   
    if(cont == t){
		printf("Palavra '%s' ocorre na DIAGONAL SECUNDARIA, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, salvarX2, salvarY2, salvarX, salvarY);
        return true;
    }
	return false;
}

bool busca_diagonal_sec_rev(char palavra[], int t, char** mat, int m, int n){
    int i = 0, j = 0, k = 0, cont = 0, salvarX, salvarY, salvarX2, salvarY2, g, h;
    char stringInvertida[80];

    t = strlen(palavra);
    for(i = t - 1; i >= 0;i--) {
        stringInvertida[j] = palavra[i];
        j += 1;
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(stringInvertida[k] == mat[i][j]){
                g=i, h=j;
                while(g < m && h > 0){
                    if(mat[g][h] == stringInvertida[k]){
                        if(cont == 0){
                            salvarX = g;
                            salvarY = h;
                        }
                        if(cont == t - 1){
                            salvarX2 = g;
                            salvarY2 = h;
                        }
                        k++;
                        cont++;
                    }
                    else{
                        k=0;
                        cont=0;
                    }
                    g++;
                    h--;

                    if(cont == t)
                        break;
                }
            }
            if(cont == t)
                break;
        }
        if(cont == t)
            break;
    }         
    if(cont == t){
		printf("Palavra '%s' ocorre na DIAGONAL SECUNDARIA REVERSA, iniciando na posicao [%d, %d] e terminando na posicao [%d, %d].\n", palavra, salvarX2, salvarY2, salvarX, salvarY);
        return true;
    }
	return false;
}

void free_mat(char** mat, int m)
{
	int i;

	for(i = 0; i < m; i++){
		free(mat);
	}
}

int main()
{
	srand(time(NULL));
	int i, m, n, t;
	char palavra[100], **mat = aloca_matriz(&m, &n, mat);

	preenche_matriz(m, n, mat);
	escreve_matriz(m, n, mat);

	do{
		printf("\nDigite uma palavra (0 para sair): ");
		scanf("%s", palavra);

		t = strlen(palavra);

		if(busca_horizontal(palavra, t, mat, m, n) == true) continue;
		if(busca_vertical_direta(palavra, t, mat, m, n) == true) continue;
		if(busca_vertical_reversa(palavra, t, mat, m, n) == true) continue;
		if(busca_diagonal_principal(palavra, t, mat, m, n) == true) continue;
		if(busca_diagonal_principal_rev(palavra, t, mat, m, n) == true) continue;
		if(busca_diagonal_sec(palavra, t, mat, m, n) == true) continue;
		if(busca_diagonal_sec_rev(palavra, t, mat, m, n) == true) continue;
		if(palavra[0] != '0'){
			printf("\n\nPalavra NAO encontrada!\n\n");
		}
	}while(palavra[0] != '0');

	free_mat(mat, m);
	
	return 0;
}
