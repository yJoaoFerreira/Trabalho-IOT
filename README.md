
# Sistema de Comunicação entre Estações

## Descrição do Projeto

Este projeto foi desenvolvido como parte do Trabalho da Disciplina Extensionista de IoT do curso de Análise e Desenvolvimento de Sistemas (ADS), sob orientação do Professor **Lucas Floriano**. Ele utiliza módulos ESP32 para criar um sistema de comunicação que auxilia deficientes auditivos em um ambiente de trabalho na elétrica. Cada estação de trabalho pode solicitar a atenção de outra estação através de botões, e a estação solicitada exibirá o número da mesa chamadora em um **display de 7 segmentos**, enquanto um **LED intermitente** indica a solicitação.

### Objetivo do Projeto

O dispositivo foi projetado para ajudar profissionais deficientes auditivos, facilitando a comunicação entre diferentes estações de trabalho. Sempre que um colega de trabalho fizer uma solicitação, o profissional será notificado por meio de um display, que mostrará o número da estação que está solicitando atenção. Além disso, um LED piscará por 2 minutos como sinal visual de notificação.

## Funcionalidades

- Cada estação possui 5 botões que permitem solicitar a atenção de outra estação de trabalho.
- Quando uma estação recebe uma solicitação, o LED intermitente pisca por 2 minutos.
- O display de 7 segmentos da estação solicitada exibe o número da mesa que fez a solicitação.
- O sistema utiliza comunicação via rede **Wi-Fi** para enviar as solicitações entre as estações.
- Alimentação das estações via **fonte de 5V**.

## Componentes Utilizados

### Hardware:
- **ESP32**: Utilizado como microcontrolador de cada estação.
- **Botões**: 5 botões por estação para fazer as solicitações.
- **LED**: Para indicar visualmente a solicitação recebida.
- **Display de 7 Segmentos**: Mostra o número da estação solicitante.
- Fonte de alimentação **5V**.

### Software:
- **IDE do Arduino**: Utilizada para programar os ESP32.
- Bibliotecas:
  - **WiFi.h**: Para conectar à rede Wi-Fi.

## Configuração do Sistema

Cada ESP32 deve estar conectado à mesma rede Wi-Fi e utilizar **IP fixo** para facilitar a comunicação entre as estações. As solicitações são enviadas via **TCP**, onde cada estação pode solicitar a atenção de outra enviando o número do seu botão correspondente à estação desejada.

### Conexões de Hardware:
1. **Botões**: Conectados aos pinos GPIO dos ESP32.
2. **LED**: Conectado ao pino GPIO 2 (ou outro disponível).
3. **Display de 7 Segmentos**: Conectado aos pinos para controle dos segmentos e dígitos, conforme configurado no código.

### Pinagem do Display de 7 Segmentos:
- Utiliza a biblioteca **SevSeg** para configuração e controle do display. Certifique-se de ajustar a pinagem de acordo com o hardware específico.

## Como Usar

### 1. Requisitos de Software:
- **IDE do Arduino**: [Link para download](https://www.arduino.cc/en/software).
- Bibliotecas:
  - **WiFi.h**: Incluída com a placa ESP32.
  - **SevSeg**: Para controle do display de 7 segmentos.

### 2. Configuração da Rede:
- Abra o arquivo `main.ino` na IDE do Arduino.
- Atualize as credenciais de Wi-Fi no código:
  ```cpp
  const char* ssid = "NOME_DA_REDE";
  const char* password = "SENHA_DA_REDE";
  ```
- Defina IPs fixos para cada estação conforme a necessidade do projeto.

### 3. Carregar o Código:
- Conecte o ESP32 ao computador via USB.
- Selecione a placa **ESP32** na IDE do Arduino (Ferramentas > Placa > ESP32).
- Carregue o código para cada uma das estações, ajustando o IP de cada uma.

### 4. Funcionamento:
- Ao pressionar um botão em uma estação, a solicitação será enviada para a estação correspondente.
- A estação solicitada acenderá seu LED e exibirá o número da estação chamadora no display de 7 segmentos por 2 minutos.

## Arquitetura do Código

### Setup:
- Conecta o ESP32 à rede Wi-Fi, inicializa o servidor para receber solicitações e configura os pinos dos botões, LED e display de 7 segmentos.

### Loop:
- **Envio de Solicitação**: Quando um botão é pressionado, a estação envia uma mensagem para o IP da estação chamada.
- **Recepção de Solicitação**: A estação solicitada recebe a mensagem via TCP, pisca o LED e exibe o número da estação chamadora.

### Funções Importantes:
- **`enviarSolicitacao()`**: Envia uma solicitação para outra estação.
- **`piscarLed()`**: Controla o LED intermitente.
- **`exibirEstacao()`**: Exibe o número da estação solicitante no display.

## Aplicações Futuras

- **Expansão do Sistema**: O sistema pode ser expandido para suportar mais estações ou até outras formas de comunicação, como alertas sonoros ou visuais adicionais.
- **Interface Web**: Adicionar uma interface web para configuração das estações e ajustes em tempo real.
- **Segurança**: Implementar criptografia para aumentar a segurança nas transmissões de dados.

## Licença

Este projeto está licenciado sob a licença MIT. Você pode utilizá-lo e modificá-lo conforme necessário.
