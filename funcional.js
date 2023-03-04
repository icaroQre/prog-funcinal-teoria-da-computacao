// definindo os produtos
const produtos = [
    { id: 1, nome: 'Camisa lisa M', preco: 25.0, categoria: 'Vestuário' },
    { id: 2, nome: 'Calça cargo G', preco: 50.0, categoria: 'Vestuário' },
    { id: 3, nome: 'Livro it: a coisa', preco: 32.0, categoria: 'Livros' },
    { id: 4, nome: 'Bicicleta', preco: 300.0, categoria: 'Esportes' },
    { id: 5, nome: 'Raquete', preco: 75.0, categoria: 'Esportes' },
    { id: 6, nome: 'Livro o assassinato de roger ackroyd', preco: 50.0, categoria: 'Livros'}
  ];

function calcularPrecosPorCategoria(produtos) {
    const categorias = [...new Set(produtos.map(produto => produto.categoria))]; // obtém as categorias únicas
    return categorias.reduce((acc, categoria) => {
      const produtosCategoria = produtos.filter(produto => produto.categoria === categoria); // filtra os produtos da categoria
      const precoCategoria = produtosCategoria.reduce((total, produto) => total + produto.preco, 0); // calcula o preço total da categoria
      acc[categoria] = precoCategoria; // adiciona a categoria ao objeto acumulado
      return acc;
    }, {});
  }
  
  const precosPorCategoria = calcularPrecosPorCategoria(produtos);
  console.log(precosPorCategoria);
  