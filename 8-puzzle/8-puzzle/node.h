#pragma once
#include <iostream>
#include <vector>

class node {

private:
	std::vector<char> path;
	int state[3][3];
	int zero[2];
	int goal[3][3] = { { 1,2,3 }, {4, 5, 6 }, {7, 8, 0 }};
	int cost;
	int level;
	node * next;
	



public :
	//void setPath(std::vector<char> theVector);
	node() {};
	node* predecessor = nullptr;
	std::vector<node> MOVE;
	std::vector<char> getPath();
	void toString();
	void setState(int theState[][3]);
	void editState(int x, int y);
	void setCost();
	int getCost();
	void setLevel(int lvl);
	int getLevel();
	node getWinner();
	int* getState();
	void createChildren();
	void setZero();
	bool compareState();



};