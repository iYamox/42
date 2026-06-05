#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie
{
	private :
		std::string name;
	public :
		void		set_name(std::string new_name);
		std::string	get_name();
		void		announce(void);

		Zombie();
		~Zombie();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif