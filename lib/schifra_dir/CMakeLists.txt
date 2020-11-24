cmake_minimum_required(VERSION 3.12)

project(schifra)

add_library(${PROJECT_NAME} 
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_ecc_traits.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_error_processes.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_galois_field.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_galois_field_element.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_galois_field_polynomial.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_block.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_codec_validator.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_decoder.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_encoder.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_file_decoder.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_file_encoder.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_product_code.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_speed_evaluator.hpp
    ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_sequential_root_generator_polynomial_creator.hpp
)

target_sources(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_ecc_traits.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_error_processes.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_galois_field.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_galois_field_element.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_galois_field_polynomial.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_block.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_codec_validator.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_decoder.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_encoder.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_file_decoder.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_file_encoder.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_product_code.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_reed_solomon_speed_evaluator.hpp
        ${CMAKE_CURRENT_LIST_DIR}/schifra/schifra_sequential_root_generator_polynomial_creator.hpp
)

add_compile_options(-ansi -pedantic-errors -Wall -Wextra -Werror -Wno-long-long -O3 -lstdc++ -lm)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/schifra
)
