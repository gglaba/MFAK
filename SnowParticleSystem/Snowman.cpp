#include "Snowman.h"


Snowman::Snowman(ofVec3f position, ofColor color) : Object(position, color)
{
}

void Snowman::draw() 
{
	ofSetColor(color);
	ofDrawSphere(position + ofVec3f(0,18,0), 20); // nogi
	ofDrawSphere(position + ofVec3f(0,45,0), 15); // tu³ów
	ofDrawSphere(position + ofVec3f(0, 60, 0), 10); // g³owa
}

void Snowman::update(float deltaTime) {

}

std::vector<float> Snowman::getSpheres() const {
	return spheres;
}
