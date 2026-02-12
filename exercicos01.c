
#include <stdio.h>

long int calcularExpoente(int base, int expoente) {
    if (expoente == 0) return 1;
    if (base == 1 || expoente == 1) return base;
    return base * calcularExpoente(base, expoente - 1);
}

int fibonacci(int x) {
    // if (x == 1) return 0; caso vc queira utilizar com base 0, porém utilizarei com base 1
    if (x == 1 || x == 2) return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
    int n1=0, n2=0, nFib=0;
    printf("Digite o número e o expoente que deseja calcular: \n");
    scanf("%i %i", &n1, &n2);
    int potencia = calcularExpoente(n1, n2);
    printf("%i elevado a %i é igual a %i \n", n1, n2, potencia);
    
    printf("Agora digite um numero para calcular o fibonacci: \n");
    scanf("%i", &nFib);
    int calcFib = fibonacci(nFib);
    printf("o termo %iº da sequencia fibonacci é igual a %i \n", nFib, calcFib);
    return 0;
}
