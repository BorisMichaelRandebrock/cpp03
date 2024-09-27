/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:54:21 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/27 17:43:28 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("") {
	if (ClapTrap::count < 42) {
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++;
	}
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << BLUE << "FragTrap Default Constructor called" << RESET  << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	if (ClapTrap::count < 42) {
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++;
	}
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << MAGENTA << "FragTrap Constructor called" << RESET  << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) {
	*this = copy;
	std::cout << CYAN << "ScavTrap Copy Constructor called" << RESET  << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
		std::cout << "FragTrap " << _name << " deconstructed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	    std::cout << "FragTrap " << _name << " says: High five, guys! ✋😄" << std::endl;
}

void FragTrap::displayAllClapTraps() {
    std::cout << std::endl << "-- Current ClapTraps --" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << "Frag " << i << ": " << clapTrapList[i]->getName() << " with "
            << clapTrapList[i]->getHitPoints() << " hit points and "
            << clapTrapList[i]->getEnergyPoints() << " energy points." << std::endl;
    }
}
