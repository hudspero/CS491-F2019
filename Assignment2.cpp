/*#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"*/

glm::mat4 Multiply(glm::mat4 a, glm::mat4 b) {
	return a * b;
}

glm::vec3 Multiply(glm::mat4 a, glm::vec3 b) {
	glm::vec4 new_b = glm::vec4(b, 1);
	glm::vec4 result = a * new_b;
	return glm::vec3(result);
}

glm::vec3 ScalePointAroundAnotherPoint(glm::vec3 inputPoint, glm::vec3 centerPoint, glm::vec3 scale) {
	glm::vec3 difference = inputPoint - centerPoint;
	inputPoint = centerPoint;
	inputPoint.x *= scale.x;
	inputPoint.y *= scale.y;
	inputPoint.z *= scale.z;
	inputPoint += difference;
	return inputPoint;
}

glm::vec3 RotatePointAroundAnotherPoint(glm::vec3 inputPoint, glm::vec3 centerPoint, glm::mat4 first, glm::mat4 second, glm::mat4 third){
	glm::vec3 difference = inputPoint - centerPoint;
	glm::mat4 transfResult = Multiply(third, second);
	transfResult *= first;
	glm::vec3 vecResult = Multiply(transfResult, difference);
	return vecResult;
}

void WhoAmI( std::string &yourName, std::string &yourEmailAddress ){
	yourName = "Robert Hudspeth";
	yourEmailAddress = "hudspero@oregonstate.edu";
}

void PrintMatrix(glm::mat4 mat) {
	for(int row = 0; row < 4; row++) {
		fprintf(stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3]);
	}
}

/*int main() {
	
	//MULTIPLY(mat4, mat4)
	printf("**Multiply(mat4, mat4)**\n");
	glm::mat4 testMatrix1(1.0,  2.0,  3.0,  4.0, 
						  5.0,  6.0,  7.0,  8.0, 
						  9.0,  10.0, 11.0, 12.0, 
						  13.0, 14.0, 15.0, 16.0);
						  
	glm::mat4 testMatrix2(17.0, 18.0, 19.0, 20.0, 
						  21.0, 22.0, 23.0, 24.0, 
						  25.0, 26.0, 27.0, 28.0, 
						  29.0, 30.0, 31.0, 32.0);
	
	glm::mat4 mult1 = Multiply(testMatrix1, testMatrix2);
	PrintMatrix(mult1);
	printf("\n");
	glm::mat4 mult2 = Multiply(testMatrix2, testMatrix1);
	PrintMatrix(mult2);
	printf("\n\n");
	
	//MULTIPLY(mat4, vec3)
	printf("**Multiply(mat4, vec3)**\n");
	glm::vec3 testVector1(1.5, 1.5, 1.5);
	glm::vec3 testResult = Multiply(testMatrix1, testVector1);
	printf("vec3 testResult = %f, %f, %f\n\n", testResult.x, testResult.y, testResult.z);
	
	//SCALE
	printf("**ScalePointAroundAnotherPoint**\n");
	glm::vec3 a(1, 2, 3);
	glm::vec3 b(1, 1, 1);
	glm::vec3 scale(2, 2, 2);
	printf("a = %f, %f, %f\n", a.x, a.y, a.z);
	printf("b = %f, %f, %f\n", b.x, b.y, b.z);
	printf("scale = %f, %f, %f\n", scale.x, scale.y, scale.z);
	glm::vec3 scaleResult = ScalePointAroundAnotherPoint(a, b, scale);
	printf("scaleResult = %f, %f, %f\n\n", scaleResult.x, scaleResult.y, scaleResult.z);
	
	//ROTATE
	glm::mat4 testMatrix3(33.0, 34.0, 35.0, 36.0,
						  37.0, 38.0, 39.0, 40.0,
						  41.0, 42.0, 43.0, 44.0,
						  45.0, 46.0, 47.0, 48.0);
	printf("**RotatePointAroundAnotherPoint**\n");
	PrintMatrix(testMatrix3);
	testResult = RotatePointAroundAnotherPoint(a, b, testMatrix3, testMatrix2, testMatrix1);
	printf("vec3 testResult = %f, %f, %f\n\n", testResult.x, testResult.y, testResult.z);
	
	return 0;
}*/