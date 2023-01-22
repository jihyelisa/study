MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

profit = 0
resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}





def report():
    """Print currently remained ingrediants and money if you enter 'report'"""
    print(f'Water: {resources["water"]}ml')
    print(f'Milk: {resources["milk"]}ml')
    print(f'Coffee: {resources["coffee"]}g')
    print(f'Money: ${profit}')


def insert_coin():
    """Calculate inserted money"""
    print("Please insert coins.")
    quarter = int(input("how many quarters?: "))
    dime = int(input("how many dimes?: "))
    nickle = int(input("how many nickles?: "))
    penny = int(input("how many pennies?: "))
    total = (quarter*25 + dime*10 + nickle*5 + penny) / 100
    return total


def money_enough(choice, inserted_money):
    cost = MENU[choice]["cost"]
    if inserted_money < cost:
        print("Sorry, that's not enough money. Money refunded.")
        return False
    else:
        return True


def ingrediants_enough(choice):
    """check if ingrediants are enough"""
    for ingrediant in MENU[choice]["ingredients"]:
        if MENU[choice]["ingredients"][ingrediant] > resources[ingrediant]:
            print(f'Sorry, there is not enough {ingrediant}.')
            return False
    return True
    

def update(choice):
    """update the current ingrediants"""
    for ingrediant in MENU[choice]["ingredients"]:
        resources[ingrediant] -= MENU[choice]["ingredients"][ingrediant]
    
    water = MENU[choice]["ingredients"]["water"]
    milk = MENU[choice]["ingredients"]["milk"]
    coffee = MENU[choice]["ingredients"]["coffee"]
   





def machine():
    choice = input("What would you like? (espresso/latte/cappuccino): ")
    
    if choice == "espresso" or "latte" or "cappuccino":
        inserted_money = insert_coin()
        if money_enough(choice, inserted_money):
            if ingrediants_enough(choice):
                change = inserted_money - MENU[choice]["cost"]
                print(f'Here is ${change} in change.')
                print(f'Here is your {choice} ☕️. Enjoy!')
    
    elif choice == "report":
        report()
        return
    
    else:
        print("Please type your order again!")
    machine()

machine()