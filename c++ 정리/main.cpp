// r 레퍼런스는 const 레퍼런스 읽기 전용이랑 비슷한느낌인데 
// 쓰기를 하기위해 사용한다
// 상수메모리의 메모리는쓰는데 
// 참조하는 메모리는 같은데 그곳의 값을 수정했다 라는 느낌?

// &&하는이유는  move함수로 &로변경하려고 상수를 L value로 바꾸려는 의도로 사용한다.
// std::move 함수를 통해 L-value를 R-value로 변경해준다.
// 임시객체는 r -value


// const Class& _rhs 매개변수로 어떤 l-value를 받으면
// 함수내부에서 참조한 대상의 값을 수정할수없다
// 함수내부에서 &형식으로 복사비용을 안들이면서 넘겨받고 수정을 하고 값을 수정하고싶을수가있다.
// 그럼 const 뺴고 &로 받으면 안되나? 맞는말이다
// 근데 만약 넘겨주는 인자가 임시객체라면? const & 형식으론 받을수 없을것이다.
// 따라서 && R-value 레퍼런스로 받는것이다. 
// 9번 줄의 L-value를 R-value로 바꿔줄수도 있다는 이야기는 함수 내부에서 또 복사가 일어날 경우이다.



// C++ 정리

// 객체를 생성하다 : 메모리 할당 > 생성자 호출
// 객체를 소멸하다 : 소멸자 호출 > 메모리 반환
// 
// 클래스 생성시 생성하지 않아도 자동으로 생성되는 것 4가지
// 1. 디폴트 생성자
// 2. 디폴트 복사 생성자
// 3. 디폴트 대입 연산자
// 4. 디폴트 소멸자
// 이 녀석들은 내가 따로 오버로딩하여 구현하면 디폴트로 생성되지 않음.
 
// 객체지향 프로그래밍(OOP)에 대한 4가지 특성
// 1. 추상화
// 2. 캡슐화     // 여기서 은닉화가 이루어짐
// 3. 다형성
// 4. 상속성
 
// 전방선언 : 상호 참조를 해결하는 문법
// 예를 들어 B라는 클래스에서 A라는 클래스 자료형을 사용하고싶음
// 근데 헤더파일을 A클래스가 담긴 헤더파일을 참조시키지 않으면
// 자료형을 알수 없기에 B클래스에서 A클래스 헤더를 참조한다.
// 여기까지의 상황에선 문제가 없다.
// 
// 하지만 만약 A클래스가 담긴 헤더파일에서도 B클래스의 자료형을 사용하고싶을경우
// A클래스가 담긴 헤더에서 B클래스의 헤더를 참조시키고 이로인해 A > B B > A
// 무한루프에 빠지는 상호참조 문제가 발생하게 된다.
// 
// 이를 해결하기 위해 class B;, class A; 라는 전방선언을하고
// 해당 클래스에서 다른 클래스의 자료형을 사용할땐 항상 포인터로 변수를 선언해주고
// 그 변수를 사용하여 쓰기 또는 멤버 변수에 참조하고 싶을 영역의 파일에서 반드시
// 해당 클래스 자료형의 헤더를 참조시켜주어야한다.
// 
// 
// 
// 클래스의 멤버변수중 const 멤버변수가 존재할 경우 이놈은 심볼릭 상수이기에
// 생성자의 이니셜라이저에서만 초기화가 가능하다.
// 또한 const 멤버변수는 함수 몸체 내부에서 다른 멤버변수의 쓰기가 불가능하다. (읽기만 가능)
// 또한 Render(), Render()const 이렇게 두가지 함수가 있을경우 const 키워드로 오버로딩이 가능하다.
// 객체를 생성할때 const 키워드를 붙이면 const가 붙은 멤버함수만 사용가능하다.
// const 멤버함수가 아닐경우 다른 멤버함수에서 객체의 멤버값을 변경시킬수 있기때문에 안됨


// static 멤버 변수는 항상 초기화를 클래스 외부에서 해주어야함
// 가령 클래스이름이 Base면 클래스 외부에서 int Base::m_staticInt = 0; 이런식으로 초기화해야함
// static 멤버함수는 함수 몸체에서 static 멤버변수 이외의 멤버는 사용불가능
// static 멤버함수 내부엔 this라는 개념이 존재하지 않기때문임

// class CYY
// {
// public:
// 
// public:
// 	static void yFun()
// 	{
// 		a; // 컴파일 에러
// 		b = 1; // 가능
// 	}
// 
// private:
// 	int a;
// 	static int b;
// 
// };


// friend 키워드를 사용하면 어떤 A클래스 내부에서 B클래스의 private등 접근이 제한되어있는 요소들을 접근할수있다.
// 이때 friend 키워드는 만약 A에서 B의 기능을 쓰고싶다면 B에서 friend 선언을 해주어야한다.
// friend 의 선언 위치는 항상 클래스 내부여야한다.
// friend 키워드를 함수 앞부분에 선언하게 된다면 그 함수 내부에서 friend 키워드를 선언한 클래스의 private 멤버에 접근할수 있다.
// friend 키워드를 내가 사용할 함수에만 붙일지, 그 클래스 전체전부를 쓸거면 클래스에 붙일지는 선택의 영역이다.


// 오버라이딩 할때 기본적으로 부모포인터 형으로 자식의 주소를 가르키는 (업캐스팅)을 활용한다
// 이를 다형성이라 한다. 하지만 이때 부모포인터형으로 자식을 가르켰기에
// 부모 클래스의 멤버만 접근할수있다. (컴파일시에 정해지는 정적 바인딩 이기때문)
// 하여 자식에 구현된 멤버를 접근하기위해 2가지 방법이 있다.
// 1. 내가 사용할 함수를 virtual 키워드를 사용해 가상함수테이블과 버추얼 포인터를 생성시켜 동적바인딩 하는방법
// 2. 다운캐스팅을 하는방법

// virtual을 사용할시 
// 자식 클래스의 vtable은 부모 클래스의 vtable 값이 그대로 복사되며,
// 오버라이딩 된 함수만 주소가 새로 업데이트 된다고 한다. ( 오버라이딩하였으면 아에 주소가 다르니 당연히 다른곳의 함수를 참조)
// 그리고 만약 자식 클래스에 부모에 없는 새로운 가상함수를 추가할 경우, 객체의 vtable 마지막 부분에 추가된다.
// 출처: https://cosyp.tistory.com/228 [nothing blog:티스토리]
// 가상함수 테이블에 저장되는 가상함수 주소를 변경하면? 해킹..
// 만약 부모에서 만드는 함수를 죄다 가상함수로 만들어버리면?
// 자식 가상함수 테이블에서 사용하지도 않는 가상함수가 적재되어 있을것이고 이는 필연적으로 오버헤드를 발생시킴
// 동적 바인딩은 필수적이지만 무분별한 가상함수를 테이블에 올릴시 성능 저하도 따라오게 된다.
// 결론: 가상함수 테이블은 클래스마다 별개로 가지고 있다. 부모랑 자식은 서로 다른 가상함수테이블을 가지고있는것

// final 키워드 , abstract
// final 붙히면 더이상 그 클래스의 자식은 생겨날수없따
// 
// abstract 는 최 상위 부모 클래스에 보통 쓰는데
// 명시적으로 abstract를 써주거나 
// ex) virtual void fun() =0; 순수가상함수를 만들어주면 해당 클래스는 추상클래스가 되어 객체 생성이 불 가 능!
// 순수가상함수는 그래서 반드시 상속받는 자식쪽에서 오버라이딩을 무 조 건 해줘야함!
// 동물클래스는 울음소리를 구현하는것이 추상적이니 얘를 추상클래스로 올리고 동물쪽에서 구현하는 방식이 맞음


// 캐스팅
// static_cast , dynamic_cast , const_cast , reinterpret_cast
// static_cast는 걍 C 시절 묵시적 캐스팅이랑 비슷함 근데 약간 안정성을 더 추가한느낌임
// ex C언어시절


void Fun()
{
	//int a = 10;
	//float f = 5.5f;
	//
	//a = f;   //  << 묵시적 캐스팅 이때 0.5가 잘리고 5만 들어감 안정성보장 X
	//a = static_cast<int>(f); // 변수의 대입은 상관없음
	//
	//int* p = &a;
	//float* fp = &f;
	//
	// p = (int*)fp;   // 명시적 캐스팅으로 어거지로 넣기 가능 근데 내가 의도한 동작이 아니죠
	// p = static_cast<int*>(fp); // 이때 이걸써주면 컴파일오류를내서 막아줄수 있음
	// 컴파일시에 내가 의도한 동작을 잡아낼수있음
	// 근데 이것도 한계가 있는데 논리적(상속구조가 아닌 형변환만 막아주는거라서 한계가잇음 // 정적 캐스팅)
	// 예를 들어 내가 상속 관계를 가진 클래스 2개의 형변환을 할시 내가 실제 가르키는 주소가 자식 주소가 아닌데
	// ex) 이때 상황이 자식포인터형 포인터변수로 부모의 주소에 접근할때 문제   아래 예시를 보도록하자.
	
	class Parent
	{
	public:

	};

	class Devir : public Parent
	{

	};

	class A
	{

	};

	Devir* p = static_cast<Devir*>(new Parent());

	// 자식포인터형으로 static_cast를 할경우 컴파일시점에선 문제가 없지만 (상속관계니까 논리적으로 맞다고 판단)
	// 런타임에 문제가 될 소지가 있다 그래서 dynamic_cast를 사용하면 nullptr을 반환해서 좀더 안전
	// 하지만 RTTI (동적 바인딩)을 사용함으로 속도가 좀 떨어짐 그래서 확실할때만 static_cast쓰고
	// 살짝 중요한부분에만 dynamic_cast를 쓰도록 하자

	// dynamic_cast로 다운캐스팅 사용하려면 조건이 있는데
	// 1. 객체간의 포인터형으로만 사용가능
	// 2. 상속을 조건으로 부모포인터형으로 가르키는곳을 자식포인터형으로 바꾸기 위함임
	// 3. 부모클래스에서 무조건 virtual 키워드가 있어야 가능함

	// const_cast 는 일시적으로 const 성향을 벗겨준다 포인터나 레퍼런스형식만 사용가능 
	// reinterpret_cast 명시적 캐스팅이랑 비슷 근데 안쓸것을 권장

	// 인라인 함수 함수 코드를 메모리에 적재시키지않고 호출시점에 바로 삽입함
	// 근데 인라인 함수가 자동으로 일반함수로 변할때는 함수포인터에 인라인 함수를 저장할때 라던지 인라인 함수를 재귀적으로 호출할때 등등

	// 함수포인터와 함수객체
	// 함수포인터는 인라인화가 될수없지만 함수객체는 인라인화가 가능하여 최적화에 도움이 된다.
	// 함수객체는 멤버변수를 추가적으로 소유할수 있어서 부득이한 어떤 조건에인하여 추가 동작을 도울수 있다.
	// 함수포인터와 함수객체의 실제 사용하는 예시는 좀더 프로젝트를 만들어보면서 고민해봐야할것같다.
	

	// 템플릿
	// 템플릿 함수의 우선순위는 특수화가 우선순위가 가장높고, 이후에는 알맞은 코드가 2순위이다.
	// 물론 일반함수가 존재한다면 일반함수가 가장 우선순위가 높다.
	// 템플릿함수 내부에 static 템플릿변수가 있다면 해당 변수의 자료형에 따라 개별적으로 메모리공간을 소유하게된다.
	// 함수 템플릿의 특수화는 template<>를 선언하면 끝이지만
	// 클래스 템플릿의 경우 클래스 이름 뒤에 <int>같이 명시적으로 작성을 해주어야함


	//template <>
	//class Counter<double> {   // << 이쪽이 함수템플릿의 특수화랑 다른부분
	//	double count;
	//public:
	//	Counter() { count = 0; }
	//	double getCount() { return count; }
	//	void inc_count(double n) { count += n; }
	//	void dec_count(double n) { count -= n; }
	//};
	/////  위의 예시는 클래스템플릿 특수화 이다 
	///// 
	///// 
	///// 
	///// 
	//template <typename T1, typename T2>
	//class Calculator {
	//	double result;
	//public:
	//	Calculator() { result = 0; }
	//	double addValue(T1 a, T2 b);
	//	double difValue(T1 a, T2 b);
	//	double mulValue(T1 a, T2 b);
	//	double divValue(T1 a, T2 b);
	//};
	/////  위의 템플릿 클래스가 있을때 특수화를하면?
	///// 
	///// 
	///// 
	//template <typename T1>
	//class Calculator<T1, double> {    // << 이처럼 해줘야한다.
	//	double result;
	//public:
	//	Calculator() { result = 0; }
	//	double addValue(T1 a, double b);
	//	double difValue(T1 a, double b);
	//	double mulValue(T1 a, double b);
	//	double divValue(T1 a, double b);
	//};

	// 라이브러리
	// 라이브러리란? 바이너리 코드 (컴파일 된)함수들을 모아놓은 파일

	// STL
	//  표준 시퀀스 컨테이너 : vector, deque, list, array, forward_list (선형적 임)
	//
	//	- 표준 연관 컨테이너
	//
	//	- 정렬하는 연관 컨테이너 : set, multiset, map, multimap (비선형적 임)
	//	- 정렬하지 않는 연관 컨테이너(모던 C++ 이후 등장)
	//	: unordered_set, unordered_multiset, unordered_map, unordered_multimap

	// 메모리 저장방법에 따른 구분
	// 배열 기반: vector, array , deque
	// 노드 기반: map,set,list.. 등등
	
	// 컨테이너 어댑터: 기존 컨테이너의 일부 기능만 사용하며, 기능제한이나 기능변형이 있는 컨테이너
	// queue, stack, priority_queue (우선순위 큐)

	// 근사 컨테이너: string, wstring 컨테이너로서의 기능은 가지지만 특정 자료형에 적용되는 예
	// 반복자: 포인터같이 동작하지만 포인터가 아니고 객체임

	// 반복자

	// 반복자의 오퍼레이션 오버로딩에 대한 이야기
	// 출력 반복자: * : 현재 iter가 가르키는곳의 읽기, 쓰기를 할수있게하는연산자
	// 입력 반복자: *, = : 현재 iter가 가르키는곳에 대입을하거나 어떤 데이터에 내가 가르키는 iter를 대입하는 연산
	// 순방향 반복자: *, =, ++  forword_list 같은거
	// 양방향 반복자: *, =, ++, --  list 같은거 앞과 뒤를 오갈수있음 노드기반 컨테이너는 전부 양방향임 forword_list 제외
	// 임의 접근 반복자: *,=,++,--, *=, +=, -= 등 vector처럼 메모리가 연속되어 있을때 
	// 포인터가 접근하는 방식처럼 p+3 이런식으로 임의접근이 가능 따라서 vector 컨테이너와
	// vector컨테이너의 iter는 [] 연산자를 오버로딩하고있음
	// 하지만 노드기반 컨테이너는 순서라는 개념이 없기에 [] 지원하지 않고있음
	
	// 또하나 중요한거 vector 에서의 iter가 insert,erase를 할때 iter = vecInt.insert(iter,10);
	// 라는 식으로 다음을 가르키는 iter로 변경해주지 않으면 std::vector는 이것을 문제라판단하고
	// 에러 발생시킴 재 할당이 되던 재 할당이 안되던 이때 iter는 불순하다고 판단하는것 같음
	// https://www.geeksforgeeks.org/iterator-invalidation-cpp/

	// 정리: 연관 컨테이너와 list는 insert시 iterator 무효화 발생하지않음
	// vector만 capacity변경 (배열 재할당) 또는 insert한 앞쪽을 가르키는 iter만 유효함 나머진 무효화시킴
	// 걍 머리아프니까 둘다 iter 다시 받도록하자.

	// erase시는 어짜피 다시 받아야함

}

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class CTest
{

private:
	int a;
	int b;
	int c;
	//CTest()
	//{}

public:

	void operator()()
	{

	}


	void operator =(const CTest& _ori)
	{

	}

	CTest(int a)
	{}

	CTest(const CTest& _ori)
		:a(_ori.a)
		,b(_ori.b)
		,c(_ori.c)
	{
	}

};

struct CStruct
{

	void operator()(int a, int b)
	{

	}

	CStruct(int a, int b)
	{

	}

	CStruct()
	{

	}
};


// CTest TestFun()
// {
// 	
// 	CTest a;
// 
// 	
// 	return CTest();
// }

template<typename T1, typename T2>
void test(T1 _test1, T2 _test2)
{
	strcmp(_test1, _test2); // 컴파일 에러 
}


//CTest fun()
//{
//	return CTest(1,2,3);
//}



class CTest1
{
public:
	
	CTest1()
		//:a(10)
		//,p(nullptr)
	{
		cout << "생성자 호출" << endl;
	}

	CTest1(int a)
	{
		cout << "매개변수";
	}

	CTest1(const CTest1& _ren)
	{
		
		cout << " 복사생성";
	}


	CTest1(CTest1&& _rhs)
	{
		cout << "이동 생성자";
	}

	void operator =(CTest1& a)
	{
		cout << " 대입연산 ";
	}

	void operator =(const CTest1& a)
	{
		cout << " 대입연산 ";
	}


//private:
//	int a;
//	int* p;
};



inline void fun();

void fun()
{

	cout << " 나는 인라인 함수" << endl;
}

int* funtest(int* p)
{

	return p;
}

//CTest1 abc(const CTest1& _ren)
//{
//
//	return CTest1();
//}

//template <typename T1>
//CTest1 abc(CTest1 a)
//{
//	//CTest1 gg = a;
//
//	return  CTest1(); // r-value 리턴  // RVO
//}


template<typename T>
void myFunction(T arg) {
	std::cout << "Argument: " << arg << std::endl;
}

// 함수 포인터를 매개변수로 받는 함수
template<typename T>
void doSomething(void (*funcPtr)(int), T arg) {
	funcPtr(arg);
}

void TestFun1(int _a)
{

}

int a12() {
	// 함수 템플릿을 함수 포인터로 전달
	doSomething(TestFun1, 42); // 인스턴스화할 타입을 명시적으로 지정해야 함

	return 0;
}


void main()
{
	CTest1 a{ 2 };

	 // const int& a = 5;
	//a12();

	//CTest1 a;

	//CTest1 b = abc(a);



	//CTest1 jjj = abc(CTest1());  // 복사생성 발생하고

	//CTest1 kkk = abc(CTest1());
	
	
	
	
	// 임시객체는 r-value이기때문에 매개변수받는쪽에서 const 선언이 없으면 문제



	//int b = 10;
	//int a = 5;
	//*funtest(&b) = a;   // 주소 자체는 r-value임  // 레퍼런스반환은 l-value니까 가능 

	// &b = nullptr // 이게 불가능한 이유 r- value이기 때문

	 //CTest1 a;					        //////// 기본생성자 호출
	 CTest1* pA = new CTest1;           //////// 기본생성자 호출
	 CTest1* pA2 = new CTest1();       //////// 기본생성자 호출
	 CTest1 a3();	         // 얘는 객체 생성이 아니라 반환형이 CTest1이고 함수이름이 a인 함수 선언을 의미
	



	// int a(5);
	// int& ren = a;
	// int& yy = ren;
	// yy = 10;
	// 
	// a; 
	// yy = nullptr;
	// 람다식
	//a3123();
	

	// Capple* a = new Capple;
	// Capple* a2 = new Capple();
	



	//CTest AA;     // 기본 생성자 호출
	//CTest A(1);   // 매개변수가 있는 생성자 호출
	//CTest C(A);   // 복사생성자 호출
	//CTest B = A;  // << 겉으로 보기엔 대입연산자 같지만 실제론 컴파일러가 최적화를 통해 복사 생성자를 호출하는 동작을 함


	// test(1, 2);  // << 이런 문제로 인하여 함수템플릿 특수화를 시켜주어야한다.

	// int		iNumber(10);
	// 
	// const int* p = &iNumber;
	// 
	// //*p = 20;
	// 
	// int* p2 = (int*)p;
	// 
	// *p2 = 20;
	// 
	// cout << iNumber << endl;

	//vector<int> vecInt;
	//
	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//vecInt.push_back(30);
	//vecInt.push_back(40);
	//
	//vector<int>::iterator iter = vecInt.end();
	//
	//cout << *iter;

	//CTest();
	// CStruct(1,2);   // 객체의 연산자 오버로딩 된 ()이게 호출되는게아니라 생성되는 시점이여서 생성자가 호출
	// CStruct a; // 객체 만들어놓고
	// a(1, 2);   // 그담에 부르는건 () 오버로딩된게 호출댐
	// 
	// 
	 map<int, int> mapInt;
	 map<int, int>::iterator iter = mapInt.begin();
	// 
	// mapInt.insert({ 1,2 });
	// 
	 //mapInt[1] = 100;
	 //iter[2];        // << map의 iter는 양방향 반복자이기에 임의접근 불가 이때 2는 키값을 의미함
	 //iter += 2;		 // << map의 iter는 양방향 반복자이기에 임의접근 불가
	// 
	// 
	// pair<int, int> Mypair(1, 100);
	// mapInt.insert(Mypair);

	//list<int> Intlist;
	//
	//Intlist.push_back(1);
	//Intlist.push_back(2);
	//Intlist.push_back(3);
	//Intlist.push_back(4);
	//Intlist.push_back(5);
	//
	//list<int>::iterator iter = Intlist.begin();
	//
	//Intlist.insert(iter, 999); // 얘는 가능함
	//Intlist.erase(iter);
	//cout << *iter << endl;
	//
	//vector<int> vecInt;
	//
	//vecInt.reserve(50);




	
	// vector<int>::iterator iter = vecInt.begin();
	// 
	// vecInt.insert(iter,999);
	// vecInt.erase(iter);
	// cout << *iter << endl;
	
	 
}



class CObj
{
public:
	CObj()
		:m_A(0)
		,m_B(0)
	{}

public:
	CObj& operator + (int iData)
	{
		m_A += iData;
		m_B += iData;
		
		return *this;
	}

	CObj& operator = (int iData)
	{
		m_A = iData;
		m_B = iData;

		return *this;
	}

	CObj& operator = (CObj& Origin)
	{
		m_A = Origin.m_A;
		m_B = Origin.m_B;

		return *this;
	}

private:
	int m_A;
	int m_B;
};




class A
{
private:
	int a;
	
private:
	 friend void f();

public:
	A(){}
	 virtual ~A(){
		cout << "A 소멸자" << endl;
	}

};

class B : public A
{
public:
	B(){}
	virtual ~B(){
		cout << "B 소멸자" << endl;
	}

	
};



