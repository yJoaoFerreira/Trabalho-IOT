import serial
import time

# Configuração da porta serial
ser = serial.Serial('COM3', 115200, timeout=1)  # Altere 'COM3' para a porta correta
time.sleep(2)  # Aguarda o ESP32 inicializar

# Abre um arquivo para salvar os logs
with open("logs.txt", "a") as log_file:
    try:
        while True:
            # Lê uma linha da serial
            if ser.in_waiting > 0:
                data = ser.readline().decode().strip()
                
                # Exibe e grava os dados no arquivo de log
                print(data)
                log_file.write(f"{time.strftime('%Y-%m-%d %H:%M:%S')} - {data}\n")
                log_file.flush()  # Garante que o log é salvo imediatamente
    except KeyboardInterrupt:
        print("Programa interrompido pelo usuário.")
    finally:
        ser.close()  # Fecha a porta serial ao sair