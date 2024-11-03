import serial

port = 'COM3'
baud_rate = 9600 

try:
    ser = serial.Serial(port, baud_rate)
    print(f"Lendo dados da porta {port} com taxa de {baud_rate} bps...")

    while True:
        if ser.in_waiting > 0:
            line = ser.readline()
            print(f"Dado recebido (em bytes): {line}")

except serial.SerialException as e:
    print(f"Erro na conexão serial: {e}")
except KeyboardInterrupt:
    print("Encerrando leitura.")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
