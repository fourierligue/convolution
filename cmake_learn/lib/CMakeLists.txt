cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME MyProject)


set(INCLUDE_DIR ../include)          # переменная - путь до заголовков 
set(SOURCE_DIR  ../src)              # путь до исполняемых файлов 
set(LIB_DIR ../lib)                    # путь до каталога с библиотеками 

set(SOURCE_CODE  main.cpp)    

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

project(${PROJECT_NAME} LANGUAGES CXX)

#-------------------------------------------------------
# Включение экспорта всех символов для создания динамической библиотеки
# в OC Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)   # создается ещё и .lib

 # Указываем пути к заголовочным файлам
include_directories(${INCLUDE_DIR})


# Получение списка исходных файлов
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

add_library(MyLib SHARED ${SOURCES})

# Указываем путь к каталогу include для заголовочных файлов
target_include_directories(MyLib  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#-------------------------------------------------------


