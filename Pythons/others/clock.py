from datetime import datetime
from time import sleep


class Clock(object):

    def __init__(self, hour=0, minute=0, second=0):  # 初始化
        self._hour = hour  # 時
        self._minute = minute  # 分
        self._second = second  # 秒

    def run(self):
        self._second += 1  # 秒數 + 1
        if self._second == 60:  # 當秒數為 60, 分數 + 1, 秒數變回 0
            self._second = 0
            self._minute += 1
            if self._minute == 60:  # 當分數為 60, 時數 + 1, 分數變回 0
                self._minute = 0
                self._hour += 1
                if self._hour == 24:  # 當時數為 24, 時數變為 0
                    self._hour = 0

    def show(self):  # 顯示時間
        return '%02d:%02d:%02d' % (self._hour, self._minute, self._second)


clock = Clock(datetime.now().hour, datetime.now().minute, datetime.now().second)
while True:
    print('\r', clock.show(), end='')
    # sleep()函數推遲程式運行，單位為 secs 秒數
    sleep(1)  # 推遲進行 1 秒
    clock.run()
