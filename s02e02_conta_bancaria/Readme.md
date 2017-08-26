## Conta Bancária

O objetivo dessa atividade é implementar uma classe responsável por
gerenciar a conta bancária de um único cliente.

Ela deve ser capaz de:
- guardar o número da conta
- realizar operações básica de saque e depósito
- realizar transferência entre contas
- retornar o extrato das operações.

A classe não está completamente definida. Alguns parâmetros já estão tipados **sugerindo** o tipo de variável a ser utilizado. Outros como o **vetor** são dependentes da linguagem que estiver trabalhando.
Cabe a você **decidir** os
tipos de cada **parâmetro** e de cada **retorno** de método. Se precisar
de métodos auxiliares, crie-os.

Tente criar alguns **testes** para sua classe, para garantir que ela
funciona como é esperado.

O trecho de código abaixo são **sugestões** de métodos e parâmetros.


### Sugestão de Métodos

```c++
class Conta{
atributos:
    int numero  //o id da conta
    float saldo //saldo atual     
    extrato[]     //vetor para guardar as movimentações bancarias

contrutor:
    //Inicialize conta atraves do número da conta e do saldo inicial
    //Crie um construtor sem parametros se quiser
    Conta(int numero, float saldo)

metodos:
    //Realiza um saque da conta
    //Não permita saque de valor acima do saldo ou valor negativo
    //Retorne se houve sucesso
    saque(float valor)

    //Adiciona dinheiro na conta
    //Não permita valor negativo
    //Retorne se houve sucesso
    deposito(float valor)

    //Retorna o número da conta
    getConta()

    //Retorna o saldo atual
    getSaldo()

    //Transfere dinheiro da conta atual para Conta Other
    //Verifique se existe saldo suficiente
    //Retorne se houve sucesso
    transferencia(Conta other, float valor)

    //Retorna a lista das atividades que ocorreram na conta
    //Valores positivos significam deposito
    //Valores negativos significam saque
    //  Exemplo: se depois da abertura, depositaram 20, sacaram 10,
    //  e trasferiram 50 dela pra outra conta, o retorno deve ser
    //  [20, -10, -50]
    getExtrato()
}


```
