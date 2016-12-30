import h2omojo


#
# Raw API score0() example
#

rawModel = h2omojo.read_mojo("path/to/mojo")

row2 = []
n = rawModel.nfeatures()
for i in range(n):
    row2.append(0.0)

pred2 = []
n = rawModel.getPredsSize()
for i in range(n):
    pred2.append(0.0)

rawModel.score0(row2, pred2)

for (i in range(len(pred2))):
    print(pred2[i]);


#
# Easy API example
#

model = h2omojo.EasyPredictModelWrapper(rawModel)

# Pure dict row case

row = {}
row['AGE'] = '68'
row['RACE'] = '2'
row['DCAPS'] = '2'
row['VOL'] = '0'
row['GLEASON'] = '6'

# RowData object case

# row = h2omojo.RowData()
# row.put("AGE", "68")
# row.put("RACE", "2")
# row.put("DCAPS", "2")
# row.put("VOL", "0")
# row.put("GLEASON", "6")

p = model.predict_binomial(row)

print("Has penetrated the prostatic capsule (1=yes; 0=no): " + p.get_label())
print("Class probabilities: ")
for i in range(len(p.class_probabilities())):
    if i > 0:
        print(",")
    print(p.class_probabilities[i])
print("")
