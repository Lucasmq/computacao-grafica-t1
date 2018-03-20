#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <stdio.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

#include "math.h"
#include <vector>
//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
typedef struct cor 
{
	int R;
	int G;
	int B;
	int A;
}COR;

typedef struct vertices 
{
	int x;
	int y;
}VERTICES;

void DesenhaPixels(void)
{
	// Escreve um pixel vermelho na posicao (0,0) da tela:
	FBptr[0] = 255; // componente R
	FBptr[1] = 0; // componente G
	FBptr[2] = 0; // componente B
	FBptr[3] = 255; // componente A
	// Escreve um pixel verde na posicao (1,0) da tela:
	FBptr[4] = 0; // componente R
	FBptr[5] = 255; // componente G
	FBptr[6] = 0; // componente B
	FBptr[7] = 255; // componente A
	// Escreve um pixel azul na posicao (2,0) da tela:
	FBptr[8] = 0; // componente R
	FBptr[9] = 0; // componente G
	FBptr[10] = 255; // componente B
	FBptr[11] = 255; // componente A
}

void DesenhaLinha(void){
	for (unsigned int i=0; i<250; i++){
		FBptr[4*i + 4*i*IMAGE_WIDTH + 0] = 255;
		FBptr[4*i + 4*i*IMAGE_WIDTH + 1] = 0;
		FBptr[4*i + 4*i*IMAGE_WIDTH + 2] = 255;
		FBptr[4*i + 4*i*IMAGE_WIDTH + 3] = 255;
	}

}


int PutPixel(VERTICES v, COR p){

	int valor = 4*v.x + 4*v.y*IMAGE_WIDTH;

	FBptr[valor + 0] = p.R;
	FBptr[valor + 1] = p.G;
	FBptr[valor + 2] = p.B;
	FBptr[valor + 3] = p.A;

}



void DrawLine(VERTICES v1, VERTICES v2, COR p, COR p1){        
        int slope;
        int dx, dy, incE, incNE, d, x, y;
        float m;
        float Rf, Gf, Bf;
        float R,G,B,A;
        
        int dist;
        
        if(v1.x == v2.x){
        	m = -1;
        }else{
			m = (float(v2.y)-float(v1.y))/(float(v2.x) - float(v1.x)); // calculo do coeficiente angular
		}

        dx = v2.x - v1.x;
        
        dy = v2.y - v1.y;


       	if(-0.5 < m < 0 || m > 1 || m < -2 || m < -1 || dx == 0){
       		        if (v1.y > v2.y){
			            DrawLine(v2, v1, p1, p); // inverte recursivamente
			             return;
			        }   

	        if (dx < 0){            
	            slope = -1;
	            dx = -dx;
	        }
	        else{            
	           slope = 1;
	        }

	        incE = 2 * dx;
	        incNE = 2 * dx - 2 * dy;
	        d = 2 * dx - dy;
	        VERTICES tempV;

	        tempV.x = v1.x;

	        Rf = (float(p1.R) - float(p.R))/(float(dy)); // calculo do incremento das cores
	    	Gf = (float(p1.G) - float(p.G))/(float(dy));
	    	Bf = (float(p1.B) - float(p.B))/(float(dy));

	        
	        COR tempP = {p.R, p.G, p.B, p.A};

	    	R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;

	        for (tempV.y = v1.y; tempV.y <= v2.y; tempV.y++){
	        	R += Rf;		// incrementa aos componentes
	        	G += Gf;
	        	B += Bf;
	        	tempP.R = R;
	        	tempP.G = G;
	        	tempP.B = B;

	            PutPixel(tempV, tempP);

	            if (d <= 0){
	              d += incE;
	            }
	            else{
	              d += incNE;
	              tempV.x += slope;
	            }
	        }
        }else{
       		        if (v1.x > v2.x){
			            DrawLine(v2, v1, p1, p); // inverte recursivamente
			             return;
			        } 

	        if (dy < 0){            
	            slope = -1;
	            dy = -dy;
	        }
	        else{            
	           slope = 1;
	        }
	        // Constante de Bresenham
	        incE = 2 * dy;
	        incNE = 2 * dy - 2 * dx;
	        d = 2 * dy - dx;
	        VERTICES tempV;
	        tempV.y = v1.y;

	        COR tempP = {p.R, p.G, p.B, p.A};

	       
	        Rf = (float(p1.R) - float(p.R))/(float(dx)); // calculo do incremento das cores
	    	Gf = (float(p1.G) - float(p.G))/(float(dx));
	    	Bf = (float(p1.B) - float(p.B))/(float(dx));


			R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;


	        for (tempV.x = v1.x; tempV.x <= v2.x; tempV.x++){
	        	R += Rf;			// incrementa aos componentes
	        	G += Gf;
	        	B += Bf;
	        	tempP.R = R;
	        	tempP.G = G;
	        	tempP.B = B;

	            PutPixel(tempV, tempP);

	            if (d <= 0){
	              d += incE;
	            }
	            else{
	              d += incNE;
	              tempV.y += slope;
	            }
	        }
	    }
	  }

//=============================================
	  void PintaTriangulo(VERTICES inicial, VERTICES v1, VERTICES v2, COR p, COR p1){        // desenha o triangulo
        int slope;
        int dx, dy, incE, incNE, d, x, y;
        float m;
        float Rf, Gf, Bf;
        float R,G,B,A;
        VERTICES aux;
        
        int dist;
        
        if(v1.x == v2.x){
        	m = -1;
        }else{
			m = (float(v2.y)-float(v1.y))/(float(v2.x) - float(v1.x));
		}
 
    
        dx = v2.x - v1.x;
        
        dy = v2.y - v1.y;

        VERTICES tempV;


       	if(-0.5 < m < 0 || m > 1 || m < -2 || m < -1){
       		        if (v1.y > v2.y){
			            PintaTriangulo(inicial, v2, v1, p1, p); // inverte recursivamente
			             return;
			        }   

	        if (dx < 0){            
	            slope = -1;
	            dx = -dx;
	        }
	        else{            
	           slope = 1;
	        }
	        // Constante de Bresenham
	        
	        incE = 2 * dx;
	        incNE = 2 * dx - 2 * dy;
	        d = 2 * dx - dy;

	        tempV.x = v1.x;

	        Rf = (float(p1.R) - float(p.R))/(float(dx)); // calculo do incremento das cores
	    	Gf = (float(p1.G) - float(p.G))/(float(dx));
	    	Bf = (float(p1.B) - float(p.B))/(float(dx));

	        COR tempP = {p.R, p.G, p.B, p.A};
	       
	    	R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;

	        for (tempV.y = v1.y; tempV.y <= v2.y; tempV.y++){
	        	R += Rf;			// incrementa aos componentes
	        	G += Gf;	
	        	B += Bf;
	        	tempP.R = R;
	        	tempP.G = G;
	        	tempP.B = B;


	        	DrawLine(inicial, tempV,p,p1);
	            if (d <= 0){
	              d += incE;
	            }
	            else{
	              d += incNE;
	              tempV.x += slope;
	            }
	        }
        }else{
       		        if (v1.x > v2.x){
			            PintaTriangulo(inicial,v2, v1, p1, p); // inverte recursivamente
			             return;
			        } 

	        if (dy < 0){            
	            slope = -1;
	            dy = -dy;
	        }
	        else{            
	           slope = 1;
	        }
	        // Constante de Bresenham
	        incE = 2 * dy;
	        incNE = 2 * dy - 2 * dx;
	        d = 2 * dy - dx;
	        
	        tempV.y = v1.y;



	        COR tempP = {p.R, p.G, p.B, p.A};

	        Rf = (float(p1.R) - float(p.R))/(float(dx)); // calculo do incremento das cores
	    	Gf = (float(p1.G) - float(p.G))/(float(dx));
	    	Bf = (float(p1.B) - float(p.B))/(float(dx));

	      
			R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;


	        for (tempV.x = v1.x; tempV.x <= v2.x; tempV.x++){
	        	R += Rf;
	        	G += Gf;
	        	B += Bf;
	        	tempP.R = R;
	        	tempP.G = G;
	        	tempP.B = B;

	        	DrawLine(inicial, tempV,p,p1);

	            if (d <= 0){
	              d += incE;
	            }
	            else{
	              d += incNE;
	              tempV.y += slope;
	            }
	        }
	    }

	  }



  void preencherTrianguloBaricentro(VERTICES va, VERTICES vb, VERTICES vc, COR p, COR p1, COR p2){
  	
  	VERTICES vBar = {(va.x+vb.x+vc.x)/3,(va.y+vb.y+vc.y)/3}; // calcula o baricentro
	
	PintaTriangulo(vBar, va, vb, p, p1);
	PintaTriangulo(vBar, vb, vc, p1, p2);
	PintaTriangulo(vBar, vc, va, p2, p);

 }

 void preencherTriangulo(VERTICES va, VERTICES vb, VERTICES vc, COR p, COR p1, COR p2){ // preenche triangulos pelas retas
  	
  	PintaTriangulo(vb, va, vc, p, p);
	PintaTriangulo(vc, vb, va, p1, p);

 }

void DrawTriangle(VERTICES va, VERTICES vb, VERTICES vc, COR p, COR p1, COR p2){ // desenha o triangulo vazio interpolado
	DrawLine(va,vb,p,p1);
	DrawLine(vb,vc,p1,p2);
	DrawLine(vc,va,p2,p);
}

 void preencherTrianguloRecursivo(VERTICES va, VERTICES vb, VERTICES vc, COR p, COR p1, COR p2){ // função por curiosidade que não se aplica a outros vertices
  	
  	VERTICES vBar = {(va.x+vb.x+vc.x)/3,(va.y+vb.y+vc.y)/3};
	//PintaTriangulo(va, vb, vc, p1, p1);
	DrawTriangle(va, vb, vc, p, p1, p2);

	va.x = va.x+1;
	va.y = va.y-1;

	vb.x = vb.x;
	vb.y = vb.y+1;

	vc.x = vc.x-1;
	vc.y = vc.y-1;

	if(vBar.x == va.x || vBar.x == vb.x || vBar.x == vc.x){
		return;
	}
	preencherTrianguloRecursivo(va,vb,vc,p,p1,p2);
 }

void trianguloEscala(VERTICES va, VERTICES vb, VERTICES vc, COR p, COR p1, COR p2){ 
	float j;
	int xbar,ybar,distx,disty,auxx,auxy;

	xbar = (va.x + vb.x + vc.x)/3; // Calcula o baricentro do triangulo
	ybar = (va.y + vb.y + vc.y)/3;

	va.x = va.x;
	va.y = va.y;

	vb.x = vb.x;
	vb.y = vb.y;

	vc.x = vc.x;
	vc.y = vc.y;

	for(float i = 400; i >= 0; i--){ //Número de triâgulos gerados
		j = 0.98; // fator de multiplicação dos triagulos

		va.x = va.x*(j); 	// multiplica por cada vértice pelo fator de multiplicação
		va.y = va.y*(j);

		vb.x = vb.x*(j);
		vb.y = vb.y*(j);

		vc.x = vc.x*(j);
		vc.y = vc.y*(j);

		auxx = xbar;		// salva o valor do baricentro do triangulo anterior
		auxy = ybar;
		xbar = (va.x + vb.x + vc.x)/3;		// calcula o baricentro do novo triangulo
		ybar = (va.y + vb.y + vc.y)/3;
		distx = auxx - xbar;				// calcula a distancia dos triangulos
		disty = auxy - ybar;

		va.x += distx;						// da um offset no novo triagulo gerado para ir para o centro do anterior 
		va.y += disty;

		vb.x += distx;
		vb.y += disty;

		vc.x += distx;
		vc.y += disty;

		xbar = (va.x + vb.x + vc.x)/3;		//  calcula o baricentro do novo triangulo para depois reiniciar o ciclo
		ybar = (va.y + vb.y + vc.y)/3;

		DrawTriangle(va,vb,vc,p,p1,p2);
	}


}
#endif // _MYGL_H_
