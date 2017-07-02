#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <vector>
#include "src/reader/csv_reader.cpp"

using namespace Eigen;


int main()
{
  int numLines = 200;
  int demarcation = 5;
  datasetData A = load_csv<MatrixXd>("../dataset/iris.data.txt", numLines, demarcation);

  return 0;
}
