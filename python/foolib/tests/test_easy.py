import h2omojo


# To avoid bouncing between Python and C++ languages, the load_mojo_model() returns an Easy API object which
# additionally exposes the raw MojoModel methods like score0().
#
# C++ returns an Easy API object instance which wraps a raw instance, but from Python's perspective, there
# is only one object to deal with.
#
# The Python wrapper has a __del__ method which naturally releases the underlying C++ object when the
# refcount drops to 0.

model = h2omojo.load_mojo_model(mojo_path="/path/to/mojo.zip",
                                convert_unknown_categorical_levels_to_na=False)


#
# Raw API score0() example
#

row2 = []
n = model.nfeatures()
for i in range(n):
    row2.append(0.0)
row2[0] = 68
row2[1] = 2
row2[2] = 2
row2[3] = 0
row2[4] = 6

pred2 = []
n = model.getPredsSize()
for i in range(n):
    pred2.append(0.0)

model.score0(row2, pred2)

for (i in range(len(pred2))):
    print(pred2[i]);


#
# Easy API example
#

# Pure dict row case

row = {}
row['AGE'] = '68'
row['RACE'] = '2'
row['DCAPS'] = '2'
row['VOL'] = '0'
row['GLEASON'] = '6'

p = model.predict_binomial(row)

print("Has penetrated the prostatic capsule (1=yes; 0=no): " + p.label)
print("Class probabilities: ")
for i in range(len(p.class_probabilities)):
    if i > 0:
        print(",")
    print(p.class_probabilities[i])
print("")
