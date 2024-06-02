#pragma once

#include "CaraBase.h"
#include <windows.h>

class LogicaCarrera {
private:
	std::vector<CaraBase*> caras;
	std::vector<bool> velocidadesUsadas;
	System::Drawing::Rectangle meta_canvas;

public:
	LogicaCarrera() {
		System::Random^ random = gcnew System::Random;

		meta_canvas = System::Drawing::Rectangle(600, 0, 3, 480);

		for (int i = 0; i < 3; i++) {
			velocidadesUsadas.push_back(false);
		}

		for (int i = 0; i < 3; i++) {
			int indiceVelocidad;
			do {
				indiceVelocidad = random->Next(0, 3);
			} while (velocidadesUsadas[indiceVelocidad]);

			caras.push_back(new CaraBase({ 12, ((float)i * 100) + 36 }, { ((float)indiceVelocidad + 1) * 2, 0 }, random->Next(0, 3)));
			velocidadesUsadas[indiceVelocidad] = true;
			Sleep(1);
		}

		delete random;
	}

	~LogicaCarrera() {
		for (auto cara : caras) {
			delete cara;
		}
		caras.clear();
	}

	void dibujar(System::Drawing::Graphics^ gr) {
		for (auto cara : caras) {
			cara->dibujar(gr);
		}
		gr->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(formlib::Negro.a, formlib::Negro.r, formlib::Negro.g, formlib::Negro.b)), meta_canvas);
	}

	bool actualizar() {
		for (auto cara : caras) {
			cara->actualizar();
			if (cara->getCanvas().IntersectsWith(meta_canvas)) {
				return true;
			}
		}
		return false;
	}
};
