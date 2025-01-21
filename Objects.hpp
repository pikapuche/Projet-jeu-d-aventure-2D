#pragma once
#include "Player.hpp"
#include "Interface.hpp"
using namespace std;

class Objects : public Entity, public IInteractable {
protected : 
	string nom;
	int x, y;
	int objectsCount = 0;
public : 

	Objects(string n, int x, int y);

	~Objects();

	void interact(Player& player) override;
};