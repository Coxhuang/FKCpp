
//protoc --cpp_out=. helloworld.proto
//protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` helloworld.proto
//
// server.cc
// Created by leo on 2020/1/31.
//
/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/29 10:15 下午
 */
//
// server.cc
// Created by leo on 2020/1/31.
//

#include <string>
#include <grpcpp/grpcpp.h>
#include "protos/mathtest.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using mathtest::MathTest;
using mathtest::MathRequest;
using mathtest::MathReply;

class MathServiceImplementation final : public MathTest::Service {
    Status sendRequest(
            ServerContext* context,
            const MathRequest* request,
            MathReply* reply
    ) override {
        int a = request->a();
        int b = request->b();
        reply->set_result(a * b);
        return Status::OK;
    }
};

void Run() {
    std::string address("0.0.0.0:5000");
    MathServiceImplementation service;
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


