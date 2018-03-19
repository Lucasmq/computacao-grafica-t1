# Introdução a Computação Gráfica - Rasterização
Baseado no framework disponibilizado pelo professor Christian Pagot que permite a simulação de acesso a memória de video para a realização desse trabalho. Neste trabalho será desenvolvido 3 funções. São elas:


## Função PutPixel();

Função que rasteriza um ponto na memória de vídeo, recebendo como parâmetros a
posição do pixel na tela (x,y) e sua cor (RGBA).
	
## DrawLine():

Função que rasteriza uma linha na tela, recebendo como parâmetros os seus vértices
(inicial e final, representados respectivamente pelas tuplas (x0,y0) e (x1,y1)), e as cores (no
formato RGBA) de cada vértice. As cores dos pixels ao longo da linha rasterizada devem ser
obtidas através da interpolação linear das cores dos vértices. O algoritmo de rasterização a ser
implementado deve ser o algoritmo de Bresenham!

## DrawTriangle: 
	
Função que desenha as arestas de um triângulo na tela, recebendo como
parâmetros as posições dos três vértices (xa,ya), (xb,yb) e (xc,yc) bem como as cores (RGBA)
de cada um dos vértices. As cores dos pixels das arestas do triângulo devem ser obtidas através
da interpolação linear das cores de seus vértices. Não é necessário o preenchimento do
triângulo!
