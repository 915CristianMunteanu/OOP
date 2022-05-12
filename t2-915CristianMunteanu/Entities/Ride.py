class Ride:
    def __init__(self,start_x,start_y,end_x,end_y):
        self.__start_x=start_x
        self.__start_y=start_y
        self.__end_x=end_x
        self.__end_y=end_y
    @property
    def start_x(self):
        return self.__start_x

    @start_x.setter
    def start_x(self, value):
        self.__start_x=value

    @property
    def start_y(self):
        return self.__start_y

    @start_y.setter
    def start_y(self, value):
        self.__start_y=value
    @property
    def end_x(self):
        return self.__end_x

    @end_x.setter
    def end_x(self, value):
        self.__end_x=value
    @property
    def end_y(self):
        return self.__end_y

    @end_y.setter
    def end_y(self, value):
        self.__end_y=value