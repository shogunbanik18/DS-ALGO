from random import randint

from sympy import Q


rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''


print("\n\n\n\n-------LET'S START--------\n")

def rps():
    print("Enter 0 for ROCK\n Enter 1 for PAPER\nEnter 2 for SCISSORS")
    n=int(input())
    if n in range(3):
        if n==0:
            print("You Choose\n",rock)
        elif n==1:
            print("You Choose\n",paper)
        elif n==2:
            print("You Choose\n",scissors)
    
        m=randint(0,2)

        if m==0:
            print("COMPUTER Chose\n",rock)
        elif m==1:
            print("COMPUTER Chose\n",paper)
        elif m==2:
            print("COMPUTER Chose\n",scissors)

        if n==0 and m==1:
            print("You LOST")
        elif n==1 and m==2:
            print("You LOST")
        elif n==2 and m==0:
            print("You LOST")
        elif n==m:
            print("____DRAW____ !!!")
        else:
            print("_____YOU WON_____")
    
        print("\n___PRESS 6 to PLAY AGAIN___OR__ENTER ANY NO TO EXIT\n")
        r=int(input())

        if r==6:
            rps()
        else:
            print("ADIOS AMIGOS")
    else:
        print("ENTER VALID NO")
        

rps()


