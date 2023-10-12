import unittest
import random


class TestPrimeNumberCheck(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Prime Number Check with CPython")
        return super().setUpClass()

    @staticmethod
    def prime_number_check(number: int) -> bool:
        if number == 1 or number == 2:
            return True
        if number % 2 != 0:
            for i in range(3, int((number + 1) / 2)):
                if number % i == 0:
                    return False
            return True
        return False

    def test_prime_number_check(self):
        try:
            from CPythonLearn4 import prime_number_check
            for i in range(5):
                random_int = random.randint(10**i, 10**(i+1))
                expected = self.prime_number_check(random_int)
                self.assertEqual(
                    expected,
                    prime_number_check(random_int),
                    f'The !{random_int} should be : {expected}'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
