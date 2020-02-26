void Forward(float th1, float th2, float th3, float l1, float l2, glm::mat4& m1g, glm::mat4& m2g, glm::mat4& m3g) {
	//Converting degree values to radians
	th1 *= (M_PI / 180.);
	th2 *= (M_PI / 180.);
	th3 *= (M_PI / 180.);
	
	glm::mat4 tl1 = glm::translate(glm::mat4(1.f), glm::vec3(l1, 0, 0)); //translation matrix of length l1
	glm::mat4 tl2 = glm::translate(glm::mat4(1.f), glm::vec3(l2, 0, 0)); //translation matrix of length l2
	glm::mat4 r1 = glm::rotate(glm::mat4(1.f), th1, glm::vec3(0, 0, 1));
	glm::mat4 r2 = glm::rotate(glm::mat4(1.f), th2, glm::vec3(0, 0, 1));
	glm::mat4 r3 = glm::rotate(glm::mat4(1.f), th3, glm::vec3(0, 0, 1));
	glm::mat4 x21 = tl1 * r2; //compound matrix transformation for intermediary portion
	glm::mat4 x32 = tl2 * r3; //compound matrix transformation for final portion

	m1g = r1; //m1g does not translate by any length; effectively applying identity matrix meaning nothing changes
	m2g = m1g * x21; 
	m3g = m2g * x32;
}

void WhoAmI(std::string &yourName, std::string &yourEmailAddress) {
	yourName = "Robert Hudspeth";
	yourEmailAddress = "hudspero@oregonstate.edu";
}