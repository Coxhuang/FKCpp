
// protoc --cpp_out=. helloworld.proto
// protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` helloworld.proto
// python3 -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. helloworld.proto

#include <string>

int main(int argc, char** argv) {
    return 0;
}


