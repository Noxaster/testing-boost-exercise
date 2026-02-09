#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <cstdio>
#include <fstream>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(OpenData)
{
  const std::string testFileName = "test_matrix_temp.csv";
  const int         size         = 3;

  std::ofstream outFile(testFileName);
  outFile << "1.0, 2.0, 3.0\n";
  outFile << "4.0, 5.0, 6.0\n";
  outFile << "7.0, 8.0, 9.0\n";
  outFile.close();

  MatrixXd expectedMatrix(3, 3);
  expectedMatrix << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;

  MatrixXd resultMatrix = matrixIO::openData(testFileName, size);

  BOOST_TEST(resultMatrix.isApprox(expectedMatrix, 1e-12));

  std::remove(testFileName.c_str());
}

BOOST_AUTO_TEST_SUITE_END()