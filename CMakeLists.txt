cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

set(PROJECT_NAME Pascal-) # Создаем обычную локальную переменную с именем проекта.
project(${PROJECT_NAME}) # Название проекта.

# Определяем переменные с именами приложений и библиотек.
set(TEST TEST)
set(skip_list skip_list)
set(priority_queue priority_queue)
set(d_heaps d_heaps)


# Создаем переменную для типов сборки и устанавливаем значения Debug и Release.
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

# Если не указан тип сборки, устанавливаем Release по умолчанию.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Включаем папку с заголовочными файлами gtest.
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
# Добавляем субдиректорию для сборки gtest.
add_subdirectory(gtest)

# Включаем папки с заголовочными файлами и библиотеками для остальных проектов.
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/skip_list
    ${CMAKE_CURRENT_SOURCE_DIR}/priority_queue
    ${CMAKE_CURRENT_SOURCE_DIR}/d_heaps
)

# Добавляем субдиректории для сборки остальных проектов.
add_subdirectory(TEST)
add_subdirectory(skip_list)
add_subdirectory(priority_queue)
add_subdirectory(d_heaps)

