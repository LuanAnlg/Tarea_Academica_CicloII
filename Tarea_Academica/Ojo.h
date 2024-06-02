#pragma once

#include "Forma.h"

class Ojo : public Forma { //-> Clase polimorfa de Forma

public:


	// ------------------------------ Constructor y Desctructor ------------------------------
	Ojo(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 20, 20 }, nuevoColor) {};
	~Ojo() = default;
	// ---------------------------------------------------------------------------------------


	// ------------------------------------------------------------------------------------ Metodo sobrescrito ------------------------------------------------------------------------------------
	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(this->color.a, this->color.r, this->color.g, this->color.b)), this->canvas);
	}
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};