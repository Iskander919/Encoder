cmake_minimum_required(VERSION 3.16)

project(Security LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)

add_executable(Security
  src/main.cpp
  inc/mainwindow.h
  src/mainwindow.cpp
  src/signupdialog.cpp
  inc/signupdialog.h
  inc/signindialog.h
  src/signindialog.cpp
  database_driver/dbdriver.cpp
  database_driver/dbdriver.h
  database_driver/dbconfig.h

)
target_link_libraries(Security PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Security PRIVATE Qt6::Sql)

target_include_directories(Security PRIVATE inc database_driver)

include(GNUInstallDirs)
install(TARGETS Security
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
