#pragma once
#include <stdlib.h>
#include <math.h>

struct  triangulo {
	int *x1, *y1, *x2, *y2, *x3, *y3;
};
struct  triangulo2 {
	int *w1, *z1, *w2, *z2, *w3, *z3;
};

void Mostrar_Carro(triangulo *movil, ALLEGRO_BITMAP *imgmovil) {
	al_draw_scaled_bitmap(imgmovil, 0, 0, 169, 171, *movil[0].x2, *movil[0].y2, 20, 20, 0);
}
void Mostrar_Carro2(triangulo2 *movil2, ALLEGRO_BITMAP *imgmovil2) {
	al_draw_scaled_bitmap(imgmovil2, 0, 0, 169, 171, *movil2[0].w2, *movil2[0].z2, 20, 20, 0);
}
void Insertar_Carro(triangulo *movil) {
	movil[0].x1 = new int;
	movil[0].y1 = new int;
	movil[0].x2 = new int;
	movil[0].y2 = new int;
	movil[0].x3 = new int;
	movil[0].y3 = new int;
	*movil[0].x1 = 375;
	*movil[0].y1 = 550;
	*movil[0].x2 = 400;
	*movil[0].y2 = 500;
	*movil[0].x3 = 425;
	*movil[0].y3 = 550;
}
void InsertarCarro2(triangulo2 *movil2) {
	movil2[0].w1 = new int;
	movil2[0].z1 = new int;
	movil2[0].w2 = new int;
	movil2[0].z2 = new int;
	movil2[0].w3 = new int;
	movil2[0].z3 = new int;
	*movil2[0].w1 = 275;
	*movil2[0].z1 = 500;
	*movil2[0].w2 = 300;
	*movil2[0].z2 = 450;
	*movil2[0].w3 = 325;
	*movil2[0].z3 = 500;
}
int mapa[15][15] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
void Dibujar_Mapa(ALLEGRO_BITMAP *imgmovil) {
	int x = 0, y = 0;
	for (int i = 0; i < 15; i++)
	{
		x = 0;
		for (int j = 0; j < 15; j++)
		{

			if(mapa[i][j]==1)al_draw_scaled_bitmap(imgmovil, 0, 0, 169, 171, x, y, 800/15, 600/15, 0);			
			x += 800 / 15;
		}		
		y += 600 / 15;
	}
	
}
bool Colisiona(int xj,int yj) {
	int x = 0, y = 0;
	for (int i = 0; i < 15; i++)
	{
		x = 0;
		for (int j = 0; j < 15; j++)
		{
			if (mapa[i][j]) {
				if ((xj>= x && xj<= (x + 800/15)) ||
					((xj+ 20) >= x && (xj+ 20) <= (x + 800/15))) {				
					if ((yj >= y && yj <= (y + 600 / 15)) ||
						((yj + 20) >= y && (yj + 20) <= (y + 600 / 15))) {
						return true;
					}
				}
			}
			x += 800/15;
		}
		y += 600 / 15;
	}
	return false;
}
void Mover_Derecha(triangulo *movil) {
	if (*movil[0].x3 < 800&&!Colisiona(*movil[0].x2+10, *movil[0].y2)) {
		*movil[0].x1 = *movil[0].x1 + 10; // se va a mover de 10 en 10 espacios
		*movil[0].x2 = *movil[0].x2 + 10; // se va a mover de 10 en 10 espacios
		*movil[0].x3 = *movil[0].x3 + 10; // se va a mover de 10 en 10 espacios
	}
}
void Mover_Izquierda(triangulo *movil) {
	if (*movil[0].x1 >1 && !Colisiona(*movil[0].x2 - 10, *movil[0].y2)) {
		*movil[0].x1 = *movil[0].x1 - 10; // se va a mover de 10 en 10 espacios
		*movil[0].x2 = *movil[0].x2 - 10; // se va a mover de 10 en 10 espacios
		*movil[0].x3 = *movil[0].x3 - 10; // se va a mover de 10 en 10
	}
}
void Mover_Abajo(triangulo *movil) {
	if (*movil[0].y3 < 600 && !Colisiona(*movil[0].x2 , *movil[0].y2+10)) {
		*movil[0].y1 = *movil[0].y1 + 10; // se va a mover de 10 en 10 espacios
		*movil[0].y2 = *movil[0].y2 + 10; // se va a mover de 10 en 10 espacios
		*movil[0].y3 = *movil[0].y3 + 10; // se va a mover de 10 en 10 espacios
	}
}
void Mover_Arriba(triangulo *movil) {
	if (*movil[0].y3 > 1 && !Colisiona(*movil[0].x2 , *movil[0].y2-10)) {
		*movil[0].y1 = *movil[0].y1 - 10; // se va a mover de 10 en 10 espacios
		*movil[0].y2 = *movil[0].y2 - 10; // se va a mover de 10 en 10 espacios
		*movil[0].y3 = *movil[0].y3 - 10; // se va a mover de 10 en 10 espacios
	}
}
void MoverDerecha(triangulo2 *movil2) {
	if (*movil2[0].w3 < 800) {
		*movil2[0].w1 = *movil2[0].w1 + 10; // se va a mover de 10 en 10 espacios
		*movil2[0].w2 = *movil2[0].w2 + 10; // se va a mover de 10 en 10 espacios
		*movil2[0].w3 = *movil2[0].w3 + 10; // se va a mover de 10 en 10 espacios
	}
}
void MoverIzquierda(triangulo2 *movil2) {
	if (*movil2[0].w1 >1) {
		*movil2[0].w1 = *movil2[0].w1 - 10; // se va a mover de 10 en 10 espacios
		*movil2[0].w2 = *movil2[0].w2 - 10; // se va a mover de 10 en 10 espacios
		*movil2[0].w3 = *movil2[0].w3 - 10; // se va a mover de 10 en 10
	}
}
void MoverAbajo(triangulo2 *movil2) {
	if (*movil2[0].z3 < 600) {
		*movil2[0].z1 = *movil2[0].z1 + 10; // se va a mover de 10 en 10 espacios
		*movil2[0].z2 = *movil2[0].z2 + 10; // se va a mover de 10 en 10 espacios
		*movil2[0].z3 = *movil2[0].z3 + 10; // se va a mover de 10 en 10 espacios
	}
}
void MoverArriba(triangulo2 *movil2) {
	if (*movil2[0].z3 > 1) {
		*movil2[0].z1 = *movil2[0].z1 - 10; // se va a mover de 10 en 10 espacios
		*movil2[0].z2 = *movil2[0].z2 - 10; // se va a mover de 10 en 10 espacios
		*movil2[0].z3 = *movil2[0].z3 - 10; // se va a mover de 10 en 10 espacios
	}
}
