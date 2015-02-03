
#ifndef CARD_HPP
#define CARD_HPP 

#include <iostream>

class card
{
public:
	card();
	~card();

	std::string	*get_package();
	void		init_package();
	void		del_card();
	void		init_nb_card();
	void		print_package();

private:
	std::string		card_package[52];
	short			nb_card;
};

#endif