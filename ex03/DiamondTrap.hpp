/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:50:24 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/30 15:07:08 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : /*public ClapTrap, */public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap &copy);
		~DiamondTrap(void);
		
		void whoAmI(void);
		void attack(const std::string &target);
	//	void highFivesGuys(void);	
	//	void displayAllClapTraps(void);
};

#endif
