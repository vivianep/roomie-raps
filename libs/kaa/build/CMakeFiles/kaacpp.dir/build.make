# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Downloads/CppEventDemo/libs/kaa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Downloads/CppEventDemo/libs/kaa/build

# Include any dependencies generated for this target.
include CMakeFiles/kaacpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kaacpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kaacpp.dir/flags.make

# Object files for target kaacpp
kaacpp_OBJECTS =

# External object files for target kaacpp
kaacpp_EXTERNAL_OBJECTS = \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/event/registration/EndpointRegistrationManager.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/event/registration/UserTransport.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/event/EventManager.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/event/EventTransport.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/impl/DefaultOperationTcpChannel.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/impl/DefaultBootstrapChannel.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/connectivity/IPConnectivityChecker.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/http/HttpUrl.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/http/MultipartPostHttpRequest.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/http/HttpResponse.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/http/HttpClient.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/transport/HttpDataProcessor.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/impl/AbstractHttpChannel.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/utils/ThreadPool.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/ClientStatus.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/KaaDefaults.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/Kaa.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/KaaClient.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/logging/Log.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/logging/DefaultLogger.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/security/KeyUtils.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/security/RsaEncoderDecoder.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/common/EndpointObjectHash.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/profile/ProfileTransport.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/bootstrap/BootstrapManager.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/bootstrap/BootstrapTransport.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/SyncDataProcessor.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/RedirectionTransport.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/KaaChannelManager.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaTcpCommon.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaTcpParser.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/kaatcp/ConnackMessage.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaSyncResponse.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaTcpResponseProcessor.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/connectivity/PingConnectivityChecker.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/TransportProtocolIdConstants.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/channel/IPTransportInfo.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/failover/DefaultFailoverStrategy.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/context/AbstractExecutorContext.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/context/SimpleExecutorContext.cpp.o" \
"/home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp_o.dir/impl/KaaClientProperties.cpp.o"

libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/event/registration/EndpointRegistrationManager.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/event/registration/UserTransport.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/event/EventManager.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/event/EventTransport.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/impl/DefaultOperationTcpChannel.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/impl/DefaultBootstrapChannel.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/connectivity/IPConnectivityChecker.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/http/HttpUrl.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/http/MultipartPostHttpRequest.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/http/HttpResponse.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/http/HttpClient.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/transport/HttpDataProcessor.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/impl/AbstractHttpChannel.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/utils/ThreadPool.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/ClientStatus.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/KaaDefaults.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/Kaa.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/KaaClient.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/logging/Log.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/logging/DefaultLogger.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/security/KeyUtils.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/security/RsaEncoderDecoder.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/common/EndpointObjectHash.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/profile/ProfileTransport.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/bootstrap/BootstrapManager.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/bootstrap/BootstrapTransport.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/SyncDataProcessor.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/RedirectionTransport.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/KaaChannelManager.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaTcpCommon.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaTcpParser.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/kaatcp/ConnackMessage.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaSyncResponse.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/kaatcp/KaaTcpResponseProcessor.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/connectivity/PingConnectivityChecker.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/TransportProtocolIdConstants.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/channel/IPTransportInfo.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/failover/DefaultFailoverStrategy.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/context/AbstractExecutorContext.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/context/SimpleExecutorContext.cpp.o
libkaacpp.so: CMakeFiles/kaacpp_o.dir/impl/KaaClientProperties.cpp.o
libkaacpp.so: CMakeFiles/kaacpp.dir/build.make
libkaacpp.so: /usr/local/lib/libbotan-1.11.so
libkaacpp.so: /usr/local/lib/libavrocpp.so
libkaacpp.so: /usr/local/lib/libboost_log.so
libkaacpp.so: /usr/local/lib/libboost_system.so
libkaacpp.so: /usr/local/lib/libboost_thread.so
libkaacpp.so: /usr/lib/arm-linux-gnueabihf/libpthread.so
libkaacpp.so: CMakeFiles/kaacpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libkaacpp.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kaacpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kaacpp.dir/build: libkaacpp.so
.PHONY : CMakeFiles/kaacpp.dir/build

CMakeFiles/kaacpp.dir/requires:
.PHONY : CMakeFiles/kaacpp.dir/requires

CMakeFiles/kaacpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kaacpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kaacpp.dir/clean

CMakeFiles/kaacpp.dir/depend:
	cd /home/pi/Downloads/CppEventDemo/libs/kaa/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Downloads/CppEventDemo/libs/kaa /home/pi/Downloads/CppEventDemo/libs/kaa /home/pi/Downloads/CppEventDemo/libs/kaa/build /home/pi/Downloads/CppEventDemo/libs/kaa/build /home/pi/Downloads/CppEventDemo/libs/kaa/build/CMakeFiles/kaacpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kaacpp.dir/depend
