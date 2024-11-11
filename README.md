Aqui está um exemplo de documentação README para o seu projeto ESP32:

---

# ESP32 UDP Display Controller

Este projeto controla um display de 7 segmentos e um LED usando o ESP32, que se conecta a uma rede Wi-Fi e recebe comandos via UDP para exibir informações específicas no display.

## Funcionalidades

- Conexão do ESP32 a uma rede Wi-Fi como Access Point.
- Recepção de pacotes UDP para controlar a exibição de números no display de 7 segmentos.
- Controle de um LED indicador, que pisca enquanto um número está sendo exibido.
- Integração de botões para diferentes funções, como enviar comandos UDP ou cancelar a exibição.

## Componentes Usados

- **ESP32**: Placa de desenvolvimento principal.
- **Display de 7 segmentos**: Controlado pelos pinos 15, 4, 16, 17, 5, 18 e 19.
- **LED**: Conectado ao pino 2.
- **Botões**: Configurados para controle de eventos e envio de pacotes UDP.

## Conexões e Configurações de Hardware

| Componente | Pino ESP32 | Função         |
|------------|------------|----------------|
| LED        | 2          | Indicador      |
| Botão 1    | 12         | Botão Stop     |
| Botão 2    | 13         | Botão Cancelar |
| Display 7 segmentos | 15, 4, 16, 17, 5, 18, 19 | Exibição de números |

## Dependências

- **WiFi.h**: Biblioteca para conectar o ESP32 ao Wi-Fi.
- **WiFiUdp.h**: Biblioteca para comunicação UDP.

## Instalação

1. **Clone este repositório**:
   ```bash
   git clone https://github.com/yJoaoFerreira/Trabalho-IOT.git
   ```

2. **Abra o projeto no Arduino IDE** e configure a placa para **ESP32**.

3. **Altere as configurações de Wi-Fi**:
   - Abra o arquivo `.ino` e modifique os valores de `ssid` e `password` para corresponder à sua rede.

4. **Compile e faça o upload do código** para a placa ESP32.

## Funcionamento

### Inicialização

- O ESP32 se conecta ao Access Point configurado (`Com5est_AP`) e inicia o servidor UDP na porta `12345`.
- O display é configurado para exibir números e o LED está pronto para indicar eventos.

### Comandos UDP

O ESP32 recebe os seguintes comandos via UDP:
- **"Estacao01"**: Exibe o número 1 no display e inicia a piscagem do LED por 30 segundos.
- **"Estacao02"**: Exibe o número 2 no display e inicia a piscagem do LED por 30 segundos.
- **"Cancela"**: Apaga o display e cancela a piscagem do LED.

### Botões

- **Botão Stop**: Apaga o display de 7 segmentos.
- **Botão Cancelar**: Envia o comando "Cancela" via UDP para o Access Point.

### Funções

- `displayNumber(uint8_t num)`: Exibe o número no display.
- `piscar_led()`: Pisca o LED enquanto o número está exibido.
- `apagarDisplay()`: Limpa o display e redefine as variáveis.

## Personalização

- Altere os números a serem exibidos ou o comportamento do LED ajustando os valores na função `displayNumber()` e na lógica do `loop()`.

## Exemplo de Uso

1. Configure e ligue o ESP32, que se conectará ao AP e exibirá o endereço IP no monitor serial.
2. Envie pacotes UDP com os comandos “Estacao01” ou “Estacao02” para exibir números.
3. Pressione os botões para testar as funcionalidades locais de cancelamento e parada do display.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir **issues** ou enviar **pull requests**.
