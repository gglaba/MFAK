#include "Object.h"

Object::Object(ofVec3f position, ofColor color) : color(color), position(position) {

}

ofVec3f Object::getPosition() const {
    return position;
}

ofColor Object::getColor() const {
    return color;
}

Object::~Object() {

}