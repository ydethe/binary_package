from setuptools import Extension, setup, find_packages


setup(
    name="talismans",
    use_scm_version=True,
    build_with_nuitka=True,
    setup_requires=["setuptools_scm", "nuitka"],
    packages=find_packages(
        where="src",
    ),
    package_dir={"": "src"},
    ext_modules=[
        Extension(
            "talismans.hello",
            ["src/talismans/hellomodule.cpp", "src/talismans/example.cpp"],
        )
    ],
)
