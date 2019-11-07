# Apps
project(Apps)

if(SAFAGA_PLATFORM_ANDROID)
    add_subdirectory(android)
elseif(SAFAGA_PLATFORM_WINDOWS)
    add_subdirectory(windows)
endif()