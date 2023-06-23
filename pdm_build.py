from setuptools import Extension
from mypyc.build import mypycify
from pdm.backend.hooks.base import Context


def pdm_build_update_setup_kwargs(context: Context, setup_kwargs: dict):
    if context.target == "wheel":
        ext_modules = mypycify(
            [
                "src/talismans/__init__.py",
                "src/talismans/compute.py",
            ]
        )
        ext_modules.extend(
            [
                Extension(
                    "talismans.hello",
                    ["src/talismans/hellomodule.cpp", "src/talismans/example.cpp"],
                )
            ]
        )
        setup_kwargs.update(ext_modules=ext_modules)
