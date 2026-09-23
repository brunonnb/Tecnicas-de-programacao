/*Elaborar um programa em Linguagem C que apresente um Menu para o usuário com as seguintes opções:

1) Obter a quantidade M (M <= 30) de elementos e também os elementos de um primeiro vetor de números inteiros;

2) Obter a quantidade N (N <= 20) de elementos e também os elementos de um segundo vetor de números inteiros;

3) Listar os elementos de um vetor de números inteiros;

4) Gerar um vetor obtido através da adição de dois vetores de números inteiros (adicionar os elementos correspondentes dos dois vetores);

5) Gerar um vetor obtido através da multiplicação de um escalar por um vetor de números inteiros;

6) Pesquisar se um determinado número existe ou não em um vetor;

7) Gerar um vetor obtido a partir de dois vetores, contendo os elementos que aparecem em apenas um dos dois vetores;

8) Gerar um vetor obtido pela intercalação de dois outros vetores ordenados (em ordem crescente de valores), mantendo a ordenação;

9) Finalizar a execução do programa.*/

#include <stdlib.h>
#include <stdio.h>

void limpartela(){
    //essa funcao limpa a tela para evitar poluicao visual
    
    system("cls");
}

int obterQuantidade(int limite) {
    //essa funcao permite que o usuario escolha o tamanho do vetor 1 ou 2 
    
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

int obterNumero(){
    //essa funcao permite que o usuario escolha qual numero ele quer verificar se existe no vetor
    
    int n;
    printf("Digite o numero que deseja verificar: \n");
    scanf("%d", &n);
    return n;
}

int obterEscalar(){
    //essa funcao permite que o usuario escolha o numero da escalar
    
    int esc;
    printf("Digite o valor do numero escalar (multiplicador): ");
    scanf("%d", &esc);
    return esc;
}

void lerVetor(int vetor[], int *tamanho_real, int limite_maximo) {
    //essa funcao le os elementos do vetor designado
    
    *tamanho_real = obterQuantidade(limite_maximo);

    for (int i = 0; i < *tamanho_real; i++) {
        printf("Digite o elemento [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}

void listarVetor(int vetor[], int *tamanho_real , int n_vetor){
    //essa funcao imprime os valores do vetor desejado na tela
    
    printf("Elementos do vetor %d: ", n_vetor);

    for(int i = 0 ; i < *tamanho_real; i++){
        printf(" [%d] = %d ", i , vetor[i]);
    }
    printf("\n");
    
}

void somarVetor(int v1[], int v2[], int vSoma[], int tamanho){
    //essa funcao somas os vetores 1 e 2 
    
    for(int i = 0 ; i < tamanho ; i++){
        vSoma[i] = v1[i] + v2[i];
    }
}

void somarVetor_2(int v1[], int v2[], int vNovo[], int tamanho){
 //essa funcao cria um vetor contendo os elementos que aparecem em apenas um dos dois vetores.
    for(int i = 0 ; i < tamanho ; i++){
        for(int j = 0 ; j < tamanho ; j++){ //varredura de elementos do vetor 2 para comparar com o vetor 1
            if(v1[i] != v2[j]){
                vNovo[i] = v1[i];
            }
        }
    }
}

void gerarEscalar(int vetor_d [], int vetor_o [], int tamanho){
    //funcao para gerar a escalar
    
    int escalar = obterEscalar();
    
    for(int i = 0 ; i < tamanho ; i++){
        vetor_d[i] = vetor_o[i] * escalar;
    }
}

void verificador(int vetor[], int tamanho, int numero){
    //funcao para verificar se o numero escolhido anteriormente existe no vetor designado
    
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

int main () {
    int opcao;
    int vetor1[30];
    int vetor2[20];
    int vetor_SOMA[20];
    int vetor_SOMA2[20];
    int vetor_ESCALAR1[30];
    int vetor_ESCALAR2[20];
    int vetor_ESCALAR_SOMA[20];
    int total_elementos1 = 0;
    int total_elementos2 = 0;
    int total_elementos_SOMA = 0;
    int total_elementos_ESCALAR = 0;

    do{ 
        printf("\n-------- MENU PRINCIPAL --------\n");
        printf("\t1. Ler vetor 1.\n");
        printf("\t2. Ler vetor 2\n");
        printf("\t3. Listar vetores \n");
        printf("\t4. Somar vetores \n");
        printf("\t5. Multiplicar por escalar \n");
        printf("\t6. Pesquisar numero \n");
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
                printf("-------- Listar qual vetor ? --------\n");
                printf("\t1. Listar vetor 1\n");
                printf("\t2. Listar vetor 2\n");
                printf("\t3. Listar vetor Somado\n");
                printf("\t4. Listar vetor escalado \n");
                printf("\n Escolha uma opcao: ");

                scanf("%d", &opcao);    
                
                if(opcao == 1 ){
                    if(total_elementos1 == 0){
                             printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                            printf("-------- Listando vetor 1 --------\n");
                            listarVetor(vetor1,&total_elementos1,1);
                    }
                } else if(opcao == 2){
                    if(total_elementos2 == 0){
                             printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                            printf("-------- Listando vetor 2 --------\n");
                            listarVetor(vetor2,&total_elementos2,2);
                    }
                } else if(opcao == 3){
                    if(total_elementos_SOMA == 0){
                        printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                        printf("-------- Listando vetor Somado --------\n");
                        listarVetor(vetor_SOMA,&total_elementos_SOMA , 3);
                    }
                } else if(opcao == 4){
                    if(total_elementos_ESCALAR == 0){
                        printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                        limpartela();
                        printf("-------- Qual vetor (escalado) ? --------\n");
                        printf("\t1. Listar vetor 1\n");
                        printf("\t2. Listar vetor 2\n");
                        printf("\t3. Listar vetor Somado\n");
                        printf("\nEscolha uma opcao: ");

                        scanf("%d", &opcao);

                        if (opcao == 1){
                            if(total_elementos1 == 0){
                             printf("\nERROR ! Vetor ainda nao gerado.\n");
                            } else {
                                    printf("-------- Listando vetor 1 --------\n");
                                    listarVetor(vetor_ESCALAR1,&total_elementos1,1);
                            }
                        } else if (opcao == 2){
                            if(total_elementos2 == 0){
                             printf("\nERROR ! Vetor ainda nao gerado.\n");
                            } else {
                                    printf("-------- Listando vetor 2 --------\n");
                                    listarVetor(vetor_ESCALAR2,&total_elementos2,2);
                            }
                        } else if (opcao == 3){
                            if(total_elementos_SOMA == 0){
                                printf("\nERROR ! Vetor ainda nao gerado.\n");
                            } else {
                                printf("-------- Listando vetor Somado --------\n");
                                listarVetor(vetor_ESCALAR_SOMA,&total_elementos_SOMA , 3);
                            }
                        } else { 
                            printf("Opcao invalida! \n");
                        }
                    }

                } else printf("Opcao invalida! ");
            
                break;

            case 4: 
                limpartela();
                printf("Soma normal (1) ou soma sem repeticao (2)?\n");
                printf("Escolha uma opcao (1 ou 2): "); scanf("%d", &opcao);
                if(opcao == 1){
                    if(total_elementos1 != total_elementos2){
                        printf("\nERROR!!! Os dois vetores precisam ter o mesmo tamanho.\n");
                    
                    } else if (total_elementos1 == 0 || total_elementos2 == 0){
                        printf("\nERROR!!! Leia os dados primeiro.\n");
                    
                    } else {
                        total_elementos_SOMA = total_elementos1;

                        somarVetor(vetor1, vetor2, vetor_SOMA, total_elementos_SOMA);

                        printf("Vetores somados com sucesso!\n");
                        printf("\nDeseja ver o resultado? 1 - sim | 2 - nao\n");
                        printf("\nEscolha uma opcao: ");

                        scanf("%d", &opcao);
                        if(opcao == 1) {
                            listarVetor(vetor_SOMA, &total_elementos_SOMA, 3);
                        } else if(opcao > 2 || opcao < 0){
                            printf("ERROR!!! Opcao invalida.\n");
                        }
                    }
                } else {
                    if(total_elementos1 != total_elementos2){
                        printf("\nERROR!!! Os dois vetores precisam ter o mesmo tamanho.\n");
                    
                    } else if (total_elementos1 == 0 || total_elementos2 == 0){
                        printf("\nERROR!!! Leia os dados primeiro.\n");
                    
                    } else {
                        total_elementos_SOMA = total_elementos1;

                        somarVetor_2(vetor1, vetor2, vetor_SOMA2, total_elementos_SOMA);

                        printf("Vetores somados com sucesso!\n");
                        printf("\nDeseja ver o resultado? 1 - sim | 2 - nao\n");
                        printf("\nEscolha uma opcao: ");

                        scanf("%d", &opcao);
                        if(opcao == 1) {
                            listarVetor(vetor_SOMA2, &total_elementos_SOMA, 3);
                        } else if(opcao > 2 || opcao < 0){
                            printf("ERROR!!! Opcao invalida.\n");
                        }
                    }
                }
                break;

            case 5:     
                limpartela();
                printf("Qual vetor deseja mulitplicar? 1 || 2 || 3(v1 + v2)\n");
                printf("Escolha uma opcao: ");
                            
                scanf("%d", &opcao);
                
                if(opcao == 1){
                        if(total_elementos1 == 0){
                            printf("\nERROR ! Vetor ainda nao gerado.\n");
                        } else{
                            total_elementos_ESCALAR = total_elementos1;
                            
                            gerarEscalar(vetor_ESCALAR1, vetor1 , total_elementos_ESCALAR);

                            printf("\nNovo vetor gerado com sucesso!\n");
                            listarVetor(vetor_ESCALAR1, &total_elementos_ESCALAR, 4); 
                        }
                    
                } else if (opcao == 2){
                        if(total_elementos2 == 0){
                            printf("\nERROR ! Vetor ainda nao gerado.\n");
                        } else {
                            total_elementos_ESCALAR = total_elementos2;
                            
                            gerarEscalar(vetor_ESCALAR2, vetor2 , total_elementos_ESCALAR);
                            
                            printf("\nNovo vetor gerado com sucesso!\n");
                            listarVetor(vetor_ESCALAR2, &total_elementos_ESCALAR, 4); 
                        }
                    
                } else if (opcao == 3){
                        if(total_elementos1 == 0 || total_elementos2 == 0){
                            printf("\nERROR!!! Gere o vetor soma primeiro.\n");
                    
                        } else {
                            total_elementos_ESCALAR = total_elementos_SOMA;
                            
                            gerarEscalar(vetor_ESCALAR_SOMA, vetor_SOMA , total_elementos_ESCALAR);

                            printf("\nNovo vetor gerado com sucesso!\n");
                            listarVetor(vetor_ESCALAR_SOMA, &total_elementos_ESCALAR, 4);  
                        }
                } else if(opcao > 3 || opcao < 0) {
                        printf("ERROR!!! Opcao invalida.\n");
                    
                }
  
                break;
            case 6:
                limpartela();

                printf("-------- Verificar em qual vetor ? --------\n");
                printf("\t1. Vetor 1\n");
                printf("\t2. Vetor 2\n");
                printf("\t3. Vetor Somado\n");
                printf("\t4. Vetor escalado\n");
                printf("\n Escolha uma opcao: ");

                scanf("%d", &opcao);    
                
                if(opcao == 1 ){
                    if(total_elementos1 == 0){
                             printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                            printf("-------- Verificando vetor 1 --------\n");
                            int numero = obterNumero();
                            verificador(vetor1, total_elementos1, numero);
                    }
                } else if(opcao == 2){
                    if(total_elementos2 == 0){
                             printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                            printf("-------- Verificando vetor 2 --------\n");
                            int numero = obterNumero();
                            verificador(vetor2, total_elementos2, numero);
                    }
                } else if(opcao == 3){
                    if(total_elementos_SOMA == 0){
                        printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                        printf("-------- Verificando vetor Somado --------\n");
                        int numero = obterNumero();
                        verificador(vetor_SOMA, total_elementos_SOMA, numero);
                    }
                } else if(opcao == 4){
                    if(total_elementos_ESCALAR == 0){
                        printf("\nERROR ! Vetor ainda nao gerado.\n");
                    } else {
                        limpartela();
                        printf("-------- Qual vetor (escalado) ? --------\n");
                        printf("\t1. Verificar vetor 1\n");
                        printf("\t2. Verificar vetor 2\n");
                        printf("\t3. Verificar vetor Somado\n");
                        printf("\nEscolha uma opcao: ");

                        scanf("%d", &opcao);

                        if (opcao == 1){
                            if(total_elementos_ESCALAR == 0){
                             printf("\nERROR ! Vetor ainda nao gerado.\n");
                            } else {
                                    printf("-------- Verificando vetor 1 --------\n");
                                    int numero = obterNumero();
                                    verificador(vetor_ESCALAR1, total_elementos1, numero);
                            }
                        } else if (opcao == 2){
                            if(total_elementos2 == 0){
                            printf("\nERROR ! Vetor ainda nao gerado.\n");
                            } else {
                                    printf("-------- Verificando vetor 2 --------\n");
                                    int numero = obterNumero();
                                    verificador(vetor_ESCALAR2, total_elementos2, numero);
                            }
                        } else if (opcao == 3){
                            if(total_elementos_SOMA == 0){
                                printf("\nERROR ! Vetor ainda nao gerado.\n");
                            } else {
                                printf("-------- Soma normal(1) ou Sem repeticao(2)? --------\n");
                                scanf("%d", &opcao);
                                if(opcao == 1){
                                    printf("-------- Verificando vetor Somado --------\n");
                                    int numero = obterNumero();
                                    verificador(vetor_ESCALAR_SOMA, total_elementos_SOMA, numero);
                                } else if(opcao == 2){
                                    printf("-------- Verificando vetor Somado sem repeticao --------\n");
                                    int numero = obterNumero();
                                    verificador(vetor_SOMA2, total_elementos_SOMA, numero);
                                } else {
                                    printf("ERROR!!! Opcao invalida.\n");
                                }
                            }
                        } else { 
                            printf("Opcao invalida! \n");
                        }
                    }

                } else printf("Opcao invalida! ");
            
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