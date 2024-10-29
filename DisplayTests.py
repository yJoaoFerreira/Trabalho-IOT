import unittest

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
        self.current_display = None  # Simula o estado atual dos segmentos

    def display_number(self, num):
        if not (0 <= num < len(self.segment_map)):
            raise ValueError(f"Número inválido: {num}. Por favor, insira um número entre 0 e {len(self.segment_map) - 1}.")

        # Atualiza o estado de exibição para teste
        self.current_display = self.segment_map[num]
        return self.current_display

    def button_press(self, button_num):
        if not (1 <= button_num <= 5):
            raise ValueError(f"Botão {button_num} é inválido. O número do botão deve estar entre 1 e 5.")
        
        # Mapeia o botão para o número correspondente e exibe
        self.num = button_num
        return self.display_number(self.num)

class TestDisplaySimulator(unittest.TestCase):
    def setUp(self):
        # Inicializa o simulador antes de cada teste
        self.simulator = DisplaySimulator()

    def test_display_number_valid(self):
        # Testa a exibição de números válidos
        self.assertEqual(self.simulator.display_number(0), 0b11000000)
        self.assertEqual(self.simulator.display_number(1), 0b11111001)
        self.assertEqual(self.simulator.display_number(2), 0b10100100)
        self.assertEqual(self.simulator.display_number(3), 0b10110000)
        self.assertEqual(self.simulator.display_number(4), 0b10011001)
        self.assertEqual(self.simulator.display_number(5), 0b10010010)

    def test_display_number_invalid(self):
        # Testa entrada inválida para display_number
        with self.assertRaises(ValueError):
            self.simulator.display_number(6)
        with self.assertRaises(ValueError):
            self.simulator.display_number(-1)

    def test_button_press_valid(self):
        # Testa a resposta aos botões válidos
        self.assertEqual(self.simulator.button_press(1), 0b11111001)
        self.assertEqual(self.simulator.button_press(2), 0b10100100)
        self.assertEqual(self.simulator.button_press(3), 0b10110000)
        self.assertEqual(self.simulator.button_press(4), 0b10011001)
        self.assertEqual(self.simulator.button_press(5), 0b10010010)

    def test_button_press_invalid(self):
        # Testa entrada inválida para button_press
        with self.assertRaises(ValueError):
            self.simulator.button_press(0)
        with self.assertRaises(ValueError):
            self.simulator.button_press(6)

# Executa os testes
if __name__ == '__main__':
    unittest.main()