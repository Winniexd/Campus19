import random

def main():
    x = random.randint(1, 100)
    
    while (True):
        y = int(input("Guess a number between 1 and 100: "))
        if (y == x):
            print("You guessed correctly!")
            break
        elif (y < x):
            print("Too low!")
        elif (y > x):
            print("Too high!")
            
main()