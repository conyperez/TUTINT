#include "TiempoGUI.h"

TiempoGUI::TiempoGUI() {}

TiempoGUI::~TiempoGUI() {}

void TiempoGUI::setIniciar(bool inc)
{
	this->iniciar = inc;
}

void TiempoGUI::setHoras(int h)
{
	this->horas = h;
}

void TiempoGUI::setMinutos(int m)
{
	this->minutos = m;
}

void TiempoGUI::setSegundos(int s)
{
	this->segundos = s;
}

int TiempoGUI::getHoras()
{
	return this->horas;
}

int TiempoGUI::getMinutos()
{
	return this->minutos;
}

int TiempoGUI::getSegundos()
{
	return this->segundos;
}

void TiempoGUI::cronometro()
{
	do {
		if (this->segundos == 60) {
			this->segundos = 0;
			this->minutos++;
		}
		if (this->minutos == 60)
		{
			this->minutos = 0;
		}
		Sleep(1000);
		this->segundos++;
	} while (iniciar);
}

int TiempoGUI::segundostotales()
{
	int segTotal = this->segundos + this->minutos * 60;
	return segTotal;
}