
project(rodzina)

set(HEDEAR_FILES Rodzic.h)
set(SOURCE_FILES Rodzic.cpp)

add_library(librodzina STATIC ${SOURCE_FILES})
target_include_directories(librodzina PUBLIC .)

add_executable(rodzina ${SOURCE_FILES} main.cpp)

target_link_libraries(rodzina librodzina)

