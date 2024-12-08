# CmakeLists.txt for a c++ library implementing a Go game

cmake_minimum_required(VERSION 3.0)

project(golib)

set(CMAKE_CXX_STANDARD 11)


add_library(golib SHARED
	"point.cpp" 
	"point.h" 
	"zoobrist.h" 
	"player.h" 
	"gostring.h" 
	"gostring.cpp" 
	"gamestate.cpp" 
	"gamestate.h" 
	"goboard.cpp"
	"goboard.h"
	"scoring.h"
	"scoring.cpp"
	"go.h"
	"go.cpp"
	"action.h"
)

target_include_directories(golib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(golib PUBLIC cxx_std_11)
set_target_properties(golib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)


install(TARGETS golib DESTINATION lib)
install(FILES goboard.h DESTINATION include)
