import unittest
import random


class TestCountVowels(unittest.TestCase):

    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Count Vowels in a string with CPython")
        return super().setUpClass()

    @staticmethod
    def get_random_string() -> str:
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        return "".join([
            random.choice(alphabet)
            for i in range(50)
        ])

    @staticmethod
    def count_vowels(random_string: str) -> int:
        vowels_list = "aeiou"
        return len([
            None
            for letter in random_string
            if letter in vowels_list
        ])

    def test_count_vowels(self):
        random_string = self.get_random_string()
        expected = self.count_vowels(random_string)
        try:
            from CPythonLearn2 import count_vowels
            self.assertEqual(
                expected,
                count_vowels(random_string),
                f'The vowels count should be : {expected}'
            )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
