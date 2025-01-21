#pragma once
#include "Player.hpp"

class IInteractable {
public : 
	virtual void interact(Player& player) = 0;
};