/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/26 18:42:42 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap* ClapTrap::clapTrapList[42] = {0};
int ClapTrap::count = 0;

ClapTrap::ClapTrap(void)
	: _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		if (count < 10) {
			clapTrapList[count] = this;
			count++;
		}
		std::cout << GREEN << "ClapTrap Default Constructor called" << RESET  << std::endl;
	}

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		if (count < 10) {
			clapTrapList[count] = this;
			count++;
		}
		std::cout << YELLOW << "ClapTrap Constructor called naming the new ClapTrap " << GREEN << _name << RESET << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap &copy)
	: _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
		if (count < 10) {
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

void ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << this->getName() << RED << " attacks " << target << ", causing damage!" 
			<< RESET  << std::endl;
		_energyPoints--;
		bool targetFound = false;
		for (int i = 0; i < count; ++i) {
			if (clapTrapList[i] != 0){
				if (!clapTrapList[i]->getName().compare(target)) {
					std::cout << _name << " attacks " << target << " causing "
						<< _attackDamage << " points of damage!" << std::endl;
					clapTrapList[i]->takeDamage(_attackDamage);  // Inflict damage on the target
					std::cout << this->getName() << " has now " << getHitPoints()
						<< " Hit Points and " << this->getEnergyPoints() << " energy" <<  std::endl;
					targetFound = true;
					break;  // Exit once the target is found and attacked
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
		std::cout << CYAN << "The Claptrap has received a severe blow and remains with 0 hit points" 
			<< RESET << std::endl;
	} else if (this->_hitPoints < amount) {
		_hitPoints =  0;
		std::cout << RED_BACKGROUND << this->getName() << " has been destroyed 🕈" << RESET << std::endl;
		return ;
	} else if (this->_hitPoints > amount) {
		_hitPoints -= amount;
		std::cout << CYAN << this->getName() << " has been attacked and remains with " << this->getHitPoints() << " hit points" << RESET  << std::endl;
	}
	 std::cout << "Final hit points of " << this->getName() << ": " << this->_hitPoints << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "Attempting to repair: " << this->getName() << std::endl;
	std::cout << "Current hit points: " << this->_hitPoints
		<< ", Current energy points: " << this->_energyPoints << std::endl;
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
	std::cout << "\n-- Current ClapTraps --\n";
	for (int i = 0; i < count; ++i) {
		std::cout << clapTrapList[i]->getName() << " with "
			<< clapTrapList[i]->getHitPoints() << " hit points and "
			<< clapTrapList[i]->getEnergyPoints() << " energy points.\n";
	}
}
