#pragma once
#include <iomanip>

#define uint unsigned int

template <class T>
class Matrix {
	uint width;
	uint height;
	T** arr;
public:
	Matrix<T>(uint width, uint height, T def) {
		this->width = width;
		this->height = height;
		this->arr = new T*[width];
		for (uint i = 0; i < width; i++) {
			this->arr[i] = new T[height];
			for (uint j = 0; j < height; j++) {
				this->arr[i][j] = def;
			}
		}
	}
	const T get(uint x, uint y) {
		return this->arr[x][y];
	}
	void set(uint x, uint y, T value) {
		this->arr[x][y] = value;
	}
	const uint get_width( ) {
		return this->width;
	}
	const uint get_height( ) {
		return this->height;
	}
	friend std::ostream& operator << (std::ostream& out, Matrix<T>& m) {
		std::vector<uint> col_size;
		for (uint i = 0; i < m.get_width( ); i++) {
			col_size.push_back(0);
			for (uint j = 0; j < m.get_height( ); j++) {
				std::string s = SU::int_to_string(m.get(i, j));
				uint s_size = s.size( );
				if (s_size > col_size[i]) {
					col_size[i] = s_size;
				}
			}
		}
		for (uint y = 0; y < m.get_height( ); y++) {
			for (uint x = 0; x < m.get_width( ); x++) {
				out << std::setw(col_size[x] + 1) << m.get(x, y);
			}
			out << std::endl;
		}
		return out;
	}
};
