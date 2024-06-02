#pragma once

#include "formlib.h" // Incluimos nuestra biblioteca

class Forma { //-> Esta será la calse padre de casi todos los siguientes objetos

protected:


	// - Hacemos uso de las variables Vec2 y ARGB para reducir codigo -
	formlib::Vec2 posicion;
	formlib::Vec2 tamanio;
	formlib::Vec2 velocidad;
	formlib::ARGB color;
	// ----------------------------------------------------------------


	System::Drawing::Rectangle canvas;
	

public:


	// ---------------------------------------------------------- Constructor y Desctructor ----------------------------------------------------------
	Forma(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::Vec2 nuevoTamanio, formlib::ARGB nuevoColor) :
		posicion(nuevaPosicion), tamanio(nuevoTamanio), velocidad(nuevaVelocidad), color(nuevoColor) { // Usamos la version abrebiada del constructor

		// Devido a que System::Drawing::Rectangle esta fuera de nuestro control lo tenemos que inicializar dentro del constructor
		this->canvas = System::Drawing::Rectangle((int)posicion.x, (int)posicion.y, (int)tamanio.x, (int)tamanio.y);
	}
	~Forma() = default;
	// -----------------------------------------------------------------------------------------------------------------------------------------------



	// --------------------------------- Setter y Getter ---------------------------------
	void setPosicion(formlib::Vec2 nuevaPosicion) { this->posicion = nuevaPosicion; }
	formlib::Vec2 getPosicion() const { return this->posicion; }

	void setVelocidad(formlib::Vec2 nuevaVelocidad) { this->velocidad = nuevaVelocidad; }
	formlib::Vec2 getVelocidad() const { return this->velocidad; }

	void setTamonio(formlib::Vec2 nuevoTamanio) { this->tamanio = nuevoTamanio; }
	formlib::Vec2 getTamanio() const { return this->tamanio; }

	void setColor(formlib::ARGB nuevoColor) { this->color = nuevoColor; }
	formlib::ARGB getColor() const { return this->color; }

	void setCanvas(System::Drawing::Rectangle nuevoCanvas) { this->canvas = nuevoCanvas; }
	System::Drawing::Rectangle getCanvas() const { return this->canvas; }
	// -----------------------------------------------------------------------------------


	// --------------------- Metodos ---------------------
	virtual void dibujar(System::Drawing::Graphics^ gr) {}

	void actualizar() {
		this->posicion.x += this->velocidad.x;
		this->posicion.y += this->velocidad.y;

		this->canvas.X += (int)this->velocidad.x;
		this->canvas.Y += (int)this->velocidad.y;
	}
	// ---------------------------------------------------
};