def test_c_add():
    from talismans.hello import add

    assert add(2, 3) == 5


# def test_c_norm():
#     import numpy as np
#     from talismans.hello import norm

#     v = np.array([3, 4])

#     assert norm(v) == 5


def test_c_class():
    from talismans.hello import create_example, Example

    a = create_example()
    assert a.getResult() == 0

    a.process()
    assert a.getResult() == 1

    b = Example()
    assert b.getResult() == 0

    b.process()
    assert b.getResult() == 1


def test_py():
    from talismans.compute import python_add

    assert python_add(2, 3) == 5


if __name__ == "__main__":
    test_c_add()
    # test_c_norm()
    test_py()
    test_c_class()
