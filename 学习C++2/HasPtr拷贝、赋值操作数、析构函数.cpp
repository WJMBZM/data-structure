//#include "HasPtr拷贝、赋值操作数、析构函数.h"
//
//int main()
//{
//
//
//	HasPtr p("some value");
//
//
//	//HasPtr m = f(p); //  等价于 = HasPtr m(ret); 因为这里是初始化 而非  赋值   = 操作符
//
//	HasPtr m = f(p);
//
//	                                                               //m.id_reduce();
//
//	//HasPtr m( 1 );
//	//m = p;
//
//	HasPtr q(p);	//  也等价于 HasPtr q = p;  因为这里是初始化，而非 赋值 运算
//
//
//	return 0;
//}
//
//// 终于改好了.....没遗漏