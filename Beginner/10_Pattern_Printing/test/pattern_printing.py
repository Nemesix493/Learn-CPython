import unittest
import random
import json
import sys
from io import StringIO
from pathlib import Path

JSON_FILE_PATH = Path(__file__).resolve().parent.parent / 'patterns.json'


class TestPatternPrinting(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        print("Testing Pattern printing with CPython")
        cls.get_json()
        return super().setUpClass()

    @classmethod
    def get_json(cls):
        with open(JSON_FILE_PATH) as json_file:
            cls.json_data = json.load(json_file)

    def test_printed_value_success(self):
        try:
            from CPythonLearn10 import pattern_printing
            for i in range(2 * len(self.json_data.keys())):
                with StringIO() as captured_pattern:
                    pattern_name = random.choice(list(self.json_data.keys()))
                    expected = self.json_data[pattern_name]
                    current_sdtout = sys.stdout
                    sys.stdout = captured_pattern
                    pattern_printing(pattern_name)
                    result = captured_pattern.getvalue()
                    sys.stdout = current_sdtout
                    self.assertEqual(
                        expected,
                        result,
                        f'The pattern printed should be : "{expected}" instead of "{result}"'
                    )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )

    def test_printed_value_error(self):
        try:
            from CPythonLearn10 import pattern_printing
            try:
                pattern_name = "invalid_pattern_name"
                pattern_printing(pattern_name)
                self.assertTrue(False, f"\"{pattern_name}\" should raise raise an error because it's invalid !")
            except ValueError:
                self.assertTrue(True)
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
