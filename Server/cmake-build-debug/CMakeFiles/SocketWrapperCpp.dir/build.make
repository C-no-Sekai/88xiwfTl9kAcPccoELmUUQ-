# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "X:\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "X:\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = X:\server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = X:\server\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SocketWrapperCpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SocketWrapperCpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SocketWrapperCpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SocketWrapperCpp.dir/flags.make

CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj: ../EncDec.cpp
CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\EncDec.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\EncDec.cpp.obj -c X:\server\EncDec.cpp

CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\EncDec.cpp > CMakeFiles\SocketWrapperCpp.dir\EncDec.cpp.i

CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\EncDec.cpp -o CMakeFiles\SocketWrapperCpp.dir\EncDec.cpp.s

CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj: ../main.cpp
CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\main.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\main.cpp.obj -c X:\server\main.cpp

CMakeFiles/SocketWrapperCpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/main.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\main.cpp > CMakeFiles\SocketWrapperCpp.dir\main.cpp.i

CMakeFiles/SocketWrapperCpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/main.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\main.cpp -o CMakeFiles\SocketWrapperCpp.dir\main.cpp.s

CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj: ../Server.cpp
CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\Server.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\Server.cpp.obj -c X:\server\Server.cpp

CMakeFiles/SocketWrapperCpp.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/Server.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\Server.cpp > CMakeFiles\SocketWrapperCpp.dir\Server.cpp.i

CMakeFiles/SocketWrapperCpp.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/Server.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\Server.cpp -o CMakeFiles\SocketWrapperCpp.dir\Server.cpp.s

CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj: ../BaseSocket.cpp
CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\BaseSocket.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\BaseSocket.cpp.obj -c X:\server\BaseSocket.cpp

CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\BaseSocket.cpp > CMakeFiles\SocketWrapperCpp.dir\BaseSocket.cpp.i

CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\BaseSocket.cpp -o CMakeFiles\SocketWrapperCpp.dir\BaseSocket.cpp.s

CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj: ../Linker.cpp
CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\Linker.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\Linker.cpp.obj -c X:\server\Linker.cpp

CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\Linker.cpp > CMakeFiles\SocketWrapperCpp.dir\Linker.cpp.i

CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\Linker.cpp -o CMakeFiles\SocketWrapperCpp.dir\Linker.cpp.s

CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj: ../ConnectionHandler.cpp
CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\ConnectionHandler.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\ConnectionHandler.cpp.obj -c X:\server\ConnectionHandler.cpp

CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\ConnectionHandler.cpp > CMakeFiles\SocketWrapperCpp.dir\ConnectionHandler.cpp.i

CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\ConnectionHandler.cpp -o CMakeFiles\SocketWrapperCpp.dir\ConnectionHandler.cpp.s

CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj: ../ClientsHandler.cpp
CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\ClientsHandler.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\ClientsHandler.cpp.obj -c X:\server\ClientsHandler.cpp

CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\ClientsHandler.cpp > CMakeFiles\SocketWrapperCpp.dir\ClientsHandler.cpp.i

CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\ClientsHandler.cpp -o CMakeFiles\SocketWrapperCpp.dir\ClientsHandler.cpp.s

CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj: CMakeFiles/SocketWrapperCpp.dir/includes_C.rsp
CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj: ../includes/sqlite3.c
CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj -MF CMakeFiles\SocketWrapperCpp.dir\includes\sqlite3.c.obj.d -o CMakeFiles\SocketWrapperCpp.dir\includes\sqlite3.c.obj -c X:\server\includes\sqlite3.c

CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E X:\server\includes\sqlite3.c > CMakeFiles\SocketWrapperCpp.dir\includes\sqlite3.c.i

CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S X:\server\includes\sqlite3.c -o CMakeFiles\SocketWrapperCpp.dir\includes\sqlite3.c.s

CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj: ../dbHandler.cpp
CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\dbHandler.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\dbHandler.cpp.obj -c X:\server\dbHandler.cpp

CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\dbHandler.cpp > CMakeFiles\SocketWrapperCpp.dir\dbHandler.cpp.i

CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\dbHandler.cpp -o CMakeFiles\SocketWrapperCpp.dir\dbHandler.cpp.s

CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/flags.make
CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/includes_CXX.rsp
CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj: ../Accounts.cpp
CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj: CMakeFiles/SocketWrapperCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj -MF CMakeFiles\SocketWrapperCpp.dir\Accounts.cpp.obj.d -o CMakeFiles\SocketWrapperCpp.dir\Accounts.cpp.obj -c X:\server\Accounts.cpp

CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.i"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\server\Accounts.cpp > CMakeFiles\SocketWrapperCpp.dir\Accounts.cpp.i

CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.s"
	"X:\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\server\Accounts.cpp -o CMakeFiles\SocketWrapperCpp.dir\Accounts.cpp.s

# Object files for target SocketWrapperCpp
SocketWrapperCpp_OBJECTS = \
"CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj" \
"CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj" \
"CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj"

# External object files for target SocketWrapperCpp
SocketWrapperCpp_EXTERNAL_OBJECTS =

SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/EncDec.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/main.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/Server.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/BaseSocket.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/Linker.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/ConnectionHandler.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/ClientsHandler.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/includes/sqlite3.c.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/dbHandler.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/Accounts.cpp.obj
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/build.make
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/linklibs.rsp
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/objects1.rsp
SocketWrapperCpp.exe: CMakeFiles/SocketWrapperCpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=X:\server\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable SocketWrapperCpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SocketWrapperCpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SocketWrapperCpp.dir/build: SocketWrapperCpp.exe
.PHONY : CMakeFiles/SocketWrapperCpp.dir/build

CMakeFiles/SocketWrapperCpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SocketWrapperCpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SocketWrapperCpp.dir/clean

CMakeFiles/SocketWrapperCpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" X:\server X:\server X:\server\cmake-build-debug X:\server\cmake-build-debug X:\server\cmake-build-debug\CMakeFiles\SocketWrapperCpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SocketWrapperCpp.dir/depend

