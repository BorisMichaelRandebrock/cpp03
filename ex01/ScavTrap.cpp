/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:57:48 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/24 18:56:54 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("") {
		_hitPoints  = 100; 
		_energyPoints =50; 
		_attackDamage = 20;
		std::cout << YELLOW << "ScavTrap Default Constructor called" << RESET  << std::endl;
	}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
		_hitPoints = 100;
		_energyPoints = 50;
		_attackDamage = 20;
		std::cout << GREEN << "ScavTrap Constructor called" << RESET  << std::endl;
	}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
		_name = copy._name; 
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._energyPoints;
		std::cout << CYAN << "ScavTrap Copy Constructor called" << RESET  << std::endl;
	}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy) {
	if (this != &copy) {
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " deconstructed" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (this->getHitPoints() > 0) {
		std::cout << this->getHitPoints() << " scavs hit points **********" << std::endl;
		std::cout << RED_BACKGROUND << this->getName() << " is now in Gatekeeper mode.. " << RESET << std::endl;
	} else {
	std::cout << RED_BACKGROUND << this->getName() << " cant do... no hp... scav is detroyed.. " << RESET << std::endl;
	}

}

