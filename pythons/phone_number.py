import re

# your code goes here
rawPhoneNum = r"^(1|8|9)[0-9]{7,7}$"

if re.match(rawPhoneNum, input()):
    print('valid')
else:
    print('Invalid')
