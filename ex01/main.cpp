/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:58 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/25 12:42:02 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <unistd.h>

int main(void) {
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "******************************************" << std::endl;
	std::cout << "******** Welcome to the World of *********" << std::endl;
	std::cout << "********* ClapTraps & ScavTraps **********" << std::endl;
	std::cout << "******************************************" << std::endl;
	std::cout << "******* Let the adventures begin! ********" << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;

	ClapTrap boo("Boo");
	ClapTrap clone("Evil Clone");
	std::cout << "Boo has " << boo.getHitPoints() << " hit points, Clone has " 
		<< clone.getHitPoints() << " hit points." << std::endl;
	clone.attack("Boo");
	boo.takeDamage(5);
	std::cout << "Boo fights back with determination!" << std::endl;
	boo.attack("Clone");
	clone.takeDamage(5);
	clone.beRepaired(5);
	boo.beRepaired(10);
	clone.attack("Boo");
	boo.takeDamage(5);
	boo.attack("Clone");
	clone.takeDamage(1);
	std::cout << "Boo lands a powerful blow on the clone!" << std::endl;
	clone.attack("Boo");
	boo.takeDamage(5);
	boo.attack("Clone");
	clone.takeDamage(20);
	std::cout << "Boo remains standing with " << boo.getHitPoints() << " hit points left!" << std::endl;
	sleep(5);

	std::cout << std::endl << "******************************************" << std::endl;
	std::cout << "************ ScavTrap Scenario ***********" << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;

	sleep(1);
	std::cout << std::endl << "----Making ClapTraps----" << std::endl <<  std::endl;
	ClapTrap	clap("Clap");
	ClapTrap	clap2(clap);
	ClapTrap	clap3 = clap;
	sleep(1);

	std::cout << std::endl << "----Making ScavTraps----" << std::endl << std::endl;
	ScavTrap	scav("Scav");
	ScavTrap	cool_scav("Cool Scav");
	sleep(1);

	std::cout << std::endl  << "----Copying ScavTraps----" << std::endl << std::endl;
	ScavTrap	scav2(scav);
	ScavTrap	scav3 = cool_scav;
	sleep(1);

	std::string name;
	ScavTrap tobi("Tobi");
	sleep(1);
	tobi.guardGate();
	sleep(1);
	std::cout << "Please... tell me... who are you? .. ";
	std::cin >> name;
	tobi.attack(name);
	sleep(1);
	tobi.takeDamage(20);
	sleep(1);
	tobi.beRepaired(12);
	sleep(1);
	tobi.takeDamage((int)192);
	sleep(2);
	tobi.guardGate();
	sleep(1);
	std::cout << std::endl <<"----Destructors: do your due diligence----" << std::endl << std::endl;
	sleep(1);
	return 0;

}
