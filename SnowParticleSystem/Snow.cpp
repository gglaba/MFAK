#include "Snow.h"
#include "Snowman.h"
#include <glm/vec3.hpp>
#include <vector>

Snow::Snow(ofVec3f position, ofVec3f acceleration, ofColor color, float size, ofVec3f direction) : Particle(position, acceleration, color, size, direction) {
	this->comeback = true;
}

void Snow::draw() {
	ofSetColor(color);
	ofDrawSphere(position, size);
}

void Snow::update(float deltaTime, std::vector<shared_ptr<glm::vec3>> forces) {

	if (getPosition().y <= 0.f) {
		collide(deltaTime);
	}
	acceleration = ofVec3f(0.f, 0.f, 0.f);

	for(auto force : forces) {
		float x = force->x * deltaTime;
		float y = force->y * deltaTime;
		float z = force->z * deltaTime;
		acceleration += ofVec3f(x, y, z);
	}

	direction += acceleration * deltaTime;

	position += direction;
}

void Snow::collide(float deltaTime) {
	acceleration = ofVec3f(0.f, 0.f, 0.f);
	direction = ofVec3f(0.f, 0.f, 0.f);
	if(!isToRemove()) {
		setIsToRemove(true);
		setLife(3.f);
	} else setLife(getLife() - deltaTime);
}
