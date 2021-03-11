class CarService:
    def __init__(self,carRepo):
        self._carRepo=carRepo

class ClientService:
    def __init__(self,clientRepo):
        self._clientRepo=clientRepo

class CarRentalDays:
    def __init__(self,car,days):
        self.Car=car
        self.Days=days
    
    def __str__(self):
        return str(self.Days) + " - "+ str(self.Car)



class RentalService:
    def __init__(self,rentalRepo,carRepo):
        self._carRepo=carRepo
        self._rentalRepo=rentalRepo

    def mostRentedCarsStat(self):
        '''
        Output: List of CarRentalDays, sorted in order of rental days (desc.)
    
        '''

        d=dict()
        for i in range(len(self._carRepo)):
            d[self._carRepo[i]] = 0

        results=[]

        for i in range(len(self._rentalRepo)):
            rental=self._rentalRepo[i]
            d[rental.Car] += len(rental)

            result = [CarRentalDays(dict.keys()[i], dict.values()[i]) for i in len(d) ]
            result = sorted(result, key= Days)

            return result





class StatisticsService:
    def __init__(self,carRepo,clientRepo,rentalRepo):
        pass
    pass
