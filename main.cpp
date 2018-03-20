#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
//DesenhaPixels();
//DesenhaLinha();
int x1 = 300;
int y1 = 200;
int x2 = 200;
int y2 = 100;

int teste;

//m = (float(y2)-float(y1))/(float(x2) - float(x1));
//printf("m = %f",m);
//DrawLine(0,0,260,260);
/*DrawLine(0,0,511,130,100,0,123,255);
DrawLine(0,0,511,230,100,0,123,255);
DrawLine(0,0,511,330,100,0,123,255);
DrawLine(100,100,511,130,100,0,123,255);
DrawLine(0,256,511,256,100,0,123,255);*/
//DrawLine(80,30,380,430,100,0,123,255);

//DrawLine(50,130,411,130,100,0,123,255);
//DrawLine(x1, y1, x2, y2,0,0,255,255);
//DrawLine(0, 0, 511, 511,0,0,255,255);

//resenham1(0,511, 450, 0,0,0,255,255);
COR p = {255,0,0,255};
COR p1 = {0,0,255,255};
COR p2 = {0,255,0,255};
VERTICES v  ={0,511};
VERTICES v1 ={511,0};
VERTICES v2 ={50,256};
VERTICES v3 ={400,389};
VERTICES v4 ={256,0};
VERTICES v5 ={256,511};
VERTICES v6 ={0,0};
VERTICES v7 ={511,511};
VERTICES v8 ={511,256};


//DrawLine( v, v1, p2, p);
DrawLine(v, v1, p1, p2);
//DrawLine(v4, v5, p2, p1);
//DrawLine(v6, v7, p2, p1);

//PutPixel(v,p);

//printf("\nValue.x = %d",value.x);
//printf("\nValue.y = %d",value.y);


//printf("\n Pixel = %d", m[0]);
//PutPixel(v1,p2);
//PutPixel(v4,p1);
//DrawTriangle(v,v1,v2,p,p1,p2);
//preencherTriangulo(v6,v7,v8,p,p2,p1);
//DrawTriangle(v3,v4,v5,p,p1,p2);
//testeT(v,v1,v2,1,p,p1,p2);
/*for(int i = 0; i <= 500; i=i+100){
	VERTICES k  ={0,i};
	VERTICES l ={510,510-i};

	VERTICES m  ={i,0};
	VERTICES n ={510-i,510};
	
	DrawLine(k, l,p1,p1);
	DrawLine(m, n,p1,p1);
}
*/
//DrawLine(v1,v2,p1,p2);
//DrawLine(v1,v2,p2,p1);
/*DrawLine(411,10,255,255,152,0,123,255);
DrawLine(411,10,0,0,152,0,123,255);*/
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

 /*void DrawTriangle(int xa, int ya, int xb, int yb, int xc, int yc,int Ra, int Ga, int Ba, int Aa,int Rb, int Gb, int Bb, int Ab, int Rc, int Gc, int Bc, int Ac){
 	DrawLine(xa,ya,xb,yb,Ra,Ga,Ba,Aa);
 	DrawLine(xb,yb,xc,yc,Rb,Gb,Bb,Ab);
  	DrawLine(xc,yc,xa,ya,Rc,Gc,Bc,Ac);


 }*/