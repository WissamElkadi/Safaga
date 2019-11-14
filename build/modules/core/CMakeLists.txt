project(Core)

set(LIB_DIR ${ROOT_DIR}/modules/core)

# Source Files
set(LIB_SRC
    ${LIB_DIR}/src/BoundingBox.cpp
    ${LIB_DIR}/src/Camera.cpp
    ${LIB_DIR}/src/CameraNode.cpp
    ${LIB_DIR}/src/DirectionalLight.cpp
    ${LIB_DIR}/src/GroupNode.cpp
    ${LIB_DIR}/src/LightNode.cpp
    ${LIB_DIR}/src/MaterialNode.cpp
    ${LIB_DIR}/src/Mesh.cpp
    ${LIB_DIR}/src/Node.cpp
    ${LIB_DIR}/src/PointLight.cpp
    ${LIB_DIR}/src/Renderable.cpp
    ${LIB_DIR}/src/RenderVisitor.cpp
    ${LIB_DIR}/src/SamplerNode.cpp
    ${LIB_DIR}/src/ShaderNode.cpp
    ${LIB_DIR}/src/SpotLight.cpp
    ${LIB_DIR}/src/SwitchNode.cpp
    ${LIB_DIR}/src/TextureNode.cpp
    ${LIB_DIR}/src/TransformNode.cpp
)

# Include Files
set(LIB_INC
    ${LIB_DIR}/include/BoundingBox.h
    ${LIB_DIR}/include/Camera.h
    ${LIB_DIR}/include/CameraNode.h
    ${LIB_DIR}/include/DirectionalLight.h
    ${LIB_DIR}/include/GroupNode.h
    ${LIB_DIR}/include/INodeVisitor.h
    ${LIB_DIR}/include/LightNode.h
    ${LIB_DIR}/include/MaterialNode.h
    ${LIB_DIR}/include/MathUtils.h
    ${LIB_DIR}/include/Mesh.h
    ${LIB_DIR}/include/Node.h
    ${LIB_DIR}/include/PointLight.h
    ${LIB_DIR}/include/Renderable.h
    ${LIB_DIR}/include/RenderVisitor.h
    ${LIB_DIR}/include/SamplerNode.h
    ${LIB_DIR}/include/ShaderNode.h
    ${LIB_DIR}/include/SpotLight.h
    ${LIB_DIR}/include/SwitchNode.h
    ${LIB_DIR}/include/TextureNode.h
    ${LIB_DIR}/include/TransformNode.h
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
