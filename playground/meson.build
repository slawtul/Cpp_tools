project('playground','cpp',version:'1.0.0',default_options:['warning_level=3','cpp_std=c++2a'])
lib=static_library('lib',dependencies:[],sources:['src/bank.h','src/simple_struct.h','src/playground.h','src/playground.cpp'])
dep=declare_dependency(link_with:lib)
executable(meson.project_name(),'src/playground_run.cpp',dependencies:[dep],install:false)
