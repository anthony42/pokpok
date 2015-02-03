
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class player
{
public:
	player();
	player(std::string name, float stack);
	~player();

	std::string		action();
	std::string		get_pseudo();
	float			get_stack();
	void			sub_jeton(float f);
	void			print_info();
	void			change_actif();
	bool			get_actif();

private:
	std::string		pseudo;
	float			nb_jeton;
	bool			actif;
};

#endif
