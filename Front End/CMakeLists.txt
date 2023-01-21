cmake_minimum_required(VERSION 3.22)
project(VirtualBank)

set(CMAKE_CXX_STANDARD 23)
link_libraries(ws2_32 wsock32)

add_executable(
        Server
        Server/Communicator.cpp
        Server/Communicator.h
        Server/main2.cpp
        Server/MainSocket.cpp
        Server/MainSocket.h
        Server/MainServer.cpp
        Server/MainServer.h
        )
add_executable(
        Client
        Client/Communicator.cpp
        Client/Communicator.h
        Client/main2.cpp
        Client/MainSocket.cpp
        Client/MainSocket.h
        Client/MainClient.cpp
        Client/MainClient.h
)

