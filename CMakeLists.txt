cmake_minimum_required(VERSION 3.31)
project(testingProj1)

set(CMAKE_CXX_STANDARD 23)


#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.txt
#        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


# Copy all .txt files from ./csv directory
file(GLOB TXT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/csv/*.csv")
foreach(txt_file ${TXT_FILES})
    file(COPY ${txt_file}
            DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/csv)
endforeach()

add_executable(testingProj1 main.cpp
        headers/csv/csv_reader.h
        headers/utils/status.h
        headers/utils/loop.h
        headers/csv/csv_structure.h
        headers/csv/csv_pair.h
        headers/csv/csv_map.h
)
