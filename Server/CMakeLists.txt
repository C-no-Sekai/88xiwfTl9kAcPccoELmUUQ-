cmake_minimum_required(VERSION 3.22)
project(SocketWrapperCpp)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")
include_directories(DataBaseCpp_Wrapper includes)
find_library(SQL sqlite3.h)
link_libraries(ws2_32 wsock32)
add_executable(SocketWrapperCpp
        EncDec.h
        EncDec.cpp
        main.cpp
        Server.h
        Server.cpp
        BaseSocket.h
        BaseSocket.cpp
        Linker.cpp
        Linker.h
        ConnectionHandler.cpp
        ConnectionHandler.h
        ClientsHandler.cpp
        ClientsHandler.h
        includes/sqlite3.c
        dbHandler.h
        dbHandler.cpp
        Accounts.cpp
        Accounts.h
        )
