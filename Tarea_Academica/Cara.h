#pragma once

#include "Forma.h"

class Cara : public Forma {

public:

	Cara(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 60, 60 }, nuevoColor) {};
	~Cara() = default;

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(color.a, color.r, color.g, color.b), 3), canvas);
	}
};