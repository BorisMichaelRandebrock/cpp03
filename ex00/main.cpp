/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:58 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/24 16:40:13 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <unistd.h>

int main(void) {
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "Welcome to the world of ClapTraps 🤖" << std::endl << std::endl;
		sleep(1);
	std::cout << "Whenever you see a Claptrap not being anounced by its name, it is because it is an evil clone 🤖" << std::endl << std::endl;
		sleep(2);
	{
		ClapTrap boo("Boo");
		ClapTrap randomClap("a robot without appearent reason");
		ClapTrap rand("some other robot");
		boo.setAttackDamage(5);
		std::cout << "Boo is born with " << boo.getHitPoints() << " hit points." <<  std::endl;
		sleep(1);
		std::cout << "Boo-evil-clone default construction:"  << std::endl;
		ClapTrap clone;
		sleep(2);
		clone.attack("a robot without appearent reason");
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
		boo.setAttackDamage(1);
		while (boo.getHitPoints() > -1 && boo.getEnergyPoints() > -1) {
			sleep(1);
			boo.attack("");
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
	}
	return 0;
}
