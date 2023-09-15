

n = 3

s1 = "aa"
s2 = "da"
evil = "b"

mass = []


for i in range(3**n):

    a = "".join([chr(ord('a') + (i // (3**j)) % 3) for j in range(n)])
    print(i, a)
    mass.append(a)

count = 0

""" for x in mass:
    if s1 <= x <= s2 and evil not in x:
        #print(x)
        count += 1
print(count) """
        


        




       