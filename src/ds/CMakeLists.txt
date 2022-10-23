add_library(ds STATIC list.c dlist.c)

target_include_directories(ds PUBLIC "../../include")
