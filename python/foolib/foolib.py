import _foolib


class FoolibWrapper:
    def __init__(self):
        self.object = _foolib.c_new()

    def operation(self):
        _foolib.c_operation(self.object)

    def __del__(self):
        self.object = _foolib.c_delete(self.object)


def load_mojo_model():
    m = FoolibWrapper()
    return m
