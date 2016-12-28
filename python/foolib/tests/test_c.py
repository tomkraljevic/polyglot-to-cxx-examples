import unittest
import foolib

class TestC(unittest.TestCase):
    def test_c_model_lifecycle(self):
        model = foolib.c_new()
        print(model)
        foolib.c_operation(model)
        foolib.c_delete(model)

if __name__ == "__main__":
    unittest.main()
