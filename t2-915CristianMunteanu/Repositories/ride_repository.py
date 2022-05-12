class RideRepository:
    def __init__(self):
        self.__list_of_all_rides=[]
    def add_a_ride(self,ride):
        self.__list_of_all_rides.append(ride)