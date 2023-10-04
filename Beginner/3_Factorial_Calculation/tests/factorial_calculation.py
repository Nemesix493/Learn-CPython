import unittest
import random


class TestFactorialCalculation(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Factorial Calculation with CPython")
        return super().setUpClass()

    @classmethod
    def factorial_calculation(cls, index: int):
        if index > 1:
            return index * cls.factorial_calculation(index - 1)
        else:
            return 1
    
    def test_factorial_calculation(self):
        random_int = random.randint(10, 20)
        expected = self.factorial_calculation(random_int)
        try:
            from CPythonLearn3 import factorial_calculation
            self.assertEqual(
                expected,
                factorial_calculation(random_int),
                f'The !{random_int} should be : {expected}'
            )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
