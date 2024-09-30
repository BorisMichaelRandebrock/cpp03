/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:20:02 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/30 19:11:43 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("") {
	if (ClapTrap::count < 42) { 
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++; 
	}
	this->_name = "_name";
	this->_hitPoints  = FragTrap::_hitPoints; 
	this->_energyPoints = ScavTrap::_energyPoints; 
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << MAGENTA << "DiamondTrap Default Constructor called" << RESET  << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_name") {
	if (ClapTrap::count < 42) { 
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++; 
	}
	this->_name = name + "_name";
	this->_hitPoints  = FragTrap::_hitPoints; 
	this->_energyPoints = ScavTrap::_energyPoints; 
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << MAGENTA << "DiamondTrap Constructor called " << this->_name << RESET  << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
	*this = copy;
	if (ClapTrap::count < 42) { 
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++; 
	}
	std::cout << MAGENTA << "DiamondTrap Copy Constructor called" << RESET  << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}


DiamondTrap::~DiamondTrap() {
		std::cout << "DiamondTrap " << _name << " deconstructed" << std::endl;
}


//void	DiamondTra::Attack ScavTrap::
void	DiamondTrap::whoAmI(void) {
	std::cout << this->getName() << ": What am I?? ScavTrap, FragTrap, ClapTrap??? " << std::endl << "Who am I? 😰 " << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
