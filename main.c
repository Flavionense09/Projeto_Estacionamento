#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[100];
    int tipo;
    double horas;
    double preco_hora = 0.0;
    double horas_cobradas;
    double valor_base;
    double desconto = 0.0;
    double multa = 0.0;
    double valor_final;
    char tipo_texto[20];
    char *p;
    size_t len;

inicio:
    /* Entrada da placa: ler uma linha inteira, remover newline e validar */
    printf("Informe a placa do veiculo (7 caracteres, letras e numeros): ");
    if (fgets(placa, sizeof(placa), stdin) == NULL) {
        printf("Erro na leitura. Encerrando.\n");
        return 0;
    }

    /* Remover newline se presente */
    p = strchr(placa, '\n');
    if (p != NULL) {
        *p = '\0';
    } else {
        /* Se não havia newline, pode haver excesso de caracteres no buffer; limpar até newline */
        int ch;
        do {
            ch = getchar();
        } while (ch != '\n' && ch != EOF);
    }

    len = strlen(placa);

    /* Verifica se tem exatamente 7 caracteres */
    if (len != 7) {
        printf("Numero da placa errado, por favor tente novamente\n\n");
        goto inicio;
    }

    /* Verifica se todos os caracteres são alfanuméricos (letras ou números) */
    {
        int i;
        for (i = 0; i < 7; i++) {
            if (!isalnum((unsigned char)placa[i])) {
                printf("Numero da placa errado, por favor tente novamente\n\n");
                goto inicio;
            }
        }
    }

    /* Entrada do tipo do veículo (switch-case) */
escolha:
    printf("Tipo do veiculo (digite o numero):\n");
    printf("1 - Carro\n");
    printf("2 - Moto\n");
    printf("3 - Caminhonete\n");
    printf("Escolha: ");
    if (scanf("%d", &tipo) != 1) {
        /* limpar entrada inválida */
        int ch;
        do { ch = getchar(); } while (ch != '\n' && ch != EOF);
        printf("Tipo invalido. Encerrando.\n");
        goto escolha;
    }

    /* limpar o newline remanescente antes de próximas leituras */
    {
        int ch;
        do { ch = getchar(); } while (ch != '\n' && ch != EOF);
    }

    switch (tipo) {
        case 1:
            preco_hora = 5.0;
            tipo_texto[0] = 'C'; tipo_texto[1] = 'a'; tipo_texto[2] = 'r'; tipo_texto[3] = 'r'; tipo_texto[4] = 'o'; tipo_texto[5] = '\0';
            break;
        case 2:
            preco_hora = 3.0;
            tipo_texto[0] = 'M'; tipo_texto[1] = 'o'; tipo_texto[2] = 't'; tipo_texto[3] = 'o'; tipo_texto[4] = '\0';
            break;
        case 3:
            preco_hora = 8.0;
            tipo_texto[0] = 'C'; tipo_texto[1] = 'a'; tipo_texto[2] = 'm'; tipo_texto[3] = 'i'; tipo_texto[4] = 'n'; tipo_texto[5] = 'h'; tipo_texto[6] = 'o'; tipo_texto[7] = 'n'; tipo_texto[8] = 'e'; tipo_texto[9] = 't'; tipo_texto[10] = 'e'; tipo_texto[11] = '\0';
            break;
        default:
            printf("Tipo invalido. Encerrando.\n");
            goto escolha;
    }

    /* Entrada do tempo de permanência */
    printf("Tempo de permanencia (em horas, ex: 2.5): ");
    if (scanf("%lf", &horas) != 1) {
        printf("Entrada de horas invalida. Encerrando.\n");
        return 0;
    }

    /* Regra: até 1 hora -> valor mínimo (cobrar 1 hora) */
    if (horas <= 1.0) {
        horas_cobradas = 1.0;
    } else {
        horas_cobradas = horas;
    }

    /* Cálculo do valor base */
    valor_base = preco_hora * horas_cobradas;

    /* Desconto de 10% se acima de 5 horas */
    if (horas > 5.0) {
        desconto = 0.10 * valor_base;
    } else {
        desconto = 0.0;
    }

    /* Multa adicional de R$20 se acima de 10 horas */
    if (horas > 10.0) {
        multa = 20.0;
    } else {
        multa = 0.0;
    }

    /* Valor final */
    valor_final = valor_base - desconto + multa;

    /* Saída formatada */
    printf("\n--- Recibo ---\n");
    printf("Placa: %s\n", placa);
    printf("Tipo do veiculo: %s\n", tipo_texto);
    printf("Tempo de permanencia: %.2f horas\n", horas);
    printf("Valor base (%.2f h x R$ %.2f/h): R$ %.2f\n", horas_cobradas, preco_hora, valor_base);
    printf("Desconto aplicado: R$ %.2f\n", desconto);
    printf("Multas/Taxas aplicadas: R$ %.2f\n", multa);
    printf("Valor final a pagar: R$ %.2f\n", valor_final);
    printf("---------------\n");

    return 0;
}
