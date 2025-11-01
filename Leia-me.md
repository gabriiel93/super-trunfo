Como jogar

=============================================
Bem-vindo ao Super Trunfo dos Países!
=============================================

Menu Principal:
1 - Comparar cartas (Brasil vs Japão)
2 - Mostrar cartas
3 - Sair

=============================================

Escolha uma opção:

Opção 1 – Comparar cartas
Você escolhe dois atributos diferentes para comparar entre Brasil e Japão.

Os atributos disponíveis são:

População (maior vence)

Área (maior vence)

PIB (maior vence)

Densidade Demográfica (menor vence)

O programa mostra os valores, soma os atributos escolhidos e anuncia o vencedor.

=============================================

Opção 2 – Mostrar cartas

Exibe todos os atributos das cartas disponíveis.

=============================================

Opção 3 – Sair

Encerra o jogo.

=============================================

Requisitos para rodar ?
Sistema Operacional: Windows, Linux ou macOS
Compilador C: GCC (recomendado via MSYS2 no Windows ou build-essential no Linux)
Editor de código (opcional): VS Code, Code::Blocks ou outro de sua preferência

=============================================

Comandos:
No Windows (MSYS2 MinGW 64-bit)
gcc super_trunfo.c -o super_trunfo.exe
./super_trunfo.exe

No Linux/macOS
gcc super_trunfo.c -o super_trunfo
./super_trunfo

Obs:
Para evitar problemas de acentuação no Windows, salve o arquivo em ANSI (Windows-1252) ou rode o programa no MSYS2/Windows Terminal.
O jogo já vem com duas cartas pré-cadastradas (Brasil e Japão), mas você pode expandir facilmente adicionando mais países na struct.
