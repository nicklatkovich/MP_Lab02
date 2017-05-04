#pragma once
#include <ostream>
#include "SimpleUtils.h"
#include <string>
#include "SMatrix.h"

#define uint unsigned int

namespace MP {
	template <class T>
	std::vector<std::set<T>> generate_subsets(std::set<T> set) {
		std::vector<T> elems = SU::set_to_vector(set);
		std::vector<std::set<T>> result;
		uint elems_numb = elems.size( );
		uint max_bitter = (uint)pow(2, elems_numb);
		for (uint bitter = 0; bitter < max_bitter; bitter++) {
			std::set<T> preresult;
			for (uint bit = 0; bit < elems_numb; bit++) {
				if (SU::get_bit(bitter, bit)) {
					preresult.insert(elems[bit]);
				}
			}
			result.push_back(preresult);
		}
		return result;
	}

	template <class T>
	std::vector<std::set<T>> generate_combinations(std::set<T> set, int k) {
		std::vector<std::set<T>> result;
		std::vector<std::set<T>> subsets = MP::generate_subsets(set);
		for (uint i = 0; i < subsets.size( ); i++) {
			if (subsets[i].size( ) == k) {
				result.push_back(subsets[i]);
			}
		}
		return result;
	}

	template <class T>
	std::vector<std::vector<T>> generate_permutations(std::set<T> set) {
		return generate_permutations(SU::set_to_vector(set));
	}

	template <class T>
	std::vector<std::vector<T>> generate_permutations(std::vector<T> v) {
		std::vector<std::vector<T>> result;
		if (v.size( ) == 1) {
			result.push_back(v);
			return result;
		} else {
			for (uint i = 0; i < v.size( ); i++) {
				std::vector<T> first_perm = v;
				T elem = first_perm[i];
				first_perm.erase(first_perm.begin() + i);
				std::vector<std::vector<T>> preresult = MP::generate_permutations(first_perm);
				for (uint j = 0; j < preresult.size( ); j++) {
					preresult[j].push_back(elem);
					result.push_back(preresult[j]);
				}
			}
			return result;
		}
	}

	template <class T>
	std::vector<std::vector<T>> generate_accomodations(std::set<T> set, uint m) {
		std::vector<std::set<T>> combs = MP::generate_combinations(set, m);
		std::vector<std::vector<T>> result;
		for (uint i = 0; i < combs.size( ); i++) {
			std::vector<std::vector<T>> preresult = MP::generate_permutations(combs[i]);
			for (uint j = 0; j < preresult.size( ); j++) {
				result.push_back(preresult[j]);
			}
		}
		return result;
	}

	std::vector<uint> sealer(SMatrix<int> matrix) {
		std::vector<uint> numbs;
		for (uint i = 1; i < matrix.get_size( ); i++) {
			numbs.push_back(i);
		}
		std::vector<std::vector<uint>> perms = MP::generate_permutations(numbs);
		std::vector<uint> result;
		uint min_way_length = UINT_MAX;
		for (uint i = 0; i < perms.size( ); i++) {
			uint way_length = matrix.get(0, perms[i][0]) + matrix.get(perms[i][perms[i].size( ) - 1], 0);
			for (uint j = 0; j < perms[i].size( ) - 1; j++) {
				uint road_length = matrix.get(perms[i][j], perms[i][(j + 1) % perms[i].size( )]);
				if (road_length >= 0) {
					way_length += road_length;
				} else {
					way_length = UINT_MAX;
					break; // j = perms.size( );
				}
			}
			if (way_length < min_way_length) {
				min_way_length = way_length;
				result = perms[i];
			}
		}
		result.insert(result.begin(), 0u);
		return result;
	}
}
