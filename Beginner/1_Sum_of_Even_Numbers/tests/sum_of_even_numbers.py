import unittest
import random


class TestSumOfEvenNumbers(unittest.TestCase):
    @staticmethod
    def gen_random_list() -> list[int]:
        return [
            random.randint(1, 20)
            for i in range(40)
        ]

    @staticmethod
    def sum_of_even_numbers(random_list: list[int]) -> int:
        return sum(
            [
                random_int
                for random_int in random_list
                if random_int % 2 == 0
            ]
        )

    def test_sum_of_even_numbers(self):
        random_list = self.gen_random_list()
        expected = self.sum_of_even_numbers(random_list)
        try:
            from CPythonLearn1 import sum_of_even_numbers
            self.assertEqual(
                expected,
                sum_of_even_numbers(random_list),
                f'The sum of even numbers should be : {expected}'
            )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
