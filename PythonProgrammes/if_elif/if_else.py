p1='Make a lot of money'
p2='buy now'
p3='subscribe this' 
p4='click this'
'''case sensitve'''
message=input("Enter your message: ")
if((p1 in message) or (p2 in message) or (p3 in message) or (p4 in message)):
  print("Your message is spam")
else:
  print("Your message is not spam")