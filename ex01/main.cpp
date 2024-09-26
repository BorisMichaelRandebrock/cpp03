/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:58 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/26 18:27:16 by brandebr         ###   ########.fr       */
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
	sleep(1);

	ClapTrap boo("Boo");
    ClapTrap clone("Clone");
	std::cout << std::endl;
	sleep(1);
    boo.setAttackDamage(5);
    clone.setAttackDamage(5);
	std::cout << std::endl;
    std::cout << "Boo has " << boo.getHitPoints() << " hit points, Clone has "
              << clone.getHitPoints() << " hit points." << std::endl << std::endl;
    sleep(1);
	clone.attack("Boo");
    sleep(1);
    boo.attack("Clone");
    sleep(1);
    boo.attack("Clone");
    sleep(1);
    clone.beRepaired(5);
    sleep(1);
    boo.beRepaired(10);
	boo.attack("Clone");
    sleep(1);
    clone.attack("Boo");
    sleep(1);
    std::cout << "Boo remains standing with " << boo.getHitPoints()
		<< " hit points left!" << std::endl;
    sleep(3);


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
	std::cout << "Tobi: Please... tell me... who are you? .. and password..? ";
	std::cin >> name;
	ScavTrap evaluator(name);
	std::cout << RED << "🤖 ...GRR... PASSWORD INCORRECT...  😡 " << RESET << std::endl;
	sleep(1);
	std::cout << RED << "YOU SHALL NOT PASS!!!" << RESET << std::endl;
	sleep(1);
	tobi.ClapTrap::attack(name);
	sleep(1);
	evaluator.setAttackDamage(100);
	std::cout << evaluator.getName() << " retaliates " << std::endl;
	evaluator.attack("Tobi");
	tobi.takeDamage(20);
	sleep(1);
	tobi.beRepaired(12);
	sleep(1);
	tobi.takeDamage(102);
	sleep(2);
	tobi.guardGate();
	sleep(1);
	std::cout << std::endl <<"----Destructors: do your due diligence----" << std::endl << std::endl;
	sleep(1);
	return 0;

}
