import unittest
import random


class TestStringReversal(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing String Reversal with CPython")
        return super().setUpClass()

    @staticmethod
    def get_random_string() -> str:
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        return "".join([
            random.choice(alphabet)
            for i in range(50)
        ])

    @staticmethod
    def string_reverse(original_string: str) -> str:
        return "".join([
            original_string[-(i + 1)]
            for i in range(len(original_string))
        ])

    def test_prime_number_check(self):
        try:
            from CPythonLearn5 import string_reverse
            for i in range(5):
                random_string = self.get_random_string()
                expected = self.string_reverse(random_string)
                self.assertEqual(
                    expected,
                    string_reverse(random_string).replace('\x00', ''),
                    f'The reverse of "{random_string}" should be : "{expected}"'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
