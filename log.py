import serial
import time

# Configuração da porta serial (ajuste para a porta do seu ESP32)
esp32_port = 'COM5'  # Exemplo: 'COM3' para Windows ou '/dev/ttyUSB0' para Linux
baud_rate = 9600  # Taxa de transmissão comum para o ESP32
log_file_path = "log_esp32.txt"

# Inicializa a conexão com o ESP32
with serial.Serial(esp32_port, baud_rate, timeout=1) as esp32_serial:
    # Aguarda o ESP32 reiniciar
    time.sleep(2)
    print("Conexão com ESP32 estabelecida.")
    
    # Abre o arquivo de log em modo de gravação
    with open(log_file_path, "a") as log_file:
        # Loop para receber e registrar os dados
        while True:
            # Lê uma linha da serial
            line = esp32_serial.readline().decode("utf-8").strip()
            if line:
                # Imprime e registra a linha no arquivo de log
                print(line)
                log_file.write(f"{time.strftime('%Y-%m-%d %H:%M:%S')} - {line}\n")
                log_file.flush()  # Garante que a linha é salva imediatamente no log
