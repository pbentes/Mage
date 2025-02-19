#pragma once

#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"

class Transform {
    public:
        glm::vec3 position = glm::vec3{0, 0, 0};
        glm::vec3 scale = glm::vec3{1, 1, 1};
        glm::vec3 rotation = glm::vec3{0, 0, 0};
    
    public:
        glm::vec3 forward();
        glm::vec3 right();
        glm::vec3 up();

        operator glm::mat4() const {
            glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
            glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);

            // Create rotation matrices for each axis
            glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1, 0, 0));
            glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0, 1, 0));
            glm::mat4 rotationZ = glm::rotate(glm::mat4(1.0f), rotation.z, glm::vec3(0, 0, 1));

            // Combine the rotation matrices
            glm::mat4 rotationMatrix = rotationZ * rotationY * rotationX;

            // Combine translation, rotation, and scale matrices
            return  translationMatrix * rotationMatrix * scaleMatrix;
        }
};
