
#pragma once

#include <vector>
#include "Particle.h"
#include "Object.h"

class Emitter {


private:
	
	std::vector<std::shared_ptr<Particle>> particles;
	std::vector<std::shared_ptr<glm::vec3>> forces;
	std::vector<std::shared_ptr<Object>> object;
	size_t maxPnumber;

public:
	Emitter(size_t max_n = 10000);

	void SnowInit(uint32_t pCount);

	void update(float dt);

	void draw();

	void add(std::shared_ptr<Particle> p);

	void addF(std::shared_ptr<glm::vec3> force);
	void resetForces();

	void addObject(std::shared_ptr<Object> character);

	void clear();
};