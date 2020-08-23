cmake_minimum_required(VERSION 3.15)
project(libft_new C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

#add_library(libft_new data_structures/list/list.h data_structures/data_structures.h)

#add_executable(main $<TARGET_OBJECTS:libft_new> library.c)
add_executable(main1 library.c sources/memory_manager/memory_manager_internal.h includes/logger.h sources/logger/logger_file.c sources/logger/logger_out.c sources/system/sys_exit.c sources/system/sys_at_exit.c sources/time/time_internal.h sources/time/time_get.c sources/time/time_utils.c)