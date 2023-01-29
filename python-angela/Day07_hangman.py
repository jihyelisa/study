stages = ['''
  +---+
  |   |
      |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']

import random

word_list = ["ardvark", "baboon", "camel"]
answer = random.choice(word_list)

# print(answer)

status_list = []
lives = 0

for letter in answer:
  status_list += "_"
print(status_list)

# while game_on == True:
#   guess = input("Guess a letter: ").lower()
#   if guess in answer:
#     for i in range(len(answer)):
#       if guess == answer[i]:
#         status_list[i] = guess
#   print(status_list)
#   else:
#     lives += 1
#     print(stages[lives])
#     if lives >= 6:
#       print("You lose.")
#       game_on == False
# print("You win!")

game_on = True
guess_list = []

while game_on == True:
  if '_' in status_list:
    guess = input("Guess a letter: ").lower()
    print("\n\n")

    if guess in guess_list:
        print(f"{status_list}\nYou've already checked this letter, try again!")
    else:
      guess_list += guess

      if guess in answer:
        for i in range(len(answer)):
          if answer[i] == guess:
            status_list[i] = guess
        print(status_list)
      else:
        lives += 1
        print(stages[lives])
        print(status_list)
        if lives > 5:
          print("You lose...")
          print(f"The answer was ^{answer}^!")
          game_on = False

  else:
    print("You win!")
    game_on = False