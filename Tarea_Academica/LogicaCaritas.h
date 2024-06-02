#pragma once

#include "CaraBase.h"

#include <vector>
class LogicaCaritas
{
private:

	CaraBase* carita;
	std::vector<int> multiplicadorVelocidad;

public:

	LogicaCaritas(System::Drawing::Graphics^ gr, short tipoCara) {
		System::Random^ random = gcnew System::Random;

		multiplicadorVelocidad.push_back(-1); multiplicadorVelocidad.push_back(1);
		carita = new CaraBase({ ((float)gr->VisibleClipBounds.Width - 60) / 2, ((float)gr->VisibleClipBounds.Height - 60) / 2 },
			{ 5 * (float)multiplicadorVelocidad[random->Next(0,2)], 5 * (float)multiplicadorVelocidad[random->Next(0,2)] }, tipoCara);

		delete random;
	}
	~LogicaCaritas() = default;

	void dibujar(System::Drawing::Graphics^ gr) {
		carita->dibujar(gr);
	}

	void actualizar(System::Drawing::Graphics^ gr) {
		if (carita->getPosicion().x + carita->getVelocidad().x < 0 || carita->getPosicion().x + carita->getVelocidad().x + carita->getCanvas().Width > gr->VisibleClipBounds.Width) {
			carita->setVelocidad({ carita->getVelocidad().x * -1, carita->getVelocidad().y });
		}
		if (carita->getPosicion().y + carita->getVelocidad().y < 0 || carita->getPosicion().y + carita->getVelocidad().y + carita->getCanvas().Height > gr->VisibleClipBounds.Height) {
			carita->setVelocidad({ carita->getVelocidad().x, carita->getVelocidad().y * -1 });
		}
		carita->actualizar();
	}
};