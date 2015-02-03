
#include "player.hpp"

player::player()
: pseudo("pseudo"), nb_jeton(0.0){
	return ;
}

player::player(std::string name, float stack)
: pseudo(name), nb_jeton(stack){
	return ;
}

player::~player(){
	return ;
}

void			player::change_actif(){
	if (this->actif == true)
		this->actif = false;
	else
		this->actif = true;
}

bool			player::get_actif(){
	return this->actif;
}

std::string		player::action(){
	std::string		a = "action du joueur";
	return a;
}

std::string		player::get_pseudo(){
	return this->pseudo;
}

float			player::get_stack(){
	return this->nb_jeton;
}

void			player::sub_jeton(float f){
	this->nb_jeton -= f;
}

void			player::print_info(){
	std::cout << this->pseudo << " possede " << this->nb_jeton << " jetons" << std::endl;
}
