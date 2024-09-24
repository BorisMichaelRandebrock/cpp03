/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:58 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/24 15:04:33 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <unistd.h>

int main(void) {
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "Welcome to the world of ClapTraps 🤖" << std::endl << std::endl;
		sleep(1);
	std::cout << "whenever you see a claptrap not named, it is because it is an evil clone 🤖" << std::endl;
		sleep(2);
	{
		ClapTrap boo("Boo");
		std::cout << "Boo is born with " << boo.getHitPoints() << " hit points." <<  std::endl;
		std::cout << "Boo-evil-clone default construction:"  << std::endl;
		ClapTrap clone;
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
			boo.attack("his evil clone");
			sleep(1);
			if (boo.getEnergyPoints() == (unsigned int)7) {
				clone.attack("Boo");
				sleep(1);
				boo.takeDamage(5);
				sleep(1);
				boo.beRepaired(3);
				sleep(1);
			}
			if (boo.getEnergyPoints() == 2) {
				boo.attack("his evil clone");
				clone.takeDamage(10);
				clone.attack("Boo");
				std::cout << GREEN << "A futile attempt of the evil clone to retaliate... " << RESET <<  std::endl;
			}
			if (boo.getEnergyPoints() == 0) {
				clone.takeDamage(10);
				boo.attack("his evil clone");
				break;
			}
		}
	boo.beRepaired(3);
	}
	return 0;
}
