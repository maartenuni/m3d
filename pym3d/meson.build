
python_exe = python_mod.find_installation('python3')

pybind11_include_flags = run_command(
    python_exe,
    '-m',
    'pybind11',
    '--includes',
    capture : true
).stdout().strip().split()

pybind11_include_paths = []
foreach flag : pybind11_include_flags
    pybind11_include_paths += (flag.substring(2))
endforeach

pybind11_dep = declare_dependency(
    include_directories : pybind11_include_paths
)

pyvec_sources = files(
    'pyvec.cpp',
    'py_nvec.cpp',
    'py_vector.cpp'
)

configure_file(
    input : '__init__.py.in',
    output : '__init__.py',
    copy : true
)

python_exe.extension_module (
    'vector',
    pyvec_sources,
    dependencies : [m3d_dep, pybind11_dep]
)


