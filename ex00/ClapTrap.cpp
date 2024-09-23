/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/23 19:09:12 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "ClapTrap Default Constructor called" << std::endl;
	}

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "ClapTrap Constructor called with the name" << _name << std::endl;
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
//	ClapTrap *victim = target->getName();
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << this->getName() << " attacks " << target << ", causing 1 point of damage!" << std::endl;
//		victim->takeDamage(1);
//		 std::cout << target << " has now " << victim->getDamagePoints()<< " Damage Points" << std::endl;
		_hitPoints--;
		_energyPoints--;
		std::cout << this->getName() << " has now " << getHitPoints() << " Hit Points  and " << getDamagePoints() <<  std::endl;
	} else if (this->_energyPoints == 0) {
		std::cout << this->getName() << " has not enough energy 😨" << std::endl;
	} else {
		std::cout << this->getName() << " has not enough hit points 😨" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_attackDamage == 0) {
		std::cout << this->getName() << " has already been destroyed 🕈" << std::endl;
		return ;
	} else if (this->_attackDamage > amount) {
		_attackDamage -= amount;
		std::cout << this->getName() << " has been attacked and remains with " << this->getDamagePoints() << " damage points" << std::endl;
	} else if (this->_attackDamage > 0) {
		_attackDamage = 0;
		std::cout << this->getName() << " has been attacked and remains with " << this->getDamagePoints() << " damage points" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << this->getName() << " has repaired itself at the cost of 1 energy point and has now " 
			<< this->getEnergyPoints() << " energy points" << std::endl;
	} else {
		std::cout << this->getName() << " has not enough energy left to repair itself... " << std::endl;
	}
}
/*
 * When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
5
C++ - Module 03 Inheritance
In all of these member functions, you have to print a message to describe what happens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!
The constructors and destructor must also display a message, so your peer-evaluators
can easily see they have been called.
Implement and turn in your own tests to ensure your code works as expected.*/
