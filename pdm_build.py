from setuptools import Extension
from mypyc.build import mypycify


ext_modules = mypycify(
    [
        "src/talismans/__init__.py",
        "src/talismans/compute.py",
    ]
)
ext_modules.extend(
    [Extension("talismans.hello", ["src/talismans/hellomodule.cpp", "src/talismans/example.cpp"])]
)


def pdm_build_update_setup_kwargs(context, setup_kwargs):
    setup_kwargs.update(ext_modules=ext_modules)
