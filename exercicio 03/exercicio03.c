

#include <stdio.h>
#include <stdlib.h>

typedef struct ContaBancaria {
    float saldo;
    int numero;
} ContaBancaria;

// Questão 3
void inicializar(ContaBancaria *conta, int numero) {
    conta->numero = numero;
    conta->saldo = 0.0;
    printf("Conta inicializada com sucesso!\n");
}

void imprimirSaldo(ContaBancaria *conta) {
    printf("Seu saldo atual: %.2f\n", conta->saldo);
}

void deposito(ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Valor de %.2f foi depositado com sucesso\n", valor);
        imprimirSaldo(conta);
    }
}

void sacar(ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("Saque Inválido\n");
        return;
    }
    conta->saldo -= valor;
    printf("Saque realizado com sucesso\n");
    imprimirSaldo(conta);
}
// -----------------------------------------------
// Questão 4

ContaBancaria* criarConta(int numero) {
    ContaBancaria *novaConta = (ContaBancaria*) malloc(sizeof(ContaBancaria));

    if (novaConta != NULL) {
        novaConta->numero = numero;
        novaConta->saldo = 0.0;
        printf("Conta %i criada com sucesso\n", novaConta->numero);
    } else {
        printf("Erro ao criar conta");
    }

    return novaConta;
}

int main() {
    ContaBancaria *contaMemoria = criarConta(3);

     if (contaMemoria != NULL) {
        printf("Conta -> Numero: %d\n", contaMemoria->numero);
        printf("Conta -> Saldo: R$%.2f\n", contaMemoria->saldo);
        free(contaMemoria);
        printf("Memoria da conta %d libertada com sucesso (free).\n", 3);
    }

    ContaBancaria conta1;
    inicializar(&conta1, 1);
    deposito(&conta1, 120.);
    sacar(&conta1, 20);
    return 0;
}
