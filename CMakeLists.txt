cmake_minimum_required(VERSION 3.1)
project (Cpp_based_FCN)
include(CheckFunctionExists)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(include Breast_Cancer_Data)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)


add_library(bce src/bce_loss.cpp)
target_link_libraries (bce m Eigen3::Eigen)
add_library(ll src/linear_layer.cpp)
target_link_libraries (ll m Eigen3::Eigen)
add_library(csv src/read_csv.cpp)
target_link_libraries (csv Eigen3::Eigen)
add_library(relu src/relu.cpp)
target_link_libraries (relu Eigen3::Eigen)
add_library(sig src/sigmoid.cpp)
target_link_libraries (sig m Eigen3::Eigen)
add_library(model src/model.cpp)
target_link_libraries (model sig relu ll bce Eigen3::Eigen)
add_library(parser src/read_csv.cpp)
target_link_libraries (parser Eigen3::Eigen)

add_executable (train src/main.cpp)
target_link_libraries (train Eigen3::Eigen model parser)


