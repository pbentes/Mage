#include "camera.hpp"
#include "glm/ext/matrix_clip_space.hpp"

glm::mat4 Camera::project() {
    switch (projection) {
        case Projection::perspective:
            return glm::perspective(glm::radians(fov), aspect_ratio, near_plane, far_plane);
        case Projection::orthographic:
            return glm::ortho(0.0f, size, 0.0f, size, near_plane, far_plane);
    }
}
