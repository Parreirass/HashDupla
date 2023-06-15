# HashDupla
Estrutura hash básica

Uma estrutura de hash dupla, também conhecida como tabela de dispersão com hash duplo, é uma técnica de armazenamento e recuperação de dados que utiliza uma matriz (ou tabela) para mapear chaves para valores correspondentes. Ela é uma variação da estrutura de hash tradicional, que utiliza apenas uma função de hash para determinar a posição de armazenamento dos elementos.

Na estrutura de hash dupla, são utilizadas duas funções de hash distintas. Essas funções transformam as chaves em índices da tabela de dispersão. A primeira função de hash determina uma posição inicial na tabela, enquanto a segunda função de hash é usada para calcular o passo adicional a ser avançado caso ocorra uma colisão na posição inicial.

Quando ocorre uma colisão, ou seja, duas chaves diferentes são mapeadas para o mesmo índice, a segunda função de hash é aplicada à chave para calcular o deslocamento adicional na tabela. Esse deslocamento é somado ao índice inicial até encontrar uma posição vazia na tabela, onde o elemento pode ser inserido. Dessa forma, a estrutura de hash dupla permite tratar colisões de maneira eficiente, evitando o acúmulo excessivo de elementos em uma única posição.

A seleção de posição de ordenação é feita a partir do módulo da divisão (resto) da chave pelo número de elementos máximos do vetor, que deve ser um número primo. Caso tenha uma colisão, esse valor é multiplicado por um número "grande", no caso `100`, e é feita novamente essa divisão a fim de encontrar uma nova posição. Caso ocorra uma nova colisão, esse valor a ser multiplicado é sempre aumentado e o processo de divisão citado são repetidos até que não ocorra colisão.

![Hash DUpla](https://upload.wikimedia.org/wikipedia/commons/thumb/5/58/Hash_table_4_1_1_0_0_1_0_LL.svg/293px-Hash_table_4_1_1_0_0_1_0_LL.svg.png)

 ## Descrição
Este é um programa simples em C++ que calcula e exibe a posição de um elemento com `valor` e `chave` em uma tabela hash.

## Instruções de Compilação
Para compilar e executar o programa, siga estas etapas:

- Abra um editor de código e copie o código-fonte acima para um novo arquivo com a extensão .cpp, por exemplo, hash.cpp.
- Abra um terminal ou prompt de comando.
- Navegue até o diretório onde o arquivo hash.cpp está localizado usando o comando cd.
- Execute o comando de compilação, por exemplo, g++ -o hash hash.cpp (considerando que você tenha o GCC instalado).
- Após a compilação bem-sucedida, execute o programa com ./hash.
- Digite a chave e o valor que serão requeridos no sistema.
- A posição no vetor será exibida.

*Certifique-se de ter um compilador C++ instalado e configurado corretamente em seu ambiente de desenvolvimento antes de executar o programa.*
