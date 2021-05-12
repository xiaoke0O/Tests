from osgeo import gdal

datasets = gdal.Open("MOD13A3.A2020001.h21v03.006.2020034153005.hdf", gdal.GA_ReadOnly).GetMetadata('SUBDATASETS')
# 输出每个数据集的键
print(datasets.keys())
# 打开第一波段
dataset1 = gdal.Open(datasets["SUBDATASET_1_NAME"])
dataset1_data = dataset1.ReadAsArray()
# 打开第二波段
dataset2 = gdal.Open(datasets["SUBDATASET_2_NAME"])
dataset2_data = dataset2.ReadAsArray()

print("dataset1\n", dataset1_data)
print("dataset2\n", dataset2_data)
