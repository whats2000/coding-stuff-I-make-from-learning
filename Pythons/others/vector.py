import math


class Vector2D:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector2D(self.x + other.x, self.y + other.y)

    def distance(self, other):
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2)

    def print_obj(self):
        print("(", self.x, ",", self.y, ")", end="")


p1 = Vector2D(5, 7)
p2 = Vector2D(3, 9)

result = p1 + p2

p1.print_obj()
print("+", end="")
p2.print_obj()
print("=", end="")
result.print_obj()
print()

print(f'Distance of the 2 points is {p1.distance(p2)}')
