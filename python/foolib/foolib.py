import _foolib


def load_model():
    print("load_model")
    # m = foolib.FoolibWrapper()
    # return m


class FoolibWrapper:
    def __init__(self):
        print('Python Foolib __init__')
        self.object = _foolib.c_new()

    def operation(self):
        print('Python Foolib operation')
        _foolib.c_operation(self.object)

    def __del__(self):
        print('Python Foolib __del__')
        self.object = _foolib.c_delete(self.object)
