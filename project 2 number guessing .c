import random

def number_guessing_game():
    secret_number = random.randint(1, 100)
    attempts = 0
    max_attempts = 10
    
    print("Welcome to the Number Guessing Game!")
    print("I'm thinking of a number between 1 and 100.")
    print(f"You have {max_attempts} attempts to guess it.\n")
    
    while attempts < max_attempts:
        try:
            guess = int(input("Enter your guess: "))
            attempts += 1
            
            if guess < secret_number:
                print("Too low! Try a higher number.")
            elif guess > secret_number:
                print("Too high! Try a lower number.")
            else:
                print(f"Congratulations! You guessed it in {attempts} attempts.")
                return
            
            remaining = max_attempts - attempts
            if remaining > 0:
                print(f"You have {remaining} attempts left.\n")
            else:
                print("Sorry, you've used all your attempts.")
                print(f"The secret number was {secret_number}.")
                return
        
        except ValueError:
            print("Please enter a valid integer.")
            attempts -= 1
    
    print(f"Game over! The secret number was {secret_number}.")

if __name__ == "__main__":
    number_guessing_game()
