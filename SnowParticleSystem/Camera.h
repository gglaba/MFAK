#pragma once

#include "ofMain.h"

class Camera {
private:
    std::unique_ptr<ofEasyCam> camera = std::make_unique<ofEasyCam>();
    std::unique_ptr<ofLight> light = std::make_unique<ofLight>();
public:
    Camera();
    void init();
    void Begin();
};