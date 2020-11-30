import grpc
from protos import mathtest_pb2
from protos import mathtest_pb2_grpc
from google.protobuf.json_format import ParseDict
import time


class TbsToTrackerBusiness(object):
    def __init__(self):
        super(TbsToTrackerBusiness, self).__init__()
        self.ip = "127.0.0.1"
        self.port = 5000
        self.client_init()

    def client_init(self):
        """
        gRPC客户端初始化
        :return: None
        """

        self.channel = grpc.insecure_channel('{}:{}'.format(self.ip, self.port))
        self.client = mathtest_pb2_grpc.MathTestStub(self.channel)

        return None

    def vehicle_command_business(self, msg):
        """

        :param msg: request msg
        :return:
        """

        proto_data = mathtest_pb2.MathRequest()  #
        ParseDict(msg, proto_data)  # 格式化msg
        response = self.client.sendRequest.future(proto_data)  # 向server发送数据
        response.add_done_callback(self.vehicle_command_callback)  # 回调函数, 发送数据使用异步[future]时, 必须加回调函数

        return response

    def vehicle_command_callback(self, future):

        print(future.result().result)
        print("callback")

class TbsToTracker(TbsToTrackerBusiness):

    def vehicle_command_estop(self, *args, **kwargs):
        """

        :return: None
        """

        self.vehicle_command_business({
            "a": 1,
            "b": 2,
        })

        return None


tracker_grpc_client = TbsToTracker()

if __name__ == '__main__':

    tracker_grpc_client.vehicle_command_estop()
    time.sleep(2)

