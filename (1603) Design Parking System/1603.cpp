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