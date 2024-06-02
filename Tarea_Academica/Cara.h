#pragma once

#include "Forma.h"

class Cara : public Forma { //-> Clase polimorfa de Forma

public:


	// ------------------------------- Constructor y Desctructor -------------------------------

	Cara(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 60, 60 }, nuevoColor) {};
	~Cara() = default;

	// -----------------------------------------------------------------------------------------


	// ---------------------------------------------------------------------------------- Metodo sobrescrito ----------------------------------------------------------------------------------

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(this->color.a, this->color.r, this->color.g, this->color.b), 3), this->canvas);
	}

	// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};