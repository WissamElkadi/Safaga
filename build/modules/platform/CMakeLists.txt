project(Platform)

set(LIB_DIR ${ROOT_DIR}/modules/platform)

# Source Files
set(LIB_SRC
    ${LIB_DIR}/src/FileReader.cpp
    ${LIB_DIR}/src/stb_image.cpp
)

# Include Files
set(LIB_INC
    ${LIB_DIR}/include/FileReader.h
)

# Source files grouping in IDE
source_group("include" FILES ${LIB_INC})
source_group("src" FILES ${LIB_SRC})

if(SAFAGA_PLATFORM_ANDROID)

    add_library(${TARGET_PLATFORM_LIB_NAME} SHARED ${LIB_SRC} ${LIB_INC})

elseif(SAFAGA_PLATFORM_WINDOWS)

    link_directories(${ROOT_DIR}/bin/${SELECTED_PLATFORM}/${TARGET_ARCH}
                )

    add_library(${TARGET_PLATFORM_LIB_NAME} STATIC ${LIB_SRC} ${LIB_INC})

endif()

target_include_directories(${TARGET_PLATFORM_LIB_NAME}
                     PUBLIC
                     ${LIB_DIR}/include
                     ${STB_IMAGE_ROOT}
                    )

installAndExportLib(${TARGET_PLATFORM_LIB_NAME})
