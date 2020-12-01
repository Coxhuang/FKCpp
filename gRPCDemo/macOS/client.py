import grpc
# from macOS.protos import helloworld_pb2
# from macOS.protos import helloworld_pb2_grpc
from .protos import helloworld_pb2,helloworld_pb2_grpc
from google.protobuf.json_format import ParseDict
import time


class HelloBusiness(object):

    def __init__(self):
        super(HelloBusiness, self).__init__()
        self.ip = "127.0.0.1"
        self.port = 5000
        self.client_init()

    def client_init(self):
        """
        gRPC客户端初始化
        :return: None
        """

        self.channel = grpc.insecure_channel('{}:{}'.format(self.ip, self.port))
        self.client = helloworld_pb2_grpc.TestServerStub(self.channel)

        return None

    def hello_business(self, msg):
        """

        :param msg: request msg
        :return:
        """

        proto_data = helloworld_pb2.HelloMessage()  #
        ParseDict(msg, proto_data)  # 格式化msg
        response = self.client.hello_request.future(proto_data)  # 向server发送数据
        response.add_done_callback(self.hello_callback)  # 回调函数, 发送数据使用异步[future]时, 必须加回调函数

        return response

    def hello_callback(self, future):

        print(future.result().result)
        print("callback")

class HelloWorld(HelloBusiness):

    def hello(self, *args, **kwargs):
        """

        :return: None
        """

        self.hello_business({
            "a": 1,
            "b": 2,
        })

        return None


grpc_client = HelloWorld()

if __name__ == '__main__':

    grpc_client.hello()
    time.sleep(2)

