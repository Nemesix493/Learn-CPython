import unittest
import random


class TestPalindromeCheck(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Palindrome Check with CPython")
        return super().setUpClass()

    @staticmethod
    def get_random_string(length: int = 5) -> str:
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        return "".join([
            random.choice(alphabet)
            for i in range(length)
        ])

    @staticmethod
    def reverse_string(string_to_reverse: str) -> str:
        return ''.join([
            string_to_reverse[i]
            for i in range(len(string_to_reverse)).__reversed__()
        ])

    @classmethod
    def get_random_palindrom(cls, length: int = 5) -> str:
        if length % 2 == 0:
            pattern = cls.get_random_string(length=int(length/2))
            reverse_pattern = cls.reverse_string(pattern)
            return pattern + reverse_pattern
        else:
            pattern = cls.get_random_string(length=int((length - 1)/2))
            reverse_pattern = cls.reverse_string(pattern)
            return pattern + cls.get_random_string(length=1) + reverse_pattern

    @classmethod
    def palindrome_check(cls, string_to_check: str) -> bool:
        return string_to_check == cls.reverse_string(string_to_check)

    def test_palindrome_check(self):
        try:
            from CPythonLearn9 import palindrome_check
            for i in range(10):
                string_to_check = self.get_random_string(random.randint(5, 20)) \
                    if i % 2 == 1 else self.get_random_palindrom(random.randint(5, 20))
                expected = self.palindrome_check(string_to_check)
                result = palindrome_check(string_to_check)
                self.assertEqual(
                    expected,
                    result,
                    f'The palindrom check of "{string_to_check}" should be : "{expected}" instead of "{result}"'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
