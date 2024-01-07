cmake_minimum_required(VERSION 3.12)
project(RetEngine)

# Spaghetticode alert!

# Add the source files
# Incase the project ever gets bigger, we need to start listing our files manually.
file(GLOB Sources src/*.cpp)
file(GLOB Headers src/*.(h|hpp))



# Files for ImGui
# Switch to seperate project!
set(ImGui
    ${IMGUI_INCLUDE_DIRS}/imgui.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_demo.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_draw.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_impl_glfw.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_impl_opengl3.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_tables.cpp
    ${IMGUI_INCLUDE_DIRS}/imgui_widgets.cpp
    ${IMGUI_FILEDIALOG_INCLUDE_DIRS}/ImGuiFileDialog.cpp

)

set(Props 
    src/props/props.cpp
)

#Adds filters, these are not the real directories!
source_group("Source Files\\ImGui" FILES ${ImGui})
source_group("Source Headers\\" FILES ${Headers})
source_group("Source Files\\Engine" FILES ${Sources})
source_group("Source Files\\Engine\\Props" FILES ${Props})

find_package(Bullet CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(RetEngine ${Sources} ${ImGui} ${Props})

# Version 20 of C++
set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 20)

if(WIN32)
    # Tell that we are compiling for windows, anything else is Linux
    target_compile_definitions(RetEngine PRIVATE __WIN32__) # Win64 too!
endif()


# STB_Image and glm, Imgui , Bullet
target_include_directories(RetEngine PRIVATE ${LIB_INCLUDE_DIRS} ${IMGUI_INCLUDE_DIRS} ${IMGUI_FILEDIALOG_INCLUDE_DIRS} ${BULLET_INCLUDE_DIRS})

target_link_libraries(RetEngine PRIVATE ${BULLET_LIBRARIES})
target_link_libraries(RetEngine PRIVATE glfw)
target_link_libraries(RetEngine PRIVATE GLEW::GLEW)