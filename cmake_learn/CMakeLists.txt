cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME MyProject)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)          # переменная - путь до заголовков 

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)                    # путь до каталога с библиотеками 


set(SOURCE_CODE  main.cpp)    

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

project(${PROJECT_NAME} LANGUAGES CXX)

#-------------------------------------------------------

# #путь до lib
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})

 # Указываем пути к заголовочным файлам
include_directories(${INCLUDE_DIR})

#-------------------------------------------------------
add_subdirectory(./lib) # тут создались библиотеки 

# исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCE_CODE})   

# Подключаем динамическую библиотеку
target_link_libraries(${PROJECT_NAME} MyLib)

#-----------------------------------------------

# обычное копирование(file(COPY))т.к. во время сборки библиотеки ещё не созданы и перемещать нечего
# Копируем библиотеки после сборки проекта 
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy                         # -E copy <file>... <destination>
    ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/Debug/MyLib.dll    #  или  $<TARGET_FILE_DIR:MyLib>/MyLib.dll // <TARGET_FILE_DIR:MyLib>
                                                             #<TARGET_FILE_DIR:MyLib> - получения каталога, Sв котором находится файл сборки цели с именем "MyLib"
    ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/Debug/MyLib.lib    # $<TARGET_LINKER_FILE:MyLib>
    $<TARGET_FILE_DIR:${PROJECT_NAME}>       # каталог сборки цели, соответствующей проекту                  
    COMMENT "...Successful copying .dll/.lib"
)