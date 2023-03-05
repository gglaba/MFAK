#include "Camera.h"
#include "ofMain.h"

Camera::Camera() {

}

void Camera::init() {
    ofSetBackgroundColor(135, 206, 235);
    light->setPosition(ofVec3f(0.f, 200.f, -400.f));
    light->setAmbientColor(ofColor(120, 120, 120));
    ofSetSphereResolution(15);
}


void Camera::Begin() {
    camera->begin();
    ofPushMatrix();
    ofRotateDeg(180, 0, 0, 1);
    light->enable();
    ofPopMatrix();
    ofSetColor(255, 228, 132);
    ofDrawSphere(ofVec3f(0.f, 1000.f, -5500.f), 500.f);
}

