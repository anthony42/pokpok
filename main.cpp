#include "table.hpp"
#include "card.hpp"
#include "player.hpp"
#include "statistique.hpp"
#include <iostream>
#include <string>

int main()
{
	card *	c = new card();
	table * t = new table();
	std::string	s;

	c->init_package();
	t->create_table();
	// t->del_player(3);
	// std::cout << "a quel position ajouter une joueur : " << std::endl;
	// std::getline(std::cin, s);
	// t->add_player(atoi(s.c_str()));
	// t->add_card_to_board(*c);
	t->print_info();
	return 0;
}
