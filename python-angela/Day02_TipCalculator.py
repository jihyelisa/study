print("Welcome to the tip calculator.")
total_bill = float(input("What was the total bill? $"))
percent_tip = int(input("What percentage tip would you like to give? 10, 12, or 15? "))
ppl_num = int(input("How many people to split the bill? "))
each_pay = (total_bill + total_bill / 100 * percent_tip) / ppl_num
each_pay = round(each_pay, 2)
# print(f"Each person should pay: ${each_pay}")
print("Each person should pay: ${:0.2f}".format(each_pay))