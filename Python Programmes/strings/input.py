name=input("Name :")
branch=input("Branch : ")
print(f"{name}, good afternoon \n your branch is {branch}")
value=9.47483
print(f"value to two decimal place={value:.2f}")
text="%d little pigs come out, or I'll %s, and I'll %s, and I'll blow your %s down." % (3, 'huff', 'puff', 'house')
# by default Python treats each line as a separate statement (on the plus side, this is why we don't need to type semi-colons on each line). To fix this, enclose the whole expression in an outer set of parenthesis -- then the expression is allowed to span multiple lines.