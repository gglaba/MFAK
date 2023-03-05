#pragma once

#include <ofMain.h>
#include "Object.h"

class Particle {

protected:
	ofVec3f position;
	ofVec3f direction;
	ofVec3f acceleration;
	ofColor color;
	float lifeTime;
	bool isRemovable;
	bool comeback;
	float size;

protected:
	Particle(ofVec3f position, ofVec3f acceleration, ofColor color, float size, ofVec3f direction);

public:
	virtual void draw() = 0;
	virtual void update(float deltaTime, std::vector<shared_ptr<glm::vec3>> forces) = 0;
	virtual void collide(float deltaTime);
	
	virtual bool isColliding(std::shared_ptr<Object> obj);

	void stop();

	void setPosition(ofVec3f position);
	ofVec3f getPosition() const;

	ofVec3f getAcceleration() const;
	void setAcceleration(ofVec3f acceleration);

	ofColor getColor() const;

	float getLife() const;
	void setLife(float lifeTime);

	bool isToRemove() const;
	void setIsToRemove(bool isRemovable);

	bool isReviveAfterDeath() const;
	void setReviveAfterDeath(bool revive);

	float getSize() const;
};