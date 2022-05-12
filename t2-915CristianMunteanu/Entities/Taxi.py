class Taxi:
    def __init__(self,taxi_id,x_coordinate,y_coordinate,total_fare):
        self.__taxi_id=taxi_id
        self.__x_coordinate=x_coordinate
        self.__y_coordinate=y_coordinate
        self.__total_fare=total_fare
    @property
    def x_coordinate(self):
        return self.__x_coordinate

    @x_coordinate.setter
    def x_coordinate(self, value):
        self.__x_coordinate=value
    @property
    def y_coordinate(self):
        return self.__y_coordinate

    @y_coordinate.setter
    def y_coordinate(self, value):
        self.__y_coordinate=value
    @property
    def taxi_id(self):
        return self.__taxi_id

    @taxi_id.setter
    def taxi_id(self, value):
        self.__taxi_id=value

    @property
    def total_fare(self):
        return self.__total_fare

    @total_fare.setter
    def total_fare(self, value):
        self.__total_fare=value