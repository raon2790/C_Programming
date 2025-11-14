//#include <iostream>
//using namespace std;
//
//class Rect_P1 {
//    int width, height;
//public:
//    Rect_P1(int w = 0, int h = 0) : width(w), height(h) {}
//    friend bool equals(Rect_P1 r1, Rect_P1 r2);
//};
//
//bool equals(Rect_P1 r1, Rect_P1 r2) {
//    return (r1.width * r1.height) == (r2.width * r2.height);
//}
//
//int main() {
//    Rect_P1 a(3, 4), b(2, 6), c(4, 4);
//    cout << boolalpha;
//    cout << "a vs b (12 vs 12): " << equals(a, b) << "\n";
//    cout << "a vs c (12 vs 16): " << equals(a, c) << "\n";
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Rect_P2; // forward
//
//class RectManager_P2 {
//public:
//    bool equals(Rect_P2 r1, Rect_P2 r2);
//};
//
//class Rect_P2 {
//    int width, height;
//public:
//    Rect_P2(int w=0, int h=0) : width(w), height(h) {}
//    friend bool RectManager_P2::equals(Rect_P2 r1, Rect_P2 r2);
//};
//
//bool RectManager_P2::equals(Rect_P2 r1, Rect_P2 r2) {
//    return (r1.width * r1.height) == (r2.width * r2.height);
//}
//
//int main() {
//    RectManager_P2 mgr;
//    Rect_P2 a(3,4), b(2,6), c(4,4);
//    cout << boolalpha;
//    cout << "a vs b (12 vs 12): " << mgr.equals(a,b) << "\n";
//    cout << "a vs c (12 vs 16): " << mgr.equals(a,c) << "\n";
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Power_P3 {
//    int kick, punch;
//public:
//    Power_P3(int k=0, int p=0) : kick(k), punch(p) {}
//    Power_P3 operator+(const Power_P3& other) const {
//        return Power_P3(kick + other.kick, punch + other.punch);
//    }
//    bool operator==(const Power_P3& other) const {
//        return kick == other.kick && punch == other.punch;
//    }
//    Power_P3& operator+=(const Power_P3& other) {
//        kick += other.kick; punch += other.punch; return *this;
//    }
//    Power_P3 operator+(int n) const {
//        return Power_P3(kick + n, punch + n);
//    }
//    void show() const { cout << "(" << kick << "," << punch << ")"; }
//};
//
//int main() {
//    Power_P3 a(3,5), b(2,4);
//    Power_P3 c = a + b;      // (5,9)
//    Power_P3 d = a + 10;     // (13,15)
//    bool eq = (a == Power_P3(3,5));
//    a += b;                  // (5,9)
//
//    cout << "c="; c.show(); cout << "\n";
//    cout << "d="; d.show(); cout << "\n";
//    cout << "eq=" << boolalpha << eq << "\n";
//    cout << "a+="; a.show(); cout << "\n";
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Power_P4 {
//    int kick, punch;
//public:
//    Power_P4(int k=0, int p=0) : kick(k), punch(p) {}
//    void show() const { cout << "(" << kick << "," << punch << ")"; }
//
//    friend Power_P4 operator+(int n, const Power_P4& rhs);
//    friend Power_P4 operator+(const Power_P4& a, const Power_P4& b);
//    friend Power_P4& operator++(Power_P4& x);      // prefix
//    friend Power_P4 operator++(Power_P4& x, int);  // postfix
//};
//
//Power_P4 operator+(int n, const Power_P4& rhs) {
//    return Power_P4(rhs.kick + n, rhs.punch + n);
//}
//Power_P4 operator+(const Power_P4& a, const Power_P4& b) {
//    return Power_P4(a.kick + b.kick, a.punch + b.punch);
//}
//Power_P4& operator++(Power_P4& x) { // ++x
//    ++x.kick; ++x.punch; return x;
//}
//Power_P4 operator++(Power_P4& x, int) { // x++
//    Power_P4 temp = x; x.kick++; x.punch++; return temp;
//}
//
//int main() {
//    Power_P4 a(1,2), b(3,4);
//    Power_P4 c = 10 + a;     // (11,12)
//    Power_P4 d = a + b;      // (4,6)
//    Power_P4 e = a++;        // e=(1,2), a=(2,3)
//    ++b;                     // b=(4,5)
//
//    cout << "c="; c.show(); cout << "\n";
//    cout << "d="; d.show(); cout << "\n";
//    cout << "e(before a++)="; e.show(); cout << " a(after a++)="; a.show(); cout << "\n";
//    cout << "++b="; b.show(); cout << "\n";
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Power_P5 {
//    int kick, punch;
//public:
//    Power_P5(int k=0, int p=0) : kick(k), punch(p) {}
//    bool operator!() const { return kick==0 && punch==0; }
//    void show() const { cout << "(" << kick << "," << punch << ")"; }
//};
//
//int main() {
//    Power_P5 zero(0,0), nonzero(3,0);
//    cout << boolalpha;
//    cout << "!zero=" << (!zero) << "  !nonzero=" << (!nonzero) << "\n";
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Power_P6 {
//    int kick, punch;
//public:
//    Power_P6(int k=0, int p=0) : kick(k), punch(p) {}
//    Power_P6& operator<<(int n) { kick += n; punch += n; return *this; }
//    void show() const { cout << "(" << kick << "," << punch << ")"; }
//};
//
//int main() {
//    Power_P6 a(0,0);
//    a << 3 << 5 << 6; // (14,14)
//    cout << "a="; a.show(); cout << "\n";
//    return 0;
//}