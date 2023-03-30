//#include "StrVec¶¯Ì¬ÄÚ´æ·ÖÅäallocate.h"
//
//int main()
//{
//
//	allocator<string> string_alloc;
//
//	string* ps = string_alloc.allocate(10);
//	for (size_t i = 0; i < 10; i++)
//	{
//		string_alloc.construct(ps+i, "hello world!");
//		cout << *ps << endl;
//	}
//
//	for (size_t i = 0; i < 10; i++)
//	{
//		string_alloc.destroy(ps+i);
//
//	}
//	string_alloc.deallocate(ps, 10);
//	
//	putchar('\n');
//
//	StrVec SV1;
//    SV1.push_back("hello!");
//    cout << *SV1.begin() << " " << SV1.size() << " " << SV1.capacity_size() << endl;
//	
//	for (size_t i = 0; i < 8; i++)
//	{
//		string s = to_string(i);
//		double d = stod(s);
//		//cout << d << endl;
//		SV1.push_back( s );
//		cout << *(SV1.end()-1) << " " << SV1.size() << " " << SV1.capacity_size() << endl;
//	}
//
//	return 0;
//}




