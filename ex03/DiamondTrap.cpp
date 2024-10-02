/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:20:02 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/02 14:16:59 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
		: ClapTrap("Default clap_name"), ScavTrap("scav_name"), FragTrap("frag_name"), _name("Default Diamond")
{
	if (ClapTrap::count < 42)
	{
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++;
	}
	this->_name = "_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << MAGENTA << "DiamondTrap Default Constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
		: ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name")
{
	if (ClapTrap::count < 42)
	{
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++;
	}
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << MAGENTA << "DiamondTrap Constructor called " << this->_name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
		: ClapTrap(copy._name + "_clap_name"), ScavTrap(), FragTrap(), _name(copy._name)
{
	*this = copy;
	if (ClapTrap::count < 42)
	{
		ClapTrap::clapTrapList[ClapTrap::count] = this;
		ClapTrap::count++;
	}
	std::cout << MAGENTA << "DiamondTrap Copy Constructor called" << RESET << std::endl;
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

void	DiamondTrap::whoAmI(void) {
	std::cout << this->getName() << ": What am I?? ScavTrap, FragTrap, ClapTrap??? " << std::endl
						<< "Who am I? 😰 " << std::endl;
	std::cout << "Am I: " << this->_name << ",.. " << this->ClapTrap::getName()
						<< ",.. " << _name << "_scav_name" << " or: " << _name << "_frag_name??" << std::endl;
}
