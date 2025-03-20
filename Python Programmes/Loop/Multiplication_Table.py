'using while loop'
num=int(input("enter the number: "))
i=1
while(i<=10):
  print(f"{num} * {i} =  ", num*i)
  i+=1
  ' using for loop'
num=int(input("enter the number: "))
for i in range(1,11):
  print(f"{num} * {i} =  ", num*i)
  