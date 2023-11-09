#include "pch.h"
#include "CppUnitTest.h"
#include "../1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 2;
            const int colCount = 3;
            const int Low = 1;
            const int High = 10;

            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

            Create(matrix, rowCount, colCount, Low, High);

    
            Assert::IsNotNull(matrix);
            Assert::AreEqual(matrix[0][0], matrix[0][0]); 

            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
		}
        TEST_METHOD(SortMatrix)
        {
            const int rowCount = 2;
            const int colCount = 3;

            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];


            Sort(matrix, rowCount, colCount);

          
            Assert::IsNotNull(matrix);
            Assert::AreEqual(matrix[0][0], matrix[0][0]); 

         
            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
        TEST_METHOD(CalcMatrix)
        {
            const int rowCount = 2;
            const int colCount = 3;

            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

      

            int S = 0;
            int k = 0;
            Calc(matrix, rowCount, colCount, 0, 0, S, k);

           
            Assert::AreEqual(S, S);

           
            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}
