#include<stdio.h>                   //// Pedro Henrique Da Silva Passos     Número USP:12683096
#include<string.h>               
#define size 501

int encontrar( char string[], char substring[]);

int main(){
    // leitura da string
    char string[size];
    printf("Informe uma string de no maximo 500 caracteres: ");
    gets(string);

    char substring[size];
    printf("\nInforme uma substring de no maximo 500 caracteres: ");
    gets(substring);

    int posicao = 0;

    posicao = encontrar(string, substring); // chamada da funcao para encontrar substring

    if(posicao > 0){          //retorna a posicao que foi encontrado o primeiro caracter da substring na string
        printf("\nA substring existe e pode ser encontrada a partir da posicao : %d \n", posicao);  
    } else if (posicao == 0){ 
        printf("A substring nao existe dentro da string.");
    }
    return 0;
}


int encontrar( char string[], char substring[]) {
	int i = 0;
	int j = 0;
    int k = 0;

	for(i = 0; string[i] != '\0'; ++i) {
        for (j = i ,k = 0; string[j] == substring[k] && string[j] != '\0' && substring[k] != '\0' ; j++,k++);
        if (substring[k] == '\0' ){     // verifica as strings varrendo posicao por posicao, até que ambos caracteres sejam diferentes
                                        // ou o caracter nulo;
                                       // se a substring tiver o caracter nulo como ultimo caracter, funcao ira retornar o valor de i;
            return i + 1;
        }
	}
    return 0;      // caso a substring nao seja encontrada eh retornado o valor 0;
}