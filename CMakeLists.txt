cmake_minimum_required(VERSION 3.12)
project(RetEngine)

set(VCPKG_LIBRARY_LINKAGE static)

# Add your source files
set(SOURCES
    src/animator.cpp
    src/camera.cpp
    src/files.cpp
    src/game.cpp
    src/gen_world.cpp
    src/input_events.cpp
    src/main.cpp
    src/mesh.cpp
    src/mesh_gen.cpp
    src/mesh_instance.cpp
    src/mesh_loader.cpp
    src/node.cpp
    src/obj_loader.cpp
    src/physics_object.cpp
    src/player.cpp
    src/setup_dynamics_world.cpp
    src/shader.cpp
    src/shaders.cpp
    src/stb_impl.cpp
    src/texture.cpp
    src/window.cpp
)

find_package(Bullet CONFIG REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(imgui REQUIRED)

add_executable(RetEngine ${SOURCES})

#Version 20 of C++
set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 20)

if(WIN32)
    # Tell that we are compiling for windows
    target_compile_definitions(RetEngine PRIVATE __WIN32__) # Win64 too!
endif()

# STB_Image and glm, ImGuiFileDialog 
target_include_directories(RetEngine PRIVATE ${LIB_INCLUDE_DIRS})

# Bullet
target_include_directories(RetEngine PRIVATE ${BULLET_INCLUDE_DIRS})


target_link_libraries(RetEngine PRIVATE ${BULLET_LIBRARIES})
target_link_libraries(RetEngine PRIVATE imgui::imgui)
target_link_libraries(RetEngine PRIVATE glfw)
target_link_libraries(RetEngine PRIVATE GLEW::GLEW)