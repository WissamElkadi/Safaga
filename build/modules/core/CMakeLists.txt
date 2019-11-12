project(Core)

set(LIB_DIR ${ROOT_DIR}/modules/core)

# Source Files
set(LIB_SRC
    ${LIB_DIR}/src/BoundingBox.cpp
    ${LIB_DIR}/src/Camera.cpp
    ${LIB_DIR}/src/CameraNode.cpp
    ${LIB_DIR}/src/DirectionalLight.cpp
    ${LIB_DIR}/src/Group.cpp
    ${LIB_DIR}/src/Light.cpp
    ${LIB_DIR}/src/Material.cpp
    ${LIB_DIR}/src/Mesh.cpp
    ${LIB_DIR}/src/Node.cpp
    ${LIB_DIR}/src/PointLight.cpp
    ${LIB_DIR}/src/Renderable.cpp
    ${LIB_DIR}/src/RenderVisitor.cpp
    ${LIB_DIR}/src/SpotLight.cpp
    ${LIB_DIR}/src/Switch.cpp
    ${LIB_DIR}/src/Transform.cpp
)

# Include Files
set(LIB_INC
    ${LIB_DIR}/include/BoundingBox.h
    ${LIB_DIR}/include/Camera.h
    ${LIB_DIR}/include/CameraNode.h
    ${LIB_DIR}/include/DirectionalLight.h
    ${LIB_DIR}/include/Group.h
    ${LIB_DIR}/include/INodeVisitor.h
    ${LIB_DIR}/include/Light.h
    ${LIB_DIR}/include/Material.h
    ${LIB_DIR}/include/MathUtils.h
    ${LIB_DIR}/include/Mesh.h
    ${LIB_DIR}/include/Node.h
    ${LIB_DIR}/include/PointLight.h
    ${LIB_DIR}/include/Renderable.h
    ${LIB_DIR}/include/RenderVisitor.h
    ${LIB_DIR}/include/SpotLight.h
    ${LIB_DIR}/include/Switch.h
    ${LIB_DIR}/include/Transform.h
)

# Source files grouping in IDE
source_group("include" FILES ${LIB_INC})
source_group("src" FILES ${LIB_SRC})

if(SAFAGA_PLATFORM_ANDROID)

    add_library(${TARGET_CORE_LIB_NAME} SHARED ${LIB_SRC} ${LIB_INC})

elseif(SAFAGA_PLATFORM_WINDOWS)

    add_library(${TARGET_CORE_LIB_NAME} STATIC ${LIB_SRC} ${LIB_INC})
    
endif()


set(LIBS  opengl32.lib)

target_link_libraries(${TARGET_CORE_LIB_NAME}
                      ${TARGET_PLATFORM_LIB_NAME}
                      ${TARGET_RENDER_LIB_NAME}
                      ${LIBS}
                )

target_include_directories(${TARGET_CORE_LIB_NAME}
                     PUBLIC
                     ${LIB_DIR}/include
                     ${GLM_ROOT}
                    )

installAndExportLib(${TARGET_CORE_LIB_NAME})
