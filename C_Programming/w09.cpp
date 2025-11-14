//#include <iostream>
//
//using namespace std;
//
//// Base 클래스 (제공된 내용)
//class Base
//{
//protected:
//    int x;
//public:
//    void setX(int x) { this->x = x; }
//    void showX() { cout << "x=" << x << endl; }
//};
//
//// Derived 클래스 (요구사항 구현)
//class Derived : public Base // public 상속
//{
//private:
//    int y; // int y 멤버 추가
//public:
//    // setY(int) 멤버 함수 구현
//    void setY(int y) { this->y = y; }
//
//    // showXY() 멤버 함수 구현 (x와 y 값을 모두 출력)
//    void showXY() {
//        // Base의 protected 멤버 x에 직접 접근 가능
//        cout << "x=" << x << ", y=" << y << endl;
//    }
//};
//
//int main()
//{
//    Derived d; // Derived 객체 생성
//
//    // x=3, y=7을 대입
//    d.setX(3); // Base 클래스의 멤버 함수 호출
//    d.setY(7); // Derived 클래스의 멤버 함수 호출
//
//    // 출력
//    d.showXY(); // x와 y 값 모두 출력
//
//    return 0;
//}


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Point {
//protected:
//    int x, y;
//public:
//    void set(int x, int y) { this->x = x; this->y = y; }
//    void showPoint() { cout << "(" << x << ", " << y << ")" << endl; }
//};
//
//class ColorPoint : public Point {
//    string color;
//public:
//    void setColor(string color) { this->color = color; }
//    void showColorPoint() {
//        cout << color << ": ";
//        showPoint();
//    }
//};
//
//int main()
//{
//    // 1. ColorPoint cp 객체 생성 및 초기화
//    ColorPoint cp;
//    cp.set(10, 20);
//    cp.setColor("Red");
//
//    // 2. Point* pBase = &cp; (업캐스팅)
//    // 파생 클래스(ColorPoint)의 주소를 기본 클래스(Point) 포인터에 대입
//    Point* pBase = &cp;
//
//    // 3. pBase를 사용해 좌표 출력 (기본 클래스의 함수만 호출 가능)
//    cout << "--- 업캐스팅 (pBase 사용) ---" << endl;
//    pBase->showPoint();
//
//    // 4. 다운캐스팅하여 색상까지 출력
//    // 기본 클래스 포인터를 파생 클래스 포인터로 강제 변환 (명시적 캐스팅)
//    ColorPoint* pDerived = (ColorPoint*)pBase;
//
//    cout << "--- 다운캐스팅 (pDerived 사용) ---" << endl;
//    pDerived->showPoint(); // Point의 함수 호출
//    pDerived->showColorPoint(); // ColorPoint의 고유 함수 호출
//
//    return 0;
//}


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class TV {
//    int size;
//public:
//    // 기본 생성자 (default constructor)
//    TV() { size = 20; }
//    // 매개변수 있는 생성자
//    TV(int size) { this->size = size; }
//    int getSize() { return size; }
//};
//
//// WideTV는 TV를 상속
//class WideTV : public TV {
//    bool videoIn;
//public:
//    // WideTV 생성자도 부모 TV의 생성자를 호출해야 함
//    // 여기서는 기본 생성자만 호출한다고 가정
//    WideTV() : TV() { videoIn = false; }
//    WideTV(int size, bool videoIn) : TV(size) { // 부모(TV) 생성자 호출
//        this->videoIn = videoIn;
//    }
//    bool hasVideoIn() { return videoIn; }
//};
//
//// SmartTV는 WideTV를 상속
//class SmartTV : public WideTV {
//    string ip;
//public:
//    // SmartTV 생성자에서 부모(WideTV) 생성자 호출하여 초기화
//    SmartTV(int size, bool videoIn, string ip)
//        : WideTV(size, videoIn) // WideTV의 생성자 호출 (TV의 생성자도 간접적으로 호출됨)
//    {
//        this->ip = ip;
//    }
//
//    void showInfo() {
//        cout << "TV Size: " << getSize() << " inches" << endl; // TV의 getSize() 사용
//        cout << "Video-In: " << (hasVideoIn() ? "Yes" : "No") << endl; // WideTV의 hasVideoIn() 사용
//        cout << "IP Address: " << ip << endl;
//    }
//};
//
//int main()
//{
//    // SmartTV 객체 생성 시, 부모(WideTV)와 조상(TV)의 생성자도 호출하여 초기화
//    SmartTV mySmartTV(55, true, "192.168.1.100");
//
//    cout << "Smart TV Information:" << endl;
//    mySmartTV.showInfo();
//
//    return 0;
//}


//#include <iostream>
//#include <stdexcept> // 예외 처리를 위해
//
//using namespace std;
//
//class Adder {
//protected:
//    int add(int a, int b) { return a + b; }
//};
//
//class Subtractor {
//protected:
//    int minus(int a, int b) { return a - b; }
//};
//
//// Calculator 클래스가 Adder와 Subtractor를 다중 상속
//class Calculator : public Adder, public Subtractor {
//public:
//    // calc(char op, int a, int b) 함수 구현
//    int calc(char op, int a, int b) {
//        if (op == '+') {
//            // '+' → add() 호출 (Adder 클래스의 protected 멤버 함수)
//            return add(a, b);
//        }
//        else if (op == '-') {
//            // '-' → minus() 호출 (Subtractor 클래스의 protected 멤버 함수)
//            return minus(a, b);
//        }
//        else {
//            // 지원하지 않는 연산자에 대한 처리
//            cout << "Error: Unsupported operator (" << op << ")" << endl;
//            // 실습이므로 간단히 -1 반환하도록 할게.
//            return -1;
//        }
//    }
//};
//
//int main()
//{
//    Calculator cal;
//
//    int result_add = cal.calc('+', 10, 5);
//    cout << "10 + 5 = " << result_add << endl; // 15
//
//    int result_minus = cal.calc('-', 10, 5);
//    cout << "10 - 5 = " << result_minus << endl; // 5
//
//    int result_error = cal.calc('*', 10, 5); // 에러 처리 확인
//
//    return 0;
//}


