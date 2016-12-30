# from foolib import FoolibWrapper

import h2omojo

rawModel = h2omojo.read_mojo("path/to/mojo")

row2 = []
n = rawModel.nfeatures()
for i in range(n):
    row2.append(0.0)

pred2 = []
n = rawModel.getPredsSize()
for i in range(n):
    pred2.append(0.0)

rawModel.score0(row2, pred2);

for (i in range(len(pred2))):
    print(pred2[i]);




model = h2omojo.EasyPredictModelWrapper(rawModel)

row = {}
row['AGE'] = '68'
row['RACE'] = '2'
row['DCAPS'] = '2'
row['VOL'] = '0'
row['GLEASON'] = '6'

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


#
# int main(int argc, char **argv) {
#     h2o::GenModel *rawModel = h2o::loadMojoModel("../test/unzipped");
#
#     std::vector<double> row2;
#     row2.resize(rawModel->nfeatures());
#     row2[0] = 68;
#     row2[1] = 2;
#     row2[2] = 2;
#     row2[3] = 0;
#     row2[4] = 6;
#     std::vector<double> pred2;
#     pred2.resize(rawModel->getPredsSize());
#     rawModel->score0(row2, pred2);
#     for (int i = 0; i < pred2.size(); i++) {
#         printf("%.16f\n", pred2[i]);
#     }
#
#     h2o::EasyPredictModelWrapper model(rawModel);
#
#     h2o::RowData row;
#     row.put("AGE", "68");
#     row.put("RACE", "2");
#     row.put("DCAPS", "2");
#     row.put("VOL", "0");
#     row.put("GLEASON", "6");
#
#     h2o::BinomialModelPrediction p = model.predictBinomial(row);
#     printf("Has penetrated the prostatic capsule (1=yes; 0=no): %s\n", p.label.c_str());
#     printf("Class probabilities: ");
#     for (int i = 0; i < p.classProbabilities.size(); i++) {
#     if (i > 0) {
#         printf(",");
#     }
#     printf("%f", p.classProbabilities[i]);
#     }
#     printf("\n");
#
#     return 0;
# }
