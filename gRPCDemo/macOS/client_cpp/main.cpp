/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/30 6:02 下午
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "../protos/helloworld.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::TestServer; // Greeter
using helloworld::HelloMessage; // HelloRequest
using helloworld::Reply; // HelloReply


class GreeterClient {
public:

    GreeterClient(std::shared_ptr<Channel> channel):stub_(TestServer::NewStub(channel)) {}

    int say_hello(const std::string& user) {

        HelloMessage request;
        Reply reply;
        ClientContext context;

        request.set_a(21);
        request.set_b(22);

        Status status = stub_->hello_request(&context, request, &reply);

        if (status.ok()) {
            return reply.result();
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return 0;
        }
    }

private:
    std::unique_ptr<TestServer::Stub> stub_;

};

int main(int argc, char** argv) {

    GreeterClient greeter(grpc::CreateChannel("127.0.0.1:5000", grpc::InsecureChannelCredentials()));
    std::string user("world");
    int reply = greeter.say_hello(user);
    std::cout << "Greeter received: " << reply << std::endl;

    return 0;
}
 