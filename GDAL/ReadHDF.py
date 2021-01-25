from osgeo import gdal

gdal.AllRegister()

datasets = gdal.Open("Assets/hdf4_testfile_1.hdf", gdal.GA_ReadOnly).GetMetadata('SUBDATASETS')
# 输出每个数据集的名称
print(datasets.keys())

dataset1 = gdal.Open(datasets["SUBDATASET_1_NAME"])
dataset1_data = dataset1.ReadAsArray()

dataset2 = gdal.Open(datasets["SUBDATASET_2_NAME"])
dataset2_data = dataset2.ReadAsArray()

print("dataset1\n", dataset1_data)
print("dataset2\n", dataset2_data)
