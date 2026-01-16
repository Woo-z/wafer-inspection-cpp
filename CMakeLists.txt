cmake_minimum_required(VERSION 3.14)
project(WaferInspection)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 14)

# OpenCV 위치 찾기
set(OpenCV_DIR "C:/opencv/build")
find_package(OpenCV REQUIRED)

# 헤더 파일 경로 포함
include_directories(${OpenCV_INCLUDE_DIRS} include)

# 실행 파일 생성
add_executable(WaferApp src/main.cpp)

# 라이브러리 연결
target_link_libraries(WaferApp ${OpenCV_LIBS})
