
//protoc --cpp_out=. helloworld.proto
//protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` helloworld.proto


#include <string>
#include <grpcpp/grpcpp.h>
#include "protos/helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using helloworld::TestServer; // MathTest
using helloworld::HelloMessage; // MathRequest
using helloworld::Reply; // MathReply

class HelloServiceImplementation final : public TestServer::Service {
    Status hello_request(
            ServerContext* context,
            const HelloMessage* request,
            Reply* reply
    ) override {
        int a = request->a();
        int b = request->b();
        reply->set_result(a * b);
        return Status::OK;
    }
};

void Run() {
    std::string address("0.0.0.0:5000");
    HelloServiceImplementation service;
    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on port: " << address << std::endl;
    server->Wait();
}

int main(int argc, char** argv) {
    Run();
    return 0;
}


