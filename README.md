# mkampo-minado

<!-- ABOUT THE PROJECT -->
## 🖥 Sobre o projeto

Esse projeto foi desenvolvido para a disciplina de **Tópicos em Computação 2020 (SEM0580)**, fornecida pela Escola de Engenharia de São Carlos (EESC-USP).

O objetivo era construir uma versão simplifcada do famoso jogo _Campo Minado_, aplicando todos os conceitos aprendidos durante o semestre.

![Animação de carregamento][loading]

### Linguagem

Todo o programa foi desenvolvido em C++. Para facilitar a nossa organização, utilizamos arquivos .h separando em classes para facilitar na hora de referenciar as funções utilizadas ao longo do programa.

Além disso, todo o projeto foi executado utilizando a IDE [CLion][clion-url].

### Organização

Todas as tarefas e funcionalidades foram mapeadas utilizando a metodologia ágil _Kanban_. Os cards utilizados para mapear tudo o que precisávamos fazer podem ser encontrados no ambiente de [projetos][kanban-url] do GitHub para esse repositório.



<!-- INTERFACE -->
## 🕹 Interface

Todo o programa é baseado na navegação pelas setas do teclado, tanto para selecionar as células do campo minado quanto para navegar pelos menus de setinha.

![Animação de carregamento][menu]

Nenhuma outra entrada do usuário é necessária.



<!-- HOW TO PLAY -->
## 💣 Como jogar

O objetivo do jogo é descobrir todas as casas do campo sem pisar em uma das 12 minas espalhadas aleatóriamente.

### Selecionando uma casa

Utilizando as setas para _cima_ e para _baixo_ o usuário primeiramente selecionará a linha que deseja. Quando estiver satisfeito, pressionará enter para prosseguir.

Após a primeira seleção, ele será informado para selecionar a coluna que deseja, apertando enter quando quiser também.

Em todo o processo a linha/coluna em questão estará destacada em amarelo.

![Animação de carregamento][gameplay]

### Operação numa casa

Após esse prcesso um menu aparecerá para o usuário falar o que ele deseja fazer. As opções são

1. Pisar = poderão ocorrer duas coisas:
    1. Caso ele pise numa casa sem mina, será mostrada a quantidade de minas que existem ao redor daquele ponto (na região 3x3 com essa casa no centro). Se forem encontradas nessa região, será mostrado um número correspondente à quantidade (de 1 até 8). Se nenhumma, um ponto sera colocado (.);
    2. Caso ele pise numa casa com mina, o jogo encerrará.
2. Marcar = o usuário colocará uma marcação especial nessa casa. Essa funcionalidade é boa para marcar possíveis localizações das minas. Ela não interfere em nada no jogo, só serve como ponto de referência para o jogador;
3. Cancelar = cancela a seleção atual.

![Animação de carregamento][options]

### Fim de jogo

O jogo pode acabar de duas formas:

1. O usuário pise em uma casa **com mina**;
2. O usuário descubra todas as **88 casas** sem pisar em nenhuma mina.

![Animação de carregamento][game-over]

De qualquer forma, é sempre mostrada a pontuação máxima que ele atingiu na rodada. Tal pontuação é baseada na quantidade de casas descobertas corretamente (as marcações não interferem em nada na pontuação).

Bom jogo!



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
<!-- External URLs -->
[clion-url]: https://www.jetbrains.com/clion/
[kanban-url]: https://github.com/andrecreppe/mkampo-minado/projects
<!-- Images -->
[loading]: images/loading.png
[menu]: images/menu.png
[gameplay]: images/gameplay.png
[options]: images/options.png
[game-over]: images/game-over.png