from setuptools import Extension
from setuptools import setup

setup(
    name='solpos',
    version='0.1.0',
    ext_modules=[Extension(name='_solpos', sources=['main.c', 'solpos.c'])],
)
