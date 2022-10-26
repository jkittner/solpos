from setuptools import Extension
from setuptools import setup

setup(
    ext_modules=[
        Extension(
            name='_solpos',
            sources=['solpos_cpy.c', 'solpos.c'],
        ),
    ],
)
