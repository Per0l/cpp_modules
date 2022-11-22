/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:13:51 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/22 14:40:32 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

static std::type_info const *t_types[4] = {&typeid(char), &typeid(int), &typeid(float), &typeid(double)};
static std::string const t_prefix[4] = {"char", "int", "float", "double"};
static std::string const pseudo_literals[] = {"-inf", "+inf", "inf", "nan", "-inff", "+inff", "inff", "nanf"};

static std::string trim(std::string const &str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

template <typename T>
static T fromString(std::string s) {
	std::istringstream ss(s);
    T x = 0;
    ss >> x;
	return x;
}

Converter::Converter(std::string s): _s(trim(s)) {
	int check = this->validLiteral();
	if (!check)
		throw InvalidLiteralException();
	if (check >= 2 && check <= 5)
		this->_type = DOUBLE;
	else if (check > 5)
		this->_type = FLOAT;
	else
		this->_type = static_cast<m_types>(this->getLiteralType(s));
	//std::cout << "Detected type: " << t_prefix[_type] << std::endl;
	switch (this->_type)
	{
	case DOUBLE:
		this->_d = std::atof(s.c_str());
		this->_f = static_cast<float>(this->_d);
		this->_i = static_cast<int>(this->_d);
		this->_c = static_cast<char>(this->_d);
		break;
	case FLOAT:
		this->_f = static_cast<float>(std::atof(s.c_str()));
		this->_d = static_cast<double>(this->_f);
		this->_i = static_cast<int>(this->_f);
		this->_c = static_cast<char>(this->_f);
		break;
	case INT:
		this->_i = std::atoi(s.c_str());
		this->_f = static_cast<float>(this->_i);
		this->_d = static_cast<double>(this->_i);
		this->_c = static_cast<char>(this->_i);
		break;
	case CHAR:
		this->_c = static_cast<char>(_s[0]);
		this->_f = static_cast<float>(this->_c);
		this->_i = static_cast<int>(this->_c);
		this->_d = static_cast<double>(this->_c);
		break;
	default:
		break;
	}
}

Converter::Converter(Converter const &copy) {
	this->_s = copy._s;
	this->_type = copy._type;
	this->_d = copy._d;
	this->_f = copy._f;
	this->_i = copy._i;
	this->_c = copy._c;
}

Converter::~Converter() {}

Converter const &Converter::operator=(Converter const &copy) {
	this->_s = copy._s;
	this->_type = copy._type;
	this->_d = copy._d;
	this->_f = copy._f;
	this->_i = copy._i;
	this->_c = copy._c;
	return *this;
}

const char *Converter::InvalidLiteralException::what() const throw() {
	return "Invalid literal";
}

int	Converter::getLiteralType(std::string s) {
	s = trim(s);
	if (s.length() == 1 && !(s[0] >= '0' && s[0] <= '9'))
		return CHAR;
	if (s.find('.') == std::string::npos && s.find('f') == std::string::npos)
		return INT;
	if (s.find('f') != std::string::npos)
		return FLOAT;
	if (s.find('.') != std::string::npos)
		return DOUBLE;
	return INT;
}


int Converter::countDigits(std::string s) {
	int res = 0;
	for (size_t i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			res++;
	}
	return res;
}

template void Converter::print<double>();
template void Converter::print<float>();
template void Converter::print<int>();
template void Converter::print<char>();
template <typename T> void Converter::print() {
	std::type_info const &t_x = typeid(T);
	int i;
	for (i = 0; i < 4; i++) {
		if (*t_types[i] == t_x)
			break;
	}
	std::cout << std::left << std::setw(8) << t_prefix[i] + ": ";
	if (this->_d != 0 && (this->_d < std::numeric_limits<T>::min() || this->_d > std::numeric_limits<T>::max()) && !std::isinf(this->_d)) {
		std::cout << "impossible" << std::endl;
		return;
	}
	if (i == CHAR && !std::isprint(this->_c)) {
		std::cout << "Non displayable" << std::endl;
		return;
	}
	if (this->_type != CHAR)
		std::cout.precision(this->countDigits(this->_s));
	switch (i)
	{
	case DOUBLE:
		std::cout << this->_d;
		if (this->_s.find(".") == std::string::npos && !std::isinf(this->_d) && !std::isnan(this->_d))
			std::cout << ".0";
		std::cout << std::endl;
		break;
	case FLOAT:
		std::cout << this->_f;
		if (this->_s.find(".") == std::string::npos && !std::isinf(this->_d) && !std::isnan(this->_d))
			std::cout << ".0";
		std::cout << "f" << std::endl;
		break;
	case INT:
		std::cout << this->_i << std::endl;
		break;
	case CHAR:
		std::cout << "'" << this->_c << "'" << std::endl;
		break;
	default:
		break;
	}
}

int Converter::validLiteral() {
	if (this->_s.length() <= 1)
		return 1;
	for (int i = 0; i < 8; i++) {
		if (this->_s.compare(pseudo_literals[i]) == 0)
			return i + 2;
	}
	std::string filter(".f-+");
	for (size_t i = 0; i < this->_s.length(); i++) {
		if (this->_s[i] >= '0' && this->_s[i] <= '9')
			continue;
		if (filter.find(this->_s[i]) == std::string::npos)
			return 0;
	}
	return 1;
}
