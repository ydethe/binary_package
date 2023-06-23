def test_c():
    from talismans.hello import add

    assert add(2, 3) == 5


def test_py():
    from talismans.compute import python_add

    assert python_add(2, 3) == 5


if __name__ == "__main__":
    test_c()
    test_py()
