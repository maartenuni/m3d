


executable(
    'nvec.test',
    'nvec.test.cpp',
    include_directories : root_inc,
    dependencies : [m3d_dep]
)

executable(
    'vector.test',
    'vector.test.cpp',
    include_directories : root_inc,
    dependencies : [m3d_dep]
)

doctest_dep = dependency('doctest', fallback : ['doctest', 'doctest_dep'])

unittest_sources = files(
    'unittest.cpp',
    'NVecTest.cpp',
    'VectorTest.cpp',
)

unittest = executable (
    'unit-test',
    unittest_sources,
    dependencies : [doctest_dep, m3d_dep]
)

test('doctest unittest', unittest)

