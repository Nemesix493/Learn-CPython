import unittest
import random


class TestAvarageCalculation(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Average Calculation with CPython")
        return super().setUpClass()

    @staticmethod
    def average_calculation(number_list: list[int]) -> float | int:
        return sum(number_list)/len(number_list)

    @staticmethod
    def get_random_int_list() -> list[int]:
        return [
            random.randint(-10, 10)
            for i in range(20)
        ]

    def test_average_calculation(self):
        try:
            from CPythonLearn7 import average_calculation
            for i in range(5):
                random_int_list = self.get_random_int_list()
                expected = self.average_calculation(random_int_list)
                result = average_calculation(random_int_list)
                self.assertEqual(
                    expected,
                    result,
                    f'The average should be : {expected} instead of {result}'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
