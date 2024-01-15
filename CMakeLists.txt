cmake_minimum_required(VERSION 3.12)
project(RetEngine)

# Spaghetticode alert!

# Add the source files
# Incase the project ever gets bigger, we need to start listing our files manually.
file(GLOB Sources src/*.cpp)
file(GLOB Headers src/*.(h|hpp))

set(Props 
    src/props/props.cpp
)

add_subdirectory(thirdparty/ImGui)

#Adds filters, these are not the real directories!
source_group("Source Headers\\" FILES ${Headers})
source_group("Source Files\\Engine" FILES ${Sources})
source_group("Source Files\\Engine\\Props" FILES ${Props})

find_package(Bullet CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(RetEngine ${Sources} ${Props})

# Version 20 of C++
set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 20)

if(WIN32)
    # Tell that we are compiling for windows, anything else is Linux
    target_compile_definitions(RetEngine PRIVATE __WIN32__) # Win64 too!
endif()


# STB_Image and glm, Imgui , Bullet
target_include_directories(RetEngine PRIVATE ${LIB_INCLUDE_DIRS} ${BULLET_INCLUDE_DIRS})

target_link_libraries(RetEngine PRIVATE ${BULLET_LIBRARIES})
target_link_libraries(RetEngine PRtarget_link_libraries(RetEngine PRIVATE GLEW::GLEW ImGuiLayer)