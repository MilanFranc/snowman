
set(CMAKE_AUTOMOC ON)

macro(qt4_wrap_cpp)
endmacro()

set(QT_LIBRARIES Qt5::Core Qt5::Widgets)

if(QT_NAMESPACE)
    add_definitions(-DQT_NAMESPACE=${QT_NAMESPACE})
endif()

# Link against qtmain.lib automatically.
cmake_policy(SET CMP0020 NEW)

set(SOURCES
    main.cpp
)

add_executable(nocode ${SOURCES})
target_link_libraries(nocode nc ${Boost_LIBRARIES} ${QT_LIBRARIES})

if (NOT ${IDA_PLUGIN_ENABLED})
    install(TARGETS nocode RUNTIME DESTINATION bin)
    if(WIN32 AND NOT ${NC_QT5})
        install_qt4_executable("bin/nocode.exe")
    endif()
endif()

# vim:set et sts=4 sw=4 nospell:
