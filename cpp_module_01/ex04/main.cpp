/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:24:52 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/17 02:48:02 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cout << "Usage: " << argv[0] << " infilename s1 s2" << std::endl;
		return (1);
	}

	std::string		line;
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	std::ifstream	infile(filename.c_str());
	if (infile.fail()) {
		std::cerr << "Error reading file: '" << filename << "'" << std::endl;
		return (1);
	}
	
	std::ofstream	outfile((filename+".replace").c_str());
	if (outfile.fail()) {
		std::cerr << "Error writing file: '" << filename << ".replace'" << std::endl;
		return (1);
	}
	
	if (infile.is_open() and outfile.is_open()) {
		while ( infile ) {
			if (infile.tellg() > 0)
				outfile << std::endl;
			std::getline(infile, line);
			std::size_t	last_i = 0;
			std::size_t idx = -1;
			while ((idx = line.find(s1, last_i)) != std::string::npos) {
				outfile << line.substr(last_i, idx-last_i) << s2;
				last_i = idx + s1.length()-1;
			}
			if (last_i == 0)
				outfile << line;
			else
				outfile << line.substr(last_i, line.length()-last_i);
		}
	} else 
		return (1);
}
