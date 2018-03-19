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

void DesenhaLinha(void)
{
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
			m = (float(v2.y)-float(v1.y))/(float(v2.x) - float(v1.x));
		}
		//printf("\n m = %f",m);  
    
        dx = v2.x - v1.x;
        
        dy = v2.y - v1.y;

        
         dist = sqrt(pow(v2.x - v1.x,2) + pow(v2.y - v1.y,2));

       	if(-0.5 < m < 0 || m > 1 || m < -2 || m < -1){
       		        if (v1.y > v2.y){
			            DrawLine(v2, v1, p1, p); // inverte recursivamente
			             return;
			        }   

       		//printf("\n m < 0 ");
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
	        VERTICES tempV;
	        
	        //tempP = {p.R, p.G, p.B, p.A}
	        tempV.x = v1.x;

	        //COR tempP;

	        printf("\n Distancia = %d", dist);
	        //dist = 120;
	        Rf = (float(p1.R) - float(p.R))/(float(dist));
	    	Gf = (float(p1.G) - float(p.G))/(float(dist));
	    	Bf = (float(p1.B) - float(p.B))/(float(dist));

	        
	        COR tempP = {p.R, p.G, p.B, p.A};
	        //Rf = 1;
	    	R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;

	        for (tempV.y = v1.y; tempV.y <= v2.y; tempV.y++){
	        	R += Rf;
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
    		//printf("\n m > 0 ");
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

	        //COR tempP;
	        
	       
	        //printf("\n Dist = %d", dist);

	        COR tempP = {p.R, p.G, p.B, p.A};

	       
	        Rf = (float(p1.R) - float(p.R))/(float(dist));
	    	Gf = (float(p1.G) - float(p.G))/(float(dist));
	    	Bf = (float(p1.B) - float(p.B))/(float(dist));


			R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;

	    	//Rf = 1;

	        for (tempV.x = v1.x; tempV.x <= v2.x; tempV.x++){
	        	R += Rf;
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
        //VERTICES b;
        
        int dist;
        
        if(v1.x == v2.x){
        	m = -1;
        }else{
			m = (float(v2.y)-float(v1.y))/(float(v2.x) - float(v1.x));
		}
		//printf("\n m = %f",m);  
    
        dx = v2.x - v1.x;
        
        dy = v2.y - v1.y;

        VERTICES tempV;
         dist = sqrt(pow(v2.x - v1.x,2) + pow(v2.y - v1.y,2));

       	if(-0.5 < m < 0 || m > 1 || m < -2 || m < -1){
       		        if (v1.y > v2.y){
			            PintaTriangulo(inicial, v2, v1, p1, p); // inverte recursivamente
			             return;
			        }   

       		//printf("\n m < 0 ");
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
	        
	        
	        //tempP = {p.R, p.G, p.B, p.A}
	        tempV.x = v1.x;

	        //COR tempP;

	        printf("\n Distancia = %d", dist);
	        //dist = 120;
	        Rf = (float(p1.R) - float(p.R))/(float(dist));
	    	Gf = (float(p1.G) - float(p.G))/(float(dist));
	    	Bf = (float(p1.B) - float(p.B))/(float(dist));

	        //printf("\n Rf = %f", Rf);
	        //printf("\n Gf = %f", Gf);
	        //printf("\n Bf = %f", Bf);

	        COR tempP = {p.R, p.G, p.B, p.A};
	        //Rf = 1;
	    	R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;

	        for (tempV.y = v1.y; tempV.y <= v2.y; tempV.y++){
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
	              tempV.x += slope;
	            }
	        }
        }else{
       		        if (v1.x > v2.x){
			            PintaTriangulo(inicial,v2, v1, p1, p); // inverte recursivamente
			             return;
			        } 
    		//printf("\n m > 0 ");
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

	        //COR tempP;
	        
	       
	        //printf("\n Dist = %d", dist);

	        COR tempP = {p.R, p.G, p.B, p.A};

	        Rf = (float(p1.R) - float(p.R))/(float(dist));
	    	Gf = (float(p1.G) - float(p.G))/(float(dist));
	    	Bf = (float(p1.B) - float(p.B))/(float(dist));

	      
			R = p.R;
	    	G = p.G;
	    	B = p.B;
	    	A = p.A;

	    	//Rf = 1;

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

	    //DrawLine(inicial, tempV, p, p1);
	  }


  void preencherTriangulo(VERTICES va, VERTICES vb, VERTICES vc, COR p, COR p1, COR p2){
  	

	//PintaTriangulo(va, vb, vc, p1, p1);
	PintaTriangulo(vb, va, vc, p1, p1);
	PintaTriangulo(vc, vb, va, p1, p);


 }

void DrawTriangle(VERTICES va, VERTICES vb, VERTICES vc, COR p, COR p1, COR p2){
	DrawLine(va,vb,p,p1);
	DrawLine(vb,vc,p1,p2);
	DrawLine(vc,va,p2,p);
}

void testeT(VERTICES va, VERTICES vb, VERTICES vc, float taxa, COR p, COR p1, COR p2){
	float j = 0.1;
	int xbar,ybar,distx,disty,auxx,auxy;

	xbar = (va.x + vb.x + vc.x)/3;
	ybar = (va.y + vb.y + vc.y)/3;

	va.x = va.x*(taxa);
	va.y = va.y*(taxa);

	vb.x = vb.x*(taxa);
	vb.y = vb.y*(taxa);

	vc.x = vc.x*(taxa);
	vc.y = vc.y*(taxa);

	//taxa = taxa - i;
	for(float i = 100; i >= 0; i--){
		j = 0.979;


		va.x = va.x*(j);
		va.y = va.y*(j);

		vb.x = vb.x*(j);
		vb.y = vb.y*(j);

		vc.x = vc.x*(j);
		vc.y = vc.y*(j);

		auxx = xbar;
		auxy = ybar;
		xbar = (va.x + vb.x + vc.x)/3;
		ybar = (va.y + vb.y + vc.y)/3;
		distx = auxx - xbar;
		disty = auxy - ybar;

		va.x += distx;
		va.y += disty;

		vb.x += distx;
		vb.y += disty;

		vc.x += distx;
		vc.y += disty;

		xbar = (va.x + vb.x + vc.x)/3;
		ybar = (va.y + vb.y + vc.y)/3;

		DrawTriangle(va,vb,vc,p,p1,p2);
	}
	//DrawTriangle(va,vb,vc,p,p1,p2);
	//if(taxa == 0){
	//	return;
	//}
	//testeT(va,vb,vc,taxa,p,p1,p2);

}
#endif // _MYGL_H_
