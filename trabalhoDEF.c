/* Elaborar um programa em Linguagem C que apresente um Menu para o usuário com as opções do trabalho. */

#include <stdlib.h>
#include <stdio.h>

// Função para limpar a tela
void limpartela(){
    system("cls");
}

// Obter a quantidade do vetor respeitando os limites maximos
int obterQuantidade(int limite) {
    int qtd;
    do {
        printf("Quantos elementos deseja digitar (max %d): ", limite);
        scanf("%d", &qtd);
        
        if (qtd < 1 || qtd > limite) {
            printf("Quantidade invalida! Digite um valor entre 1 e %d.\n", limite);
        }
    } while (qtd < 1 || qtd > limite);
    
    return qtd; 
}

// Obter um numero inteiro generico para pesquisa
int obterNumero(){
    int n;
    printf("Digite o numero que deseja verificar: ");
    scanf("%d", &n);
    return n;
}

// Obter um numero escalar para multiplicacao
int obterEscalar(){
    int esc;
    printf("Digite o valor do numero escalar (multiplicador): ");
    scanf("%d", &esc);
    return esc;
}

// Item 1 e 2: Ler os elementos de um vetor
void lerVetor(int vetor[], int *tamanho_real, int limite_maximo) {
    *tamanho_real = obterQuantidade(limite_maximo);

    for (int i = 0; i < *tamanho_real; i++) {
        printf("Digite o elemento [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}

// Item 3: Listar os elementos de um vetor
void listarVetor(int vetor[], int tamanho_real, int n_vetor){
    printf("Elementos do vetor %d (Total %d): ", n_vetor, tamanho_real);

    for(int i = 0 ; i < tamanho_real; i++){
        printf(" [%d] = %d ", i , vetor[i]);
    }
    printf("\n");
}

// Item 4: Somar os elementos correspondentes de dois vetores
void somarVetor(int v1[], int v2[], int vSoma[], int tamanho){
    for(int i = 0 ; i < tamanho ; i++){
        vSoma[i] = v1[i] + v2[i];
    }
}

// Item 7: Gerar vetor contendo elementos exclusivos (com tamanhos independentes)
void gerarExclusivos(int v1[], int tam1, int v2[], int tam2, int v3[], int *c){
    *c = 0; // Inicializa o contador via ponteiro

    // Procura elementos de v1 que NAO estao em v2
    for (int i = 0; i < tam1; i++) {
        int achou = 0;
        for (int j = 0; j < tam2; j++) {
            if (v1[i] == v2[j]) {
                achou = 1;
                break;
            }
        }
        if (!achou) {
            v3[*c] = v1[i];
            (*c)++;
        }
    }

    // Procura elementos de v2 que NAO estao em v1
    for (int i = 0; i < tam2; i++) {
        int achou = 0;
        for (int j = 0; j < tam1; j++) {
            if (v2[i] == v1[j]) {
                achou = 1;
                break;
            }
        }
        if (!achou) {
            v3[*c] = v2[i];
            (*c)++;
        }
    }
}

// Item 5: Multiplicar vetor por um escalar
void gerarEscalar(int vetor_d[], int vetor_o[], int tamanho){
    int escalar = obterEscalar();
    
    for(int i = 0 ; i < tamanho ; i++){
        vetor_d[i] = vetor_o[i] * escalar;
    }
}

// Item 6: Pesquisar se um número existe no vetor
void verificador(int vetor[], int tamanho, int numero){
    int achou = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            printf("Numero %d encontrado na posicao %d.\n", numero, i);
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("Numero %d nao encontrado no vetor.\n", numero);
    }
}

// Item 8: Intercalar dois vetores mantendo a ordenação
void intercalarVetores(int v1[], int tam1, int v2[], int tam2, int vIntercalado[], int *tamResultado) {
    int i = 0, j = 0, k = 0; 

    while (i < tam1 && j < tam2) {
        if (v1[i] <= v2[j]) {
            vIntercalado[k] = v1[i];
            i++;
        } else {
            vIntercalado[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < tam1) {
        vIntercalado[k] = v1[i];
        i++;
        k++;
    }

    while (j < tam2) {
        vIntercalado[k] = v2[j];
        j++;
        k++;
    }

    *tamResultado = k;
}

int main () {
    int opcao;
    int subOpcao; // Variável para controlar submenus sem quebrar o laço principal[cite: 3]
    
    // Vetores Principais
    int vetor1[30];
    int vetor2[20];
    int vetor_SOMA[20];
    int vetor_EXCLUSIVO[50];
    
    // Vetores para os resultados do Escalar
    int vetor_ESCALAR1[30];
    int vetor_ESCALAR2[20];
    int vetor_ESCALAR_SOMA[20];
    int vetor_ESCALAR_EXCLUSIVO[50];

    // Variáveis de tamanho real
    int total_elementos1 = 0;
    int total_elementos2 = 0;
    int total_elementos_SOMA = 0;
    int total_elementos_EXCLUSIVO = 0;
    int total_elementos_ESCALAR = 0;

    do { 
        printf("\n-------- MENU PRINCIPAL --------\n");
        printf("\t1. Ler vetor 1 (Max 30)\n");
        printf("\t2. Ler vetor 2 (Max 20)\n");
        printf("\t3. Listar vetores\n");
        printf("\t4. Somar vetores (Elemento por Elemento)\n");
        printf("\t5. Multiplicar vetor por um escalar\n");
        printf("\t6. Pesquisar numero em um vetor\n");
        printf("\t7. Gerar vetor de elementos exclusivos (Item 7)\n");
        printf("\t8. Intercalar vetores ordenados (Item 8)\n");
        printf("\t0. Sair\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                limpartela();
                printf("-------- Lendo o Vetor 1 --------\n");
                lerVetor(vetor1, &total_elementos1, 30);
                break;
            
            case 2:
                limpartela();
                printf("-------- Lendo o Vetor 2 --------\n");
                lerVetor(vetor2, &total_elementos2, 20);
                break;
            
            case 3:
                limpartela();
                printf("-------- Listar qual vetor? --------\n");
                printf("\t1. Vetor 1\n");
                printf("\t2. Vetor 2\n");
                printf("\t3. Vetor Somado\n");
                printf("\t4. Vetor Exclusivo (Item 7)\n");
                printf("\t5. Vetor Escalado\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &subOpcao);    
                
                if (subOpcao == 1) {
                    if (total_elementos1 == 0) printf("\nERROR! Vetor 1 ainda nao foi lido.\n");
                    else listarVetor(vetor1, total_elementos1, 1);
                } else if (subOpcao == 2) {
                    if (total_elementos2 == 0) printf("\nERROR! Vetor 2 ainda nao foi lido.\n");
                    else listarVetor(vetor2, total_elementos2, 2);
                } else if (subOpcao == 3) {
                    if (total_elementos_SOMA == 0) printf("\nERROR! Vetor Soma ainda nao foi gerado.\n");
                    else listarVetor(vetor_SOMA, total_elementos_SOMA, 3);
                } else if (subOpcao == 4) {
                    if (total_elementos_EXCLUSIVO == 0) printf("\nERROR! Vetor Exclusivo ainda nao foi gerado.\n");
                    else listarVetor(vetor_EXCLUSIVO, total_elementos_EXCLUSIVO, 7);
                } else if (subOpcao == 5) {
                    if (total_elementos_ESCALAR == 0) printf("\nERROR! Nenhum vetor escalado foi gerado ainda.\n");
                    else listarVetor(vetor_ESCALAR1, total_elementos_ESCALAR, 5);
                } else {
                    printf("Opcao invalida!\n");
                }
                break;

            case 4:
                limpartela();
                if (total_elementos1 == 0 || total_elementos2 == 0) {
                    printf("\nERROR! Leia os vetores 1 e 2 primeiro.\n");
                } else if (total_elementos1 != total_elementos2) {
                    printf("\nERROR! Os dois vetores precisam ter o mesmo tamanho para somar elemento a elemento.\n");
                } else {
                    total_elementos_SOMA = total_elementos1;
                    somarVetor(vetor1, vetor2, vetor_SOMA, total_elementos_SOMA);
                    printf("Vetores somados com sucesso!\n");
                    listarVetor(vetor_SOMA, total_elementos_SOMA, 3);
                }
                break;

            case 5:   
                limpartela();
                printf("Qual vetor deseja multiplicar por escalar?\n");
                printf("\t1. Vetor 1\n");
                printf("\t2. Vetor 2\n");
                printf("\t3. Vetor Somado\n");
                printf("Escolha uma opcao: ");
                            
                scanf("%d", &subOpcao);
                
                if (subOpcao == 1) { 
                    if (total_elementos1 == 0) printf("\nERROR! Vetor 1 ainda nao foi lido.\n");
                    else {
                        total_elementos_ESCALAR = total_elementos1;
                        gerarEscalar(vetor_ESCALAR1, vetor1, total_elementos_ESCALAR);
                        printf("\nNovo vetor escalado gerado com sucesso!\n");
                        listarVetor(vetor_ESCALAR1, total_elementos_ESCALAR, 1); 
                    }
                } else if (subOpcao == 2) {
                    if (total_elementos2 == 0) printf("\nERROR! Vetor 2 ainda nao foi lido.\n");
                    else {
                        total_elementos_ESCALAR = total_elementos2;
                        gerarEscalar(vetor_ESCALAR2, vetor2, total_elementos_ESCALAR);
                        printf("\nNovo vetor escalado gerado com sucesso!\n");
                        listarVetor(vetor_ESCALAR2, total_elementos_ESCALAR, 2); 
                    }
                } else if (subOpcao == 3) {
                    if (total_elementos_SOMA == 0) printf("\nERROR! Gere o vetor soma primeiro.\n");
                    else {
                        total_elementos_ESCALAR = total_elementos_SOMA;
                        gerarEscalar(vetor_ESCALAR_SOMA, vetor_SOMA, total_elementos_ESCALAR);
                        printf("\nNovo vetor escalado gerado com sucesso!\n");
                        listarVetor(vetor_ESCALAR_SOMA, total_elementos_ESCALAR, 3);
                    }
                } else {
                    printf("Opcao invalida!\n");
                }
                break;

            case 6:
                limpartela();
                printf("-------- Pesquisar numero em qual vetor? --------\n");
                printf("\t1. Vetor 1\n");
                printf("\t2. Vetor 2\n");
                printf("\t3. Vetor Somado\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &subOpcao);    
                
                if (subOpcao == 1) {
                    if (total_elementos1 == 0) printf("\nERROR! Vetor 1 ainda nao lido.\n");
                    else verificador(vetor1, total_elementos1, obterNumero());
                } else if (subOpcao == 2) {
                    if (total_elementos2 == 0) printf("\nERROR! Vetor 2 ainda nao lido.\n");
                    else verificador(vetor2, total_elementos2, obterNumero());
                } else if (subOpcao == 3) {
                    if (total_elementos_SOMA == 0) printf("\nERROR! Vetor soma ainda nao gerado.\n");
                    else verificador(vetor_SOMA, total_elementos_SOMA, obterNumero());
                } else {
                    printf("Opcao invalida!\n");
                }
                break;

            case 7:
                limpartela();
                if (total_elementos1 == 0 || total_elementos2 == 0) {
                    printf("\nERROR! Leia os vetores 1 e 2 primeiro.\n");
                } else {
                    // Chamada corrigida com tamanhos independentes e ponteiro
                    gerarExclusivos(vetor1, total_elementos1, vetor2, total_elementos2, vetor_EXCLUSIVO, &total_elementos_EXCLUSIVO);
                    printf("Vetor de elementos exclusivos gerado com sucesso!\n");
                    listarVetor(vetor_EXCLUSIVO, total_elementos_EXCLUSIVO, 7);
                }
                break;

            case 8:
                limpartela();
                printf("-------- INTERCALACAO DE VETORES --------\n");
                printf("Escolha o PRIMEIRO vetor:\n");
                printf("\t1. Vetor 1\n");
                printf("\t2. Vetor 2\n");
                printf("\t3. Vetor Somado\n");
                printf("\t4. Vetor Exclusivo (Item 7)\n");
                printf("Opcao: ");
                int op1, op2;
                scanf("%d", &op1);

                printf("\nEscolha o SEGUNDO vetor:\n");
                printf("\t1. Vetor 1\n");
                printf("\t2. Vetor 2\n");
                printf("\t3. Vetor Somado\n");
                printf("\t4. Vetor Exclusivo (Item 7)\n");
                printf("Opcao: ");
                scanf("%d", &op2);

                int *vA = NULL, tamA = 0;
                int *vB = NULL, tamB = 0;

                if (op1 == 1) { vA = vetor1; tamA = total_elementos1; }
                else if (op1 == 2) { vA = vetor2; tamA = total_elementos2; }
                else if (op1 == 3) { vA = vetor_SOMA; tamA = total_elementos_SOMA; }
                else if (op1 == 4) { vA = vetor_EXCLUSIVO; tamA = total_elementos_EXCLUSIVO; }

                if (op2 == 1) { vB = vetor1; tamB = total_elementos1; }
                else if (op2 == 2) { vB = vetor2; tamB = total_elementos2; }
                else if (op2 == 3) { vB = vetor_SOMA; tamB = total_elementos_SOMA; }
                else if (op2 == 4) { vB = vetor_EXCLUSIVO; tamB = total_elementos_EXCLUSIVO; }

                if (tamA == 0 || tamB == 0) {
                    printf("\nERROR! Um ou ambos os vetores selecionados ainda nao foram gerados.\n");
                } else {
                    int total_intercalado = 0;
                    int vetor_INTERCALADO[50];

                    intercalarVetores(vA, tamA, vB, tamB, vetor_INTERCALADO, &total_intercalado);

                    printf("\nVetor intercalado gerado com sucesso!\n");
                    listarVetor(vetor_INTERCALADO, total_intercalado, 8);
                }
                break;

            case 0:
                limpartela();
                printf("\nSaindo do programa...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}