/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:58 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/02 14:20:11 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << MAGENTA << "Welcome to the ClapTrap Funhouse!" << RESET << std::endl;
    std::cout << "Today, we have some very special guests!" << std::endl << std::endl;

    std::cout << "Please enter the name of your ClapTrap: ";
    std::string userName;
    std::cin >> userName;

    DiamondTrap diamond(userName);
    FragTrap frag("Frank");
    ScavTrap scav("Scout");
    DiamondTrap enemy("Shiny_Diamond");

    std::cout << std::endl
              << GREEN << "Meet our special guests!" << YELLOW << std::endl;
    std::cout << userName << " the DiamondTrap has entered the scene!" << std::endl;
    std::cout << "Frank the FragTrap is ready to high five!" << std::endl;
    std::cout << "Scout the ScavTrap ready to keep the gates!" << std::endl;
    std::cout << RED << "A foreign, strange Trap is showing up: " << enemy.getName()
              << " an enemy DiamondTrap!" << RESET << std::endl
              << std::endl;
    sleep(2);
    std::cout << YELLOW << "In response to the appearence of the uninvited guest, Scout, the ScavTrap is activating guard mode..." << RESET << std::endl;
    sleep(2);
    scav.guardGate();
    std::cout << YELLOW << "Scout is now guarding the Funhouse gates!" << RESET << std::endl
              << std::endl;
    sleep(1);

    std::cout << BLUE << "Frank the FragTrap wants to celebrate with a High Five!" << RESET << std::endl;
    sleep(1);
    frag.highFivesGuys();
    std::cout << "Frank says: \"Come on, high five me, don't let me hanging..!\"" << std::endl
              << std::endl;
    sleep(1);

    std::cout << MAGENTA << userName << " the DiamondTrap is having an identity crisis..." << RESET << std::endl;
    sleep(1);
    diamond.whoAmI();
    std::cout << BLUE << "Poor " << userName << "... Maybe a little confidence boost would help!" << std::endl;

    std::cout << std::endl
              << YELLOW << "Say something nice to: " << userName << ". " MAGENTA;
    std::string compliment;
    std::cin.ignore();
    std::getline(std::cin, compliment);
    std::cout << diamond.getName() << " beams with joy after hearing: \"" << compliment << "\"!" << std::endl;
    sleep(1);

    std::cout << std::endl << RED << "Suddenly, the enemy DiamondTrap wants to crash the party! It's " << enemy.getName() << "!" << RESET << std::endl;
    sleep(1);
	diamond.guardGate();
    while (enemy.getHitPoints() > 0) {
        std::cout << BLUE << "Scout, the gatekeeper attacks " << enemy.getName() << "!" << RESET << std::endl;
        scav.attack(enemy.getName()); 
		sleep(1);

        if (enemy.getHitPoints() > 0) {
            std::cout << RED << enemy.getName() << " is under attack!" << RESET << std::endl;
            sleep(1);
        } else {
            std::cout << RED << enemy.getName() << " is having an identity crisis! \"Who am I? Am I just a shiny rock?\"" << RESET << std::endl;
			enemy.whoAmI();
            sleep(3);
            std::cout << YELLOW << "In order to set an end to the attacks of the poor " << enemy.getName() << " "
                      << diamond.getName() << " lowers his attack to a minimum and gives Scout a nudge" << RESET << std::endl;
            diamond.setAttackDamage(0);
            diamond.attack(scav.getName());
            sleep(1);
            std::cout << BLUE << "Frank says: \"You're more than just a shiny rock! "
                      << enemy.getName() << std::endl
                      << "Let's celebrate your uniqueness!\"" << RESET << std::endl;
            frag.highFivesGuys();
			diamond.highFivesGuys();
			enemy.highFivesGuys();
            std::cout << "Scout adds: \"We're all special in our own way! You belong here!\"" << std::endl;
            sleep(1);
			enemy.beRepaired(50);
    		std::cout << "Our heroes comfort the " << enemy.getName() << ", present some hp and give high fives!" << std::endl;
			sleep(1);
			enemy.setHitPoints(5);
			sleep(1);
			enemy.beRepaired(50);
			break ;
        }
        std::cout << std::endl
                  << YELLOW << "The fight continues!" << RESET << std::endl;
        sleep(1);
    }
    std::cout << std::endl << GREEN << "The party continues..!" << RESET << std::endl;
    sleep(1);
    std::cout << std::endl << "Thanks for joining the ClapTrap Funhouse! See you next time!" << std::endl;

	return 0;
}
