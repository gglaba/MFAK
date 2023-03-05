#pragma once

#include <ofMain.h>
#include "Object.h"

class Snowman : public Object {

private:
    std::vector<float> spheres;
    float ratio;
public:
    Snowman(ofVec3f position, ofColor color);
    void draw() override;
    void update(float deltaTime) override;


    std::vector<float> getSpheres() const;

};