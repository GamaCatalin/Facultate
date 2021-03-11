from Repository import Repository
from Car import Car
from Client import Client
from Rental import Rental
from _datetime import date

carRepo = Repository()
carRepo.store(Car(1,"CJ01ABC","Skoda","Fabia","red"))

clientRepo = Repository()
clientRepo.store(Client(1,"Pop Maria",20))

rentRepo = Repository()
rentRepo.store(Rental(1,date(2019,11,20),date(2019,11,24),clientRepo[0],carRepo[0]))

carService = CarService(carRepo)
clientService = ClientService(clientRepo)
rentService = RentalSercice(rentRepo)


ui= UI(carService, clientService, rentService)
ui.start()