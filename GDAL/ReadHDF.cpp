/*
 * hdf文件链接
 * https://dl2.sanchor.xyz/RSDATA/MOD13A3.A2020001.h21v03.006.2020034153005.hdf
 */
#include <gdal/gdal_priv.h>
#include <iostream>
int main()
{
    //注册驱动
    GDALAllRegister();
    // HDF文件名
    CPLString file_path = "MOD13A3.A2020001.h21v03.006.2020034153005.hdf";
    // 打开文件
    GDALDataset *currentDataset = (GDALDataset *)GDALOpen(file_path, GA_ReadOnly);
    // 获取子数据集信息
    CPLStringList subdataset = CPLStringList(currentDataset->GetMetadata("SUBDATASETS"));
    // 提取第一个数据集的名称
    auto ndvi_path = subdataset["SUBDATASET_1_NAME"];
    // 打开第一个子数据集NDVI
    GDALDataset *poDataset = (GDALDataset *)GDALOpen(ndvi_path, GA_ReadOnly);
    // 读取数据集形状
    int xsize = poDataset->GetRasterXSize();
    int ysize = poDataset->GetRasterYSize();
    std::cout << "X size = " << xsize << ", "
              << "Y size = " << ysize << std::endl;
    // 获取波段
    GDALRasterBand *ndvi_band = poDataset->GetRasterBand(1);
    //获取波段统计值
    double result[4] = {0.0, 0.0, 0.0, 0.0};
    CPLErr statis_error2 = ndvi_band->ComputeStatistics(0, &result[0], &result[1], &result[2], &result[3], NULL, NULL);
    if (statis_error2 == CE_None)
        std::cout <<"Max："<< result[1] << " " << std::endl;
    // 读取波段值
    float *buffer = new float[xsize * ysize];
    CPLErr error = ndvi_band->RasterIO(GF_Read, 0, 0, xsize, ysize, buffer, xsize, ysize, GDT_Float32, 0, 0);
    return 0;
}
