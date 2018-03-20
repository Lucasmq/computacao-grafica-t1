#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
//DesenhaPixels();
//DesenhaLinha();

COR p = {255,0,0,255};
COR p1 = {0,0,255,255};
COR p2 = {0,255,0,255};
VERTICES v  ={0,511};
VERTICES v1 ={256,0};
VERTICES v2 ={511,511};
VERTICES v3 ={400,389};
VERTICES v4 ={200,100};
VERTICES v5 ={100,300};
VERTICES v6 ={0,0};
VERTICES v7 ={511,511};
VERTICES v8 ={511,256};


//DrawLine( v, v1, p2, p);
//DrawLine(v, v1, p1, p2);
//DrawLine(v4, v5, p2, p1);
//DrawLine(v6, v7, p2, p1);

//PutPixel(v,p);

//PutPixel(v1,p2);
//PutPixel(v4,p1);
//preencherTrianguloBaricentro(v,v1,v2,p,p1,p2);
preencherTriangulo(v3,v4,v5,p1,p1,p1);
//preencherTrianguloRecursivo(v,v1,v2,p,p1,p2);
//DrawTriangle(v,v1,v2,p,p1,p2);
//trianguloEscala(v,v1,v2,p,p1,p2);
//trianguloEscala(v,v1,v2,p,p1,p2);

}
//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
