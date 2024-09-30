/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/30 18:55:59 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ClapTrap* ClapTrap::clapTrapList[42] = {0};
int ClapTrap::count = 0;

ClapTrap::ClapTrap(void)
	: _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		if (count < 42) {
			clapTrapList[count] = this;
			count++;
		}
		std::cout << GREEN << "ClapTrap Default Constructor called" << RESET  << std::endl;
	}

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		if (count < 42) {
			clapTrapList[count] = this;
			count++;
		}
		std::cout << YELLOW << "ClapTrap Constructor called naming the new ClapTrap " << GREEN << _name << RESET << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap &copy)
	: _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
		if (count < 42) {
			clapTrapList[count] = this;
			count++;
		}
		std::cout << "ClapTrap Copy Constructor called" << std::endl;
	}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
	if (this != &copy) {
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
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

void ClapTrap::setAttackDamage(unsigned int amount) {
	std::cout << this->getName() << " has now: " << amount << " attack damage points" << std::endl;
	this->_attackDamage = amount;	
}

void ClapTrap::setHitPoints(unsigned int amount) {
	this->_hitPoints = amount;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		bool targetFound = false;
		for (int i = 0; i < count; ++i) {
			if (clapTrapList[i] != 0){
				if (!clapTrapList[i]->getName().compare(target)) {
					std::cout << RED << _name << " attacks " << target << " with "
						<< _attackDamage << " points of damage!" << RESET << std::endl;
					_energyPoints--;
					clapTrapList[i]->takeDamage(_attackDamage);
					targetFound = true;
					break;  
				}
			}
		}
		if (!targetFound) {
			std::cout << "Target " << target << " not found!"  << std::endl;
		}
	} else if (this->_energyPoints == 0) {
		std::cout << BLUE << this->getName() << " has no more energy 😨" << RESET << std::endl;
	} else {
		std::cout << BLUE << this->getName() << " has not enough hit points 😨" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == amount) {
		_hitPoints = 0;
		std::cout << CYAN << "The Claptrap has received a severe blow and remains with "
			<< this-> getHitPoints() << " hit points" << RESET << std::endl;
	} else if (this->_hitPoints < amount) {
		_hitPoints =  0;
		std::cout << RED_BACKGROUND << this->getName() << " has been destroyed 🕈" << RESET << std::endl;
		return ;
	} else if (this->_hitPoints > amount) {
		_hitPoints -= amount;
		std::cout << CYAN << this->getName() << " has been attacked and remains with " << this->getHitPoints() << " hit points";
	 	std::cout << "  and " << this->getEnergyPoints() << " energy points" << RESET  << std::endl;
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

void ClapTrap::displayAllClapTraps() {
	std::cout << std::endl << "-- Current ClapTraps --" << std::endl;
	for (int i = 0; i < count; ++i) {
		std::cout << clapTrapList[i]->getName() << " with "
			<< clapTrapList[i]->getHitPoints() << " hit points and "
			<< clapTrapList[i]->getEnergyPoints() << " energy points." << std::endl;
	}
}
