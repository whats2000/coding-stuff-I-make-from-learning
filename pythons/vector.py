class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __add__(self, other):
        return Vector2D(self.x + other.x, self.y + other.y)
    def printobj(self):
        print ("(",self.x,",",self.y,")",end="")

first = Vector2D(5, 7)
second = Vector2D(3, 9)
result = first + second
first.printobj()
print("+",end="")
second.printobj() 
print("=",end="")
result.printobj()
