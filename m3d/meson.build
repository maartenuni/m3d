
m3d_sources = files(
    'Vector.cpp',
)

libm3d = library(
    'm3d',
    m3d_sources,
    install : true
)

m3d_dep = declare_dependency(
    link_with : libm3d,
    include_directories : root_inc
)
