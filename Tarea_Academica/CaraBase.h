#pragma once

#include "Forma.h"
#include "Cara.h"
#include "Ojo.h"
#include "Bocas.h"

#include <vector>

class CaraBase {

private:
	formlib::Vec2 posicion;
	formlib::Vec2 velocidad;

	int* indiceColor;
	std::vector<bool> coloresUsados;
	std::vector<formlib::ARGB> colores;
	formlib::ARGB caraColor;
	formlib::ARGB ojosColor;
	formlib::ARGB bocaColor;

	System::Drawing::Rectangle canvas;

	std::vector<Forma*> caraBase;

public:
	CaraBase(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, short NuevoTipoCara)
		: posicion(nuevaPosicion), velocidad(nuevaVelocidad) {

		System::Random^ random = gcnew System::Random;
		indiceColor = new int;

		canvas = System::Drawing::Rectangle((int)posicion.x, (int)posicion.y, 60, 60);

		for (int i = 0; i < 6; i++) { coloresUsados.push_back(false); }
		colores.push_back(formlib::Rojo);  colores.push_back(formlib::Naranja); colores.push_back(formlib::Amarillo);
		colores.push_back(formlib::Verde); colores.push_back(formlib::Azul);    colores.push_back(formlib::Violeta);

		*indiceColor = random->Next(0, 6); caraColor = colores[*indiceColor]; coloresUsados[*indiceColor] = true;
		do { *indiceColor = random->Next(0, 6); } while (coloresUsados[*indiceColor]); ojosColor = colores[*indiceColor]; coloresUsados[*indiceColor] = true;
		do { *indiceColor = random->Next(0, 6); } while (coloresUsados[*indiceColor]); bocaColor = colores[*indiceColor];

		caraBase.push_back(new Cara(posicion, velocidad, caraColor));
		caraBase.push_back(new Ojo({ posicion.x, posicion.y + 10 }, velocidad, ojosColor));
		caraBase.push_back(new Ojo({ posicion.x + 40, posicion.y + 10 }, velocidad, ojosColor));
		switch (NuevoTipoCara) {
		case 0: caraBase.push_back(new BocaA({ posicion.x + 15, posicion.y + 40 }, velocidad, bocaColor)); break;
		case 1: caraBase.push_back(new BocaB({ posicion.x + 15, posicion.y + 40 }, velocidad, bocaColor)); break;
		case 2: caraBase.push_back(new BocaC({ posicion.x + 15, posicion.y + 40 }, velocidad, bocaColor)); break;
		default: break;
		}

		delete indiceColor;
		delete random;
	}

	~CaraBase() {
		for (auto parte : caraBase) {
			delete parte;
		}
		caraBase.clear();
	}

	formlib::Vec2 getPosicion() const { return posicion; }

	void setVelocidad(formlib::Vec2 nuevaVelocidad) {
		velocidad = nuevaVelocidad;
		for (auto parte : caraBase) {
			parte->setVelocidad(nuevaVelocidad);
		}
	}
	formlib::Vec2 getVelocidad() const { return velocidad; }

	System::Drawing::Rectangle getCanvas() const { return canvas; }

	void dibujar(System::Drawing::Graphics^ gr) {
		for (auto parte : caraBase) {
			parte->dibujar(gr);
		}
	}

	void actualizar() {

		posicion.x += velocidad.x;
		posicion.y += velocidad.y;

		canvas.X = (int)posicion.x;
		canvas.Y = (int)posicion.y;

		for (auto parte : caraBase) {
			parte->actualizar();
		}
	}
};
