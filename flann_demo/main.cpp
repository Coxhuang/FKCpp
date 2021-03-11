#include <flann/flann.hpp>

int main(int argc, char **argv) {
    /*
     * 条件:
     * 1. 空间X(例:xy轴坐标系)
     * 2. 一个属于X空间的点集合Ps([[1,1],[2,1],...,[n,m]])
     * 3. 一个位于X空间内的任意一点p([2.3,3.9])
     * 4. 求出p到Ps中距离最近的k个点
     * */
    unsigned int rows{1000};
    unsigned int cols{2};
    int nn = 2; // k值, 求附件的3个点


    flann::Matrix<float> dataset(new float[rows * cols], rows, cols); // 空间X

    for (int i = 0; i < 1000; ++i) {
        dataset[i][0] = i*1.0;
        dataset[i][1] = (i*2)*1.0;
    }
    flann::Matrix<float> query(new float[1 * 2], 1, 2); // 承载查询点的矩阵，矩阵大小是：查询点数*纬数；
    query[0][0] = 3;
    query[0][1] = 1;


    flann::Matrix<int> indices(new int[nn * cols], nn, cols); // k临近点对应的索引
    flann::Matrix<float> dists(new float[nn * cols], nn, cols); // k临近点到 原点的距离
    flann::Index<flann::L2<float> > index(dataset, flann::KDTreeIndexParams(4)); // construct an randomized kd-tree index using 4 kd-trees
    index.buildIndex();
    index.knnSearch(query, indices, dists, nn, flann::SearchParams(128)); // do a knn search, using 128 checks

    std::cout << indices[0][0] << "-(" << dataset[indices[0][0]][0] << "," << dataset[indices[0][0]][1] << ")" << std::endl;
    std::cout << indices[0][1] << "-(" << dataset[indices[0][1]][0] << "," << dataset[indices[0][1]][1] << ")" << std::endl;

    delete[] dataset.ptr();
    delete[] query.ptr();
    delete[] indices.ptr();
    delete[] dists.ptr();

    return 0;
}