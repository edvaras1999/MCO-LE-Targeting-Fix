cmake_minimum_required(VERSION 3.10)
project(MCO_LE_Targeting_Fix)

# Configuração para C++ moderno compatível com LE (32-bit)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Adiciona o arquivo fonte do projeto
add_library(${PROJECT_NAME} SHARED src/main.cpp)

# Configura a pasta onde a DLL compilada será salva
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Release"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Release"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Release"
)
