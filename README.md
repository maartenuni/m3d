# m3d a small toy to get aquinted with Pybind11

So before downloading this library, be warned that it exists because I wanted to learn something
about linear algebra and also how to bind C++ to python.

# m3d library is a small C++ library that contains a N dimensional vector NVec.
The vector is based on the std::vector and uses templates to get a vector of a
specific numerical type. The m3d::NVec has predefined types for (double precision)
floating point numbers.

# The pym3d contains a python package, with the vector module
The module should be importable as:
```python
import m3d.vector
# or
from m3d.vector import NVec
```
This python module only exposes the double precision variant of m3d::NVec

# The project may be build using meson (www.mesonbuild.com)

make sure you have installed meson
e.g.:
```
pip install meson
```
Using a terminal in which your compiler may be found you should navigate to the root of the
project and run
```console
meson setup build
meson compile -C build
```
Look up meson about how you may create debug and release builds, the project above is tested
on Ubuntu linux 20.04: