cmake_minimum_required(VERSION 3.12)

# Defina o nome do seu projeto
project(pico_ws2812_project)

# Defina o caminho para o SDK do Raspberry Pi Pico
set(PICO_SDK_PATH /caminho/para/pico-sdk)

# Inicie o SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

# Defina seu executável e arquivos de código-fonte
add_executable(pico_ws2812_project
    src/Atividade-UN4CAP2.c
    src/ws2812.c  # Se você baixou a biblioteca WS2812, adicione-a aqui
)

# Link o SDK do Raspberry Pi Pico
target_link_libraries(pico_ws2812_project pico_stdlib hardware_pwm)

# Defina as definições de compilação
pico_add_extra_outputs(pico_ws2812_project)
