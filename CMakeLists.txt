cmake_minimum_required(VERSION 3.12)
project(RetEngine)



# Add your source files
set(SOURCES
    src/animator.cpp
    src/camera.cpp
    src/files.cpp
    src/Framebuffer.cpp
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

# Files for ImGui
set(ImGui
    ${IMGUI_INCLUDE_DIRS}/imgui.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_demo.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_draw.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_impl_glfw.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_impl_opengl3.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_tables.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_widgets.cpp
    ${IMGUIFILE_INCLUDE_DIRS}/ImGuiFileDialog.cpp
)

set(Props 
    src/props/props.cpp
)


source_group("Source Files\\ImGui" FILES ${ImGui})
source_group("Source Files\\Engine" FILES ${SOURCES})
source_group("Source Files\\Engine\\Props" FILES ${Props})


find_package(Bullet CONFIG REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)


add_executable(RetEngine ${SOURCES} ${ImGui} ${Props})

#Version 20 of C++
set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 20)

if(WIN32)
    # Tell that we are compiling for windows
    target_compile_definitions(RetEngine PRIVATE __WIN32__) # Win64 too!
endif()


# STB_Image and glm, Imgui , Bullet
target_include_directories(RetEngine PRIVATE ${LIB_INCLUDE_DIRS} ${IMGUI_INCLUDE_DIRS} ${BULLET_INCLUDE_DIRS} ${IMGUIFILE_INCLUDE_DIRS})

target_link_libraries(RetEngine PRIVATE ${BULLET_LIBRARIES})
target_link_libraries(RetEngine PRIVATE glfw)
target_link_libraries(RetEngine PRIVATE GLEW::glew_s)