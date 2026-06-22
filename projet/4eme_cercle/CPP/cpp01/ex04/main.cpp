/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 12:00:48 by amary             #+#    #+#             */
/*   Updated: 2026/06/22 16:45:04 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	fill_str(std::fstream &infiles, std::string &str)
{
	std::string line;

	while (std::getline(infiles, line))
	{
		str += line;
		str += '\n';
	}
	return ;
}

int	main(int argc, char **argv)
{
	std::string				s1;
	std::string				s2;
	std::string				infilesName;
	std::string				str;
	std::string::size_type	pos; // npos est de type size_type si je garde un int je mange un Warning

	if (argc == 4)
	{
		s1 = argv[2];
		s2 = argv[3];
		infilesName = argv[1];
		std::fstream infiles(argv[1]);
		if (!infiles.is_open())
			return (1);
		fill_str(infiles, str);
		pos = str.find(s1);
		if (pos == std::string::npos)
		{
			std::cout << "No occurence find" << std::endl;
			return (0);
		}
		while (pos != std::string::npos)
		{
			str.erase(pos, s1.size());
			str.insert(pos, s2);
			pos = str.find(s1);
		}
		
		std::string outfileName = infilesName + ".replace";
	
		std::ofstream outfile(outfileName.c_str()); // le c_str pour convertir en const char * 
		if (!outfile.is_open())
		{
			std::cout << "Outfile error" << std::endl;
			return (1);
		}
		outfile << str;
		return (0);
	}
	else
		return (1);
}
