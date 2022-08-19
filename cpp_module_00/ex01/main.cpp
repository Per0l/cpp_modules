#include <iostream>
#include <cstring>
#include <iomanip>
#include "PhoneBook.hpp"

int main() {
	PhoneBook	pb;
	std::string	cmd;

	std::string test[] = {"a", "b", "c", "d", "e"};
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	do {
		std::getline(std::cin, cmd);
		if (cmd.compare("SEARCH") == 0)
			pb.SEARCH();
		else if (cmd.compare("ADD") == 0)
			pb.ADD();
		else
			std::cout << "Available actions: EXIT SEARCH ADD" << std::endl;
	} while (cmd.compare("EXIT") != 0);
	return 0;
}
