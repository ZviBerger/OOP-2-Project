#pragma once
#include "RemovableObj.h" 
class Bomb : public RemovableObj//, public ProcessInterface
{
public:
	Bomb(sf::Vector2f &scaling, sf::Vector2f& position);
	virtual void collide(GameObject& otherObject);
	virtual void collide(Alien& otherObject) { ; }
	virtual void collide(Astroid& otherObject) { ; }
	virtual void collide(Astronaut& otherObject) { ; }
	virtual void collide(Bomb& otherObject) { ; }
	virtual void collide(Fruit& otherObject) { ; }
	virtual void collide(Rock& otherObject) { ; }
	virtual void collide(Shot& otherObject) { ; }
	virtual void collide(SpaceShip& otherObject) { ; }

	void updateMove() { ; }
};

