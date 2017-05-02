#pragma once
#include "Matrix.h"

template <class T>
class SMatrix : public Matrix<T> {
public:
	SMatrix<T>(uint size, T def_value) : Matrix<T>(size, size, def_value) {

	}
	uint get_size( ) {
		return this->get_width( );
	}
};
