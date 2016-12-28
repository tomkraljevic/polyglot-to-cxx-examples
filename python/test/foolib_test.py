import foolib

def test():
    model = foolib.c_new()
    print(model)
    foolib.c_operation(model)
    foolib.c_delete(model)

test()
test()
test()
