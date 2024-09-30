/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:50:24 by brandebr          #+#    #+#             */
/*   Updated: 2024/09/30 15:08:02 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &copy);
		~FragTrap(void);
		
		void highFivesGuys(void);	
		void displayAllClapTraps(void);
};

#endif
