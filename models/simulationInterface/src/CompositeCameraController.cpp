#include "CompositeCameraController.hh"
#include "inputAbstraction/include/Utils.hh"
#include <algorithm>

using namespace idf;

void CompositeCameraController::add(CameraController& cameraController) {
    // Add the controller, if not present.
    if(std::find(cameraControllers.begin(), cameraControllers.end(), &cameraController) == cameraControllers.end()) {
        cameraControllers.push_back(&cameraController);
    }
}

void CompositeCameraController::remove(const CameraController& cameraController) {
    // Remove the controller, if present.
    cameraControllers.erase(std::remove(cameraControllers.begin(),
      cameraControllers.end(), &cameraController), cameraControllers.end());
}

double CompositeCameraController::getCommandedPan() const {
    double result = 0;

    // Sum all constituent controller's pan commands.
    for (std::vector<CameraController*>::const_iterator i = cameraControllers.begin();
      i != cameraControllers.end(); ++i) {
        result += (*i)->getPan();
    }

    // Restrict the result to [-1, 1]
    return bound(result);
}

double CompositeCameraController::getCommandedTilt() const {
    double result = 0;

    // Sum all constituent controller's tilt commands.
    for (std::vector<CameraController*>::const_iterator i = cameraControllers.begin();
      i != cameraControllers.end(); ++i) {
        result += (*i)->getTilt();
    }

    // Restrict the result to [-1, 1]
    return bound(result);
}

double CompositeCameraController::getCommandedSpin() const {
    double result = 0;

    // Sum all constituent controller's spin commands.
    for (std::vector<CameraController*>::const_iterator i = cameraControllers.begin();
      i != cameraControllers.end(); ++i) {
        result += (*i)->getSpin();
    }

    // Restrict the result to [-1, 1]
    return bound(result);
}

double CompositeCameraController::getCommandedZoom() const {
    double result = 0;

    // Sum all constituent controller's zoom commands.
    for (std::vector<CameraController*>::const_iterator i = cameraControllers.begin();
      i != cameraControllers.end(); ++i) {
        result += (*i)->getZoom();
    }

    // Restrict the result to [-1, 1]
    return bound(result);
}

void CompositeCameraController::setActive(bool activate) {
    // Set all constituent controller's states.
    for (std::vector<CameraController*>::iterator i = cameraControllers.begin();
      i != cameraControllers.end(); ++i) {
        (*i)->setActive(activate);
    }

    // Call the parent method to set this instance's state.
    Controller::setActive(activate);
}
