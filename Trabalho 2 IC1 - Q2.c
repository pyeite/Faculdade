#include <stdio.h> //// Pedro Henrique Da Silva Passos     Número USP:12683096
/*  1. Escreva um programa que contenha uma função que retorne a primeira posição de uma substring dentro de uma string.
Caso a substring não seja encontrada, a função deve retornar zero.
   2. Faça um programa que leia dois números n e m e:
• Crie e leia um vetor de inteiros de n posições;
• Crie e leia um vetor de inteiros de m posições;
• Crie e construa um vetor de inteiros que seja a interseção entre os dois vetores anteriores, ou seja,
que contém apenas os números que estão em ambos os vetores. Não deve conter números repetidos.
*/
// Parte 2
void leitura_vetor(int vetor[], int tam)
{ // funcao responsavel por fazer leitura dos vetores;
   int i = 0;
   for (i = 0; i < tam; i++)
   {
      printf("Preencha o vetor: ");
      scanf("%d", &vetor[i]);
   }
}
// Funcao responsavel por verificar a interseccao dos vetores;
int interseccao(int vetorN[], int n, int vetorM[], int m, int vetorI[])
{
   int i = 0;
   int j = 0;
   int k = 0;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < m; j++)
      {
         if (vetorN[i] == vetorM[j])
         {
            vetorI[k] = vetorN[i];
            ++k; // responsavel por percorrer todas as posicoes do vetorI;
         }
      }
   }

   return k; // retorna o tamanho do vetor intersecao;
}

int main()
{
   int n = 0;
   int m = 0;
   int i = 0, j = 0, l = 0, c = 0;
   printf(" !! Insira os tamanhos para os respectivos vetores !! \n ");
   printf("Tamanho vetor N: ");
   scanf("%d", &n);
   printf(" Tamanho vetor M: ");
   scanf("%d", &m);
   int vetor_N[n];
   int vetor_M[m];
   int vetor_I[1000];
   printf("\n");

   printf("Leitura vetor N:\n");
   leitura_vetor(vetor_N, n); // chamada da funcao que faz leitura dos valores dos vetores;
   printf("\n");
   printf("Leitura vetor M\n");
   leitura_vetor(vetor_M, m);                        // chamada da funcao que faz leitura dos valores dos vetores;
   i = interseccao(vetor_N, n, vetor_M, m, vetor_I); // chamada da funcao que verifica a intersecao;

   printf("O vetor interseccao eh dado pelos seguintes valores: {");
   int flag;
   for (l = 0; l < i; l++)
   { // parte responsavel por verificar se existe duplicata dos valores;
      flag = 0;
      for (c = 0; c < l; c++)
      {
         if (vetor_I[l] == vetor_I[c])
         {            // analisa se existe um valor anterior ao analisado que seja semelhante as mesmo.
            flag = 1; // responsavel por isso é o for interno,isso é caso exista um valor igual, é atribuido a variavel flag o valor 1;
            break;
         }
      }
      if (flag == 0) // uma vez com o flag valendo 1, nao sera feito o printf do elemento na posicao i analisada.
      {
         printf(" %d ", vetor_I[l]); // valores do vetor intersecao
      }
   }
   printf("}");
   return 0;
}