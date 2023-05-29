# Intuition
Just count the cars lmao. I don't see the significance of this being a daily problem.

# Approach
Use a class **ParkingSystem** to simulate a parking system with different types of parking spots (big, medium, and small). The class is initialized with the available number of spots for each type. The **addCar** method is then used to add a car of a specific type to the parking system. It checks if there are available spots of the corresponding type and decreases the count if a spot is allocated. The method returns **true** if a spot is allocated successfully and **false** otherwise.

Overall, the approach is to maintain the count of available spots for each car type and check if there are spots available when adding a car.

# Complexity
- Time complexity:
$$O(1)$$

- Space complexity:
$$O(1)$$

# Code
```c++
class ParkingSystem {
private:
    int bigSpots;
    int mediumSpots;
    int smallSpots;

public:
    ParkingSystem(int big, int medium, int small) {
        bigSpots = big;
        mediumSpots = medium;
        smallSpots = small;
    }

    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (bigSpots > 0) {
                    bigSpots--;
                    return true;
                }
                break;
            case 2:
                if (mediumSpots > 0) {
                    mediumSpots--;
                    return true;
                }
                break;
            case 3:
                if (smallSpots > 0) {
                    smallSpots--;
                    return true;
                }
                break;
        }
        return false;
    }
};
```