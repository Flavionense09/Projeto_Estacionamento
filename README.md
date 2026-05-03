## Sistema de Gerenciamento de Estacionamento Rotativo : 

nome: DAVID LUCAS SÁ CORDEIRO<br>
matricula: 2023030470<br>
nome: FLAVIO ARAGAO TENORIO DE BRITTO<br>
matricula: 2023041680<br>


## Descrição do problema: 

## 1 - Como funciona um estacionamento rotativo na vida real:<br>
	 O estacionamento rotativo, conhecido como "Zona Azul", foi implementado com o intuito de melhorar o tráfego e aumentar a disponibilidade de vagas nas ruas, permitindo que as pessoas estacionem próximo aos seus destinos mediante regras específicas. O sistema visa assegurar que um número maior de cidadãos utilize as vagas disponíveis, promovendo um fluxo contínuo de veículos. Embora seja mais comum em áreas comerciais, sua aplicação pode se estender a outros locais. A regulamentação e as características do estacionamento rotativo podem ser determinadas individualmente por cada município brasileiro.

## 2 - Quais decisões o sistema precisa tomar:<br>

- validação dos dados de entrada
- calculo do tempo de permanência 
- definição de tarifas 
- aplicação de desconto e multas 
- controle de vagas: normais e especiais 
- verificação da duplicidade de veículos 
- forma e confirmação de pagamento 
- tarifas especiais por tempo ou tipo de veiculo 

##  Explicação da lógica:<br>
	O sistema de gerenciamento de estacionamento rotativo visa controlar a entrada e saída de veículos, calcular o tempo de permanência e determinar o valor a ser pago conforme regras pré-definidas. Ele opera através de uma sequência de etapas para garantir um funcionamento correto e organizado.

## 1 - Funcionamento:<br>

ENTRADAS :<br>
- Ler placa do veiculo <br>
- ler horário de entrada <br>
- ler horário de saída <br>
- ler tipo de veiculo <br>
- ler se possui desconto <br>

PROCESSAMENTO:<br>
- verificar se o horário de saída é maior que o de entrada 
- verificar se os horários são validos 
- calcular tempo de permanência : tempo = saída - entrada 
- ajustar para tempo mínimo, se necessário 
- Valor base
 	O valor é calculado com base no tempo de permanência e no tipo de veículo.
- **Até 1 hora:**
  - Cobrança mínima (valor fixo de 1 hora)
    - Carro: R$ 5,00  
    - Moto: R$ 3,00  
    - Caminhonete: R$ 8,00  
- **Acima de 5 hora:**
  - O valor é calculado proporcionalmente ao número de horas:
    valor_base = preco_hora × horas_cobradas
- Preço por hora
	- Carro: R$ 5,00/h  
	- Moto: R$ 3,00/h  
	- Caminhonete: R$ 8,00/h  

- Regras adicionais

- **Desconto:**
  - Aplicado quando o tempo de permanência for maior que 5 horas
  - Valor do desconto: 10% do valor base

- **Multa:**
  - Aplicada quando o tempo de permanência for maior que 10 horas
  - Valor fixo: R$ 20,00

  - ajustar valor conforme o tipo de veiculo <br>
- verificar forma de pagamento 
- confirmar se o pagamento foi realizado 

SAIDA:
- Placa do veículo
- Tipo do veículo
- Tempo de permanência
- Valor base
- Desconto aplicado
- Multas/taxas
- Valor final a pagar

##  Variáveis utilizadas

O programa utiliza as seguintes variáveis para armazenar e processar as informações do sistema de estacionamento:

| Variável        | Tipo        | Descrição |
|----------------|------------|----------|
| placa          | char[100]  | Armazena a placa do veículo digitada pelo usuário 
| tipo           | int        | Tipo do veículo (1 = carro, 2 = moto, 3 = caminhonete) 
| horas          | double     | Tempo de permanência informado pelo usuário 
| preco_hora     | double     | Valor cobrado por hora de acordo com o tipo do veículo 
| horas_cobradas | double     | Tempo considerado para cobrança (mínimo de 1 hora) 
| valor_base     | double     | Valor inicial calculado antes de descontos e multas 
| desconto       | double     | Valor de desconto aplicado (10% para permanência acima de 5 horas) 
| multa          | double     | Taxa adicional aplicada (R$20 para permanência acima de 10 horas) 
| valor_final    | double     | Valor total a ser pago após todos os cálculos 
| tipo_texto     | char[20]   | Armazena o nome do tipo do veículo em formato texto 
| p              | char*      | Ponteiro utilizado para localizar e remover o caractere de nova linha da placa 
| len            | size_t     | Armazena o tamanho da string da placa 
| ch             | int        | Variável auxiliar para limpeza do buffer de entrada 
| i              | int        | Variável auxiliar utilizada na validação dos caracteres da placa 

 ### Observações

- Variáveis do tipo `char[]` são utilizadas para armazenar textos (strings)
- Variáveis do tipo `int` são utilizadas para valores inteiros
- Variáveis do tipo `double` são utilizadas para cálculos com casas decimais
- O tipo `size_t` é utilizado para representar tamanhos de forma segura
- Ponteiros (`char*`) são utilizados para manipulação de strings

##  Como compilar e executar

O programa pode ser executado diretamente em um compilador online, sem necessidade de instalação.

### Passos para execução

1. Acesse um compilador online, como:
- https://www.online-ide.com/#google_vignette
2. Crie um novo projeto em linguagem **C**
3. Copie e cole o código do arquivo `estacionamento.exe` no editor
4. Clique no botão **Run / Execute**
5. Insira os dados solicitados pelo programa no console

ENTRADA ESPERADA:

O programa vai solicitar informações como:

- Placa do veículo (7 caracteres)
- Tipo do veículo:
  - 1 - Carro  
  - 2 - Moto  
  - 3 - Caminhonete  
- Tempo de permanência (em horas)

SAIDA :

O sistema exibirá um recibo contendo:

- Placa do veículo
- Tipo do veículo
- Tempo de permanência
- Valor base
- Desconto aplicado
- Multas/taxas
- Valor final a pagar

### Observação

O programa foi desenvolvido em linguagem C padrão e pode ser executado em qualquer compilador online compatível.
