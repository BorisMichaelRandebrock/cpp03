/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:58 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/30 10:57:13 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "\033[2J\033[H" << std::endl;
	sleep(1);
	std::cout << "Well, enough of claps and scavs..., i am not going to bore you with that.. "
		<< std::endl << "It s time now to see the newest models.. our FragTaps..: " << std::endl << std::endl;
	std::cout << "******************************************" << std::endl;
	std::cout << "******** Welcome to the World of *********" << std::endl;
	std::cout << "*********        FragTraps      **********" << std::endl;
	std::cout << "******************************************" << std::endl;
	std::cout << "*******     Let's get started!    ********" << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;
	sleep(2);
	std::cout << std::endl << YELLOW << "To get started," << RESET << std::endl
		<< "Please enter your name: ";
	std::string name;
	std::cin >> name;

	FragTrap evaluator(name);
    sleep(1);
	evaluator.highFivesGuys();
	sleep(1);
	std::cout << std::endl << "----Making ClapTraps----" << std::endl << std::endl;
    ClapTrap clap("Clap");
    ClapTrap clap2(clap);
    ClapTrap clap3 = clap;
    sleep(1);

    std::cout << std::endl << "----Making FragTraps----" << std::endl << std::endl;
    FragTrap frag("Frag");
    FragTrap coolFrag("Cool Frag");
    sleep(1);

    std::cout << std::endl << "----Copying FragTraps----" << std::endl << std::endl;
    FragTrap frag2(frag);
    FragTrap frag3 = coolFrag;

    FragTrap tobi("Tobi");
    tobi.highFivesGuys();

    std::string response;
    std::string response3;
    std::string response2;
    std::cout << "Tobi: Hey, " << evaluator.getName() << "! Do you want to see something cool? (yes/no): ";
    std::cin >> response;

    if (response == "yes") {
        std::cout << YELLOW << "Tobi: Awesome! Here's my best high five! ✋😄" << RESET << std::endl;
        tobi.highFivesGuys();
    } else {
        std::cout << RED << "Tobi: Aww... You're missing out! 😞" << RESET << std::endl;
    }
    sleep(2);

    std::cout << "Tobi: Time for a quick duel, " << evaluator.getName() << "! Get ready!" << std::endl;
     std::cout << "I will give you a random attackdamage and you attack me, ok " << evaluator.getName()
		 << "? answer yes if you want to give it a go." << std::endl;
	 std::cin  >> response3;
	 if (response3 == "yes") {
		 int damage = std::rand() % 50 + 1;
		evaluator.setAttackDamage(damage);
    	evaluator.attack("Tobi");
	    sleep(1);
	    if (damage >= 25) {
    	    std::cout << BLUE << "Tobi: Ouch! That hurt! But I can still fight!" << RESET << std::endl;
			tobi.highFivesGuys();
 	   } else {
    	    std::cout << "Tobi: Haha! That barely tickled! Try harder next time!" << std::endl;
			tobi.highFivesGuys();
			}
	 } else {
		 std::cout << "Aww, i thought it could be fun.. well... " << std::endl;
	 }
	sleep(1);
    evaluator.highFivesGuys();

    std::cout << "Tobi: Should I go into give you high five <hf> or should I repair <rp> myself? ";
    std::cin >> response;

    if (response == "hf") {
        tobi.highFivesGuys();
    } else if (response == "rp") {
        tobi.beRepaired(30);
    } else {
        std::cout << "Tobi: Hmm... I don't understand that. I'll just rest for now." << std::endl;
    }
    sleep(1);

	std::cout << "Please have a look at all tis beautyfull Frags.. :" <<std::endl;
	tobi.displayAllClapTraps();
	
	std::cout << "shall they be deconstructed? (y/n) ";
	std::cin >> response2;
	if (response2 ==  "y") {
		std::cout << "As you wish " << evaluator.getName() << ", all this beauties are going to be destroyed... 😥" << std::endl; 
		sleep(1);
	} else if (response2 == "n") {
		std::cout << "Sorry " << evaluator.getName() << ", i have to deconstruct them 😥" << std::endl; 
		sleep(1);
	} else {
		std::cout << "Ah, what the heck... let's just get on with it..  😥" << std::endl;
		sleep(1);
	}
	sleep(1);
		return 0;
}
