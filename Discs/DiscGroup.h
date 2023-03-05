#pragma once
#include "ofMain.h"

class DiscGroup
{
public:
	DiscGroup();

	void setGravity(vector <glm::vec3>* attract);

	void reset();
	void update();
	void draw();

	float drag;
	float scale;
	float mass;
	float r;
	float dt;
	float viscosity;

	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 friction;
	glm::vec3 acceleration;
	glm::vec3 force;
	vector <glm::vec3>* gpts;
	ofColor color;
	glm::vec3 forceNet;

	bool isStokesOn = false;
};

