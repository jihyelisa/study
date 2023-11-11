// for문을 사용하여 1부터 4까지의 팩토리얼 값 출력

using System;

class forFactorial
{
    static void Main()
    {
        int fact = 1;

        for (int i = 1; i <= 4; i++)
        {
            fact *= i;
            Console.WriteLine($"{i}! = {fact}");
        }
    }
}