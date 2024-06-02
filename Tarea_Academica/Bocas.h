#pragma once

#include "Forma.h"

class BocaA : public Forma {

public:

	BocaA(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 30, 3 }, nuevoColor) {};
	~BocaA() = default;

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(color.a, color.r, color.g, color.b), 3), canvas);
	}
};

class BocaB : public Forma {

public:

	BocaB(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 30, 15 }, nuevoColor) {};
	~BocaB() = default;

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(color.a, color.r, color.g, color.b), 3), canvas);
	}
};

class BocaC : public Forma {

public:

	BocaC(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 30, 15 }, nuevoColor) {};
	~BocaC() = default;

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(color.a, color.r, color.g, color.b), 3), canvas);
	}
};