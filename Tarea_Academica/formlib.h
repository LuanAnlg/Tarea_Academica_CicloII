#pragma once

namespace formlib {

	struct Vec2 {
		float x, y;
	};

	struct Vec3 {
		float x, y, z;
	};

	struct ARGB {
		int a, r, g, b;
	};

	enum class Direcciones {
		Izquierda,
		Derecha,
		Arriba,
		Abajo,
		Ninguno
	};

	constexpr ARGB Rojo =     { 255, 250, 0, 24 };
	constexpr ARGB Naranja =  { 255, 250, 165, 44 };
	constexpr ARGB Amarillo = { 255, 255, 255, 65 };
	constexpr ARGB Verde =    { 255, 0, 128, 24 };
	constexpr ARGB Azul =     { 255, 0, 0, 249 };
	constexpr ARGB Violeta =  { 255, 134, 0, 125 };
	constexpr ARGB Negro =    { 255, 0, 0, 0 };
	constexpr ARGB Blanco =   { 255, 255, 255, 255 };
}