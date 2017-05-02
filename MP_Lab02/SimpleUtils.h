#pragma once
#include <vector>
#include <set>
#include <string>

#define uint unsigned int

namespace SU {

	template <class T>
	std::vector<T> set_to_vector(std::set<T> set) {
		std::vector<T> result;
		for (T el : set) {
			result.push_back(el);
		}
		return result;
	}

	bool get_bit(int integer, uint numb) {
		int temp = integer;
		temp >>= numb;
		return (integer >> numb) & 1 > 0;
	}

	void clear_console( ) {
		system("cls");
	}

	template <class T>
	std::ostream& operator << (std::ostream& out, std::set<T> set) {
		out << "set = { ";
		for (T elem : set) {
			out << elem << ' ';
		}
		return out << '}';
	}

	template <class T>
	std::ostream& operator << (std::ostream& out, std::vector<T> v) {
		uint v_size = v.size( );
		out << "Vector(" << v_size << ") = {";
		if (v_size > 0) {
			out << std::endl;
		}
		for (uint i = 0; i < v_size; i++) {
			out << " " << i << ". " << v[i] << std::endl;
		}
		out << '}';
		return out;
	}

	void pause( ) {
		system("pause");
	}

	std::string int_to_string(int i, uint radix = 10) {
		char str[16];
		_itoa_s(i, str, radix);
		std::string result = str;
		return result;
	}
}
