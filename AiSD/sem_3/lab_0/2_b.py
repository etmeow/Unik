
def f(a, b, c, x):

    return a*x**2 + b*x + c


nums = [-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]

x = []
d = []
my_x = []

for a in range(-20, 20):
    for b in range(-20, 20):
        for c in range(-20, 20):

            if a == 0:
                continue

            vertex = -b/(2*a)


            for el in nums:
                x.append(f(a, b, c, el))
                d.append(abs(vertex - el))

            x_sorted = sorted(x)

            i = 0
            j = len(nums) - 1

            while i <= j:

                if d[i] < d[j]:
                    my_x.append(f(a, b, c, nums[j]))
                    j -= 1
                else:
                    my_x.append(f(a, b, c, nums[i]))
                    i += 1

            if a > 0:
                my_x = my_x[::-1]

            if (my_x == x_sorted):
                print("FALSE")
                print(a, b, c)
                print(nums)
                print("d", d)
                print("x", x)
                print("sorted", x_sorted)
                print("my", my_x)
                print(my_x == x_sorted)
                input()
            else:
                print("TRUE")

            x.clear()
            my_x.clear()
            d.clear()

            






""" print(nums)
print(d)
print(x)
print(x_sorted)
print(my_x)
print(my_x == x_sorted) """


