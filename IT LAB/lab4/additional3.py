
class Circle:

    def __init__(self,radius):
        self.radius=radius

    def area(self):
        return (3.14*self.radius*self.radius)

    def perimeter(self):
        return (2*3.14*self.radius)

radius=int(input("Enter the radius :"))

my_obj=Circle(radius)
print("Area of the circle: "+str(my_obj.area()))
print("Perimeter of the circle: "+str(my_obj.perimeter()))