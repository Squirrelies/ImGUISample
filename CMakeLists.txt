cmake_minimum_required(VERSION 3.11)
project (ImGUISample)
#set(CMAKE_C_STANDARD 17) # 90, 99, 11, 17, 23
set(CMAKE_CXX_STANDARD 20)  # 98, 11, 14, 17, 20, 23, 26

# vcpkg dependencies.
find_package(imgui CONFIG REQUIRED)

# Required libraries we'll link for ImGUI.
find_library(D3D11_LIBRARY d3d11 REQUIRED)
find_library(D3DCOMPILER_LIBRARY d3dcompiler REQUIRED)
find_library(GDI32_LIBRARY Gdi32 REQUIRED)
find_library(DWMAPI_LIBRARY dwmapi REQUIRED)

# # Debug print of the locations we found.
# include(CMakePrintHelpers)
# cmake_print_variables(D3D11_LIBRARY D3DCOMPILER_LIBRARY GDI32_LIBRARY DWMAPI_LIBRARY)

add_compile_options(
    -Wall -Wextra -Wpedantic -Wno-overflow -Wno-unused-but-set-variable -Wno-unknown-pragmas -m64
    $<$<CONFIG:RELEASE>:-O3> # Optimize.
    $<$<CONFIG:RELEASE>:-s> # Debug symbol stripping.
    $<$<CONFIG:DEBUG>:-O0> # No optimizations.
    $<$<CONFIG:DEBUG>:-ggdb3> # Set symbol type.
    )
add_compile_definitions(
    $<$<CONFIG:RELEASE>:RELEASE>
    $<$<CONFIG:DEBUG>:DEBUG>
    )
add_link_options(
    -municode -static-libgcc -static-libstdc++ -static
)

target_link_libraries(imgui::imgui INTERFACE ${D3D11_LIBRARY} ${D3DCOMPILER_LIBRARY} ${GDI32_LIBRARY} ${DWMAPI_LIBRARY})
include_directories(include)

### Executable
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
