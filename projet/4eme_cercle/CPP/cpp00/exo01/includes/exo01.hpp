#ifndef EXO01_HPP
#define EXO01_HPP

# include <iostream>
# include <iomanip>

// Pour stocker lors de la boucle infini
typedef struct s_contact_stock
{
	std::string	name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;
}				t_contact_stock;

class Contact
{
	private :
		std::string	name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void		set_name(std::string new_name);
		void		set_last_name(std::string new_lastName);
		void		set_nick_name(std::string new_nickName);
		void		set_phone_number(std::string new_phoneNumber);
		void		set_darkest_secret(std::string new_darkestSecret);
		std::string	get_name();
		std::string	get_last_name();
		std::string	get_nick_name();
		std::string	get_phone_number();
		std::string	get_darkest_secret();
};

class PhoneBook
{
	private:
		Contact all_contact[8];
		int		i;
		int		count;
	public:
		void	ADD(std::string name, std::string last_name, std::string nick_name,  std::string phone_name, std::string darkest_secret);
		void	search();
				PhoneBook();
};


void	get_arg(t_contact_stock	*contact);
void	display_column(std::string str);
#endif