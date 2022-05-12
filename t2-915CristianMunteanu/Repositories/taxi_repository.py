class TaxiRepository:
    def __init__(self):
        self.__list_of_all_taxis=[]
    def find_taxi_by_id(self,taxi_id):
        if taxi_id in self.__list_of_all_taxis:
            return self.__list_of_all_taxis[taxi_id]
        else:
            return None
    def add_taxi_to_repository(self,taxi):
        if taxi not in self.__list_of_all_taxis:
            self.__list_of_all_taxis.append(taxi)
        else:
            raise ValueError("There is already a taxi with the given id!")
    def change_taxi_data_after_ride(self,taxi,end_x,end_y,fare):
        if self.find_taxi_by_id(taxi.taxi_id) is not None:
            self.__list_of_all_taxis[taxi.taxi_id].x_coordinate=end_x
            self.__list_of_all_taxis[taxi.taxi_id].y_coordinate=end_y
            self.__list_of_all_taxis[taxi.total_fare] += fare
        else:
            raise ValueError("There is not any taxi with the given ID!")
    def return_list_of_all_taxis(self):
        return self.__list_of_all_taxis