# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

cmake_minimum_required(VERSION 3.13)

# "C:\FreeRTOS-LTS\FreeRTOS\FreeRTOS-Kernel\portable\ThirdParty\GCC\RP2040\FreeRTOS_Kernel_import.cmake"
include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
include_directories(${PICO_SDK_PATH}/src/rp2_common/hardware_adc/include)
project(semaforo C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()


add_executable(semaforo
    semaforo.c
)

target_include_directories(semaforo PRIVATE ${CMAKE_CURRENT_LIST_DIR})    

target_link_libraries(semaforo pico_stdlib  FreeRTOS-Kernel FreeRTOS-Kernel-Heap4) 

pico_enable_stdio_uart(semaforo 0)
pico_enable_stdio_usb(semaforo 1)

pico_add_extra_outputs(semaforo)