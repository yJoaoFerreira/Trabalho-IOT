import matplotlib.pyplot as plt
import networkx as nx

# Criar o grafo direcionado
G = nx.DiGraph()

# Adicionar nós
nodes = [
    "Estação 1", "Display 2", "Display 3", 
    "Display 4", "Display 5", "WiFi (UDP)", 
    "Estação 2", "Estação 3", "Estação 4", 
    "Estação 5", "Display Servidor"
]
G.add_nodes_from(nodes)

# Adicionar arestas sem setas bidirecionais, criando duas linhas paralelas
edges = [
    ("Estação 2", "Display 2"),
    ("Estação 3", "Display 3"),
    ("Estação 4", "Display 4"),
    ("Estação 5", "Display 5"),
    ("Display 2", "WiFi (UDP)"),
    ("Display 3", "WiFi (UDP)"),
    ("Display 4", "WiFi (UDP)"),
    ("Display 5", "WiFi (UDP)"),
    ("WiFi (UDP)", "Estação 1"),
    ("WiFi (UDP)", "Estação 1"),
    ("Estação 1", "WiFi (UDP)"),
    ("Estação 1", "Display Servidor"),
    ("WiFi (UDP)", "Estação 2"),
    ("WiFi (UDP)", "Estação 3"),
    ("WiFi (UDP)", "Estação 4"),
    ("WiFi (UDP)", "Estação 5"),
]

G.add_edges_from(edges)

# Definir posições para os nós, trocando as posições dos displays com as estações
pos = {
    "Display 2": (-2, 3),
    "Display 3": (0, 3),
    "Display 4": (2, 3),
    "Display 5": (4, 3),
    "Estação 2": (-2, 1),
    "Estação 3": (0, 1),
    "Estação 4": (2, 1),
    "Estação 5": (4, 1),
    "WiFi (UDP)": (1, -1),
    "Estação 1": (1, -3),
    "Display Servidor": (2, -2)
}

# Desenhar o grafo com arestas paralelas
plt.figure(figsize=(12, 8))
nx.draw(
    G, pos, with_labels=True, node_size=2000, node_color="skyblue", 
    font_size=8, font_weight="bold", arrows=False
)

# Desenhar as arestas para simular linhas paralelas
edge_labels = {
    ("Estação 2", "Display 2"): "Apertar Botão",
    ("Estação 3", "Display 3"): "Apertar Botão",
    ("Estação 4", "Display 4"): "Apertar Botão",
    ("Estação 5", "Display 5"): "Apertar Botão",
    ("Display 2", "WiFi (UDP)"): "Enviar Pacote",
    ("Display 3", "WiFi (UDP)"): "Enviar Pacote",
    ("Display 4", "WiFi (UDP)"): "Enviar Pacote",
    ("Display 5", "WiFi (UDP)"): "Enviar Pacote",
    ("WiFi (UDP)", "Estação 1"): "Receber Pacote",
    ("Estação 1", "WiFi (UDP)"): "Enviar / Receber",
    ("Estação 1", "Display Servidor"): "Acessar Display",
    ("WiFi (UDP)", "Estação 2"): "Resposta",
    ("WiFi (UDP)", "Estação 3"): "Resposta",
    ("WiFi (UDP)", "Estação 4"): "Resposta",
    ("WiFi (UDP)", "Estação 5"): "Resposta"
}

nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=8, font_color="darkgreen")

plt.title("Grafo de Comunicação ESP32")
plt.axis('off')  # Ocultar eixos
plt.show()