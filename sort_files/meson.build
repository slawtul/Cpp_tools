project('sort_files','cpp',version:'1.0.0',default_options:['warning_level=3','cpp_std=c++2a'])
lib=static_library('lib',dependencies:[],sources:['src/sort_files.h','src/sort_files.cpp'])
dep=declare_dependency(link_with:lib)
executable(meson.project_name(),'src/sort_files_run.cpp',dependencies:[dep],install:false)
