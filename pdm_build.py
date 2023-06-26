from setuptools import Extension
from pdm.backend.hooks.base import Context


def pdm_build_update_setup_kwargs(context: Context, setup_kwargs: dict):
    if context.target != "sdist":
        ext_modules = [
            Extension(
                "talismans.hello",
                ["src/talismans/hellomodule.cpp", "src/talismans/example.cpp"],
            )
        ]
        setup_kwargs.update(
            setup_requires=["nuitka", "pybind11"],
            build_with_nuitka=True,
            ext_modules=ext_modules,
        )
