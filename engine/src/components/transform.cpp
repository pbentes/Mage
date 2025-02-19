#include "transform.hpp"

#include "glm/ext/vector_float3.hpp"
#include "glm/gtc/quaternion.hpp"

glm::vec3 Transform::forward() {
    glm::vec4 forward = glm::vec4{ 0, 0, -1, 1 };

    glm::quat rotation =  glm::quat(this->rotation);
    glm::vec4 result = glm::normalize(rotation * forward);

    return result;
}

glm::vec3 Transform::right() {
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); 
    return glm::normalize(glm::cross(up, this->forward()));
}

glm::vec3 Transform::up() {
    return glm::cross(this->forward(), this->right());
}
