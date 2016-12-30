import unittest
import foolib


class TestPy(unittest.TestCase):
    def test_load_model(self):
        foolib.load_model()

    def test_py_wrapper(self):
        w = foolib.FoolibWrapper()
        w.operation()


if __name__ == "__main__":
    unittest.main()
