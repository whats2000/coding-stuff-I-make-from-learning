# convert list to dict
test_list = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]

test_dict = {}

for key, value in test_list:
    if key not in test_dict:
        test_dict[key] = [value]
    else:
        test_dict[key].append(value)

print(test_dict)

# convert  dict to list
test_dict = {'Science': [88, 89, 62, 95], 'Language': [77, 78, 84, 80]}
test_list = []

for value1, value2 in zip(test_dict['Science'], test_dict['Language']):
    test_list.append({'Science': value1, 'Language': value2})

print(test_list)

# calculate times of word in sentence
sentence = input('Enter a sentence : ')

sentence = sentence.split(' ')

cal_word = {}

for word in sentence:
    if word not in cal_word:
        cal_word[word] = 1
    else:
        cal_word[word] += 1

for key in cal_word:
    print(f'\'{key}\' appears {cal_word[key]} times in the sentence')
