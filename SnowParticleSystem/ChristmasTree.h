#pragma once

#include "Object.h"
#include <vector>


class ChristmasTree : public Object
{

public:
    ChristmasTree(ofVec3f position, ofColor color);
    void draw();
    void update(float deltaTime);
};

