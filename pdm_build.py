from setuptools import Extension

ext_modules = [Extension("talismans.hello", ["src/talismans/hellomodule.cpp"])]


def pdm_build_update_setup_kwargs(context, setup_kwargs):
    setup_kwargs.update(ext_modules=ext_modules)
