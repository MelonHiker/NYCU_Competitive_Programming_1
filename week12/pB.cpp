#include <bits/stdc++.h>
using namespace std;

// Constants
constexpr double EPS = 1e-10;
constexpr double PI = 3.14159265358979323846;

/**
 * 2D point/vector class with common geometric operations
 */
template <typename T = double>
class Point2D {
public:
    T x, y;

    // Constructors
    Point2D() : x(0), y(0) {}
    Point2D(T _x, T _y) : x(_x), y(_y) {}

    // Vector operations
    Point2D operator+(const Point2D& p) const { return Point2D(x + p.x, y + p.y); }
    Point2D operator-(const Point2D& p) const { return Point2D(x - p.x, y - p.y); }
    Point2D operator*(T scalar) const { return Point2D(x * scalar, y * scalar); }
    Point2D operator/(T scalar) const { return Point2D(x / scalar, y / scalar); }

    // Dot product
    T dot(const Point2D& p) const { return x * p.x + y * p.y; }

    // Cross product
    T cross(const Point2D& p) const { return x * p.y - y * p.x; }

    // Euclidean norm squared
    T normSquared() const { return dot(*this); }

    // Euclidean norm (length)
    double norm() const { return sqrt(normSquared()); }

    // Distance to another point
    double distanceTo(const Point2D& p) const {
        return (*this - p).norm();
    }

    // Equality comparison
    bool operator==(const Point2D& p) const {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }

    bool operator!=(const Point2D& p) const {
        return !(*this == p);
    }
    
    // Lexicographical comparison for sorting
    bool operator<(const Point2D& p) const {
        return (x < p.x) || (abs(x - p.x) < EPS && y < p.y);
    }
};

/**
 * Compute the cross product (p2-p1) × (p3-p1)
 */
template <typename T>
T crossProduct(const Point2D<T>& p1, const Point2D<T>& p2, const Point2D<T>& p3) {
    return (p2 - p1).cross(p3 - p1);
}

/**
 * Compute the dot product (p2-p1) · (p3-p1)
 */
template <typename T>
T dotProduct(const Point2D<T>& p1, const Point2D<T>& p2, const Point2D<T>& p3) {
    return (p2 - p1).dot(p3 - p1);
}

/**
 * Class for convex hull calculations and related geometric algorithms
 */
template <typename T = double>
class ConvexHull {
private:
    vector<Point2D<T>> points;       // Input points
    vector<Point2D<T>> hullPoints;   // Points on the convex hull

public:
    // Constructor with initial points
    explicit ConvexHull(const vector<Point2D<T>>& inputPoints = {}) : points(inputPoints) {}

    // Add a point to the input set
    void addPoint(const Point2D<T>& point) {
        points.push_back(point);
    }

    // Add multiple points to the input set
    void addPoints(const vector<Point2D<T>>& newPoints) {
        points.insert(points.end(), newPoints.begin(), newPoints.end());
    }

    // Clear all points
    void clear() {
        points.clear();
        hullPoints.clear();
    }

    // Compute the convex hull using Andrew's monotone chain algorithm
    void compute() {
        if (points.size() <= 2) {
            hullPoints = points;
            return;
        }

        // Sort points lexicographically
        sort(points.begin(), points.end());
        
        hullPoints.clear();
        int n = points.size();
        
        // Build lower hull
        for (int i = 0; i < n; i++) {
            while (hullPoints.size() >= 2 && 
                   (hullPoints.back() - hullPoints[hullPoints.size() - 2]).cross(points[i] - hullPoints[hullPoints.size() - 2]) <= 0) {
                hullPoints.pop_back();
            }
            hullPoints.push_back(points[i]);
        }
        
        // Build upper hull
        size_t lower_hull_size = hullPoints.size();
        for (int i = n - 2; i >= 0; i--) {
            while (hullPoints.size() > lower_hull_size && 
                   (hullPoints.back() - hullPoints[hullPoints.size() - 2]).cross(points[i] - hullPoints[hullPoints.size() - 2]) <= 0) {
                hullPoints.pop_back();
            }
            hullPoints.push_back(points[i]);
        }
        
        // Remove duplicate (last point is same as first)
        if (hullPoints.size() > 1) {
            hullPoints.pop_back();
        }
    }

    // Get perimeter of the convex hull
    T getPerimeter() const {
        T perimeter = T(0);
        if (hullPoints.size() <= 1) return perimeter;
        
        for (size_t i = 0; i < hullPoints.size(); i++) {
            perimeter += hullPoints[i].distanceTo(hullPoints[(i + 1) % hullPoints.size()]);
        }
        return perimeter;
    }

    // Get area of the convex hull
    T getArea() const {
        if (hullPoints.size() < 3) return T(0);
        
        T area = T(0);
        Point2D<T> origin(0, 0);
        for (size_t i = 0; i < hullPoints.size(); i++) {
            size_t j = (i + 1) % hullPoints.size();
            area += crossProduct(origin, hullPoints[i], hullPoints[j]);
        }
        return abs(area) / T(2);
    }

    // Get diameter of the convex hull (farthest point pair)
    T getDiameter() const {
        if (hullPoints.size() <= 1) return T(0);
        if (hullPoints.size() == 2) return hullPoints[0].distanceTo(hullPoints[1]);
        
        // Rotating calipers algorithm
        T maxDist = T(0);
        size_t j = 1;
        for (size_t i = 0; i < hullPoints.size(); i++) {
            while (abs(crossProduct(
                hullPoints[i], hullPoints[(i+1) % hullPoints.size()], hullPoints[(j+1) % hullPoints.size()])) > 
                abs(crossProduct(
                hullPoints[i], hullPoints[(i+1) % hullPoints.size()], hullPoints[j % hullPoints.size()]))) {
                j++;
                if (j >= hullPoints.size()) j %= hullPoints.size();
            }
            
            maxDist = max(maxDist, static_cast<T>(hullPoints[i].distanceTo(hullPoints[j % hullPoints.size()])));
            maxDist = max(maxDist, static_cast<T>(hullPoints[(i+1) % hullPoints.size()].distanceTo(hullPoints[j % hullPoints.size()])));
        }
        return maxDist;
    }

    // Find maximum area triangle in the convex hull
    T getMaxTriangleArea() const {
        if (hullPoints.size() < 3) return T(0);
        
        T maxArea = T(0);
        size_t n = hullPoints.size();

        // Rotating caliper approach
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1, k = i + 1; j < n; j++) {
                // Find the farthest point from edge (i,j)
                while (abs(crossProduct(hullPoints[i], hullPoints[j], hullPoints[(k + 1) % n])) > 
                       abs(crossProduct(hullPoints[i], hullPoints[j], hullPoints[k]))) {
                    k = (k + 1) % n;
                }
                maxArea = max(maxArea, abs(crossProduct(hullPoints[i], hullPoints[j], hullPoints[k])));
            }
        }
        return maxArea / T(2);
    }
    
    // Get barycenter (center of mass) of the convex hull
    Point2D<T> getBarycenter() const {
        if (hullPoints.size() < 3) {
            if (hullPoints.empty()) return Point2D<T>(0, 0);
            if (hullPoints.size() == 1) return hullPoints[0];
            return Point2D<T>((hullPoints[0].x + hullPoints[1].x) / T(2), 
                              (hullPoints[0].y + hullPoints[1].y) / T(2));
        }
        
        Point2D<T> barycenter(0, 0);
        T totalArea = T(0);
        
        for (size_t i = 1; i < hullPoints.size() - 1; i++) {
            T area = abs(crossProduct(hullPoints[0], hullPoints[i], hullPoints[i+1])) / T(2);
            Point2D<T> center = (hullPoints[0] + hullPoints[i] + hullPoints[i+1]) / T(3);
            barycenter = barycenter + center * area;
            totalArea += area;
        }
        
        if (totalArea > T(0)) {
            barycenter = barycenter / totalArea;
        }
        return barycenter;
    }

    // Find minimum area enclosing rectangle
    pair<T, T> getMinRectangle() const {
        if (hullPoints.size() <= 1) return {T(0), T(0)};
        if (hullPoints.size() == 2) {
            T length = static_cast<T>(hullPoints[0].distanceTo(hullPoints[1]));
            return {T(0), T(2) * length};
        }
        
        T minArea = numeric_limits<T>::max();
        T minPerimeter = numeric_limits<T>::max();
        size_t n = hullPoints.size();
        size_t j = 1, k = 1, r = 1;
        for (size_t i = 0; i < n; i++) {
            // Get the base vector
            Point2D<T> baseVec = hullPoints[j] - hullPoints[i];
            T baseLen = static_cast<T>(baseVec.norm());
            
            // Find extreme points
            while (abs(crossProduct(hullPoints[i], hullPoints[j], hullPoints[(k+1) % n])) > 
                  abs(crossProduct(hullPoints[i], hullPoints[j], hullPoints[k]))) {
                k = (k + 1) % n;
            }
            
            // Compute height
            T height = abs(crossProduct(hullPoints[i], hullPoints[j], hullPoints[k])) / baseLen;
            
            // Find opposite extreme points
            while (dotProduct(hullPoints[i], hullPoints[j], hullPoints[(k+1) % n]) > 
                  dotProduct(hullPoints[i], hullPoints[j], hullPoints[k])) {
                k = (k + 1) % n;
            }
            
            if (i == 0) r = k;
            
            while (dotProduct(hullPoints[i], hullPoints[j], hullPoints[(r+1) % n]) <= 
                  dotProduct(hullPoints[i], hullPoints[j], hullPoints[r])) {
                r = (r + 1) % n;
            }
            
            // Compute width
            T width = (dotProduct(hullPoints[i], hullPoints[j], hullPoints[k]) - 
                      dotProduct(hullPoints[i], hullPoints[j], hullPoints[r])) / baseLen;
            
            // Update min area and perimeter
            T area = width * height;
            T perimeter = T(2) * (width + height);
            minArea = min(minArea, area);
            minPerimeter = min(minPerimeter, perimeter);
        }
        return {minArea, minPerimeter};
    }

    // Get the points on the convex hull
    const vector<Point2D<T>>& getHullPoints() const {
        return hullPoints;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ConvexHull<long double> hull;
    
    // Read points
    for (int i = 0; i < n; ++i) {
        long double x, y;
        cin >> x >> y;
        hull.addPoint(Point2D<long double>(x, y));
    }
    
    // Compute convex hull
    hull.compute();
    cout << fixed << setprecision(10) << hull.getMaxTriangleArea() << '\n';
}