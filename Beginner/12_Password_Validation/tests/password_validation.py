import unittest
import random
import itertools


class TestPasswordValidation(unittest.TestCase):
    UPPERCASE = 0
    LOWERCASE = 1
    NUMERIC = 2
    SPECIAL = 3

    def char_to_tag(self, char):
        if char.islower():
            return self.LOWERCASE
        elif char.isupper():
            return self.UPPERCASE
        elif char.isnumeric():
            return self.NUMERIC
        else:
            return self.SPECIAL

    def password_validation(self, password_to_check: str):
        # check length
        if len(password_to_check) < 8:
            return False
        tagged_string = [self.char_to_tag(pass_char) for pass_char in password_to_check]
        # check contain lowercase letter
        if self.LOWERCASE not in tagged_string:
            return False
        # check if contain uppercase letter
        if self.UPPERCASE not in tagged_string:
            return False
        # check if contain numeric char
        if self.NUMERIC not in tagged_string:
            return False
        # check if contain special char
        if self.SPECIAL not in tagged_string:
            return False
        return True

    def get_random_password(self, lenght: int, contain_types: list[int]) -> str:
        if len(contain_types) == 0:
            return ''
        characters = {
            self.UPPERCASE: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
            self.LOWERCASE: 'abcdefghijklmnopqrstuvwxyz',
            self.NUMERIC: '0123456789',
            self.SPECIAL: ',?;.:/!&~#{[]}()@=+/*-'
        }
        ordoned_string = ''
        for i in range(lenght):
            ordoned_string += random.choice(
                characters[contain_types[i % len(contain_types)]]
            )
        ordoned_string = list(ordoned_string)
        shuffle_string = ''
        while len(ordoned_string) > 0:
            shuffle_string += ordoned_string.pop(random.randint(0, len(ordoned_string)-1))
        return shuffle_string

    def get_all_spec_suit_password(self):
        type_list = [
            self.UPPERCASE,
            self.LOWERCASE,
            self.NUMERIC,
            self.SPECIAL
        ]
        return [
            {
                'lenght': 8 if spec_suit[0] == 1 else 7,
                'contain_types': [
                    type_list[i]
                    for i in range(4)
                    if spec_suit[i+1] == 1
                ]
            }
            for spec_suit in list(itertools.product([0, 1], repeat=5))
        ]

    def test_password_validation(self):
        try:
            from CPythonLearn12 import password_validation
            for spec_suit in self.get_all_spec_suit_password():
                # generate the password
                password_to_check = self.get_random_password(**spec_suit)
                # check validation
                expected = self.password_validation(password_to_check)
                result = password_validation(password_to_check)
                self.assertEqual(
                    expected,
                    result,
                    f'This password "{password_to_check}" should {"not " if not expected else ""}be valid !'
                )
        except ImportError as e:
            self.assertTrue(
                False,
                f'The importation failed due to this error: {e}'
            )
