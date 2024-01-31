import unittest
import random


class TestFibonacciCalculation(unittest.TestCase):

    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Fibonacci Calculation with CPython")
        return super().setUpClass()

    def fibonacci_calculation(self, index: int):
        if index <= 1:
            return 1
        return self.fibonacci_calculation(index - 1) + self.fibonacci_calculation(index - 2)

    def test_fibonacci_calculation(self):
        try:
            from CPythonLearn11 import fibonacci_calculation
            for i in range(10):
                index = random.randint(1, 20)
                expected = self.fibonacci_calculation(index)
                result = fibonacci_calculation(index)
                self.assertEqual(
                    expected,
                    result,
                    f'The fibonacci of "{index}" should be : "{expected}" instead of "{result}"'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
