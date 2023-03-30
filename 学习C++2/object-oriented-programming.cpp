#include "object-oriented-programming.h"

//int main()
//{
//	quote q;
//	bulk_quote bq;
//	quote* pq = &q;
//	pq = &bq;
//
//	quote q2((string)"1996-10-26", 20);
//	bulk_quote bq2((string)"1996-10-26", 20.0, 10, 0.8);
//
//	// revenue 函数即为   动态绑定
//	cout << bq2.revenue(5) << endl;    // 100
//	cout << bq2.revenue(10) << endl;   // 160
//
//	cout << q2.revenue(5) << endl;    //100
//	cout << q2.revenue(10) << endl;   //200
//
//	return 0;
//}


//
//int main()
//{
//	//set_intersection();
//	//vector<int> vi = { 0,1,2,3,4,5,6 };
//	shared_ptr<vector<int>> p = make_shared <vector<int>>();    //也是新建空间
//	//shared_ptr<vector<int>> pv = new vector<int>(10,6) ;
//	vector<int>* pv = new vector<int>(10, 6);
//	//auto pv = new vector<int>(10, 6);
//	shared_ptr<vector<int>> pv1(pv);
//	*pv = { 0,1,2,3,4,5,6 };
//	*p = {0,1,2,3,4,5,6};
//	cout << *(p->end() - 1) << endl;
//	// 但是分配内存有区别  new有先后  ，是分两块的
//	cout << *(pv1->end() - 1) << endl;
//
//	return 0;
//}



