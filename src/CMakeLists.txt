include("${_build_cmake_local}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME} INTERFACE
        "../public/PiSubmarine/Control/Api/Input/ISink.h"
        "../public/PiSubmarine/Control/Api/Input/Mode/Request.h"
        "../public/PiSubmarine/Control/Api/Input/OperatorCommand.h"
        "../public/PiSubmarine/Control/Api/Input/Mode/Manual.h"
        "../public/PiSubmarine/Control/Api/Input/Mode/HoldPosition.h"
)
target_include_directories(${PISUBMARINE_MODULE_NAME} INTERFACE "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Error.Api)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Control.Horizontal.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Control.Horizontal.Api)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Control.Vertical.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Control.Vertical.Api)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Control.Gimbal.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Control.Gimbal.Api)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Control.Lamp.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Control.Lamp.Api)
