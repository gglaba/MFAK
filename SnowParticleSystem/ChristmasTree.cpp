#include "ChristmasTree.h"
#include "math.h"

ChristmasTree::ChristmasTree(ofVec3f position, ofColor color) : Object(position, color) {
 
}

void ChristmasTree::draw() {

    //rysuje choinke
    ofSetColor(color);
    ofDrawCone(position + ofVec3f(0, 40, 0), 100, -200);
    ofSetColor(255, 255, 255);
    ofDrawCone(position + ofVec3f(0, 50, 0), 100, -200);
    ofSetColor(color);
    ofDrawCone(position + ofVec3f(0, 60, 0), 95, -200);
    ofSetColor(255, 255, 255);
    ofDrawCone(position + ofVec3f(0, 70, 0), 90, -200);
    ofSetColor(color);
    ofDrawCone(position + ofVec3f(0, 80, 0), 85, -200);
    ofSetColor(255,255,255);
    ofDrawCone(position + ofVec3f(0, 90, 0), 80, -200);
    ofSetColor(color);
    ofDrawCone(position + ofVec3f(0, 100, 0), 75, -200);
    ofSetColor(255, 255, 255);
    ofDrawCone(position + ofVec3f(0, 110, 0), 70, -200);
    ofSetColor(139, 69, 19);
    ofDrawCylinder(position - ofVec3f(0,60,0), 30, 100);
}

void ChristmasTree::update(float deltaTime) {
    
}
