#include <stdio.h>
#include <stdlib.h>  // Necessário para malloc

// Função strtok personalizada para dividir uma string com base em um caractere delimitador
char** strtok(char *string, char carac, int *quantidade){

    int i = 0, quant = 0;

    // Conta quantas vezes o caractere delimitador aparece na string
    while(string[i] != '\0'){
        if(carac == string[i])
            quant++;
        i++;
    }

    // Define a quantidade de substrings resultantes
    *quantidade = quant + 1;

    // Aloca um vetor de ponteiros para armazenar as substrings
    char **mat_string = malloc((quant + 1) * sizeof(char*));

    i = 0;

    // Itera para criar as substrings e armazená-las
    for(int j = 0; j < quant + 1; j++){
        // Avança até encontrar o delimitador ou o final da string
        while(string[i] != carac && string[i] != '\0')
            i++;

        // Aloca memória para a substring (com espaço para o caractere nulo '\0')
        mat_string[j] = malloc((i + 1) * sizeof(char));

        mat_string[j] = string;

        // Insere o caractere nulo no final da substring para delimitá-la corretamente
        mat_string[j][i] = '\0';

        // Move o ponteiro da string para a próxima parte após o delimitador
        string = string + i + 1;

        // Reinicia o índice para processar a próxima substring
        i = 0;
    }

    return mat_string;
}

int main (){

    int quantidade = 0;
    char string[50], caracter;

    // Solicita ao usuário que insira uma string
    printf("\nDigite uma string:\n>> ");
    scanf("%49[^\n]", string);  // Lê a string com espaços
    getchar();  // Limpa o buffer do teclado

    // Solicita ao usuário o caractere delimitador
    printf("\nDigite o caracter:\n>> ");
    scanf("%c", &caracter);

    // Chama a função strtok personalizada para dividir a string
    char **mat = strtok(string, caracter, &quantidade);

    // Exibe as substrings resultantes
    int i = 0;
    while(i < quantidade){
        printf("\"%s\"", mat[i]);
        i++;
        if(i != quantidade)
            printf(", ");
    }

    return 0;
}
