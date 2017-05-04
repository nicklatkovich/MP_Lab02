#include <iostream>
#include "MathProgramming.h"
#include <fstream>
#include "Source.h"

#define uint unsigned int

int main( ) {
	std::set<std::string> set = {
		"Slipknot",
		"Godsmack",
		"Dethklok",
		//"Evanescence",
		//"Breaking Benjamin",
		"Disturbed"
	};
	while (true) {
		SU::clear_console( );
		std::cout << std::endl;
		std::cout << " 1. Generate Subsets" << std::endl;
		std::cout << " 2. Generate Combinations" << std::endl;
		std::cout << " 3. Generate Permutations" << std::endl;
		std::cout << " 4. Generate Accomodations" << std::endl;
		std::cout << " 5. Sealer's Way Finder (random)" << std::endl;
		std::cout << " 6. Sealer's Way Finder (from file)" << std::endl;
		std::cout << " 0. Exit" << std::endl;
		std::cout << std::endl << " >> ";
		char a;
		std::cin >> a;
		if (a == '0') {
			return 0;
		}
		SU::clear_console( );
		switch (a) {
			case '1':
				std::cout << "\n\tSubsets\n\n";
				SU::operator<< (std::cout, set) << std::endl;
				SU::operator<< (std::cout, MP::generate_subsets(set)) << std::endl;
				break;
			case '2':
			{
				std::cout << "\n\Combinations\n\n";
				SU::operator<< (std::cout, set) << std::endl;
				std::cout << "k = ";
				uint k;
				std::cin >> k;
				SU::operator<< (std::cout, MP::generate_combinations(set, k)) << std::endl;
				break;
			}
			case '3':
				std::cout << "\n\tPermutations\n\n";
				SU::operator<< (std::cout, set) << std::endl;
				SU::operator<< (std::cout, MP::generate_permutations(set)) << std::endl;
				break;
			case '4':
			{
				std::cout << "\n\tAccomodations\n\n";
				SU::operator<< (std::cout, set) << std::endl;
				std::cout << "m = ";
				uint m;
				std::cin >> m;
				SU::operator<< (std::cout, MP::generate_accomodations(set, m)) << std::endl;
				break;
			}
			case '5':
			{
				std::cout << "\n\tSealer's Way (Random)\n\n";
				std::cout << "t = ";
				uint t;
				std::cin >> t;
				std::cout << std::endl;
				SMatrix<int> country(t, 0);
				for (uint i = 0; i < country.get_size( ); i++) {
					for (uint j = 0; j < country.get_size( ); j++) {
						country.set(i, j, rand( ) % 290 + 10);
					}
				}
				for (uint i = 0; i < 3; i++) {
					country.set(rand( ) % country.get_size( ), rand( ) % country.get_size( ), -1);
				}
				std::cout << country << std::endl;
				clock_t start_time = clock( );
				SU::operator<< (std::cout, MP::sealer(country)) << std::endl;
				clock_t end_time = clock( );
				clock_t used_time = end_time - start_time;
				std::cout << std::endl << " Time: " << used_time << " y.e. (" << (float)used_time / CLOCKS_PER_SEC << " s.)" << std::endl;
				break;
			}
			case '6':
			{
				std::cout << "\n\tSealer's Way (From File)\n\n";
				std::cout << "filename = ";
				std::string filename;
				std::cin >> filename;
				std::ifstream in(filename);
				uint t;
				in >> t;
				SMatrix<int> country(t, 0);
				for (uint i = 0; i < t; i++) {
					for (uint j = 0; j < t; j++) {
						int way_length;
						in >> way_length;
						country.set(i, j, way_length);
					}
				}
				in.close( );
				std::cout << country << std::endl;
				clock_t start_time = clock( );
				SU::operator<< (std::cout, MP::sealer(country)) << std::endl;
				clock_t end_time = clock( );
				clock_t used_time = end_time - start_time;
				std::cout << std::endl << " Time: " << used_time << " y.e. (" << (float)used_time / CLOCKS_PER_SEC << " s.)" << std::endl;
				break;
			}
		}
		SU::pause( );
	}
	return 0;
}
