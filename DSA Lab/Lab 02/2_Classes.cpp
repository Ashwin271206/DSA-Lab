#include <iostream>
using namespace std;

class area
{
private:
    float length, breadth, height;

public:
    area()
    {
        length = 1;
        breadth = 1;
        height = 1;
    }

    void setSquare(float len)
    {
        length = len;
    }
    void setRectangle(float len, float bre)
    {
        length = len;
        breadth = bre;
    }
    void setCube(float len)
    {
        length = len;
    }
    void setCuboid(float len, float bre, float hei)
    {
        length = len;
        breadth = bre;
        height = hei;
    }

    void getSquare()
    {
        cout << "Area of Square : " << length * length << endl;
    }
    void getCube()
    {
        cout << "Surface Area of Cube: " << 6 * length * length << endl;
    }
    void getRectangle()
    {
        cout << "Area of Rectangle: " << length * breadth << endl;
    }
    void getCuboid()
    {
        cout << "Surface Area of Cuboid: " << 2 * (length * breadth + breadth * height + height * length) << endl;
    }
};

int main()
{
    int choice, stop = 0;
    float len, bre, hei;
    area shape;
    while (!stop)
    {
        printf("\n\nMenu : \n 1. Square\n 2. Cube\n 3. Rectangle\n 4. Cuboid\n 5. Exit\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cout << "\nEnter side of square: ";
            cin >> len;
            shape.setSquare(len);
            shape.getSquare();
            break;
        case 2:
            cout << "\nEnter side of cube: ";
            cin >> len;
            shape.setCube(len);
            shape.getCube();
            break;
        case 3:
            cout << "\nEnter length of rectangle: ";
            cin >> len;
            cout << "\nEnter breadth of rectangle: ";
            cin >> bre;
            shape.setRectangle(len, bre);
            shape.getRectangle();
            break;
        case 4:
            cout << "\nEnter length of cuboid: ";
            cin >> len;
            cout << "\nEnter breadth of cuboid: ";
            cin >> bre;
            cout << "\nEnter height of cuboid: ";
            cin >> hei;
            shape.setCuboid(len, bre, hei);
            shape.getCuboid();
            break;
        case 5:
            stop = 1;
            cout << "Exitting program.\n";
            break;
        default:
            cout << "Invalid Choice.\n\n";
            break;
        }
    }
}
