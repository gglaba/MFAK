#pragma once
#include "Particle.h"
#include "ofMain.h"


class Snow : public Particle {

public:
	Snow(ofVec3f position, ofVec3f acceleration, ofColor color, float size, ofVec3f direction);

	void Snow::draw() override;

	void Snow::update(float deltaTime, std::vector<shared_ptr<glm::vec3>> forces) override;

	//bool Snow::isColliding(std::shared_ptr<Object> object) override;

	void Snow::collide(float deltaTime) override;
};

