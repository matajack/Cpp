#include "node.h"
#include <vector>
#include <iostream>

void node::toString() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << this->state[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n\n\n";


}

int* node::getState() {
	return *this->state;
}

std::vector<char> node::getPath() {
	return this->path;
}

int node::getCost(){
	return this->cost;
}
int node::getLevel(){
	return this->level;
}

node node::getWinner() {
	int WINNER = 0;
	for (int i = 0; i < this->MOVE.size(); i++) {
		if (MOVE[i].getCost() <= MOVE[WINNER].getCost()) {
			WINNER = i;
		}
		/*if (MOVE[i].getCost() == MOVE[WINNER].getCost()) {
			if (MOVE[i].getCost() < MOVE[WINNER].getCost())
		}*/
	}
	return MOVE[WINNER];

}

void node::createChildren() {
	if (this->zero[0] - 1 >= 0) {
		this->next = new node;
		this->next->setLevel(this->level + 1);
		this->next->setState(this->state);
		this->next->predecessor = this;
		this->next->setZero();
		this->next->editState(this->zero[0]-1, this->zero[1]);
		this->next->setCost();
		this->MOVE.push_back(*this->next);
		delete this->next;
	}
	if (this->zero[0] + 1 < 3) {
		this->next = new node;
		this->next->setLevel(this->level + 1);
		this->next->setState(this->state);
		this->next->predecessor = this;
		this->next->setZero();
		this->next->editState(this->zero[0]+1, this->zero[1]);
		this->next->setCost();
		this->MOVE.push_back(*this->next);
		delete this->next;
	}
	if (this->zero[1] - 1 >= 0) {
		this->next = new node;
		this->next->setLevel(this->level + 1);
		this->next->setState(this->state);
		this->next->predecessor = this;
		this->next->setZero();
		this->next->editState(this->zero[0], this->zero[1]-1);
		this->next->setCost();
		this->MOVE.push_back(*this->next);
		delete this->next;
	}
	if (this->zero[1] + 1 < 3) {
		this->next = new node;
		this->next->setLevel(this->level + 1);
		this->next->setState(this->state);
		this->next->predecessor = this;
		this->next->setZero();
		this->next->editState(this->zero[0], this->zero[1] + 1);
		this->next->setCost();
		this->MOVE.push_back(*this->next);
		delete this->next;
	}	


}

void node::editState(int x, int y) {
	
	this->state[this->zero[0]][this->zero[1]] = this->state[x][y];
	this->state[x][y] = 0;
	this->zero[0] = x;
	this->zero[1] = y;

}

void node::setLevel(int lvl) {
	this->level = lvl;
}

void node::setState(int theState[][3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->state[i][j] = theState[i][j];
		}
	}

}

void node::setCost() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (this->state[i][j] != goal[i][j] && this->state[i][j] != 0) {
				this->cost += 1;
			}
		}
	}
	this->cost += this->level;
}

bool node::compareState() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (this->state[i][j] != this->goal[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void node::setZero() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (this->state[i][j] == 0) {
				this->zero[0] = i;
				this->zero[1] = j;
				break;
			}
		}
	}

}