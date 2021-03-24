#include <flann/flann.hpp>
#include <json/json.h>
#include <memory>
#include <fstream>

Json::Value get() {
    Json::Value file_value;
    std::ifstream file_handle;
    std::string file_string;
    file_handle.open("/Users/cox/Documents/GitHub/FKCpp/flann_demo/map.lan", std::ios::in);

    if (file_handle) {
        file_handle.seekg(0, std::ios::end);
        file_string.reserve(file_handle.tellg());
        file_handle.seekg(0, std::ios::beg);
        file_string.assign((std::istreambuf_iterator<char>(file_handle)),std::istreambuf_iterator<char>());
        std::string err;
        Json::CharReaderBuilder reader;
        std::unique_ptr<Json::CharReader>const json_read(reader.newCharReader());
        json_read->parse(file_string.c_str(), file_string.c_str() + file_string.length(), &file_value, &err);
    }
    std::cout << file_value.size() << std::endl;
    return file_value;
}

void knn(flann::Index<flann::L2<float>>& index, flann::Matrix<float>& query, flann::Matrix<float>& dataset) {
    unsigned int rows{1000};
    unsigned int cols{2};
    int nn = 2; // k值, 求附件的3个点

    flann::Matrix<int> indices(new int[nn * cols], nn, cols); // k临近点对应的索引
    flann::Matrix<float> dists(new float[nn * cols], nn, cols); // k临近点到 原点的距离
    index.knnSearch(query, indices, dists, nn, flann::SearchParams(128)); // do a knn search, using 128 checks
    std::cout << indices[0][0] << "-(" << dataset[indices[0][0]][0] << "," << dataset[indices[0][0]][1] << ")" << std::endl;
    std::cout << indices[0][1] << "-(" << dataset[indices[0][1]][0] << "," << dataset[indices[0][1]][1] << ")" << std::endl;
    std::cout << "----" << std::endl;
//    get();
}


class Flannx{
public:
    Flannx() {
        dataset_ = std::make_shared<flann::Matrix<float>>(new float[rows * cols], rows, cols);
//        flann::Matrix<float> dataset(new float[rows * cols], rows, cols); // 空间X
//        for (int i = 0; i < 1000; ++i) {
//            dataset[i][0] = i*1.0;
//            dataset[i][1] = (i*2)*1.0;
//        }
        for (int i = 0; i < 1000; ++i) {
            (*dataset_)[i][0] = i*1.0;
            (*dataset_)[i][1] = (i*2)*1.0;
        }
        index.buildIndex(*dataset_);
//        delete dataset.ptr();
    }
    ~Flannx(){
        std::cout << "析构" << std::endl;
    };

    void delete_matrix(){
        delete [] dataset_->ptr();
    }

    void fknn(){
        flann::Matrix<float> query(new float[1 * 2], 1, 2); // 承载查询点的矩阵，矩阵大小是：查询点数*纬数；
        query[0][0] = 3;
        query[0][1] = 1;

        flann::Matrix<int> indices(new int[nn * cols], nn, cols); // k临近点对应的索引
        flann::Matrix<float> dists(new float[nn * cols], nn, cols); // k临近点到 原点的距离
        index.knnSearch(query, indices, dists, nn, flann::SearchParams(128)); // do a knn search, using 128 checks
        auto ret1 = index.getPoint(indices[0][0]);
        auto ret2 = index.getPoint(indices[0][1]);
        std::cout << indices[0][0] << "-(" << ret1[0] << "," << ret1[1] << ")" << std::endl;
        std::cout << indices[0][1] << "-(" << ret2[0] << "," << ret2[1] << ")" << std::endl;
        std::cout << "----" << std::endl;
        delete [] query.ptr();
        delete [] indices.ptr();
        delete [] dists.ptr();
    }

private:
    unsigned int rows{1000};
    unsigned int cols{2};
    int nn = 2; // k值, 求附件的3个点
    flann::Index<flann::L2<float>> index{flann::KDTreeIndexParams(4)}; // construct an randomized kd-tree index using 4 kd-trees
    std::shared_ptr<flann::Matrix<float>> dataset_;
};

int main(int argc, char **argv) {
    /*
     * 条件:
     * 1. 空间X(例:xy轴坐标系)
     * 2. 一个属于X空间的点集合Ps([[1,1],[2,1],...,[n,m]])
     * 3. 一个位于X空间内的任意一点p([2.3,3.9])
     * 4. 求出p到Ps中距离最近的k个点
     * */

    std::unique_ptr<Flannx> fnn = std::make_unique<Flannx>();
    fnn->fknn();
    fnn->delete_matrix();
    fnn->fknn();

    return 0;
}