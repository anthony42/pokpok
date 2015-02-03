
#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include "player.hpp"
#include "card.hpp"

class table
{
public:
	table();
	~table();

	void			restart_hand();
	void			add_card_to_board(card & c);
	void			add_pot(float f);
	void			create_table();
	void			create_new_player();
	void			fold_player();
	short			get_player_actif();
	float			get_pot();
	std::string *	get_board();
	void			print_info();
	void			del_player(int position);
	void			add_player(int i);

private:
	std::string				board[6];
	float					pot;
	float					min_blind;
	float					max_blind;
	int						max_player;
	short					player_actif;
	std::vector<player>		player_in_table;
};

#endif
