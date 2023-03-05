#pragma once

#include "ChristmasTree.h"
#include "ofMain.h"
#include "Snowman.h"
#include "Camera.h"
#include "Snow.h"
#include "Emitter.h"
#include <vector>

class ofApp : public ofBaseApp {
private:
    float dtChange = 5.f;
    int snowParticlesAmount = 10000;
    std::unique_ptr<Emitter> p_emitter = std::make_unique<Emitter>(Emitter(10000));
    std::vector<std::shared_ptr<Object>> objects;
    std::unique_ptr<Camera> camera = std::make_unique<Camera>();

public:
    void setup() override;
    void update() override;
    void draw() override;
    void reset();

    void keyPressed(int key) override;
    void keyReleased(int key) override;
};