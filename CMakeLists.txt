cmake_minimum_required(VERSION 3.20)
project(schoolHR)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall)

add_executable(schoolHR main.cpp People/Person.cpp People/Person.h People/Teacher.cpp People/Teacher.h People/HeadOfDepartment.cpp People/HeadOfDepartment.h People/Pupil.cpp People/Pupil.h JSON/Map.cpp JSON/Map.h JSON/JSONConvertible.cpp JSON/JSONConvertible.h Utils/MyUtils.h Date/Date.cpp Date/Date.h)
