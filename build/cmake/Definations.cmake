#thirdparty Libs
set(MODULES_ROOT ${ROOT_DIR}/modules)
set(GLAD_ROOT ${ROOT_DIR}/thirdparty/glad)
set(GLM_ROOT ${ROOT_DIR}/thirdparty/glm)
set(STB_IMAGE_ROOT ${ROOT_DIR}/thirdparty/stb_image)
set(GLFW_ROOT ${ROOT_DIR}/thirdparty/glfw)

# Libs Names
set(TARGET_PLATFORM_LIB_NAME "Platform")
set(TARGET_RENDER_LIB_NAME "Render")
set(TARGET_SAFAGA_LIB_NAME "Safaga")
set(TARGET_SAFAGA_JNI_LIB_NAME "Safaga-JNI")
set(TARGET_SAFAGA_JAVA_LIB_NAME "Safaga-java")

# PACKAGES DIRECTORY
set(SAFAGA_INSTALL_DIRECTORY    ${ROOT_DIR}/install)

# INTERNAL PACKAGES
set(SAFAGA_INTERNAL_PACKAGE_DIRECTORY    ${SAFAGA_INSTALL_DIRECTORY}/${SELECTED_PLATFORM}/Internal)

mark_as_advanced(SAFAGA_INSTALL_DIRECTORY)