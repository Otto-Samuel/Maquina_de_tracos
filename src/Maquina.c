#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>

char tracos1[2000];
char tracos2[2000];
char tracos3[2000];

char mapearParaLetra(char *bloco) {
         if (strcmp(bloco, "AAA") == 0) return 'A';
    else if (strcmp(bloco, "AAC") == 0) return 'B';
    else if (strcmp(bloco, "AAG") == 0) return 'C';
    else if (strcmp(bloco, "AAT") == 0) return 'D';
    else if (strcmp(bloco, "ACA") == 0) return 'E';
    else if (strcmp(bloco, "ACC") == 0) return 'F';
    else if (strcmp(bloco, "ACG") == 0) return 'G';
    else if (strcmp(bloco, "ACT") == 0) return 'H';
    else if (strcmp(bloco, "AGA") == 0) return 'I';
    else if (strcmp(bloco, "AGC") == 0) return 'J';
    else if (strcmp(bloco, "AGG") == 0) return 'K';
    else if (strcmp(bloco, "AGT") == 0) return 'L';
    else if (strcmp(bloco, "ATA") == 0) return 'M';
    else if (strcmp(bloco, "ATC") == 0) return 'N';
    else if (strcmp(bloco, "ATG") == 0) return 'O';
    else if (strcmp(bloco, "ATT") == 0) return 'P';
    else if (strcmp(bloco, "CAA") == 0) return 'Q';
    else if (strcmp(bloco, "CAC") == 0) return 'R';
    else if (strcmp(bloco, "CAG") == 0) return 'S';
    else if (strcmp(bloco, "CAT") == 0) return 'T';
    else if (strcmp(bloco, "CCA") == 0) return 'U';
    else if (strcmp(bloco, "CCC") == 0) return 'V';
    else if (strcmp(bloco, "CCG") == 0) return 'W';
    else if (strcmp(bloco, "CCT") == 0) return 'X';
    else if (strcmp(bloco, "CGA") == 0) return 'Y';
    else if (strcmp(bloco, "CGC") == 0) return 'Z';
    else if (strcmp(bloco, "CGG") == 0) return '0';
    else if (strcmp(bloco, "CGT") == 0) return '1';
    else if (strcmp(bloco, "CTA") == 0) return '_';
    // ...
    else return ' '; // Retorna espaço se o bloco não mapear para uma letra
}
///////////////////////////////////////////////////////////////////////////////////////////////////


void monolitico(char *dna1) {
  char bloco[4]; // Each block of DNA molecules has a maximum of 3 bases + 1 for the null character
  int tamanho = strlen(dna1);
  int indiceBloco = 0;
  int i = 0;
  int t = 0;

  tracos1[t++] = 'A'; // Start tracing character

  loop:
    if (i >= tamanho) goto end; // Check if end of DNA sequence reached

    bloco[indiceBloco++] = dna1[i];
    tracos1[t++] = 'B'; // Tracing character indicating block processing

    if (indiceBloco == 3) { // When the block is complete
      tracos1[t++] = 'F'; // Tracing character indicating block completion
      bloco[indiceBloco] = '\0'; // Add null terminator to the block
      char letra = mapearParaLetra(bloco); // Map the block to a letter

      // Check if the translated letter is a space before printing "palavra"
      if (letra != ' ') {
        printf("%c", letra); // Print the translated letter
      }

      indiceBloco = 0; // Reset the block index
    }

    i++;
    goto loop;

  end:
    tracos1[t++] = 'C'; // End tracing character
    printf("\n"); // Print a new line
}

void iterativo(char *dna) {
    char bloco[4]; // Cada bloco de moléculas de DNA tem no máximo 3 bases + 1 para o caractere nulo
    int tamanho = strlen(dna);
    int indiceBloco = 0;
    int i = 0;
    int t = 0;

    while (i < tamanho) {
        tracos2[t++] = 'A';

        bloco[indiceBloco++] = dna[i];
        tracos2[t++] = 'B';

        if (indiceBloco == 3 || i == tamanho - 1) { // Quando o bloco estiver completo ou for a última base
            tracos2[t++] = 'F';
            bloco[indiceBloco] = '\0'; // Adiciona o caractere nulo ao final do bloco
            printf("%c", mapearParaLetra(bloco)); // Mapeia o bloco para uma letra e imprime
            indiceBloco = 0;
        }

        i++;
    }

    tracos2[t++] = 'C';
    printf("\n"); // Imprime uma nova linha para separar as mensagens
}

int main(){
    system("cls");
    printf("+++++++++++++++++++++++++\n\t   menu\n+++++++++++++++++++++++++\n");
    printf("\n - problema da cifra de DNA \n\n");
    printf("1 - monolitico\n2 - iterativo\n3 - recursivo\n4 - mostrar equivalencia\n5 - sair\n");
    int op;
    scanf("%d", &op);

    switch (op)
    {
    case 1: 
        v1:
        system("cls");
        char dna[201]; // Máximo de 200 bases + 1 para o caractere nulo
        printf("Entre com as moleculas de DNA: ");
        scanf("%s", dna);
        monolitico(dna);
        
        // Imprime o array tracos1
        printf("Tracos: [ ");
        
        for (int i = 0; i < 2000 && tracos1[i] != '\0'; i++) {
            printf("%c ", tracos1[i]);
        }
        printf(" ]\n");

        printf("\ndeseja retornar ao menu ? (s/n)");
        char resposta1;
        scanf(" %c", &resposta1);
        if (resposta1 == 's'){
            system("cls");
            main();
        }else{
            goto v1;
        }

        
        break;
    case 2: // iterativo
            v2:
            system("cls");
            
            char dna2[201]; // Máximo de 200 bases + 1 para o caractere nulo
            printf("Entre com as moleculas de DNA: ");
            scanf("%s", dna2);
            iterativo(dna2);
            
            // Imprime o array tracos2
            printf("Tracos do iterativo: [ ");
            
            for (int i = 0; i < 2000 && tracos2[i] != '\0'; i++) {
                printf("%c ", tracos2[i]);
            }
            printf(" ]\n");

            printf("\ndeseja retornar ao menu ? (s/n)");
            char resposta2;
            scanf(" %c", &resposta2);
            if (resposta2 == 's'){
                system("cls");
                main();
            } else {
                goto v2;
            }
        break;
    case 3: // recursivo
        v3:
        system("cls");
        char dna3[201]; // Máximo de 200 bases + 1 para o caractere nulo
        printf("Entre com as moleculas de DNA: ");
        scanf("%s", dna3);
        recursivo(dna3);

        printf("\ndeseja retornar ao menu ? (s/n)");
        char resposta3;
        scanf(" %c", &resposta3);
        if (resposta3 == 's'){
            system("cls");
            main();
        }else{
            goto v3;
        }
        break;
    case 4: // mostrar equivalencia
        system("cls");
        printf("Tracos do Monolitico: [ ");
        for (int i = 0; i < 2000 && tracos1[i] != '\0'; i++) {
            printf("%c", tracos1[i]);
        }
        printf(" ]\n\n");

        printf("Tracos do Iterativo: [ ");
        for (int i = 0; i < 2000 && tracos2[i] != '\0'; i++) {
            printf("%c", tracos2[i]);
        }
        printf(" ]\n");

        printf("\nTracos do Recursivo: [ ");
        for (int i = 0; i < 2000 && tracos3[i] != '\0'; i++) {
            printf("%c", tracos3[i]);
        }
        printf(" ]\n\n");

        // Compare os tracos usando strcmp
        if (tracos1 == tracos3) {
            printf("Os tracos sao iguais\n");
            printf("> os programas monolitico e recursivo sao equivalentes !!!\n\n");
        }else if(tracos2 == tracos3){
            printf("Os tracos sao iguais\n");
            printf("> os programas iterativo e recursivo sao equivalentes !!!\n\n");
        }else if(tracos1 == tracos2) {
            printf("Os tracos sao diferentes\n");
            printf("> os programas monolitico e iterativo sao equivalentes !!!\n\n");
        } else if((tracos1 == tracos2) && (tracos2 == tracos3) && (tracos1 == tracos3)){
            printf("Os tracos sao iguais\n");
            printf("> os programas monolitico, recursivo e iterativo sao equivalentes !!!\n\n");
        }
        else{
            printf("Os tracos { Nao } sao esquivalentes\n");
        }
    break;

    case 5:
        exit(0);
        break;
        
    default:
        break;
    }
}

////////////////////////////////////////////////////////

void subrotina(char *dna, int tamanho, int i, int indiceBloco, int t) {
    if (i >= tamanho) {
        tracos3[t++] = 'C'; // Marca o final da sequência de traços
        printf("\n"); // Imprime uma nova linha para separar as mensagens
        return;
    }

    tracos3[t++] = 'A'; // Marca o início de um novo bloco

    char bloco[4]; 
    bloco[indiceBloco++] = dna[i];
    tracos3[t++] = 'B'; // Marca a adição de uma base ao bloco

    // Se o bloco estiver completo ou for a última base, mapeia e imprime
    if (indiceBloco == 3 || i == tamanho - 1) {
        tracos3[t++] = 'F';
        bloco[indiceBloco] = '\0'; // Adiciona o caractere nulo ao final do bloco
        printf("%c", mapearParaLetra(bloco)); // Mapeia o bloco para uma letra e imprime
        indiceBloco = 0; // Reseta o índice do bloco para o próximo bloco
    }

    // Chamada recursiva para processar o restante do DNA
    subrotina(dna, tamanho, i + 1, indiceBloco, t);
}

void recursivo(char *dna) {
    int tamanho = strlen(dna);
    int indiceBloco = 0;
    int t = 0;
    tracos3[t++] = 'A'; // Marca o início da sequência de traços
    subrotina(dna, tamanho, 0, indiceBloco, t);
    tracos3[t++] = 'C'; // Marca o final da sequência de traços
    printf("\n"); // Imprime uma nova linha para separar as mensagens

    // Imprime a palavra correspondente à sequência de DNA
    printf("Palavra: ");
    for (int i = 0; i < tamanho; i += 3) {
        char bloco[4];
        strncpy(bloco, dna + i, 3);
        bloco[3] = '\0';
        printf("%c", mapearParaLetra(bloco));
    }

    // Imprime o array tracos3
    printf("\nTracos do Recursivo: [ ");
    for (int i = 0; i < 2000 && tracos3[i] != '\0'; i++) {
        printf("%c ", tracos3[i]);
    }
    printf(" ]\n\n");
}