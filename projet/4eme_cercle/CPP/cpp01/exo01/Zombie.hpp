#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <unistd.h>

class Zombie
{
	private :
		std::string	name;
	public :
		void		announce(void);
		std::string	get_name(void);
		void		set_name(std::string new_name);

		Zombie();
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif