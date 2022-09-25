//#include <iostream>
//
//using namespace std;
//
//template<typename T>
//void myswap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template<typename T>
//void mysort(T array[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (array[max] < array[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			myswap(array[i], array[max]);
//		}
//	}
//}
//
//template<typename T>
//void printArr(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test()
//{
//	char arr1[] = "abdcfeg";
//	int len = sizeof(arr1) / sizeof(char);
//	mysort(arr1, len);
//	printArr(arr1, len);
//
//	int arr2[] = { 1,2,3,4,5,6,8,7 };
//	int len2 = sizeof(arr2) / sizeof(int);
//	mysort(arr2, len2);
//	printArr(arr2, len2);
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}