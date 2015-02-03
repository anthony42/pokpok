
#include "table.hpp"
#include <string> 

table::table(){
	this->board[0] = "";
	this->board[1] = "";
	this->board[2] = "";
	this->board[3] = "";
	this->board[4] = "";
	this->board[5] = "";
	this->pot = 0.0;
	this->max_player = 0;
	this->player_actif = 0;
	return ;
}

table::~table(){
	return ;
}

void	table::restart_hand(){
	this->board[0] = "";
	this->board[1] = "";
	this->board[2] = "";
	this->board[3] = "";
	this->board[4] = "";
	this->board[5] = "";
	this->pot = 0.0;
	this->player_actif = this->player_in_table.size();
	return ;
}

void	table::add_card_to_board(card & c){
	std::string	buff;
	std::string	*package;
	unsigned int i = 0;

	while (this->board[i] != ""){
		i++;
	}
	if (i == 5){
		std::cout << "toute les carte sont deja sur le board" << std::endl;
		return ;
	}
	std::cout << "entre la carte a ajouter : ";
	std::getline(std::cin, buff);
	package = c.get_package();
	i = 0;
	while (i < package->size()){
		if (package[i] == buff){
			break ;
		}
		i++;
	}
	if (i < 52){
		i = 0;
		while (this->board[i] != ""){
			i++;
		}
		this->board[i] = buff;
		std::cout << "nouveau board :" << std::endl;
		i = 0;
		while (this->board[i] != ""){
			std::cout << this->board[i] << " ";
			i++;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "la carte " << buff << " n'existe pas" << std::endl;
	}
	return ;
}

void	table::add_pot(float f){
	this->pot += f;
	return ;
}

void	table::create_table(){
	std::string 	buff;

	std::cout << "max player : "; 
	std::getline(std::cin, buff);
	this->max_player = atoi(buff.c_str());
	this->player_actif = atof(buff.c_str());

	std::string		min;
	std::string		max;
	unsigned int	pos = 0;
	bool			b = true;
	std::cout << "blind (0.1/0.2) : ";
	std::getline(std::cin, buff);
	while (pos < buff.size()){
		if (buff[pos] == '/'){
			b = false;
			pos++;
		}
		if (b == true){
			min += buff[pos];
		}
		else {
			max += buff[pos];
		}
		pos++;
	}
	std::cout << "min : " << min << std::endl;
	std::cout << "max : " << max << std::endl;
	this->min_blind = atof(min.c_str());
	this->max_blind = atof(max.c_str());

	std::string 	buff_moi;
	std::cout << "mon stack : ";
	std::getline(std::cin, buff_moi);
	player	moi("moi", atof(buff_moi.c_str()));
	this->player_in_table.push_back(moi);

	player			p;
	int				i = 1;
	while (i < this->max_player){
		this->player_in_table.push_back(p);
		i++;
	}
	this->create_new_player();
	return ;
}

void	table::create_new_player(){
	std::string buff_name;
	std::string buff_stack;
	short i = 1;
	std::cout << "0 pour passer le joueur. q pour arretter" << std::endl;
	while (i < this->max_player){
		std::cout << "creation joueur" << std::endl;
		if (this->player_in_table[i].get_pseudo() == "pseudo"){
			std::cout << "pseudo du joueur " << i << " : ";
			std::getline(std::cin, buff_name);
			if (buff_name == "q"){
				break ;
			}
			else if (buff_name != "0"){
				std::cout << "nombre de jetons :";
				std::getline(std::cin, buff_stack);
				player	p(buff_name, atof(buff_stack.c_str()));
				this->player_in_table.insert(this->player_in_table.begin()+i, p);
			}
		}
		i++;
	}
	return ;
}

void	table::add_player(int i){
	std::string	buff_name;
	std::string	buff_stack;

	if (i < this->max_player && i != 0){
		if (this->player_in_table[i].get_pseudo() == "pseudo"){
			std::cout << "pseudo du joueur " << i << " : ";
			std::getline(std::cin, buff_name);
			std::cout << "nombre de jetons : ";
			std::getline(std::cin, buff_stack);
			player	p(buff_name, atof(buff_stack.c_str()));
			this->player_in_table.erase(this->player_in_table.begin()+i);
			this->player_in_table.insert(this->player_in_table.begin()+i, p);
		}
		else {
			std::cout << this->player_in_table[i].get_pseudo() << " occupe deja la place numero " << i << std::endl;
			std::cout << "remplcer le joueur ? 1 -> pour echanger " << std::endl;
			std::getline(std::cin, buff_name);
			if (buff_name == "1"){
				player p;
				this->player_in_table.erase(this->player_in_table.begin()+i);
				this->player_in_table.insert(this->player_in_table.begin()+i, p);
				this->add_player(i);
				return ;
			}
			else {
				std::cout << "entre 'q' pour annuler sinn entre un autre numero de siege :";
				std::getline(std::cin, buff_name);
				if (buff_name != "q" && (buff_name == "1" || buff_name == "2" || buff_name == "3" || 
					buff_name == "4" || buff_name == "5" || buff_name == "6" || buff_name == "7" || buff_name == "8")){
					
					this->add_player(atoi(buff_name.c_str()));
				}
				return ;
			}
		}
	}
	else {
		std::cout << "le nombre entre est trop grand " << std::endl;
	}
}

void	table::del_player(int position){
	if (this->player_in_table[position].get_pseudo() != "pseudo"){
		this->player_in_table.erase(this->player_in_table.begin()+position);
		player p;
		this->player_in_table.insert(this->player_in_table.begin()+position, p);
		return ;
	}
	else {
		std::cout << " pas de joueur a cette position " << std::endl;
	}
}

void	table::fold_player(){
	this->player_actif -= 1;
	return ;
}

short	table::get_player_actif(){
	return this->player_actif;
}

float	table::get_pot(){
	return this->pot;
}

std::string *	table::get_board(){
	return this->board;
}

void			table::print_info(){
	std::cout << "borad : ";
	int i = 0;
	while (i < 5){
		std::cout << this->board[i] << " / ";
		i++;
	}
	std::cout << std::endl;
	std::cout << "pot : " << this->pot << std::endl;
	std::cout << "nb max player : " << this->max_player << std::endl;
	std::cout << "blind : " << this->min_blind << "/" << this->max_blind << std::endl;
	std::cout << "nb de joueur actif : " << this->player_actif << std::endl;
	i = 0;
	while (i < this->max_player){
		std::cout << "joueur " << i << " : " << std::endl;
		this->player_in_table[i].print_info();
		if (this->player_in_table[i].get_actif() == true){
			std::cout << "ce joueur est actif" << std::endl;
		}
		else
			std::cout << "ce joueur est coucher" << std::endl;
		i++;
	}

}
