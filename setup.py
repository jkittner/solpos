import platform
import sys

from setuptools import Extension
from setuptools import setup

if platform.python_implementation() == 'CPython':
    try:
        import wheel.bdist_wheel
    except ImportError:
        cmdclass = {}
    else:
        class bdist_wheel(wheel.bdist_wheel.bdist_wheel):
            def finalize_options(self) -> None:
                self.py_limited_api = f'cp3{sys.version_info[1]}'
                super().finalize_options()

        cmdclass = {'bdist_wheel': bdist_wheel}

setup(
    ext_modules=[
        Extension(
            name='_solpos',
            sources=['solpos_cpy.c', 'solpos.c'],
            py_limited_api=True,
            define_macros=[('Py_LIMITED_API', None)],
        ),
    ],
    cmdclass=cmdclass,
)
