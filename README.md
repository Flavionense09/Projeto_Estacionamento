-- Sistema de Gerenciamento de Estacionamento Rotativo : 

nome: DAVID LUCAS SÁ CORDEIRO<br>
matricula: 2023030470<br>
nome: FLAVIO ARAGAO TENORIO DE BRITTO<br>
matricula: 2023041680<br>


-- Descrição do problema: 

1 - Como funciona um estacionamento rotativo na vida real:<br>
	 O estacionamento rotativo, conhecido como "Zona Azul", foi implementado com o intuito de melhorar o tráfego e aumentar a disponibilidade de vagas nas ruas, permitindo que as pessoas estacionem próximo aos seus destinos mediante regras específicas. O sistema visa assegurar que um número maior de cidadãos utilize as vagas disponíveis, promovendo um fluxo contínuo de veículos. Embora seja mais comum em áreas comerciais, sua aplicação pode se estender a outros locais. A regulamentação e as características do estacionamento rotativo podem ser determinadas individualmente por cada município brasileiro.

2 - Quais decisões o sistema precisa tomar:<br>

- validação dos dados de entrada
- calculo do tempo de permanência 
- definição de tarifas 
- aplicação de desconto e multas 
- controle de vagas: normais e especiais 
- verificação da duplicidade de veículos 
- forma e confirmação de pagamento 
- tarifas especiais por tempo ou tipo de veiculo 


--  Explicação da lógica:<br>
	O sistema de gerenciamento de estacionamento rotativo visa controlar a entrada e saída de veículos, calcular o tempo de permanência e determinar o valor a ser pago conforme regras pré-definidas. Ele opera através de uma sequência de etapas para garantir um funcionamento correto e organizado.

1 - Funcionamento:<br>

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
- valor base:<br>
até 1hr - valor fixo <br>
até 2hrs - valor intermediário<br>
acima de 2hrs - adicionar valor por hora extra <br>
- regras adicionais:<br>
aplicar desconto, se o veiculo possuir <br>
aplicar acréscimos ou multas, se necessário <br>
ajustar valor conforme o tipo de veiculo <br>
- verificar forma de pagamento 
- confirmar se o pagamento foi realizado 

SAIDA:
- exibir placa do veiculo 
- exibir tempo de permanência
- exibir valor total a pagar
- informar status do pagamento
- encerrar sistema 


-- variave
