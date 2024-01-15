cmake_minimum_required(VERSION 3.5)

project(ImGuiLayer)

add_library(ImGuiLayer) 

target_sources(ImGuiLayer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking/imgui_impl_opengl3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiFileDialog/ImGuiFileDialog.cpp
)

find_package(GLEW REQUIRED)

target_include_directories(ImGuiLayer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ImGuiDocking" "${CMAKE_CURRENT_SOURCE_DIR}/ImGuiFileDialog")
target_link_libraries(ImGuiLayer PUBLIC glfw GLEW::GLEW)

if(UNIX)
    target_compile_options(ImGuiLayer PUBLIC "-Wno-unknown-pragmas")
endif()
