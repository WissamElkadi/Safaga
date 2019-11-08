project(RenderApp)

set(APP_DIR ${ROOT_DIR}/apps/render)

# Source Files
set(LIB_SRC
    ${APP_DIR}/OpenGL.cpp
    ${APP_DIR}/main.cpp
)

# Include Files
set(LIB_INC
    ${APP_DIR}/OpenGL.h
)

# Source files grouping in IDE
source_group("include" FILES ${LIB_INC})
source_group("src" FILES ${LIB_SRC})

if(SAFAGA_PLATFORM_WINDOWS)

    add_executable(${TARGET_RENDER_APP_NAME}   ${LIB_SRC} ${LIB_INC})

    link_directories(${ROOT_DIR}/bin/${SELECTED_PLATFORM}/${TARGET_ARCH}
                     )

    # add_library(RenderLib SHARED IMPORTED)
    # set_property(TARGET RenderLib PROPERTY IMPORTED_LOCATION ${TARGET_RENDER_LIB_NAME})
    # set_property(TARGET RenderLib PROPERTY IMPORTED_IMPLIB ${TARGET_RENDER_LIB_NAME})

endif()

set(LIBS  opengl32.lib glfw3.lib)

target_link_libraries(${TARGET_RENDER_APP_NAME}
                      ${TARGET_PLATFORM_LIB_NAME}
                      ${TARGET_RENDER_LIB_NAME}
                      ${LIBS}
                )

target_link_directories(${TARGET_RENDER_APP_NAME}
                       PUBLIC
                       ${GLFW_ROOT}/lib  
)

target_include_directories(${TARGET_RENDER_APP_NAME}
                     PUBLIC
                     ${LIB_DIR}/include
                     ${GLM_ROOT}
                     ${GLFW_ROOT}/include
                    )
