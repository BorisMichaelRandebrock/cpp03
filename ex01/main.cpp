/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:58 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/24 19:04:41 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <unistd.h>

int main(void) {
	/*std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "Welcome to the world of ClapTraps 🤖" << std::endl << std::endl;
		sleep(1);
	std::cout << "Whenever you see a Claptrap not being anounced by its name, it is because it is an evil clone 🤖" << std::endl << std::endl;
		sleep(2);
	{
		ClapTrap boo("Boo");
		std::cout << "Boo is born with " << boo.getHitPoints() << " hit points." <<  std::endl;
		sleep(1);
		std::cout << "Boo-evil-clone default construction:"  << std::endl;
		ClapTrap clone;
		sleep(2);
		clone.attack("a robot without apearent reason");
		sleep(1);
		clone.attack("some other robot");
		sleep(1);
		clone.takeDamage(5);
		sleep(1);
		clone.beRepaired(5);
		sleep(1);
		clone.attack("some other other robot");
		sleep(1);
		boo.beRepaired(3);
		sleep(1);
		while (boo.getHitPoints() > -1 && boo.getEnergyPoints() > -1) {
			sleep(1);
			boo.attack("his evil clone");
			if (boo.getEnergyPoints() == (unsigned int)7) {
				clone.attack("Boo");
				sleep(1);
				boo.takeDamage(5);
				sleep(2);
				boo.beRepaired(3);
				sleep(2);
			}
			if (boo.getEnergyPoints() == 2) {
				boo.attack("his evil clone");
				sleep(1);
				clone.takeDamage(10);
				sleep(1);
				clone.attack("Boo");
				std::cout << GREEN << "A futile attempt of the evil clone to retaliate... " << RESET <<  std::endl;
			}
			if (boo.getEnergyPoints() == 0) {
				std::cout << RED_BACKGROUND << "the evil clone" << RESET;
				clone.takeDamage(10);
				boo.attack("his evil clone");
				break;
			}
		}
	boo.beRepaired(3);
	}*/


		std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap c;
		ScavTrap d("Savage");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		c.attack("CloneTrap");
		// for (int i = 0; i < 50; i++)
		// 	c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	{
		std::cout  << RED << "****************************" << RESET <<std::endl;
		std::cout << "----Making ClapTraps----" << std::endl;
		ClapTrap	clap("Clap");
		ClapTrap	clap2(clap);
		ClapTrap	clap3 = clap;

		std::cout << "----Making ScavTraps----" << std::endl;
		ScavTrap	scav("Scav");
		ScavTrap	cool_scav("Cool Scav");

		std::cout << "----Copying ScavTraps----" << std::endl;
		ScavTrap	scav2(scav);
		ScavTrap	scav3 = cool_scav;

		std::cout << "----Destructors go brrrr----" << std::endl;
	}
	{
		std::cout << "----------Functionality Tests----------" << std::endl;
		ScavTrap scav("Scav");
		scav.guardGate();
		scav.attack("Evaluator");
		scav.takeDamage(20);
		scav.beRepaired(12);
		scav.takeDamage(1200);
		scav.guardGate();
	}
	return 0;

}
