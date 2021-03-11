class UI:
    def __init__(self,carService,clientService, rentService):
        self._carService = carService
        self._clientService = clientService
        self._rentService = rentService

    def mostRentedCarsStat(self):
        result = self._rentService.mostRentedCarsStat()
        for r in result:
            #for each car:
            #how manu days was it rented for
            #car's details(id,make,model)
            print(r)



    def start(self):
        '''
        Show program menu
        read user input
        redirect to a more specific function
        '''
        pass