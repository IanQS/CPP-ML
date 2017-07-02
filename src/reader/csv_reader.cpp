#include <Eigen/Dense>
#include <vector>
#include <fstream>

using namespace Eigen;

struct datasetData {
  MatrixXd features;
  std::vector<std::string> labels;
};

template<typename M>
M load_csv (const std::string & path, uint numLines = ULONG_MAX, uint demarcation = ULONG_MAX) {
  std::ifstream indata;
  indata.open(path);
  std::string line;
  std::vector<double> Xs;
  std::vector<std::string> Ys;
  uint count = 1;
  uint rows = 0;
  datasetData returnVals;

  for (int start=0; start < numLines; start++){
    std::getline(indata, line);
    if (line.empty()){
      indata.close();
      returnVals.features = Map<const Matrix<typename M::Scalar, M::RowsAtCompileTime, M::ColsAtCompileTime, RowMajor>>(Xs.data(), rows, Xs.size()/rows);
      returnVals.labels = Ys;
      return returnVals;
    }
    std::stringstream lineStream(line);
    std::string cell;
    while (std::getline(lineStream, cell, ',')) {
      if (count % demarcation == 0 && count != 0){
        Ys.push_back(cell);
          }
      else{
        Xs.push_back(std::stod(cell));
      }
      count++;
    }
    ++rows;
  }
  indata.close();
  returnVals.features = Map<const Matrix<typename M::Scalar, M::RowsAtCompileTime, M::ColsAtCompileTime, RowMajor>>(Xs.data(), rows, Xs.size()/rows);
  returnVals.labels = Ys;
  return returnVals;
}
