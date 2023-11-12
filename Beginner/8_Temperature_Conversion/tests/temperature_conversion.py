import unittest
import random


class TestTemperatureConversion(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Temperature Conversion with CPython")
        return super().setUpClass()

    @staticmethod
    def temperature_conversion(celsius_temperature: float) -> float:
        return celsius_temperature * 9 / 5 + 32

    def test_temperature_conversion(self):
        try:
            from CPythonLearn8 import temperature_conversion
            for i in range(5):
                celsius_temperature = round(random.uniform(-10, 60), 5)
                expected = round(self.temperature_conversion(celsius_temperature), 5)
                result = round(temperature_conversion(celsius_temperature), 5)
                self.assertEqual(
                    expected,
                    result,
                    f'The Fahrenheit temperature of {celsius_temperature}°C should be {expected} instead of {result}'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
