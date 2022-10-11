#include <iostream>
#include <cstring>
#include <iomanip>
#include "PhoneBook.hpp"


	/* std::string test[] = {"aaaaaaa", "bbbbbbbbbbbbbbbbbbbbb", "ccccccc", "ddddddd", "eeeeeee"};
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test);
	pb.add(test); */

int main() {
	PhoneBook	pb;
	std::string	cmd;

	do {
		std::cout << "Command> ";
		std::getline(std::cin, cmd);
		std::cout << std::endl;
		if (cmd.compare("SEARCH") == 0)
			pb.SEARCH();
		else if (cmd.compare("ADD") == 0)
			pb.ADD();
		else if (cmd.compare("EXIT") != 0)
			std::cout << "Available actions: EXIT SEARCH ADD" << std::endl << std::endl;
	} while (cmd.compare("EXIT") != 0);
	return 0;
}
