#pragma once

#include "formlib.h"

class Forma {

protected:

	formlib::Vec2 posicion;
	formlib::Vec2 tamanio;
	formlib::Vec2 velocidad;

	formlib::ARGB color;

	System::Drawing::Rectangle canvas;

public:

	Forma(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::Vec2 nuevoTamanio, formlib::ARGB nuevoColor) :
		posicion(nuevaPosicion), tamanio(nuevoTamanio), velocidad(nuevaVelocidad), color(nuevoColor) {

		canvas = System::Drawing::Rectangle((int)posicion.x, (int)posicion.y, (int)tamanio.x, (int)tamanio.y);
	}

	~Forma() = default;

	void setPosicion(formlib::Vec2 nuevaPosicion) { posicion = nuevaPosicion; }
	formlib::Vec2 getPosicion() const { return posicion; }

	void setVelocidad(formlib::Vec2 nuevaVelocidad) { velocidad = nuevaVelocidad; }
	formlib::Vec2 getVelocidad() const { return velocidad; }

	void setTamonio(formlib::Vec2 nuevoTamanio) { tamanio = nuevoTamanio; }
	formlib::Vec2 getTamanio() const { return tamanio; }

	void setColor(formlib::ARGB nuevoColor) { color = nuevoColor; }
	formlib::ARGB getColor() const { return color; }

	virtual void dibujar(System::Drawing::Graphics^ gr) {}

	void actualizar() {
		posicion.x += velocidad.x;
		posicion.y += velocidad.y;

		canvas.X += (int)velocidad.x;
		canvas.Y += (int)velocidad.y;
	}

};