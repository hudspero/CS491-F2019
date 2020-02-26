
#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"


glm::vec3 WhatPartOfALivesInBDir(glm::vec3 a, glm::vec3 b) {
	glm::vec3 unitb = normalize(b); //MAKE b INTO A UNIT VECTOR
	return unitb * (dot(a, unitb));
}

glm::vec3 WhatPartOfALivesPerpToB(glm::vec3 a, glm::vec3 b){
	glm::vec3 unitb = normalize(b); //MAKE b INTO A UNIT VECTOR
	return a - (unitb * (dot(a, unitb)));
}

glm::vec3 UnitSurfaceNormal(glm::vec3 q, glm::vec3 r, glm::vec3 s){
	return normalize(cross((r - q), (s - q)));
}

float Area(glm::vec3 q, glm::vec3 r, glm::vec3 s) {
	glm::vec3 cpr = cross((r - q), (s - q)); //CROSS-PRODUCT RESULT
	float mag = sqrt((cpr.x * cpr.x) + (cpr.y * cpr.y) + (cpr.z * cpr.z)); //MAGNITUDE OF CROSS-PRODUCT
	return 0.5 * mag;
}

bool IsPointInTriangle(glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p) {
	glm::vec3 n = cross((r - q), (s - q));
	glm::vec3 nq = cross((r - q), (p - q));
	glm::vec3 nr = cross((s - r), (p - r));
	glm::vec3 ns = cross((q - s), (p - s));

	if (dot(n, nq) > 0 && dot(n, nr) > 0 && dot(n, ns) > 0)
		return true;
	else	
		return false;
}

float DistanceFromPointToPlane(glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p) {
	glm::vec3 surfnorm = UnitSurfaceNormal(q, r, s);
	return dot((p - q), surfnorm);
}

void WhoAmI(std::string &yourName, std::string &yourEmailAddress) {
	yourName = "Robert Hudspeth";
	yourEmailAddress = "hudspero@oregonstate.edu";
}


int main() {
	glm::vec3 a(2, 2, -1);
	glm::vec3 b(1, 1, 1);
	
	printf("\n**WhatPartOfALivesInBDir**\n");
	printf("a = {2, 2, -1}, b = {1, 1, 1}\n");
	//printf("Result should be: {3, 3, 3} according to Symbolab\n");
	glm::vec3 result_a(WhatPartOfALivesInBDir(a, b));
	printf("Result = {%f, %f, %f}\n\n", result_a.x, result_a.y, result_a.z);
	
	printf("**WhatPartOfALivesPerpToB**\n");
	printf("a = {2, 2, -1}, b = {1, 1, 1}\n");
	//printf("Result should be: {-1, -1, -4} according to Symbolab\n");
	glm::vec3 result_b = WhatPartOfALivesPerpToB(a, b);
	printf("Result = {%f, %f, %f}\n\n", result_b.x, result_b.y, result_b.z);
	
	glm::vec3 q(1, 0, 0);
	glm::vec3 r(0, 1, 0);
	glm::vec3 s(0, 0, 1);
	glm::vec3 p(0.5, 0.5, 0.5);
	
	printf("**IsPointInTriangle**\n");
	printf("q = {1, 0, 0}, r = {0, 1, 0}, s = {0, 0, 1}, p = {0.5, 0.5, 0.5}\n");
	//printf("Result should be 0 (FALSE)\n");
	bool truth = IsPointInTriangle(q, r, s, p);
	printf("Result = %d\n\n", truth);
	
	printf("**Area**\n");
	printf("q = {1, 0, 0}, r = {0, 1, 0}, s = {0, 0, 1}\n");
	//printf("Result should be \n");
	float output_a = Area(q, r, s);
	printf("Result = %f\n\n", output_a);
	
	printf("**UnitSurfaceNormal**\n");
	printf("q = {1, 0, 0}, r = {0, 1, 0}, s = {0, 0, 1}\n");
	//printf("Result should be \n");
	glm::vec3 result_c = UnitSurfaceNormal(q, r, s);
	printf("Result = {%f, %f, %f}\n\n", result_c.x, result_c.y, result_c.z);
	
	printf("**DistanceFromPointToPlane**\n");
	printf("q = {1, 0, 0}, r = {0, 1, 0}, s = {0, 0, 1}, p = {0.5, 0.5, 0.5}\n");
	//printf("Result should be \n");
	float output_b = DistanceFromPointToPlane(q, r, s, p);
	printf("Result = %f\n\n", output_b);
	
	return 0;
}
