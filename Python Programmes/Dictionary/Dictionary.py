dic={'Jami': 'IT',
     'Nigga': 'IT',
     'Rudra': 'DSA',
     'Shivam': 'CSE',
    'Jami': 'Hey!'}    
'''if same keys then latest value of same keys is printed and if same value then no problemo'''
print(dic.items())
print(dic.keys())
print(dic.values())
print(dic.pop('Rudra'))
print(dic.update({'Nigga': 'Nothing'}))
print(dic.items())
print(dic.get('Jami')) 