cmake_minimum_required(VERSION 3.10)
project(SQL-File-Manager)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include /usr/include/cppconn)  # adjust this path if your header files are located elsewhere

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the MySQL Connector/C++ library directly
target_link_libraries(${PROJECT_NAME} mysqlcppconn)
