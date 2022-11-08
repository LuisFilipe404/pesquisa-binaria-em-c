/*
    Trabalho Pesquisa bińaria
    Aluno: Luís Filipe Silva de Vasconcelos
    Professor: Kayo Monteiro
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int qdd_numeros = 0;

// imprimir o vetor
void imprimir_vetor(int vetor[qdd_numeros]) {
    int i; // contador
    printf("\n\nSeu vetor é:\n\n[ ");
    
    // codigo para imprimir o vetor
    for(i = 0; i < qdd_numeros; i++) {
        printf("%d ", vetor[i]);
    }

    printf("]\n\n");
}


// imprimir e voltar para o menu
void imprimir_vetor_menu(int vetor[qdd_numeros]) {
    imprimir_vetor(vetor);

    menu(vetor);
}


// busca binaria - chave, meio, inicio e fim
int buscaBinariaRecursiva(int *vet, int chave, int inicio, int fim) {
    int meio = 0;
    if(inicio <= fim) {
        meio = (inicio + fim) / 2; // descobrir o meio
        if(chave == vet[meio]){
            return meio; // se achar retorne o valor
        } else {
            if(chave < vet[meio]) {
                return buscaBinariaRecursiva(vet, chave, inicio, meio - 1); // descartar todos os numeros a cima do resultado
            } else {
                return buscaBinariaRecursiva(vet, chave, inicio, meio + 1); // descartar todos os numeros abaixo do resultado
            }
        }
    }
    
    return -1; // caso nao exista valor retorne -1
}


// menu da pesquisa binaria
void pesquisa_binaria(int vetor[qdd_numeros]){
    system("clear"); // limpar console (win = cls, linux = clear)

    imprimir_vetor(vetor);
    int valor = 0; // valor a ser buscado - chave
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    //chamada da funcao pra realizar a busca
    printf("\nResultado: %d\n\n", buscaBinariaRecursiva(vetor, valor, 0, qdd_numeros - 1));

    menu(vetor);
}

void ordernar_vetor(int vetor[qdd_numeros]) {
    system("clear"); // limpar console (win = cls, linux = clear)
    imprimir_vetor(vetor);

    int i, x, aux; // variaveis de controle

    // Codigo de ordenacao
    for(i = 0; i < qdd_numeros; i++) {
        for(x = i + 1; x < qdd_numeros; x++){
            // troca de valores
            if(vetor[i] > vetor[x]) {
                aux = vetor[i];
                vetor[i] = vetor[x];
                vetor[x] = aux;
            }
        }
    }

    printf("Ordenacao concluida");
    imprimir_vetor(vetor);

    menu(vetor);
}

void pesquisa_sequencial(int vetor[qdd_numeros]){
    system("clear"); // limpar console (win = cls, linux = clear)
    int num = 0; // numero que será pesquisado

    imprimir_vetor(vetor);
    printf("Qual numero voce deseja pesquisar? ");
    scanf("%d", &num);
    
    int i; // contador
    int c = 0; // controlador caso nao encontre nenhum resultado
    printf("\n");

    // pesquisar um por um e caso encontre alterar o controlador para 1 e exibir na tela todos os resultados
    for(i = 0; i < qdd_numeros; i++) {
        if(vetor[i] == num) {
            printf("%d posicao: %d\n", i, num);
            c = 1;
        }
    }

    
    if(c == 0) {
        // caso o controlador nao seja alterado o resultado nao foi encontrado
        printf("\nValor nao encontrado!!\n\n");
        menu(vetor);
    } else {
        printf("\n\n");
        menu(vetor);
    }
}

void gerar_aleatorio() {
    system("clear"); // limpar console (win = cls, linux = clear)
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &qdd_numeros);

    int vetor[qdd_numeros];

    srand(time(NULL)); // randomizar o vetor baseado no tempo do computador

    int i; // contador
    int max; // valor maximo

    printf("Qual o valor maximo de numero que voce deseja: ");
    scanf("%d", &max);

    for(i = 0; i < qdd_numeros; i++) {
        vetor[i] = rand() % max + 1; // retornara no maximo o valor que foi enviado (max)
    }
    
    imprimir_vetor(vetor);

    menu(vetor);
}

void gerar_vetor() {
    system("clear"); // limpar console (win = cls, linux = clear)
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &qdd_numeros);

    int vetor[qdd_numeros];

    printf("Digite %d números:\n", qdd_numeros);

    int i; // contador

    //ler todos o vetor recebido por usuario
    for(i = 0; i < qdd_numeros; i++) {
        scanf("%d", &vetor[i]);
    }

    imprimir_vetor(vetor);

    menu(vetor);
    
}

void menu(int vetor[qdd_numeros]) {
    int opcao = 0; // opcao do menu

    do{
        printf("Digite uma opcao:\n\n(1)Gerar vetor\n(2)Gerar vetor aleatorio\n(3)Ordenar vetor\n(4)Imprimir vetor\n(5)Pesquisa Sequencial\n(6)Pesquisa Binaria\n(7)Sair\n");
        scanf("%d", &opcao);

        // Condiçao de erro
        if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7) {
            printf("\n\nOpcao Invalida");
        };
    } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7);

    switch(opcao){
        case 1:
            gerar_vetor();
            break;
        case 2:
            gerar_aleatorio();
            break;
        case 3:
            ordernar_vetor(vetor);
            break;
        case 4:
            imprimir_vetor_menu(vetor);
            break;
        case 5:
            pesquisa_sequencial(vetor);
            break;
        case 6:
            pesquisa_binaria(vetor);
            break;
        case 7:
            system("pause"); // pausar aplicacao
            break;
    }       
}

int main() {
    system("clear"); // limpar console (win = clear, linux = cls)
    int vetor[2] = {1, 2};
    menu(vetor);
}