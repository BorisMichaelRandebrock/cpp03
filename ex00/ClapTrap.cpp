/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/24 15:05:57 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << GREEN << "ClapTrap Default Constructor called" << RESET  << std::endl;
	}

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << YELLOW << "ClapTrap Constructor called naming the new ClapTrap " << GREEN << _name << RESET << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap &copy)
	: _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
		std::cout << "ClapTrap Copy Constructor called" << std::endl;
	}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
		if (this != &copy) {
			_name = copy._name;
		}
		return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " deconstructed" << std::endl;
}

const std::string& ClapTrap::getName(void) const {
	return _name;
}

int ClapTrap::getDamagePoints(void) {
	return _attackDamage;
}

int ClapTrap::getHitPoints(void) {
	return _hitPoints;
}

int ClapTrap::getEnergyPoints(void) {
	return _energyPoints;
}

void ClapTrap::setName(const std::string name) {
	this->_name = name;	
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << this->getName() << RED << " attacks " << target << ", causing damage!" << RESET  << std::endl;
		_energyPoints--;
		std::cout << this->getName() << " has now " << getHitPoints() << " Hit Points and " << this->getEnergyPoints() << " energy" <<  std::endl;
	} else if (this->_energyPoints == 0) {
		std::cout << BLUE << this->getName() << " has no more energy 😨" << RESET << std::endl;
	} else {
		std::cout << BLUE << this->getName() << " has not enough hit points 😨" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == amount) {
		_hitPoints = 0;
		std::cout << CYAN << "The Claptrap has received a severe blow and remains with 0 hit points" 
			<< RESET << std::endl;
	} else if (this->_hitPoints < amount) {
		std::cout << RED_BACKGROUND << this->getName() << " has been destroyed 🕈" << RESET << std::endl;
		return ;
	} else if (this->_hitPoints > amount) {
		_hitPoints -= amount;
		std::cout << CYAN << this->getName() << " has been attacked and remains with " << this->getHitPoints() << " hit points" << RESET  << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << GREEN << this->getName() << " has repaired itself at the cost of 1 energy point and has now " 
			<< this->getEnergyPoints() << " energy points and " << this->getHitPoints()  << " hit points" << RESET << std::endl;
	} else if (this->_energyPoints == 0) {
		std::cout << BLUE << this->getName() << " has not enough energy left to repair itself... " << RESET << std::endl;
	} else {
		std::cout << BLUE << this->getName() << " has not enough hit points left to repair itself... " << RESET << std::endl;
	}
}
/*
 * When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
In all of these member functions, you have to print a message to describe what happens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!
The constructors and destructor must also display a message, so your peer-evaluators
can easily see they have been called.
Implement and turn in your own tests to ensure your code works as expected.*/
