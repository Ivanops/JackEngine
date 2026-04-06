# CMakeList.txt : CMake project for JackEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("JackEngine")

# Add source to this project's executable.
add_executable (JackEngine "JackEngine.cpp" "JackEngine.h" "engine/core/logger.cpp" "engine/core/logger.h" "engine/core/core.h" "engine/core/timer.h" "engine/core/timer.cpp" "engine/core/application.h" "engine/core/application.cpp" "engine/platform/window.h" "engine/platform/window.cpp")

# Add GLFW
add_subdirectory(third_party/glfw/)

# Add GLAD
add_library(glad third_party/glad/src/glad.c)

target_include_directories(glad PUBLIC third_party/glad/include)

target_link_libraries(JackEngine PRIVATE
	glfw
	glad
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JackEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
