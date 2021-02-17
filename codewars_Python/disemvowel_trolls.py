def disemvowel(string):
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    set_without_vowels = set(string) - set(vowels)
    string_without_vowels = ''.join([x for x in string if x in set_without_vowels])
    return string_without_vowels
 
#@test.describe("Fixed Tests")
#def basic_tests():
#    test.assert_equals(disemvowel("This website is for losers LOL!"), "Ths wbst s fr lsrs LL!")
