#pragma once
#include <chrono>

namespace global {

	namespace framesDijkstra {
		constexpr unsigned int celdasPorFrame = 8;
	}

	namespace mapa {
		constexpr int tamanioCelda = 8;
		constexpr int x = 8;
		constexpr int y = 8;

		constexpr int columnas = 78;
		constexpr int filas = 43;

		enum Celda {
		vacio,
		noValido,
		camino,
		visitados,
		pared
		};
	}

	
	namespace pantalla {
		int resize = 1;
		int alto = 720;
		int ancho = 1280;

		constexpr std::chrono::microseconds FRAME_DURATION(16667);//para q vaya a 60 fps

	}

	template <typename value_type>
	char sign(const value_type value)
	{
		return (0 < value) - (0 > value);
	}

	template <typename value_type = mapa::Celda>
	using map = std::array<std::array<value_type, mapa::filas>, mapa::columnas>;

	template <typename value_type = unsigned int>
	using posicion = std::pair<value_type, value_type>;

}
