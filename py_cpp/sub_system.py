import psutil

def get_current_bytes_sent():
    """
    获取当前的发送量
    :return: 发送量
    """
    return psutil.net_io_counters().bytes_sent

def get_current_bytes_recv():
    """
    获取当前的接收量
    :return: 接收量
    """
    return psutil.net_io_counters().bytes_recv

def psutil_format(data):
    """
    格式化输出
    :param data:
    :return: str
    """

    return format(data, '.1f')

def get_cpu_percent():
    """
    获取CPU使用率, 这里的interval会影响整体的速度, 相当于 sleep, 频率不能太小, 太小CPU使用率取不到数据
    :return:
    """
    return psutil.cpu_percent()

def get_memory_percent():
    """
    获取内存使用率
    :return:
    """

    mem = psutil.virtual_memory()

    return mem.percent

def get_disk_percent():
    """
    获取磁盘使用率
    :return:
    """

    disk = psutil.disk_usage('/')

    return disk.percent

def get():

    # return get_current_bytes_sent(), get_current_bytes_recv(), get_cpu_percent(), get_memory_percent(), get_disk_percent()
    return get_current_bytes_recv()

if __name__ == '__main__':

    print(get_current_bytes_sent())
    print(get_current_bytes_recv())
    print(get_cpu_percent())
    print(get_memory_percent())
    print(get_disk_percent())