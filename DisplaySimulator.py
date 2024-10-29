class DisplaySimulator:
    def __init__(self):
        self.LEDs = [15, 4, 16, 17, 5, 18, 19]  # Pinos conectados ao display de 7 segmentos
        self.segment_map = [
            0b11000000,  # 0
            0b11111001,  # 1
            0b10100100,  # 2
            0b10110000,  # 3
            0b10011001,  # 4
            0b10010010   # 5
        ]
        self.num = 0

    def display_number(self, num):
        try:
            if not (0 <= num < len(self.segment_map)):
                raise ValueError(f"Número inválido: {num}. Por favor, insira um número entre 0 e {len(self.segment_map) - 1}.")

            # Simulação da ativação dos segmentos (em um Arduino, isso seria feito com digitalWrite)
            segments = self.segment_map[num]
            print(f"Exibindo o número {num} com segmentos: {bin(segments)}")

        except ValueError as e:
            print("Erro:", e)

    def button_press(self, button_num):
        try:
            if not (1 <= button_num <= 5):
                raise ValueError(f"Botão {button_num} é inválido. O número do botão deve estar entre 1 e 5.")
            
            # Exibe o número com base no botão pressionado
            self.num = button_num
            self.display_number(self.num)

        except ValueError as e:
            print("Erro:", e)

    def run_simulation(self):
        try:
            # Simula a leitura dos botões (substitua com inputs ou sinais em um Arduino real)
            while True:
                button_num = int(input("Pressione um botão (1 a 5): "))
                self.button_press(button_num)

        except KeyboardInterrupt:
            print("\nSimulação finalizada pelo usuário.")
        except Exception as e:
            print("Erro inesperado:", e)

# Executa a simulação
display = DisplaySimulator()
display.run_simulation()