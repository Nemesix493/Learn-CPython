from setuptools import setup, find_packages, Extension

# Define the extension modules
extensions = [
    Extension(
        'CPythonLearn10',
        sources=['cpp/wrapper.cpp', 'cpp/get_pattern.cpp'],
        extra_compile_args=['-std=c++11'],
        extra_link_args=[],
    ),
]

setup(
    name='CPythonLearn10',
    packages=find_packages(),
    ext_modules=extensions,
    long_description='open(\'../README.md\').read()',
    long_description_content_type='text/markdown',
)
