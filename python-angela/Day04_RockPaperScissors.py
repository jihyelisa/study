rock = """          _______
      ---'   ____)
            (_____)
            (_____)
            (____)
      ---.__(___)"""

paper = """          _______
      ---'   ____)____
                ______)
                _______)
               _______)
      ---.__________)"""

scissors = """          _______
      ---'   ____)____
                ______)
             __________)
            (____)
      ---.__(___)"""

import random

# r_p_s = [rock, paper, scissors]

# you = r_p_s[int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors. "))]
# computer = random.choice(r_p_s)
# print(you)
# print(f"\nComputer chose:\n{computer}\n")

# result = r_p_s.index(you) - r_p_s.index(computer)



r_p_s = [rock, paper, scissors]

you = int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors. "))
computer = random.randint(0, 2)

if you > 2 or you < 0:
  print("You entered invalid number!")
else:
  print(r_p_s[you])
  print(f"\nComputer chose:\n{r_p_s[computer]}\n")

  result = you - computer
  if result == 1 or result == -2:
    print("You win!")
  elif result == -1 or result == 2:
    print("You lose!")
  else:
    print("Ended in a draw!")