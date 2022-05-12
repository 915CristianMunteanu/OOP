"""
Implement the solution here. 
You may add other source files.
Make sure you commit & push the source code before the end of the test.

Solutions using user-defined classes will not be graded.
"""
import functions
import datetime
import ui
from time import time,sleep
def run_menu():
    calculator_number=functions.generate_first_number()
    game_finished=False
    while game_finished==False:
        user_number=ui.read_user_number()
        if functions.check_user_number(user_number)==False:
            ui.print_calculator_wins_wrong_user_number()
            game_finished=True
        else:
            if user_number==8086:
                ui.print_calculators_number(calculator_number)
            if(calculator_number==user_number):
                ui.print_user_wins()
                game_finished = True
            else:
                number_of_codes=functions.calculate_codes(calculator_number,user_number)
                number_of_runners=functions.calculate_runners(calculator_number,user_number)-number_of_codes
                ui.print_number_of_codes_and_runners(number_of_codes,number_of_runners)






run_menu()