//函数
#include<iostream>
using namespace std;

void simon(int);       //函数原型
double taxes(double);

int main()
{
	...
	return 0;
}

void simon(int  n)
{
	...
}


double taxes(double t)
{
	...
	return 2 * t;
}

// 面对对象编程（OOP）的本质是设计并扩展自己的数据类型
// 类定义了如何表示和控制数据，成员函数归类所有，描述了操纵类数据的方法

//浮点类型 d.dddE+n 指的是将小数点向右移n位， d.dddE~n 指的是将小数点向左移n位

//通常cout会删除结尾的零，保留机制(main 函数中添加)
cout.setf(ios_base::fixed, ios_base::floatfield);  //若果编译器不接受 ios_base, 改为 ios

对于 float,C++只保证6位有效位，如果需要更高的精度，使用 double, long double 

校验表：
（1） 如果有一个操作数的类型是 long double ， 则将另一个操作数转换位该类型
（2） 否则 double 
（3） 否则 float
（4） 否则 int
（5） 在这种情况下，如果两个数哦都是有符号或无符号的，且其中一个操作数的级别比另一个低，则转换为级别高的类型
（6） 如果一个操作数为有符号的，另一个操作数为无符号的，且无符号操作数的级别比有符号操作数高，则将有符号操作数转换为无符号操作数所属的类型
（7） 否则，如果有符号类型课表示无法号类型的所有可能取值，则将无符号操作数转化为有符号操作数所属的类型
（8） 否则，将两个操作数都转化为有符号类型的无法好版本


/************************************************************************************************************************************/
/************************************************************************************************************************************/

//数组
typeName arrayName[arryySize]; \\初始化的时候可以省略=，可不在大括号里面包含任何东西，但是列表初始化禁止缩窄转换，如将浮点数转换为整形，超过类型变量取值范围

//每次读取一行字符串输入
//1.面向行的输入：getline()
cin.getline(name,20);
//2.面向行的输入：get()
cin.get(name, 20);   // 使用不带任何参数的cin.get()调用可读取下一个字符（即使是转行符），用它来处理换行符，为读取下一行输入做好准备。如下例：
cin.get(name, ArSize);
cin.get();         // 或者在上下连个中都改为：cin.get(name,ArSize).get();
cin.get(dessert, ArSize);

//混合输入字符串和数字，如
int year;
cin >> year;
cout << "What is its street address?\n";
char address[80];
cin.getline(address, 80);
// 应当改为
cin >> year;
cin.get(); // or cin.get(ch)

//共用体的长度为其最大成员的长度
//共用体的用途：当数据项使用两种或更多种格式（但是不会同时使用）时，可以节省空间


//在声明语句中初始化指针，在这种情况下，被初始化的时指针，而不是其指向的值
int higgens = 5;
int * pt = &higgens;   // 将pt（而不是*pt）的值设置为&higgens

/*			一定要在对指针应用解除引用运算符（*）之前，将指针初始化为一个确定的，适当的地址				*/

//内存
int * ps = new int ; //allocate memory with new    和delete配套使用，不要用delete来释放不是new分配的内存，不能重复使用
...					 //use the memory
delete ps;			 //free memory with delete when done 只是释放ps指向的内存，不会删除指针pd本身，对空指针应用delete是安全的

int * psome = new int [10];   // new 运算符返回第一个元素的地址，该地址给psome
...
delete [] psome;   // 如果使用new [] 为数组分配内存，则应当使用delete[]来释放，若new []为一个实体分配内存，用delete 释放

// 将指针变量加1后，其增加的值等于指向的类型占用的字节数
double * pn;
double * pa;
char * pc;
double bubble = 3.2;
pn = &bubble;  					//pn是指向bubble的指针，则*pn是指向的值
pc = new char;     				//assign address of newly allocated char memory to pc
pa = new double[30];			//assign address of 1st element of array of 30 double to pa 
//如果pt是指向int的指针，则*pt是完全等同于一个int类型的值

使用strcpy()或strncpy(),而不是复制运算符来将字符串赋给数组

// 用于指向结构的指针  ->   使用见 pointer_struc.cpp

1. 自动存储

在函数内部定义的常规变量使用自动存储空间，称为自动变量
在所属的函数被调用时自动产生，在该函数结束时消亡

2. 静态存储

整个程序执行期间都存在的存储方式，使变量称为静态的方式有两种
	1） 在函数外卖那定义
	2） 在声明变量时使用关键字static: static double fee =  56.60;

3. 动态存储

使用 new 和 delete 运算符


C++ 的3种复合类型：
 数组： 数组可以在一个数据对象中存储多个同种类型的纸，用过使用索引和下标，可以访问数组中各个元素
 结构： 结构可以将多个不同类型的值存储到同一个数据对象中，可以使用成员关系运算符（.)来访问其中的成员。
	使用结构的第一步时创建建构模板，它定义结构存储了哪些成员，模板的名称将称为新类型的标识符
 指针： 被设计用来存储地址的变量。指针指向它存储的地址，指针声明指出了指针指向的对象的类型。对指针应用
 	解除引用运算符，将得到指针指向的位置中的值。


new 运算符允许在程序运行时为数据对象请求内存。该运算符返回获得内存的地址，可以将这个地址赋给一个指针，程序将只能使用该指针来访问这块内存。
如果数据对象是简单变量，则可以使用解除引用运算符（*）来获得其值；
如果数据对象是数组，则可以使用数组名那样来只用指针来访问元素；
如果数据对象是结构，则可以使用指针解除引用运算符（->）来访问其成员。

eg.
// reading chars to end of file
// input a string and <ENTER>, the input another string and <ENTER>, and press <CTRL>+<Z><ENTER> 
#include<iostream>
int main()
{
	using namespace std;
	char ch;												// int ch;   // for compatibility with EOF vaule
	int count = 0;
	cin.get(ch);    // attempt to read a char
	while (cin.fail() == false)    // test for EOF          // while (ch != EOF)
	{
		cout << ch;  // echo character						// cout.put(ch);  // cout.put(char(ch)) for some impkementations
		++count;
		cin.get(ch);	// attempt to read another char     // ch = cin.get();
	}
	cout << endl << count << "character read\n";
	return 0;
}

															// if ch is a character, loop will show it and ends if it's EOF

cin.get(ch), cin.get() 区别

		属性 						cin.get(ch)					       ch=cin.get()
传递输入字符的方式               赋给参数ch                             将函数返回值赋给ch
用于字符输入时函数的返回值       istream对象(执行bool转换后为true)        int类型的字符编码
到达EOF时函数的返回值           istream对象(执行bool转换后为false)       EOF


get() 主要用途时能够将stdio.h的getchar()和putchar()函数转换为iostream的cin.get()和cout.put()方法。
只要用头文件iostream替换stdio.h，并用作用相似的方法替换所有的getchar()和putchar().

输入一个常见的二维数组
 const int Cities = 5;
 const int Years = 4;
 ...

 const char * cities[Cities] = // array of pointers
 {
 	"Gribble City",
 	...
 };

 int maxtemps[Years][Cities] = // 2-D array
 {
 	{96, 100, 87, 101, 105},    // values for maxtemps[0]
 	...
 }

//output the structure of all the data
for ( int year = 0; city < Cities; ++city)
{
	cout << cities[city] << ":\t";
	for (int year = 0; year < Years; ++year)
		cout << maxtemps[year][city] << "\t";
	cout << endl;
}

/************************************************  分支语句和逻辑运算符 ***************************************************************/
/************************************************************************************************************************************/

简单的读整个字符输入并统计空格和字数
char ch;
int spaces = 0;
int total = 0;
cin.get(ch);
while (ch != '.')		// quit @ end of sentence
{
	if (ch == ' ')      // check if ch is a space
		++spaces;
	++total;			// done every time(字符总数包含按回车键生成的换行符)
	cin.get(ch)
}


头文件 cctype(ctype.h) 中定义的函数可以简化诸如确定字符是否为大写字母，数字，标点符号等工作

							cctype 中的字符函数
函数名称 												返回值
isalnum()                              如果参数是字母或数字，返回true
isalpha()                              参数为字母，返回true
iscntrl()							   参数为控制字符，返回true
isdigit() 							   数字（0~9）
isgraph()							   除空格之外的打印字符
islower()
isprint()							   打印字符（包括空格）
ispunct()							   标点符号
isspace()							   标准空白字符，如空格，进纸，换行符，回车，水平/垂直制表符
isupper()
tolower()
toupper()

处理错误输入
比如下例为要求用户提供5个高尔夫得分，当用户输入为错误内容时，将采取
1. 重置cin以接受新的输入
2. 删除错误输入
3. 提示用户再输入

while (!(cin >> golf[i]))
{
	cin.clear();           // reset input
	while (cin.get() != '\n')					// 比如声明想 char automobile[50] 这种，又要获取相关数据，就使用cin.getline(automobile, 50); 单个数用 cin >> year;
		continue;			// get rid of bad input
	cout << "Please enter a number";
}


/****************************************************************************************/


使用文件输出的主要步骤：
1. 包含头文件fstream        #include<fstream>     // file I/O support 
2. 创建一个ofstream对象     ofstream outFile;		// create object for output
3. 将该ofstream对象同一个文件关联起来    outFile.open("carinfo.txt");   // associate with a file
4. 就像使用cout那样使用该ofstream对象

// 存入文本相关信息, 注意打开已有的文件，以接受输出时，默认将其长度截短为0，因此原来的内容将丢失
cout.precision(2);				// use a precision of 2 for the display
...
outFile << fixed;
outFile.precision(2);			// use a precision of 2 for file output
outFile.setf(ios_base::showpoint);
outFile << "Make and model: " << automobile << endl;
outFile << "Year: " << year << endl;
outFile << "Was asking $" << a_price << endl;
outFile << "Now asking $" << d_price << endl;

outFile.close();			// done with file



读取文本文件

1. 声明对象
ifstream inFile;   // inFile an ifstream object
ifstream fin;      // fin an ifstream object
2. 将对象与特定的文件关联起来
inFile.open("bowing.txt");   // inFile used to read bowing.txt file
char filename[50];
cin >> filename;			 // user specifies a name
fin.open(filename);			 // fin used to read specified file
3. 使用这种对象
double wt;
inFile >> wt;				// read a number from bowing.txt
char line[81];
fin.getline(line, 81);		// read a line of text


在使用前先要判断文件是否成中打开
inFile.open("bowing.txt");
if (!inFile.is_open())
{
	exit(EXIT_FAILURE);					// #include<cstdlib>   // support for exit()
}



/**********************************************          函数 基础        ************************************************************/
/************************************************************************************************************************************/

定义函数格式
void functionName(parameterList) //  void fifi(float a, float b)  // declare each variable separately
{
	statement(s)
	return;    		// optional
}

C++ 中将数组名视为指针
cookies = &cookies[0]  // array name is address of first element

arr[i] == *(ar + i)   // value in two notations
&arr[i] == ar + i     // addresses in two notations

为将数组类型和元素数量告诉数组处理函数，建议通过两个不同得参数传递
void fillArray(int arr[], int size);


将const关键字用于指针
1. 让指针指向一个常量对象，防止使用该指针来修改所指向的值
int age = 39;
const int * pt = &age;

2. 将指针本身声明为常量，防止改变指针指向的位置。



要将字符串作为参数传递给函数，则表示字符串的方式有：
1. char数组
2. 用引号括起的字符串常量（即字符串字面值）；
3. 被设置为字符串的地址的char指针

char ghost[15] = "galloping";
char * str = "galumphing";
int n1 = strlen(ghost);   // ghost is &ghost[0]
int n2 = strlen(str);     // pointer to char
int n3 = strlen("gamboling");  // address of string


定义结构
struct travel_time
{
	int hours;
	int mins;
};

const int Mine_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
	travel_time day1 = {5, 45};
	...
	travel_time trip = sum(day1, day2);
	show_time(trip);
	...
}

travel_time sum(travel_time t1, travel_time t2)
{
	travel_time total;

	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
	total.hours = ...
	return total
}


void show_time(travel_time t)
{
	...
}

while(cin >> rplace.x >> rplace.y)	 // 整个while循环的测试表达式的最终结果为cin,  这个的运行机制需要详细看一下？？？


C++ 函数自己调用自己称为递归
eg.      //   test 最终将为false, 调用链将断开
void recurs(argumentlist)
{
	statements1
	if (test)
		recurs(arguments)
	statements2
}

例如：
...
void countdown(int n)
{
	cout << "Counting down ..." << n << endl;
	if (n > 0)
		countdown(n - r);	// function calls itself
	cout << n << ":Kaboom!\n";
}

/********************************* 函数指针 *********************************************/
函数的地址是存储其机器语言代码的内存的开始地址

1. 获取函数的地址
process(think);  // passes address of think() to process()
thought(think()); // passes return value of think() to thought()


2. 声明函数指针
例如一个估算时间函数的原型如下
double pam(int);   // prototype
则正确的指针类型声明如下
double (*pf)(int);   // pf points to a function that takes one int argument and that return type double 

通常要声明直向特定类型的函数的指针，可以首先编写这种函数的原型，然后用(*pf)替换函数名，这样pf就是这类函数的指针


3. 使用指针来调用函数
double pam(int);
double (*pf)(int);
pf = pam;     			// pf now points to the pam() function
double x = pam(4);      // call pam() using the function name
double y = (*pf)(5);    // call pam() using the pointer pf

(其他部分可以参见 auto / typedef)


/**********************************************          函数 深入     ***************************************************************/
/************************************************************************************************************************************/
a. 内联函数
只有经常调用内联函数，才能在时间节省上起到内联函数相较于普通函数上的优势
使用条件下选一
· 在函数声明前加上关键字inline；
· 在函数定义前加上关键字inline；
 
 eg.
inline double square(double x) {return x * x}

b. 引用变量
引用区别于指针：
1. 必须在声明引用前将其初始化，指针可以先声明，再赋值
int rat;
int & rodent;
rodent = rat;         // NO, you cant do this
int & rodents = rat;  // rodents is a reference


c. 临时变量
如果引用参数是const，则编译器将在下面两种情况下生成临时变量：
· 实参的类型正确，但不是左值；
· 实参的类型不正确，但可以转换为正确的类型。

左值参数是可被引用的数据对象，如变量，数组元素，结构成员，引用和解除引用的指针。


尽可能使用const
· 使用const可以避免无意中修改数据的编程错误；
· 使函数能够处理const和非const实参，否则只能接受非const数据；
· 使用const引用使函数能够正确生成并使用临时变量。

d. 继承
使得能够将特性从一个类传递给另一个类的语言特性被称为继承
继承的另一个特征：基类引用可以指向派生类对象，而无需进行强制类型转换。

e. 引用参数
使用引用参数的主要原因：
· 程序员能够修改调用函数中的数据对象。
· 通过传递引用而不是整个数据对象，可以提高程序的运行速度。


f. 默认参数
默认参数指的是当函数调用中省略了实参时自动使用的一个值

设置默认值，必须通过函数原型，将值赋给原型中的参数。

对于带参数列表的函数，必须从又向左添加默认值。
int harpo(int n, int m = 4, int j = 5);  // valid
int chico(int n, int m = 6, int j);      // invalid

beeps = harpo(2);   // same as harpo(2, 4, 5)


g. 函数重载
函数重载的关键是函数的参数列表。C++允许定义名称相同的函数，条件是他们的特征标不同，如果参数数目和/或参数类型不同，则特征标也不同。

仅当函数基本上执行相同的任务，但使用不同形式的数据时，才应使用函数重载。


h. 函数模板
如果需要多个将同一种算法用于不同类型的函数，使用函数模板；
如果不考虑向后兼容的问题，并愿意键入较长的单词，则声明类型参数时，使用关键字typename而不是用class

eg.
...
template <typename T> // or class T
void Swap(T &a, T &b);

int main()
{
	...
	Swap(i, j);   // generates void Swap(int &, int &)

	...
	Swap(x, y);   // generates void Swap(double &, double &)
    ...
}

// function template definition
template <typename T>   // or class T
void Swap(T &a, T &b)
{
	T temp; 	// temp a variable of type T
	temp = a;
	a = b;
	b = temp;
}


重载的模板
template <typename T>   // original template
void Swap(T &a, T &b):

template <typename T>   // new template
void Swap(T *a, T *b, int n);

...

template <typename T>    
void Swap(T &a, T &b)
{
	T temp; 	 
	temp = a;
	a = b;
	b = temp;
}

template <typename T>    
void Swap(T a[], T b[], int n)
{
	T temp; 
	for (int i = 0; i < n; i++)	 
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;	
	}

}

在代码中包含函数模板本身不会生成函数定义，其只是一个用于生成函数定义的方案。编译器使用模板为特定类型
生成函数定义时，得到的是模板实例

显式实例化：直接命令编译器创建特定的实例，如Swap<int>(), 语法：声明所需的种类--用<>符号指示类型，并在声明前
加上关键字template:
// 使用Swap()模板生成int类型的函数定义
template void Swap<int>(int, int);   //explicit instantiation

## 显示具体化， 使用下面两个等价的声明之一：
// 不要使用Swap()模板来生成函数定义，而应使用专门为int类型显式的定义的函数定义
template <> void Swap<int>(int &, int &); // explicit specialization
template <> void Swap(int &, int &);      // explicit specialization


/********************************* 显式实例化/显示具体化 ***************************************/

...
template <class T>
void Swap (T &, T &);    // template protype

template <> void Swap<job>(job &, job &);   // explicit specialization for job
int main(void)
{
	template void Swap<char>(char &, char &);	// explicit instantiation for char
	short a, b;
	...
	Swap(a, b); 		// implicit template instantiation for short
	job n, m;
	...
	Swap(n, m); 	//	use explicit specialization for job
	char g, h;
	...
	Swap(g, h); 	//  use explicit template instantiation for char
	...
}

引用变量是一种伪装指针，允许为变量创建别名。引用变量主要被用作处理结构和类对象的函数的参数。通常，
被声明为特定类型引用的标识符只能指向这种类型的数据。然而，如果一个类是从另一个类派生出来的，
则基类引用可以指向派生类对象



/**********************************************   内存模型和名称空间       ************************************************************/
/************************************************************************************************************************************/

程序组织策略：
·	头文件： 包含结构声明和使用这些结构的函数的原型
	·	函数原型；
	·	使用#define或const定义的符号变量；
	·	结构声明；
	·	类声明；
	·	模板声明；
	·	内联函数。
·	源代码文件： 包含于结构有关的函数的代码
·	源代码文件： 包含调用与结构相关的函数的代码

"coordin.h": 文件名包含在双引号中，编译器将首先查找当前的工作目录或源代码目录；
<coordin.h>: 文件名包含在尖括号中，编译器将在存储标准头文件的主机系统中查找。

coordin.h
-----------------------------------------------------------------------------------------------------------------------------------
// coordin.h --structure templates and function and function prototypes
// structure templates
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double distance;	// distance from origin
	double angle;		// direction from origin
};

struct rect
{
	double x; 	// horizontal distance from origin
	double y; 	// vertical distance from origin
};

// prototype
polar rect_to_polar(rect xypos);
void show_polar(polar daos);

#endif


file1.cpp
-----------------------------------------------------------------------------------------------------------------------------------
// file1.cpp -- example of a three-file program
#include<iostream>
#include "coordin.h"  	// structure templates, function prototypes
using namespace std;
int main()
{
	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while(cin >> rplace.x >> rplace.y)	// slick use of cin
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two number (q to quit):";
	}
	cout << "Bye!\n";
	return 0;
}


file2.cpp
-----------------------------------------------------------------------------------------------------------------------------------
// file2.cpp -- contains functions called in file1.cpp
#include<iostream>
#include<cmath>
#include "coordin.h"	

// convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;

	answer.distance =
	sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle  = atan2(xypos.y, xypos.x);
	return answer;    //return to polar structure
}


//show polar coordinates, converting anfle to degrees
void show_polar(polar dapos)
{
	using namespace std;
	const doubel Rad_to_deg = 57.29577951;

	cout << "distance = " << dapos.distance;
	cout << ", angle = " << dapos.angle * Rad_to_deg;
	cout << " degrees\n"; 
}


静态持续变量的声明
int global = 1000; 	// static duration, external linkage				作用于整个文件
static int one file = 50;   // static duration, internal linkage
int main()
{
	...
}

void fun1(int n)		// 变量count的作用域为局部，没有链接性。只能在func1()函数中使用；但是区别于llama，其即使在func1()没有被执行时，count也留在内存中
{
	static int count = 0; 	// static duration, no linkage
	int llama = 0;
}

void func2(int q)
{
	...
}

链接性为外部的变量即为外部变量（全局变量），其存储持续性为静态， 作用域为整个文件。

在多文件程序中，可以在一个文件（且只能在一个文件）中定义一个外部变量。使用该变量的其它文件必须使用关键字extren声明它




/********************************* 名称空间实例 ***************************************/

namesp.h
-----------------------------------------------------------------------------------------------------------------------------------

// namesp.h
#include<string>
//create the pers and debts namespaces
namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void getPerson(Person &);
	void showPerson(const Person &);
}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};
	void getDebt(Debt &);
	void showDebt(const Debt &);
	double sumDebts(const Debt ar[], int n);
}

namesp.cpp
-----------------------------------------------------------------------------------------------------------------------------------
// namesp.cpp  -- namespaces
#include<iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;
	void getPerson(Person & rp)
	{
		cout << "Enter first name: ";
		cin >> rp.fname;
		cout << "Enter last name: ";
		cin >> rp.lname;
	}
	void showPerson(const Person & rp)
	{
		std::cout << rp.lname << ", " << rp.fname;
	}
}

namespace debts
{
	void getDebt(Debt & rd)
	{
		getPerson(rd.name)
		std::cout << "Enter debt: ";
		std::cin >> rd.amount;
	}
	void showDebt(const Debt & rd)
	{
		showPerson(rd.name);
		std::cout << ": $" << rd.amount << std::endl;
	}
	double sumDebts(const Debt ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i ++)
			toutal += ar[i].amount
		return total;
	}
}


namessp.cpp
-----------------------------------------------------------------------------------------------------------------------------------
// usenmsp.cpp	--using namespaces
#include<iostream>
#include "namesp.h"
void other(void);
void another(void);
int main(void)
{
	using debts::Dent;

	using debts::showDebt;
	Debt golf = {{"Benny", "Goatsniff"}, 120.0};
	showDebt(golf);
	other();
	another();
	return 0;
}

void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;
	Person dg = {"Dooles", "Glister"};
	showPerson(dg);
	cout << endl;
	Debt zippy[3];
	int i;
	for (i = 0; i < 3; i++)
		getDebt(zippy[i]);

	for (i = 0; i < 3; i++)
		showDebt(zippy[i]);
	cout << "Total debt : $" << sumDebts(zippy, 3) << endl;
	return ;
}

void another(void)
{
	using pers::Person
	Person collector = {"Milo", "Rightshift"};
	pers::showPerson(collector);
	std::cout << std::endl;
}



/**********************************************          对象和类         ************************************************************/
/************************************************************************************************************************************/

类声明；
类定义的工作方式

stock00.h
-----------------------------------------------------------------------------------------------------------------------------------
// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include<string>

class Stock
{
private:	// 默认				// 只能通过公共成员访问类成员（数据隐藏）
	std::string company;
	long shares;											//		---
	void set_tot() {total_val = shares * share_val;}		//		---
	...																//  类成员可以是数据类型，也可以是函数
public:
	void acquire(const std::string & co, long n, double pr);//      ---
	...
};

#endif


数据项通常放在私有部分，组成类接口的成员函数放在公有部分

结构的默认访问类型是public, 
类为private


成员函数：
·	定义成员函数时，使用作用域解析运算符(::)来标识函数所属的类；
·	类方法可以访问类的private组件：	访问私有成员的唯一方法就是使用类方法。  使用友元函数可以避开这种限制。 让函数成为友元，需要再类声明中声明该函数，并在声明前加上关键字 friend



stock00.cpp
-----------------------------------------------------------------------------------------------------------------------------------
...

void Stock::acquire9const std::string & co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
					...
	    shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
...

void Stock::sell(long num, double price)
...

void Stock::update(double price)
...



usestock00.cpp
-----------------------------------------------------------------------------------------------------------------------------------
...
int main()
{
	Stock fluffy_the_cat;
	fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
	fluffy_the_cat.show();
	...
	return 0;
}

程序声明对象时，将自动调用构造函数

函数原型：
Stock(const string & co, long n =0, double pr = 0.0);
构造函数的一种可能定义：
Stock::Stock(const string & co, long n, double pr)
{
	company = co;

	if (n < 0)
		{
			atd::cerr ...
		
}

/*******  使用构造函数初始化对象  *******/
显式地调用构造函数
Stock food = Stock("World Cabbage", 250, 1.25);
隐式地调用构造函数
Stock garment("Furry Mason", 50, 2.5);

构造函数和析构函数可以没有返回值和声明类型，析构函数没有参数。
用构造函数创建对象后，程序负责跟踪该对象，直到其过期为止。析构函数完成清理工作

析构函数的原型
~Stock();				// 程序自动生成


stock10.h
-----------------------------------------------------------------------------------------------------------------------------------
...
class Stock
{
	...
public:
	// two constructors
	Stock();			// default constructor
	Stock(const std::string & co, long n = 0, double pr = 0.0);
	~Stock(); 	// noisy destructor
	void buy(long num, double price);
	...
}



/********************************* this指针 ***************************************/
this 指针指向用来调用成员函数的对象（this 被作为隐藏参数传递给方法）

每个成员函数（包括构造函数和析构函数）都有一个this指针。this 指针只想调用对象。如果方法需要引用整个调用对象，则可以使用表达式 *this

s私有数据成员存储信息，公有成员函数（又称为方法）提供访问数据的唯一途径。




/**********************************************          使用类         **************************************************************/
/************************************************************************************************************************************/

重载的运算符不必是成员函数，但必须至少有一个操作数是用户定义的类型

/*********************************  友元  ***************************************/
//友元函数
//友元类
//友元成员函数

通过让函数成为类的友元，可以赋予该函数与类的成员函数相同的访问权限；
在为类重载二元运算符时（带有两个参数的运算符）常常需要友元


***************** 创建友元
1.将函数原型放在类声明中，并在原型声明前加上关键字 friend
friend Time operator*(double m, const Time &t);  // goes in class decalration

2.编写函数定义。不要使用Time::限定符（用于成员函数），不要再定义中使用关键字 friend
Time operator *(double m, const Time & t)    // friend not used in definition
{
	Time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

只有在类声明中的原型中 friend 关键字，除非函数定义也是原型，否则不能在函数定义中使用该关键字

Time 类的加法运算符再Time类声明中的原型：
Time operator+(const Time & t) const; 	// member version
或者
friend Time operator+(const Time & t1, const Time & t2);	// nonmember version

非成员版本的重载运算符函数所需的形参数目与运算符使用的操作数数目相同；而成员版本所需的参数数目少一个，因为其中的一个操作数是被隐式地传递的调用对象。




/************************  类的自动转换和强制类型转换  *******************************/

将一个标准类型变量的值赋给另一个标准类型的变量时，如果两种类型兼容，则系统将自动将这个值转换为接收变量的类型

关键字 explicit
声明构造函数：
explicit Stonewt(double lbs);	// no implicit conversions allowed
将关闭该示例中的隐式转换，但允许显示转换：
Stonewt myCat;	// create a Stonewt object
myCat = 19.6;	// not valid if Stonewt(double) is declared as explicit
myCat = Stonewt(19.6);  // an explicti conversion


构造函数只能用于从某种类型到类类型的转换。要进行相反的转换，必须使用 转换函数


创建转换函数
operator typeName();

·	转换函数必须是类方法；
·	转换函数不能指定返回类型；
·	转换函数不能有参数。




此处的内容到12.2 ？？？后整章																						to be continued ...
/**********************************************     类和动态内存分配     *************************************************************/
/************************************************************************************************************************************/

静态数据成员在类声明中声明， 在包含类方法的文件中初始化。
初始化时使用作用域运算符来指出静态成员所属的类。但如果静态成员数整形或枚举型 const,则可以在类声明中初始化

C++自动提供下述成员函数
·	默认构造函数，如果没有定义构造函数；
·	默认析构函数，如果没有定义；
·	复制构造函数，如果没有定义；
·	赋值运算符，如果没有定义；
·	地址运算符，如果没有定义。


复制构造函数： 用于将一个对象复制到新创建的对象中，用于初始化过程中（包括按值传递参数），而不是常规的赋值过程中。
类的复制构造函数原型声明：
Class_name(const Class_name &);

新建一个对象并将其初始化为同类现有对象时，复制构造函数都将被调用

默认的复制构造函数逐个复制非静态成员(成员复制也称为浅复制），复制的是成员的值)




/**********************************************     C++中的代码重用      *************************************************************/
/************************************************************************************************************************************/






