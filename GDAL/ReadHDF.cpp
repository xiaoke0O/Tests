#include <iostream>
#include <gdal_priv.h>

int main() {
    GDALAllRegister();
    auto *dataset = (GDALDataset *) GDALOpen(R"(c:/Users/k/Pictures/modH5.h5)", GA_ReadOnly);
    std::cout << *dataset->GetMetadata("SUBDATASETS") << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
