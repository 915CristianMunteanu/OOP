import random

def generate_first_number():
    """
    This function is used to generate a random number between 1023 and 9876(so it can have different digits).
    Firstly, a random number is generated between 1023 and 9876, using the random library.
    Then, a bunch of assignements are made, to get all 4 digits in different variables.
    Then we check if the digits are different 2 by 2.
    If they are all different 2 by 2, the generated number is returned.
    If they are not different 2 by 2 a new integer number of 4 digits its generated and we start again.
    :return: This function returns a integer value between 1023 and 9876 that also has all 4 digits different.
    """
    while True:
        generated_number=random.randint(1023,9876)
        auxiliary_number=generated_number
        first_digit=auxiliary_number%10
        auxiliary_number =generated_number//10
        second_digit=auxiliary_number%10
        auxiliary_number=generated_number//100
        third_digit=auxiliary_number%10
        auxiliary_number=generated_number//1000
        forth_digit=auxiliary_number
        if first_digit!= second_digit and first_digit!=third_digit and first_digit!=forth_digit and second_digit!=third_digit and second_digit!=forth_digit and third_digit!=forth_digit:
            return generated_number
        else:
            generated_number=random.randint(1023,9876)

def calculate_codes(calculator_number,user_number):
    number_of_codes=0
    for counter in range(0,4):
        if calculator_number%10==user_number%10:
            number_of_codes+=1
        calculator_number //=10
        user_number//=10
    return number_of_codes


def calculate_runners(calculator_number,user_number):
    number_of_runners=0
    auxiliary_number=calculator_number
    for current_digit_index in range(0,4):
        digit_to_compare=user_number%10
        auxiliary_number=calculator_number
        for current_digit_index_for_second_number in range(0,4):
            if digit_to_compare== auxiliary_number%10:
                number_of_runners +=1
            auxiliary_number//=10
        user_number//=10
    return number_of_runners


def check_user_number(user_number):
    if user_number==8086:
        return True
    auxiliary_number = user_number
    first_digit = auxiliary_number % 10
    auxiliary_number = user_number // 10
    second_digit = auxiliary_number % 10
    auxiliary_number = user_number // 100
    third_digit = auxiliary_number % 10
    auxiliary_number = user_number // 1000
    forth_digit = auxiliary_number
    if first_digit != second_digit and first_digit != third_digit and first_digit != forth_digit and second_digit != third_digit and second_digit != forth_digit and third_digit != forth_digit:
        return True
    else:
        return False

def calculate_number_of_seconds(start,this_time):
    return this_time-start