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






def insert_coin():
    """Calculate inserted money."""
    print("Please insert coins.")
    quarter = int(input("how many quarters?: "))
    dime = int(input("how many dimes?: "))
    nickle = int(input("how many nickles?: "))
    penny = int(input("how many pennies?: "))
    total = (quarter*25 + dime*10 + nickle*5 + penny) / 100
    return total


def money_enough(choice, inserted_money):
    menu_cost = MENU[choice]["cost"]
    if inserted_money < menu_cost:
        print("Sorry, that's not enough money. Money refunded.")
        return False
    else:
        return True


def ingrediants_enough(choice):
    """Check if ingrediants are enough."""
    menu_ingrediant = MENU[choice]["ingredients"]
    for ingrediant in menu_ingrediant:
        if menu_ingrediant[ingrediant] > resources[ingrediant]:
            print(f'Sorry, there is not enough {ingrediant}.')
            return False
    return True
    

def update_ingrediants(choice):
    """Update the current ingrediants and profit."""
    global MENU, profit
    menu_ingrediant = MENU[choice]["ingredients"]
    menu_cost = MENU[choice]["cost"]
    for ingrediant in menu_ingrediant:
        resources[ingrediant] -= menu_ingrediant[ingrediant]
    profit += menu_cost
   

def report():
    """Print currently remained ingrediants and money if you enter 'report'."""
    for item in resources:
        print(f'{item.title()}: {resources[item]}ml')
    print(f'Money: ${profit}')





def machine():
    choice = input("What would you like? (espresso/latte/cappuccino): ")
    choice = choice.lower()
    
    if choice == "espresso" or choice == "latte" or choice == "cappuccino":
        if ingrediants_enough(choice):
            inserted_money = insert_coin()
            if money_enough(choice, inserted_money):
                update_ingrediants(choice)
                change = inserted_money - MENU[choice]["cost"]
                print(f'Here is ${change} in change.')
                print(f'Here is your {choice} ☕️. Enjoy!')
    
    elif choice == "report":
        report()
    else:
        print("Please type your order again!")
    machine()
machine()