# Introdução a Computação Gráfica - Rasterização
     
Baseado no framework disponibilizado pelo professor Christian Pagot que permite a simulação de acesso a memória de video para a realização desse trabalho. Neste trabalho será desenvolvido 3 funções. São elas:


## Função PutPixel();

Função que rasteriza um ponto na memória de vídeo, recebendo como parâmetros a
posição do pixel na tela (x,y) e sua cor (RGBA).

### Pixel

Os pixels estão dispostos nas telas em uma matriz de pontos que cada elemento possui informação referente a cor associada aquele ponto específico. O mais utilizado é o RGBA, onde cada componente representa uma cor primaria e varia de 0 a 255 para a formação de mais de 16 milhões de cores. Cada componente ocupa 8 bits de memória, num total de 32 bits por pixel nesse nosso caso.

Para acessar é criado duas estruturas.

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/struct.jpg)

Como a tela gerada pelo framework é uma tela de 512x512 pixels, para acendermos temos que entender como é armazenado suas coordenadas.

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/pixels.png)

Para isso, dado uma coordenada na tela, utilizaremos do seguinte calculo para acessar cada componente de cada pixel.

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/putpixel.jpg)

Onde o IMAGE_WIDTH representa o tamanho da tela de 512, com isso o ponteiro FBptr aponta para a posição inicial da memória de video, onde estão armazenados as informações do primeiro pixel no monitor, representado pelos 4 primeiros bytes. Os proximos 4 bytes representam o próximo pixel e assim sucessivamente. Assim é possivel rasterizar um pixel em qualquer posição da tela.

Exemplo do funcionamento do do PutPixel() com dois pixels na tela:

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/putpixel_funcionando.jpg)


	
## DrawLine():

Função que rasteriza uma linha na tela, recebendo como parâmetros os seus vértices
(inicial e final, representados respectivamente pelas tuplas (x0,y0) e (x1,y1)), e as cores (no
formato RGBA) de cada vértice. As cores dos pixels ao longo da linha rasterizada devem ser
obtidas através da interpolação linear das cores dos vértices. O algoritmo de rasterização a ser
implementado deve ser o algoritmo de Bresenham!

### Bresenham

Depois de conseguir acender um pixel na tela, agora iremos gerar uma reta, que é um conjunto de pixels acesos de um ponto a outro. Nesse caso iremos utilizar do algoritmo de Bresenham, que é um algoritmo criado para o desenho de linhas, em dispositivos matriciais, que permite determinar quais os pontos numa matriz de base quadriculada que devem ser destacados para atender o grau de inclinação de um ângulo.
O algoritmo de inicio serve apenas para o primeiro octante, pois ele vai incrementando ou decrementando o eixo X, gerando linhas de no máximo 45º. Para resorvermos isso fazemos algumas alterações para que ele consiga servir para todos os octantes, no caso incrementando ou decrementando no eixo Y e invertendo os vertices para quando o vertice final for menor que o vertice inicial, gerando assim a reta em qualquer octante.

Exemplo de uma reta pelo algoritmo e função DrawLine, onde recebe dois vértices e o parametro de COR (no caso 0,255,0,255):

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/reta.jpg)

Octantes:

![alt text](octantes_real)

Após a configuração para todos os octantes, podemos ver as retas geradas em varias direções:

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/retas_octantes.jpg)

### Interpolação de Cores

Após a formação da reta, vamos receber dois vertices, cada um com uma cor, e vamos interpolar essas cores entre a reta. Primeiramente é usado a distáncia entre o eixo X e Y dos vertices e obtemos dx e dy. Com isso calculamos a diferença de cada componente dos pixels entre os vertices e dividimos esse valor obtido por dx ou dy. O que determinarará qual dos dois utilizar vai ser de qual octante irá pertencer a reta, se ela incrementa em X ou Y.

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/reta_interpolada.jpg)

Também foi testado utilizando a distância entre os dois pontos pela seguinte fórmula para substituição do uso do dx e dy.

![alt text](figura formula da distancia)

Além de aumentar o número de calculos, foi observada que com o uso da distância entre os dois pontos, uma cor predominava mais que a outra, como podemos ver nessa imagem onde o azul predomina mais pela reta do que a cor verde, o que não ocorre no uso do dx e dy.
 
![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/reta_interpolada_dist.jpg)

## DrawTriangle(): 
	
Função que desenha as arestas de um triângulo na tela, recebendo como
parâmetros as posições dos três vértices (xa,ya), (xb,yb) e (xc,yc) bem como as cores (RGBA)
de cada um dos vértices. As cores dos pixels das arestas do triângulo devem ser obtidas através
da interpolação linear das cores de seus vértices. Não é necessário o preenchimento do
triângulo!

![alt text](https://github.com/Lucasmq/computacao-grafica-t1/blob/master/imagens/triangulo_preenchido.jpg)
