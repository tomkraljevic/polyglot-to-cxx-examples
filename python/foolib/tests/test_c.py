import unittest
import _foolib


class TestC(unittest.TestCase):
    def test_c_lifecycle(self):
        model = _foolib.c_new()
        print(model)
        _foolib.c_operation(model)
        _foolib.c_delete(model)


if __name__ == "__main__":
    unittest.main()
