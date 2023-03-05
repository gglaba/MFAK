#pragma once
#include "ofMain.h"

class Object {

protected:
    ofColor color;
    ofVec3f position;
public:
    Object(ofVec3f position, ofColor color);
    virtual ~Object();
    virtual void draw() = 0;
    virtual void update(float deltaTime) = 0;
    ofVec3f getPosition() const;
    ofColor getColor() const;
};