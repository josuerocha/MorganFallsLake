
#include "BolaLago.h"
#include <iostream>
#include <ctime>


#define PI 3.14159265
using namespace std;
BolaLago::BolaLago(float x, float y, float z, float dx, float dy, float dz,float tempo2) {
	posiX = x;
	posiY = y;
	posiZ = z;
	posiYdescanso = y;
	dimX = dx;
	dimY = dy;
	dimZ = dz;
	velocidade = 0.2;
	subindo = true;
	subiu = false;
	posiYMax = y + 0.2*dimY;
	posiYMin = y - 0.0*dimY;
	tempoEspera = 100;
	tempo = tempo2;

}


void BolaLago::desenha() {
	glPushMatrix();
	glColor4f(0.3*((posiY - posiYMin) / (posiYMax - posiYMin)), 0.3*((posiY - posiYMin) / (posiYMax - posiYMin)), 0.3+0.6*((posiY - posiYMin) / (posiYMax - posiYMin)), 1-((posiY - posiYMin) / (posiYMax - posiYMin)));
	glTranslatef(posiX, posiY, posiZ);

	glPushMatrix();
	glScalef(dimX, dimY, dimZ);
											  //desenhar um circulo raio 0.5, centro(0,0,0)
	GLUquadricObj *obj1 = gluNewQuadric();
	//glColor3f(0.5, 0.5, 0.5);
	//glBindTexture(GL_TEXTURE_2D, texture_id[textura]);
	gluQuadricNormals(obj1, GLU_SMOOTH);
	gluQuadricTexture(obj1, GL_TRUE);
	gluSphere(obj1, 0.5, 20, 20);
	glPopMatrix();

	glColor3f(1,1,1);
	glPopMatrix();


	if (tempo < tempoEspera) {
		tempo++;
	}else{
		if (subindo) {
			posiY += velocidade;
		}
		else {
			posiY -= velocidade;

		}
		if (posiY >= posiYMax) {
			subindo = false;
			subiu = true;
		}
		else if (posiY <= posiYMin) {
			subindo = true;
		}
		if (subindo && subiu && posiY >= posiYdescanso) {
			subiu = false;
			tempo = 0;
			posiY = posiYdescanso;
		}
	}

	

}


float BolaLago::getPosiX() { return posiX; }
float BolaLago::getPosiY() { return posiY; }
float BolaLago::getPosiZ() { return posiZ; }
void BolaLago::setPosiX(float a) { posiX = a; }
void BolaLago::setPosiY(float a) { posiY = a; }
void BolaLago::setPosiZ(float a) { posiZ = a; }