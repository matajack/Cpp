#include <iostream>
#include <vector>
#include "node.h"
#include <time.h>

void random(std::vector<int> &randVec, int amount) {
	std::vector<int> numbers;
	int num;
	int index;
	for (int i = 0; i < amount; i++) {
		numbers.push_back(i);
	}
	std::srand(time(NULL));
	for (int i = 0; i < amount; i++) {
		index = rand() % numbers.size();
		num = numbers[index];
		std::swap(numbers[index], numbers[numbers.size()-1]);
		numbers.pop_back();
		randVec.push_back(num);
	}
}

int main(void) {
	std::vector<int> theRand;
	int initial[3][3] = { {1,2,3},{4,5,0},{6,7,8} };;
	int num = 0;
	int count = 0;
	int inc = -1;
	bool solvable = false;

	// this was for the random initial state but it doesnt find a solvable initial state that often 
	// and my check for a solvable state is not correct

	/*while (solvable == false) {
		random(theRand, 9);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				initial[i][j] = theRand[theRand.size() - 1];
				theRand.pop_back();
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int a = i; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (initial[i][j] > initial[a][b] && initial[a][b] != 0) {
							count++;
						}
					}
				}
			}
		}
		if (count % 2 == 0) {
			solvable = true;
		}
	}*/
	int exit = 0;
	int lowest = 0;
	std::vector<node*> bestPath;


	node* ptr;
	int temp = 0;
	int choice = 0;

	ptr = new node;

	ptr->setState(initial);
	ptr->setZero();
	ptr->setLevel(0);

	std::cout << "Enter 0 for A* or 1 for BFS: ";
	std::cin >> choice;

	if (choice == 0) {
		while (exit != 1) {

				if (ptr->compareState() == true) {
					for (int j = 0; j < bestPath.size(); j++) {
						if (ptr->getCost() < bestPath[j]->getCost()) {
							exit = 1;
							inc = j;
						}
						else {
							exit = -1;
							inc = -1;
							break;
						}
					}
				}

			if (inc == -1) {
				ptr->createChildren();
				for (int i = 0; i < ptr->MOVE.size(); i++) {
					bestPath.push_back(&ptr->MOVE[i]);
				}
				for (int i = 0; i < bestPath.size(); i++) {
					if (bestPath[i]->getCost() < bestPath[lowest]->getCost()) {
						lowest = i;
					}
				}
				ptr = bestPath[lowest];
				bestPath.erase(bestPath.begin() + lowest);
				lowest = 0;
			}
		}

		bestPath.clear();
		while (ptr != NULL) {
			bestPath.push_back(ptr);
			ptr = ptr->predecessor;
		}
		for (int i = bestPath.size() - 1; i >= 0; i--) {
			bestPath[i]->toString();
		}
	}
	if (choice == 1) {
		ptr->createChildren();
		for (int i = 0; i < ptr->MOVE.size(); i++) {
			bestPath.push_back(&ptr->MOVE[i]);
		}
		while (exit != 1) {
			for (int i = temp; i < bestPath.size(); i++) {
				if (bestPath[i]->compareState() == true) {

					ptr = bestPath[i];
					exit = 1;

				}
				temp = i + 1;
				if (exit != 1) {
					bestPath[i]->createChildren();
					for (int j = 0; j < bestPath[i]->MOVE.size(); j++) {
						bestPath.push_back(&bestPath[i]->MOVE[j]);
					}
				}
			}
		}
		bestPath.clear();
		while (ptr != NULL) {
			bestPath.push_back(ptr);
			ptr = ptr->predecessor;
		}
		for (int i = bestPath.size() - 1; i >= 0; i--) {
			bestPath[i]->toString();
		}
	}




	return 0;
}