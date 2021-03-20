#include <H5Cpp.h>
int main()
{
    const std::string fileName("Hello.h5");
    const std::string datasetName("IntArray");
    const int NX = 10, NY = 10, RANK = 2;
    int i, j;
    int data[NX][NY]; // buffer for data to write
    for (j = 0; j < NX; j++)
    {
        for (i = 0; i < NY; i++)
            data[j][i] = i + j;
    }
    H5::H5File file(fileName, H5F_ACC_TRUNC);
    /*
   * Define the size of the array and create the data space for fixed
   * size dataset.
   */
    hsize_t dimsf[2]; // dataset dimensions
    dimsf[0] = NX;
    dimsf[1] = NY;
    H5::DataSpace dataspace(RANK, dimsf);
    /*
   * Define datatype for the data in the file.
   * We will store little endian INT numbers.
   */
    H5::IntType datatype(H5::PredType::NATIVE_INT);
    datatype.setOrder(H5T_ORDER_LE);
    /*
   * Create a new dataset within the file using defined dataspace and
   * datatype and default dataset creation properties.
   */
    H5::DataSet dataset = file.createDataSet(datasetName, datatype, dataspace);
    /*
   * Write the data to the dataset using default memory space, file
   * space, and transfer properties.
   */
    dataset.write(data, H5::PredType::NATIVE_INT);
    return 0;
}