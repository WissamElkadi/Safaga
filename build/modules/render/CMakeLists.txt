project(Render)

set(LIB_DIR ${ROOT_DIR}/modules/render)

# Source Files
set(LIB_SRC
    ${LIB_DIR}/src/Buffer.cpp
    ${LIB_DIR}/src/Device.cpp
    ${LIB_DIR}/src/Drawer.cpp
    ${LIB_DIR}/src/RenderPipelineState.cpp
    ${LIB_DIR}/src/Sampler.cpp
    ${LIB_DIR}/src/Shader.cpp
    ${LIB_DIR}/src/Texture.cpp
    ${LIB_DIR}/src/Uniform.hpp
    ${LIB_DIR}/src/VertexBuffer.cpp
    ${ROOT_DIR}/thirdparty/glad/src/glad.c
)

# Include Files
set(LIB_INC
    ${LIB_DIR}/include/Buffer.h
    ${LIB_DIR}/include/DataStructure.h
    ${LIB_DIR}/include/Device.h
    ${LIB_DIR}/include/Drawer.h
    ${LIB_DIR}/include/Mapper.h
    ${LIB_DIR}/include/RenderPieplineDescriptor.h
    ${LIB_DIR}/include/RenderPipelineState.h
    ${LIB_DIR}/include/Sampler.h
    ${LIB_DIR}/include/SamplerDescriptor.h
    ${LIB_DIR}/include/Shader.h
    ${LIB_DIR}/include/Texture.h
    ${LIB_DIR}/include/TextureDescriptor.h
    ${LIB_DIR}/include/Types.h
    ${LIB_DIR}/include/Uniform.h
    ${LIB_DIR}/include/UniformBuffer.h
    ${LIB_DIR}/include/VertexBuffer.h
    ${LIB_DIR}/include/VertexDescriptor.h
)

# Source files grouping in IDE
source_group("include" FILES ${LIB_INC})
source_group("src" FILES ${LIB_SRC})

if(SAFAGA_PLATFORM_ANDROID)

    add_library(${TARGET_RENDER_LIB_NAME} SHARED ${LIB_SRC} ${LIB_INC})

elseif(SAFAGA_PLATFORM_WINDOWS)

    link_directories(${ROOT_DIR}/bin/${SELECTED_PLATFORM}/${TARGET_ARCH}
                )

    add_library(${TARGET_RENDER_LIB_NAME} SHARED ${LIB_SRC} ${LIB_INC})

    add_library(PlatformLib SHARED IMPORTED)
    set_property(TARGET PlatformLib PROPERTY IMPORTED_LOCATION ${TARGET_PLATFORM_LIB_NAME})
    set_property(TARGET PlatformLib PROPERTY IMPORTED_IMPLIB ${TARGET_PLATFORM_LIB_NAME})

endif()

set(LIBS  opengl32.lib)

target_link_libraries(${TARGET_RENDER_LIB_NAME}
                      ${TARGET_PLATFORM_LIB_NAME}
                      ${LIBS}
                )

target_include_directories(${TARGET_RENDER_LIB_NAME}
                     PUBLIC
                     ${LIB_DIR}/include
                     ${GLAD_ROOT}/include
                     ${GLM_ROOT}
                     ${GLFW}/include
                    )

installAndExportLib(${TARGET_RENDER_LIB_NAME})
