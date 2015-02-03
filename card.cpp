
#include "card.hpp"

card::card(){
	int i = 0;
	int pos = 0;
	int	color = 0;
	char n = '9';
	while (i < 52){
		if (i % 13 == 0 && i != 0){
			n = '9';
			pos = 0;
			color++;
		}
		if (pos == 0)
			this->card_package[i] = 'A';
		else if (pos == 1)
			this->card_package[i] = 'K';
		else if (pos == 2)
			this->card_package[i] = 'Q';
		else if (pos == 3)
			this->card_package[i] = 'J';
		else if (pos == 4)
			this->card_package[i] = 'T';
		else {
			this->card_package[i] = n;
			n--;
		}
		pos++;
		if (color == 0)
			this->card_package[i] += 'c';
		else if (color == 1)
			this->card_package[i] += 'p';
		else if (color == 2)
			this->card_package[i] += 'k';
		else if (color == 3)
			this->card_package[i] += 't';

		i++;
	}
	return ;
}

card::~card(){
	return ;
}

std::string *	card::get_package(){
	return this->card_package;
}

void	card::init_package(){
	int i = 0;
	int pos = 0;
	int	color = 0;
	char n = '9';
	while (i < 52){
		if (i % 13 == 0 && i != 0){
			n = '9';
			pos = 0;
			color++;
		}
		if (pos == 0)
			this->card_package[i] = 'A';
		else if (pos == 1)
			this->card_package[i] = 'K';
		else if (pos == 2)
			this->card_package[i] = 'Q';
		else if (pos == 3)
			this->card_package[i] = 'J';
		else if (pos == 4)
			this->card_package[i] = 'T';
		else {
			this->card_package[i] = n;
			n--;
		}
		pos++;
		if (color == 0)
			this->card_package[i] += 'c';
		else if (color == 1)
			this->card_package[i] += 'p';
		else if (color == 2)
			this->card_package[i] += 'k';
		else if (color == 3)
			this->card_package[i] += 't';

		i++;
	}
	return ;
}

void	card::del_card(){
	return ;
}

void	card::init_nb_card(){
	return ;
}

void	card::print_package(){
	int i = 0;
	while (i < 52){
		std::cout << this->card_package[i] << std::endl;
		i++;
	}
}