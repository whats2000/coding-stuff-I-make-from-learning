score = 0

# 轉換對照表
score_range = {
    'A+': {'min': 90, 'max': 100},
    'A': {'min': 85, 'max': 89},
    'A-': {'min': 80, 'max': 84},
    'B+': {'min': 77, 'max': 79},
    'B': {'min': 73, 'max': 76},
    'B-': {'min': 70, 'max': 72},
    'C+': {'min': 67, 'max': 69},
    'C': {'min': 63, 'max': 66},
    'C-': {'min': 60, 'max': 62},
    'D': {'min': 50, 'max': 59},
    'E': {'min': 40, 'max': 49},
    'F': {'min': 0, 'max': 39}
}

# 信息差異
is_pass_msg = {
    0: 'Congratulations! you pass ',
    1: 'Sorry, you fail '
}

while True:
    # 資料輸入
    try:
        score = int(input("Please input your score: "))

    except ValueError:
        print('What are you input? Check again\n')

        continue

    # 判定是否為有效範圍
    if 0 <= score <= 100:
        # 逐步檢驗
        for grade in score_range:
            if score_range[grade]['min'] <= score <= score_range[grade]['max']:
                print(f'Your grade is {grade}')

                # 檢驗是否及格
                if score >= 60:
                    print('{}this class.\n'.format(is_pass_msg[0]))
                else:
                    print('{}this class.\n'.format(is_pass_msg[1]))

                continue

    else:
        print('Your score out of range!')

        break
