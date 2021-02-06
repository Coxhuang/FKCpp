/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/30 6:02 下午
 */

// protoc --cpp_out=. helloworld.proto
// protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` helloworld.proto
// python3 -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. helloworld.proto



#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <memory>
#include <time.h>
#include <grpcpp/grpcpp.h>
#include "../protos/helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;

using helloworld::TestServer; // MathTest
using helloworld::HelloMessage; // MathRequest
using helloworld::Reply; // MathReply



class ServerImpl final {
public:
    ServerImpl() {};

    ~ServerImpl() {
        this->server_->Shutdown();
        this->cq_->Shutdown();
    };

public:
    void run() {
        std::string server_address("0.0.0.0:50051");
        ServerBuilder builder;
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
        builder.RegisterService(&service_);
        this->cq_ = builder.AddCompletionQueue();
        this->server_ = builder.BuildAndStart();
        std::cout << "Server listening on " << server_address << std::endl;
        this->HandleRpcs();
    }

public:
    void HandleRpcs() {
        new CallData(&service_, cq_.get());
        void* tag;
        bool ok;
//        while (true) {}
    }

private:
    class CallData {
    public:
        CallData(TestServer::AsyncService* service, ServerCompletionQueue* cq):service_(service),cq_(cq),responder_(&ctx_),status_(CREATE) {
            this->Proceed();
        }

    public:
        void Proceed(){
            std::cout << "Proceed" << std::endl;
        }
    private:
        TestServer::AsyncService* service_;
        ServerCompletionQueue* cq_;
        HelloMessage request_;
        Reply reply_;
        ServerAsyncResponseWriter<Reply> responder_;
        ServerContext ctx_;
        enum CallStatus { CREATE, PROCESS, FINISH };
        CallStatus status_;  // The current serving state.
    };
private:
    std::unique_ptr <ServerCompletionQueue> cq_;
    TestServer::AsyncService service_;
    std::unique_ptr <Server> server_;
};


int main(int argc, char **argv) {
    std::cout << ".." << std::endl;
    ServerImpl server;
    server.run();
    return 0;
}



 