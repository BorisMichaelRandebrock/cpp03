/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:57:48 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/27 14:56:38 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp" 

ScavTrap::ScavTrap(void) : ClapTrap("") {
	if (ClapTrap::count < 42) { 
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++; 
	}
	this->_hitPoints  = 100; 
	this->_energyPoints = 50; 
	this->_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap Default Constructor called" << RESET  << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	if (ClapTrap::count < 42) { 
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++; 
	}

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << GREEN << "ScavTrap Constructor called named " << _name << RESET  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	//*this = copy;
	this->_name = copy._name; 
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	if (ClapTrap::count < 42) { 
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++; 
	}
	std::cout << CYAN << "ScavTrap Copy Constructor called" << RESET  << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " deconstructed" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (_hitPoints > 0) {
		std::cout << RED_BACKGROUND << this->getName() << " is now in Gatekeeper mode.. " << RESET << std::endl;
	} else {
		std::cout << RED_BACKGROUND << this->getName() << ".. can't do Gatekeeper... no hit points... scav " 
			<< this->getName() << " .. destroyed.. prrrfzzczczxx  🤖 ... " << RESET << std::endl;
	}
}
/*
   void ScavTrap::takeDamage(int amount) {
   if ((int)this->_hitPoints == amount) {
   _hitPoints = 0;
   std::cout << CYAN << "The Claptrap has received a severe blow and remains with 0 hit points"
   << RESET << std::endl;
   } else if ((int)this->_hitPoints < amount) {
   _hitPoints = 0;
   std::cout << RED_BACKGROUND << this->getName() << " has been destroyed 🕈" << RESET << std::endl;
   return ;
   } else if ((int)this->_hitPoints > amount) {
   _hitPoints -= amount;
   std::cout << CYAN << this->getName() << " has been attacked and remains with "
   << this->getHitPoints() << " hit points" << RESET  << std::endl;
   }
   }*/

void ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		bool targetFound = false;
		for (int i = 0; i < count; ++i) {
			if (clapTrapList[i] != 0){
				if (!clapTrapList[i]->getName().compare(target)) {
					std::cout << RED << _name << " attacks " << target << " with "
						<< _attackDamage << " points of damage!" << RESET << std::endl;
					_energyPoints--;
					std::cout << RED << "Eat sh.. " << RESET << std::endl;
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

