from Repositories.ride_repository import RideRepository
from Repositories.taxi_repository import TaxiRepository
from Services.ride_service import RideService
from Services.taxi_service import TaxiService
from UI.console import Console

taxi_repository=TaxiRepository()
ride_repository=RideRepository()
taxi_service=TaxiService(taxi_repository)
ride_service=RideService(taxi_repository,ride_repository)
console=Console(taxi_service,ride_service)
console.run_console()
