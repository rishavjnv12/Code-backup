class Point:
    def __init__(self, x=0, y=0):
        self.x=x
        self.y=y
    
    def __str__(self):
        return '('+str(self.x)+', '+str(self.y)+')'
    
    def __add__(self, other):
        return Point(self.x+other.x, self.y+other.y)

    def __len__(self):
        return 9
        
        




x=Point(1,2)
y=Point(3,4)
print(len(x))


