/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:57:27 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/30 15:07:42 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

#define SCAV_HP 100
#define SCAV_EP 50
#define SCAV_DP 20

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &copy);
		~ScavTrap(void);

		
		void	guardGate(void);
		void	attack(const std::string& target);
};

#endif
	
//void	takeDamage(int amount);
