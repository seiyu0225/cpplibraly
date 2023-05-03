#include <cmath>
const double PI = acos(-1);
double get_henkaku(double y, double x) {
    return atan2(y, x) * 180 / PI;
}
