#pragma once

#include "Forma.h"

class Ojo : public Forma {

public:

	Ojo(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, {20, 20}, nuevoColor) {};
	~Ojo() = default;

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(color.a, color.r, color.g, color.b)), canvas);
	}
};