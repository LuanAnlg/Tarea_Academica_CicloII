#pragma once

#include "Forma.h"
#include "Cara.h"
#include "Ojo.h"
#include "Bocas.h"

#include <vector>

class CaraBase { //-> Clase contenedora de objetos figura

private:

	// - Poosicion y Velocidad -
	formlib::Vec2 posicion;
	formlib::Vec2 velocidad;
	// -------------------------


	// ------------- Color -------------
	int* indiceColor;
	std::vector<bool> coloresUsados;
	std::vector<formlib::ARGB> colores;
	formlib::ARGB caraColor;
	formlib::ARGB ojosColor;
	formlib::ARGB bocaColor;
	// ---------------------------------


	// ------------ Canvas ------------
	System::Drawing::Rectangle canvas;
	// --------------------------------


	// ------ Conjunto Cara ------
	std::vector<Forma*> caraBase;
	// ---------------------------


public:


	// -------------------------------------------------------------------------- Constructor y Desctructor --------------------------------------------------------------------------

	CaraBase(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, short NuevoTipoCara)
		: posicion(nuevaPosicion), velocidad(nuevaVelocidad) {

		// Declaramos e iniciamos nuestros punteros
		System::Random^ random = gcnew System::Random;
		indiceColor = new int;

		// Inicializamos nuestro canvas
		this->canvas = System::Drawing::Rectangle((int)this->posicion.x, (int)this->posicion.y, 60, 60);

		// Rellenamos nuestros vector encargado de los colores
		for (int i = 0; i < 6; i++) { this->coloresUsados.push_back(false); }
		this->colores.push_back(formlib::Rojo);  this->colores.push_back(formlib::Naranja); this->colores.push_back(formlib::Amarillo);
		this->colores.push_back(formlib::Verde); this->colores.push_back(formlib::Azul);    this->colores.push_back(formlib::Violeta);

		// Logica para que no se repitan los colores
		*indiceColor = random->Next(0, 6); this->caraColor = this->colores[*indiceColor]; this->coloresUsados[*indiceColor] = true;
		do { *indiceColor = random->Next(0, 6); } while (this->coloresUsados[*indiceColor]); this->ojosColor = this->colores[*indiceColor]; this->coloresUsados[*indiceColor] = true;
		do { *indiceColor = random->Next(0, 6); } while (this->coloresUsados[*indiceColor]); this->bocaColor = this->colores[*indiceColor];

		// Rellenamos vector cara con distintas partes
		this->caraBase.push_back(new Cara(this->posicion, this->velocidad, this->caraColor));
		this->caraBase.push_back(new Ojo({ this->posicion.x, this->posicion.y + 10 }, this->velocidad, ojosColor));
		this->caraBase.push_back(new Ojo({ this->posicion.x + 40, this->posicion.y + 10 }, this->velocidad, this->ojosColor));
		switch (NuevoTipoCara) { // Logica para hacer distintas caras
		case 0: this->caraBase.push_back(new BocaA({ this->posicion.x + 15, this->posicion.y + 40 }, this->velocidad, this->bocaColor)); break;
		case 1: this->caraBase.push_back(new BocaB({ this->posicion.x + 15, this->posicion.y + 40 }, this->velocidad, this->bocaColor)); break;
		case 2: this->caraBase.push_back(new BocaC({ this->posicion.x + 15, this->posicion.y + 40 }, this->velocidad, this->bocaColor)); break;
		default: break;
		}

		// Liberamos nuestra memoria
		delete indiceColor;
		delete random;
	}

	~CaraBase() {
		// Eliminamos todo dentro del vector
		for (auto parte : this->caraBase) { delete parte; }
		this->caraBase.clear();
	}

	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


	// --------------------------------- Setter y Getter ---------------------------------

	void setPosicion(formlib::Vec2 nuevaPosicion) { this->posicion = nuevaPosicion; }
	formlib::Vec2 getPosicion() const { return this->posicion; }

	void setVelocidad(formlib::Vec2 nuevaVelocidad) {
		this->velocidad = nuevaVelocidad;
		for (auto parte : this->caraBase) { parte->setVelocidad(nuevaVelocidad); }
	}
	formlib::Vec2 getVelocidad() const { return this->velocidad; }

	void setCaraColor(formlib::ARGB nuevoColor) { this->caraColor = nuevoColor; }
	formlib::ARGB getCaraColor() const { return this->caraColor; }

	void setOjosColor(formlib::ARGB nuevoColor) { this->ojosColor = nuevoColor; }
	formlib::ARGB getOjosColor() const { return this->ojosColor; }

	void setBocaColor(formlib::ARGB nuevoColor) { this->bocaColor = nuevoColor; }
	formlib::ARGB getBocaColor() const { return this->bocaColor; }

	void setCanvas(System::Drawing::Rectangle nuevoCanvas) { this->canvas = nuevoCanvas; }
	System::Drawing::Rectangle getCanvas() const { return this->canvas; }

	// -----------------------------------------------------------------------------------


	// ------------------------- Metodos -------------------------

	void dibujar(System::Drawing::Graphics^ gr) {
		for (auto parte : this->caraBase) { parte->dibujar(gr); }
	}
	
	void actualizar() {

		this->posicion.x += this->velocidad.x;
		this->posicion.y += this->velocidad.y;

		this->canvas.X = (int)this->posicion.x;
		this->canvas.Y = (int)this->posicion.y;

		for (auto parte : this->caraBase) { parte->actualizar(); }
	}

	// -----------------------------------------------------------
};
