#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que define um produto
struct Produto {
  int id;
  char nome[50];
  float preco;
  char categoria[20];
};

// Função que calcula o preço total dos produtos de uma categoria
float calcularPrecosPorCategoria(struct Produto produtos[], int tamanho, char categoria[]) {
  float total = 0;
  // Percorre os produtos e soma o preço dos produtos da categoria desejada
  for (int i = 0; i < tamanho; i++) {
    if (strcmp(produtos[i].categoria, categoria) == 0) {
      total += produtos[i].preco;
    }
  }
  return total;
}

int main() {
  // Define um array de produtos
  struct Produto produtos[6] = {
    { 1, "Camiseta", 25.0, "Vestuário" },
    { 2, "Calça", 50.0, "Vestuário" },
    { 3, "Livro", 32.0, "Livros" },
    { 4, "Bicicleta", 300.0, "Esportes" },
    { 5, "Raquete", 75.0, "Esportes" },
    { 6, "Livro o assassinato de roger ackroyd", 50.0, "Livros"}
  };
  // Define um array de categorias
  char categorias[3][20] = { "Vestuário", "Livros", "Esportes" };
  // Define o número de categorias
  int num_categorias = 3;
  // Define um array para armazenar os preços totais de cada categoria
  float precos_por_categoria[num_categorias];
  // Percorre as categorias e calcula o preço total de cada uma
  for (int i = 0; i < num_categorias; i++) {
    precos_por_categoria[i] = calcularPrecosPorCategoria(produtos, 6, categorias[i]);
  }
  // Imprime o resultado no formato de um objeto
  printf("{ ");
  for (int i = 0; i < num_categorias; i++) {
    printf("\"%s\": %.1f", categorias[i], precos_por_categoria[i]);
    if (i < num_categorias - 1) {
      printf(", ");
    }
  }
  printf(" }\n");
  return 0;
}
