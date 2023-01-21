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
    print(f'Money: ${profit}ml')

def insert_coin():
    """Caculate inserted money"""
    quarter = int(input("how many quarters?: "))
    dime = int(input("how many dimes?: "))
    nickle = int(input("how many nickles?: "))
    penny = int(input("how many pennies?: "))
    money = (quarter*25 + dime*10 + nickle*5 + penny) / 100
    return money

def check_ingrediants(menu, money):
    menu_cost = MENU[menu["cost"]]
    menu_water = MENU[menu]["ingredients"]["water"]
    menu_milk = MENU[menu]["ingredients"]["milk"]
    menu_coffee = MENU[menu]["ingredients"]["coffee"]
    
    if money < menu_cost:
        print("Sorry, that's not enough money. Money refunded.")
        machine()
    else:
        if menu_water < resources["water"]:
            print("Sorry, there is not enough water.")
        elif menu_milk < resources["milk"]:
            print("Sorry, there is not enough milk.")
        elif menu_coffee < resources["coffee"]:
            print("Sorry, there is not enough coffee.")
        else:
            print(f'Here is ${money - menu_cost} in change.')
            print(f'Here is your {menu} ☕️. Enjoy!')



def machine():
    choice = input("What would you like? (espresso/latte/cappuccino): ")

    if choice == "espresso" or "latte" or "cappuccino":
        print("Please insert coins.")
        inserted_money = insert_coin()
        check_ingrediants(choice, inserted_money)
    elif choice == "report":
        report()
    else:
        print("Please type your order again!")
    machine()