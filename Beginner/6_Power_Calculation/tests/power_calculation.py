import unittest
import random


class TestPowerCalculation(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Power Calculation with CPython")
        return super().setUpClass()

    @staticmethod
    def get_power_calculation(base: int, exponent: int) -> int:
        return base**exponent
    
    def test_power_calculation(self):
        try:
            from CPythonLearn6 import power_calculation
            for i in range(5):
                base = random.randint(2, 20)
                exponent = random.randint(2, 10)
                expected = self.get_power_calculation(base, exponent)
                result = power_calculation(base, exponent)
                self.assertEqual(
                    expected,
                    result,
                    f'The {base} raised to {exponent} power should be : {expected} \n {expected} != {result}'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
